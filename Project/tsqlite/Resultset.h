/*
	Resultset.h
*/

#ifndef __RESULTSET_H_
#define __RESULTSET_H_

#include "resource.h"       // main symbols
#include "ErrorMsg.h"

class ATL_NO_VTABLE Resultset : 
	public CComObjectRootEx<CComObjectThreadModel>,
	public CComCoClass<Resultset, &CLSID_Resultset>,
	public ISupportErrorInfo,
	public IDispatchImpl<IResultset, &IID_IResultset, &LIBID_TSqlite>,
	public IProvideClassInfo2Impl<&CLSID_Resultset, NULL, &LIBID_TSqlite>
{
public:

	Resultset()
	{
		m_ErrMsg.Init(CLSID_Resultset, IID_IResultset);

		m_bEOF = true;
		m_nRowCount = 0;
		m_eState = osClosed;
		m_stmt = NULL;
	}

	void FinalRelease()
	{
		//SQL已经准备好
		if (m_eState == osPrepared)
		{
			//sqlite3_finalize
			//销毁一个准备语句(prepared statement)对象，在需要时执行这个销毁函数以防止内存泄露。
			//在准备语句对象为空指针时调用这个函数也没有什么影响。
			//sqlite3_finalize释放stmt占用的内存.该内存是在sqlite3_prepare()时分配的. 
			int nRet = sqlite3_finalize(m_stmt);
			m_eState = osClosed;
			m_nRowCount = 0;
			m_bEOF = true;
			m_stmt = NULL;
		}
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_RESULTSET)
	DECLARE_PROTECT_FINAL_CONSTRUCT()

	BEGIN_COM_MAP(Resultset)
		COM_INTERFACE_ENTRY(IResultset)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(ISupportErrorInfo)
		COM_INTERFACE_ENTRY(IProvideClassInfo)
		COM_INTERFACE_ENTRY(IProvideClassInfo2)
	END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ILiteStatement
public:

	//返回当前活动连接对象")] 
	STDMETHOD(get_ActiveConnection)(/*[out, retval]*/ IConnection** ppConn);

	//设置当前活动连接对象
	STDMETHOD(put_ActiveConnection)(/*[in]*/ IConnection* pConn);

	//返回待执行的SQL查询
	STDMETHOD(get_SQL)(/*[out, retval]*/ BSTR* pVal);

	//设置待执行的SQL查询
	STDMETHOD(put_SQL)(/*[in]*/ BSTR newVal);

	//预备SQL查询
	STDMETHOD(Prepare)(/*[in, defaultvalue("")]*/ BSTR strSql);

	//执行SQL查询
	STDMETHOD(Execute)();

	//重新执行SQL查询
	STDMETHOD(Requery)();

	//关闭结果集
	STDMETHOD(Close)();
	
	//当前记录位置位于结果集的第一条记录之前
	//STDMETHOD(get_BOF)(/*[out, retval]*/ VARIANT_BOOL* pVal);

	//当前记录位置位于结果集的最后一条记录之后
	STDMETHOD(get_EOF)(/*[out, retval]*/ VARIANT_BOOL* pVal);

	//移动到第一条记录
	STDMETHOD(MoveFirst)();

	//移动到下一条记录
	STDMETHOD(MoveNext)();

	//移动到上一条记录
	//STDMETHOD(MovePrevious)();

	//移动到最后一条记录
	STDMETHOD(MoveLast)();

	//移动到指定的记录行
	//STDMETHOD(MoveSpecial)(/*[in, defaultvalue(1)]*/ LONG lngRow);
	
	//移动指定行数
	STDMETHOD(MoveStep)(/*[in, defaultvalue(1)]*/ LONG nSteps, /*[out, retval]*/ VARIANT_BOOL* pVal);

	//返回列数
	STDMETHOD(get_ColumnCount)(/*[out, retval]*/ LONG* pVal);

	//返回列类型
	STDMETHOD(get_ColumnType)(/*[in]*/ VARIANT varIndex, /*[out, retval]*/ DataTypeConstants* pVal);

	//返回列名
	STDMETHOD(get_ColumnName)(/*[in]*/ LONG lngIndex, /*[out, retval]*/ BSTR* pVal);

	//返回列值
	STDMETHOD(get_ColumnValue)(/*[in]*/ VARIANT varIndex, /*[in, defaultvalue(dtUnknown)]*/ DataTypeConstants eType, /*[out, retval]*/ VARIANT* pVal);
	
	//返回列集
	STDMETHOD(get_Columns)(/*[out, retval]*/ IColumns** ppCols);
	
	//返回行值
	STDMETHOD(get_Row)(/*[in, defaultvalue(rtDefault)]*/ RowTypeConstants eMode, /*[out, retval]*/ VARIANT* pVal);
	
	//返回行数
	STDMETHOD(get_RowCount)(/*[out, retval]*/ VARIANT* pVal);

	//返回行集
	STDMETHOD(get_Rows)(/*[in, defaultvalue(0)]*/ VARIANT_BOOL blnStatic, /*[in, defaultvalue(0)]*/ LONG lngMaxRecords, /*[out, retval]*/ IRows** ppRows);

	//绑定参数
	STDMETHOD(BindParameters)(/*[in]*/ LPSAFEARRAY* varParams);

	//绑定一个参数
	STDMETHOD(BindParameter)(/*[in]*/ VARIANT varIndex, /*[in, optional]*/ VARIANT varValue, /*[in, defaultvalue(dtUnknown)]*/ DataTypeConstants eType);
	
	//返回参数数量
	STDMETHOD(get_ParameterCount)(/*[out, retval]*/ LONG* pVal);

	//返回参数名称
	STDMETHOD(get_ParameterName)(/*[in]*/ LONG lngIndex, /*[out, retval]*/ BSTR* strName);

	//返回参数集合
	STDMETHOD(get_Parameters)(/*[out, retval]*/ IParameters** ppParams);
	
	//返回状态
	STDMETHOD(get_State)(/*[out, retval]*/ ObjectStateConstants* pVal);
 
protected:

	ObjectStateConstants m_eState;
	CComPtr<IConnectionObject> m_pConnection;
	sqlite3_stmt* m_stmt;
	CComBSTR m_strSql;
	LONGLONG m_nRowCount;
	bool m_bEOF;

	HRESULT bind_blob(CComPtr<IStream>&, LONG, int&);
	HRESULT bind_blob(SAFEARRAY*, LONG, int&);

	HRESULT create_row(LONG, CComVariant& v);
	DataTypeConstants get_column_type(int) const;
	HRESULT get_column_index(const VARIANT&, int&) const;
	HRESULT get_column_name(LONG, CComBSTR&) const;

	HRESULT get_parameter_index(const VARIANT&, int&) const;

private:
	ErrorMsg m_ErrMsg;

};

#endif //__RESULTSET_H_
