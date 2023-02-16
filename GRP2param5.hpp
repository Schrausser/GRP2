//------------------------------------------------------------------------| GRP2param5.hpp                               //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#if !defined(AFX_GRP2param5_H__1AA8F375_2EAE_4C13_A346_7E97A3329C49__INCLUDED_)
#define AFX_GRP2param5_H__1AA8F375_2EAE_4C13_A346_7E97A3329C49__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class GRP2param5 : public CDialog
{
	public:
	GRP2param5(CWnd* pParent = NULL);   

	//{{AFX_DATA(GRP2param5)
	enum { IDD = IDD_GRP2_Param_5 };
	CTabCtrl	m_tab;
	CString	m_emfx;
	CString	m_emfy;
	BOOL	m_ch_ini;
	CString	m_file;
	//}}AFX_DATA


	//{{AFX_VIRTUAL(GRP2param5)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

	protected:

	//{{AFX_MSG(GRP2param5)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnCHECKini();
	afx_msg void OnVoreinstellungen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
