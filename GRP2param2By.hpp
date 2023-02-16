//------------------------------------------------------------------------| GRP2param2By.hpp                             //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//


#if !defined(AFX_GRP2PARAM2BY_HPP__31AEA1D9_5CCF_4FDF_B382_6B5C3D55886B__INCLUDED_)
#define AFX_GRP2PARAM2BY_HPP__31AEA1D9_5CCF_4FDF_B382_6B5C3D55886B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class GRP2param2By : public CDialog
{
	public:

	BOOL m_ch_ini;
	short sw;

	GRP2param2By(CWnd* pParent = NULL);   

	//{{AFX_DATA(GRP2param2By)
	enum { IDD = IDD_GRP2_Param_2_By };
	CString	m_By;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(GRP2param2By)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

	protected:
	//{{AFX_MSG(GRP2param2By)
	afx_msg void OnBUTTONtlgxreset();
	afx_msg void OnChangeEDITBx();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif
