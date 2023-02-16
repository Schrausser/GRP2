//------------------------------------------------------------------------| GRP2info.hpp                               //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#if !defined(AFX_GRP2INFO_H__DB368CF9_3DF8_41E9_BE1B_C52E67D98C35__INCLUDED_)
#define AFX_GRP2INFO_H__DB368CF9_3DF8_41E9_BE1B_C52E67D98C35__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class GRP2info : public CDialog
{
	public:
	GRP2info(CWnd* pParent = NULL); 
	
	CString GRP2info::CompileStamp(BOOL Lngw);

	//{{AFX_DATA(GRP2info)
	enum { IDD = IDD_GRP2_Info };
	CString	m_compile;
	//}}AFX_DATA


	//{{AFX_VIRTUAL(GRP2info)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

	protected:

	//{{AFX_MSG(GRP2info)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


//{{AFX_INSERT_LOCATION}}

#endif 



