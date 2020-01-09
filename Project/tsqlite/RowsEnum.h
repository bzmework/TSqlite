/*
	RowsEnum.h
*/

#ifndef __ROWSDYNENUM_H_
#define __ROWSDYNENUM_H_

/*
	�м�(��̬)ö����
*/
class ATL_NO_VTABLE RowsDynEnumImpl: public IEnumVARIANT
{
public:

	//��ʼ��
	HRESULT Init(IResultset* pRs);	
	
public:
	// IEnumVARIANT

	STDMETHOD(Next)(ULONG celt, VARIANT* rgelt, ULONG* pceltFetched);
	STDMETHOD(Skip)(ULONG celt);
	STDMETHOD(Reset)(void);
	STDMETHOD(Clone)(IEnumVARIANT** ppEnum);
	
protected:

	CComPtr<IResultset> m_pRs;
	
};

class ATL_NO_VTABLE RowsDynEnum:
	public RowsDynEnumImpl,
	public ISupportErrorInfo,
	public CComObjectRootEx<CComObjectThreadModel>
{
public:

	BEGIN_COM_MAP(RowsDynEnum)
		COM_INTERFACE_ENTRY_IID(IID_IEnumVARIANT, RowsDynEnumImpl)
		COM_INTERFACE_ENTRY(ISupportErrorInfo)		
	END_COM_MAP()
	
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);
	
public:

	//������̬�м�ö��(RowsDynEnum)
	static HRESULT CreateObject(IResultset* pRs, IUnknown** ppEnum);
};

#endif //__ROWSDYNENUM_H_