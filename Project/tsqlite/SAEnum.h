/*
	SAEnum.h
	
	Implementing enumeration on one-dimension safearray.
*/

template <class DestinationType, class SourceType = DestinationType, 
	class DestinationCopy = _Copy<DestinationType>,
	class SourceCopy = _Copy<SourceType>
>
class GenericCopy
{
public :
	typedef DestinationType	destination_type;
	typedef SourceType		source_type;

	static void init(destination_type* p)
	{
		DestinationCopy::init(p);
	}
	static void destroy(destination_type* p)
	{
		DestinationCopy::destroy(p);
	}
	
	static void source_destroy(source_type* p)
	{
		SourceCopy::destroy(p);
	}
	
	static HRESULT copy(destination_type* pTo, const source_type* pFrom)
	{
		return DestinationCopy::copy(pTo, const_cast<source_type*>(pFrom));
	}

}; // class GenericCopy 

/*
template<>
class _Copy<IDispatch*> :public _CopyInterface<IDispatch>
{
};

template<>
class _Copy<IUnknown*> :public _CopyInterface<IUnknown>
{
};
*/

/*
template<class T>
class _Copy<T*> :public _CopyInterface<T>
{
};
*/

/*
template<>
class _Copy<IUnknown*>
{
public:

	typedef _CopyInterface<IUnknown> copy_iunknown;

	static HRESULT copy(IUnknown* * p1, IUnknown * const * p2)
	{
		return copy_iunknown::copy(p1,p2);
	}
	static void init(IUnknown** p ) { copy_iunknown::init(p);}
	static void destroy(IUnknown** p) {copy_iunknown::destroy(p);}
};

template<>
class _Copy<IDispatch*>
{
public:

	typedef _CopyInterface<IDispatch> copy_idisp;

	static HRESULT copy(IDispatch* * p1, IDispatch * const * p2)
	{
		return copy_idisp::copy(p1,p2);
	}
	static void init(IDispatch** p ) { copy_idisp::init(p);}
	static void destroy(IDispatch** p) {copy_idisp::destroy(p);}
};
*/

template <>
class GenericCopy<VARIANT, IDispatch*>
{
public :

	typedef VARIANT	destination_type;
	typedef IDispatch	source_interface;
	typedef IDispatch*	source_type;

	static void init(destination_type* p)
	{
		_Copy<destination_type>::init(p);
	}
	static void destroy(destination_type* p)
	{
		_Copy<destination_type>::destroy(p);
	}
	
	static void source_destroy(source_type* p)
	{
		_CopyInterface<source_interface>::destroy(p);
	}
	
	static HRESULT copy(destination_type* pTo, const source_type* pFrom)
	{
		return CComVariant(*pFrom).Detach(pTo);
	}

}; 

template <>
class GenericCopy<VARIANT, IUnknown*>
{
public :

	typedef VARIANT	destination_type;
	typedef IUnknown	source_interface;
	typedef IUnknown*	source_type;

	static void init(destination_type* p)
	{
		_Copy<destination_type>::init(p);
	}
	static void destroy(destination_type* p)
	{
		_Copy<destination_type>::destroy(p);
	}
	
	static void source_destroy(source_type* p)
	{
		_CopyInterface<source_interface>::destroy(p);
	}
	
	static HRESULT copy(destination_type* pTo, const source_type* pFrom)
	{
		return CComVariant(*pFrom).Detach(pTo);
	}

}; 


template <class Base, const IID* piid, class TB, class T, class Copy = GenericCopy<T,TB> >
class ATL_NO_VTABLE CComSAEnumImpl : public Base
{
public:

	CComSAEnumImpl()
	{
		m_dwFlags = 0;
		m_sa = NULL;
		m_end = m_iter = 0;
		m_pelem = NULL;
	}
	
	virtual ~CComSAEnumImpl();
	STDMETHOD(Next)(ULONG celt, T* rgelt, ULONG* pceltFetched);
	STDMETHOD(Skip)(ULONG celt);
	STDMETHOD(Reset)(void){m_iter = 0;return S_OK;}
	STDMETHOD(Clone)(Base** ppEnum);
	HRESULT Init(SAFEARRAY* sa, IUnknown* pUnk, CComEnumFlags flags = AtlFlagNoCopy);
	
	ULONG m_iter;
protected:

	CComPtr<IUnknown> m_spUnk;
	SAFEARRAY* m_sa;
	
	ULONG m_end;
	TB* m_pelem;
	DWORD m_dwFlags;
	
protected:

	enum FlagBits
	{
		BitCopy=1,
		BitOwn=2
	};
};

template <class Base, const IID* piid, class TB, class T, class Copy>
CComSAEnumImpl<Base, piid, TB, T, Copy>::~CComSAEnumImpl()
{
	if (( m_sa != NULL ) && (m_dwFlags & BitOwn))
	{
		SafeArrayDestroy( m_sa );
	}
	
	if ( m_pelem != NULL )
	{
		delete [] m_pelem;
	}
}

template <class Base, const IID* piid, class TB, class T, class Copy >
STDMETHODIMP CComSAEnumImpl<Base, piid, TB, T, Copy>::Next(ULONG celt, T* rgelt,
	ULONG* pceltFetched)
{
	if (pceltFetched != NULL)
		*pceltFetched = 0;
	if (celt == 0)
		return E_INVALIDARG;
	if (rgelt == NULL || (celt != 1 && pceltFetched == NULL))
		return E_POINTER;
	if (m_sa == NULL)
		return E_FAIL;
		
	ULONG nRem = m_end - m_iter;
	HRESULT hRes = S_OK;
	if (nRem < celt)
		hRes = S_FALSE;
	ULONG nMin = celt < nRem ? celt : nRem ;
	if (pceltFetched != NULL)
		*pceltFetched = nMin;
	T* pelt = rgelt;
	bool bSource;
	
	while(nMin--)
	{
		bSource = false;
		HRESULT hr = SafeArrayGetElement( m_sa, (LONG*)&m_iter, m_pelem );
		if ( S_OK == hr )
		{
			bSource = true;
			hr = Copy::copy(pelt, m_pelem);
		}
		
		if (FAILED(hr))
		{
			if ( bSource )
			{
				Copy::source_destroy( m_pelem );
			}
			
			while (rgelt < pelt)
				Copy::destroy(rgelt++);
			if (pceltFetched != NULL)
				*pceltFetched = 0;
			return hr;
		}
		
		if ( bSource )
		{
			Copy::source_destroy( m_pelem );
		}
		
		pelt++;
		m_iter++;
	}
	return hRes;
}

template <class Base, const IID* piid, class TB, class T, class Copy >
STDMETHODIMP CComSAEnumImpl<Base, piid, TB, T, Copy>::Skip(ULONG celt)
{
	if (celt == 0)
		return E_INVALIDARG;

	ULONG nRem = m_end - m_iter;
	ULONG nSkip = (celt > nRem) ? nRem : celt;
	m_iter += nSkip;
	return (celt == nSkip) ? S_OK : S_FALSE;
}

template <class Base, const IID* piid, class TB, class T, class Copy>
STDMETHODIMP CComSAEnumImpl<Base, piid, TB, T, Copy>::Clone(Base** ppEnum)
{
	typedef CComObject<CComSAEnum<Base, piid, TB, T, Copy> > _class;
	HRESULT hRes = E_POINTER;
	if (ppEnum != NULL)
	{
		*ppEnum = NULL;
		_class* p;
		hRes = _class::CreateInstance(&p);
		if (SUCCEEDED(hRes))
		{
			// If this object has ownership of the data then we need to keep it around
			hRes = p->Init(m_sa, (m_dwFlags & BitOwn) ? this : m_spUnk);
			if (SUCCEEDED(hRes))
			{
				p->m_iter = m_iter;
				hRes = p->_InternalQueryInterface(*piid, (void**)ppEnum);
			}
			if (FAILED(hRes))
				delete p;
		}
	}
	return hRes;
}

template <class Base, const IID* piid, class TB, class T, class Copy>
HRESULT CComSAEnumImpl<Base, piid, TB, T, Copy>::Init(SAFEARRAY* sa, IUnknown* pUnk,
	CComEnumFlags flags)
{
	if (flags == AtlFlagCopy)
	{
		HRESULT hr = SafeArrayCopy( sa, &m_sa );
		if ( FAILED(hr) )
		{
			return hr;
		}
	}
	else
	{
		m_sa = sa;
	}
	
	m_spUnk = pUnk;
	m_iter = 0;
	
	HRESULT hr = SafeArrayGetUBound( m_sa, 1, (LONG*)&m_end );
	if ( FAILED(hr) )
	{
		return hr;
	}
	m_end++;
	
	UINT nSize = SafeArrayGetElemsize( m_sa );
	ATLASSERT( nSize > 0 );
	m_pelem = (TB*)new BYTE[nSize];
	
	m_dwFlags = flags;
	return S_OK;
}

template <class Base, const IID* piid, class TB, class T, class Copy = GenericCopy<T,TB>, class ThreadModel = CComObjectThreadModel>
class ATL_NO_VTABLE CComSAEnum :
	public CComSAEnumImpl<Base, piid, TB, T, Copy>,
	public CComObjectRootEx< ThreadModel >
{
public:
	typedef CComSAEnum<Base, piid, TB, T, Copy > _CComEnum;
	typedef CComSAEnumImpl<Base, piid, TB, T, Copy > _CComEnumBase;
	BEGIN_COM_MAP(_CComEnum)
		COM_INTERFACE_ENTRY_IID(*piid, _CComEnumBase)
	END_COM_MAP()
};
