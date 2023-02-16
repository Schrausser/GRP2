//------------------------------------------------------------------------| GRP2param2Bx.hpp                             //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#if !defined(AFX_GRP2PARAM2BX_HPP__63A5EFBF_4C5B_4521_94F2_20748ED91E69__INCLUDED_)
#define AFX_GRP2PARAM2BX_HPP__63A5EFBF_4C5B_4521_94F2_20748ED91E69__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 
class GRP2param2Bx : public CDialog
{
	public:

	BOOL m_ch_ini;
	short sw;

	GRP2param2Bx(CWnd* pParent = NULL);  

	//{{AFX_DATA(GRP2param2Bx)
	enum { IDD = IDD_GRP2_Param_2_Bx };
	CString	m_Bx;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(GRP2param2Bx)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

	protected:

	//{{AFX_MSG(GRP2param2Bx)
	afx_msg void OnBUTTONtlgxreset();
	virtual void OnOK();
	afx_msg void OnChangeEDITBx();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
