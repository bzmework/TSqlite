/*
	Row.h
*/

#ifndef __ROW_H_
#define __ROW_H_

#include "TSqlite.h"
#include "ErrorMsg.h"

/*
	行枚举类
*/
class ATL_NO_VTABLE RowEnum: public CComSAEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, VARIANT>
{
public:
	
	//创建行枚举(RowEnum)
	static HRESULT CreateObject(SAFEARRAY* sa, IUnknown* pUnk, IUnknown** ppEnum)
	{
		typedef CComObject<RowEnum> TRowEnum;

		HRESULT hRet = E_POINTER;
		if (ppEnum != NULL)
		{
			*ppEnum = NULL;
			TRowEnum* p;
			hRet = TRowEnum::CreateInstance(&p);
			if (SUCCEEDED(hRet))
			{
				// If this object has ownership of the data then we need to keep it around
				hRet = p->Init(sa, pUnk, AtlFlagCopy);
				if (SUCCEEDED(hRet))
				{
					hRet = p->_InternalQueryInterface(IID_IUnknown, (void**)ppEnum);
				}
				
				if (FAILED(hRet))
				{
					delete p;
				}
			}
		}
		return hRet;
	} 
};

class ATL_NO_VTABLE Row :
	public CComObjectRootEx<CComObjectThreadModel>,
	public CComCoClass<Row, &CLSID_Row>,
	public ISupportErrorInfo,	
	public IDispatchImpl<IRow, &IID_IRow, &LIBID_TSqlite>,
	public IProvideClassInfo2Impl<&CLSID_Row, NULL, &LIBID_TSqlite>
{
public:

	Row()
	{
		m_ErrMsg.Init(CLSID_Row, IID_IRow);
		m_nSize = 0;
		m_sa = NULL;
	}
	
	DECLARE_NOT_AGGREGATABLE(Row)

	BEGIN_COM_MAP(Row)
		COM_INTERFACE_ENTRY(IRow)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(ISupportErrorInfo)		
		COM_INTERFACE_ENTRY(IProvideClassInfo)
		COM_INTERFACE_ENTRY(IProvideClassInfo2)
	END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
		if (m_sa != NULL)
		{
			SafeArrayDestroy(m_sa);
		}
	}

public:
	// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

public:

	//初始化
	HRESULT Init(IResultset* pRs);
	
	//创建行(Row)
	static HRESULT CreateObject(IResultset* pRs, IRow** ppRow);

public:
	// IRow

	//支持ForEach
	STDMETHOD(get__NewEnum)(/*[out, retval]*/ IUnknown** ppEnum);

	//返回行的指定列值
	STDMETHOD(get_Item)(/*[in]*/ LONG lngIndex, /*[in, defaultvalue(dtUnknown)]*/ DataTypeConstants eType, /*[out, retval]*/ VARIANT* pVal);
	
	//返回行的列值, ForEach时自动调转到下一列并返回列值")] 
	STDMETHOD(get_Value)(/*[out, retval]*/ VARIANT* pVal);

	//返回行包含的列数
	STDMETHOD(get_Count)(/*[out, retval]*/ LONG* pVal);

protected:
	
	LONG m_nSize;
	SAFEARRAY* m_sa;
	
private:
	ErrorMsg m_ErrMsg;

};

#endif //__ROW_H_

