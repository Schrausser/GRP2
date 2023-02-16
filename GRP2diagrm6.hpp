//------------------------------------------------------------------------| GRP2diagrm6.hpp                              //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//


#if !defined(AFX_GRP2DIAGRM6_HPP__3E26FE7E_AD7F_464B_8899_2CE1FCE7A3C4__INCLUDED_)
#define AFX_GRP2DIAGRM6_HPP__3E26FE7E_AD7F_464B_8899_2CE1FCE7A3C4__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class GRP2diagrm6 : public CDialog
{
	public:
	GRP2diagrm6(CWnd* pParent = NULL); 
	
	BOOL e_clr, x0_clr, s0_clr, x_clr;
	BOOL        x1_clr, s1_clr;

	BOOL mod_e;
	BOOL mod_x;
	BOOL mod_x0;
	BOOL mod_x1;
	BOOL mod_s0;
	BOOL mod_s1;

	//{{AFX_DATA(GRP2diagrm6)
	enum { IDD = IDD_GRP2_Diagrm_6 };
	CTabCtrl	m_tab;
	BOOL	m_ch_ini;
	CString	m_e_art;
	CString	m_s0_art;
	CString	m_x_art;
	CString	m_x0_art;
	CString	m_s1_art;
	CString	m_x1_art;
	int		m_e_gr;
	int		m_s0_gr;
	int		m_s1_gr;
	int		m_x_gr;
	int		m_x0_gr;
	int		m_x1_gr;
	int		m_ch_e;
	int		m_ch_s0;
	int		m_ch_s1;
	int		m_ch_x;
	int		m_ch_x0;
	int		m_ch_x1;
	//}}AFX_DATA


	//{{AFX_VIRTUAL(GRP2diagrm6)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

	protected:
	//{{AFX_MSG(GRP2diagrm6)
	afx_msg void OnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnCHECKini();
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnVoreinstellungen();
	afx_msg void OnBUTTONefb();
	afx_msg void OnBUTTONs0fb();
	afx_msg void OnBUTTONs1fb();
	afx_msg void OnBUTTONXfb();
	afx_msg void OnBUTTONx0fb();
	afx_msg void OnBUTTONx1fb();
	afx_msg void OnCHECKe();
	afx_msg void OnCHECKs0();
	afx_msg void OnCHECKs1();
	afx_msg void OnCHECKx();
	afx_msg void OnCHECKx0();
	afx_msg void OnCHECKx1();
	afx_msg void OnSelchangeCOMBOeart();
	afx_msg void OnSelchangeCOMBOs0art();
	afx_msg void OnSelchangeCOMBOs1art();
	afx_msg void OnSelchangeCOMBOXart();
	afx_msg void OnSelchangeCOMBOx0art();
	afx_msg void OnSelchangeCOMBOx1art();
	afx_msg void OnChangeEDITegr();
	afx_msg void OnChangeEDITs0gr();
	afx_msg void OnChangeEDITs1gr();
	afx_msg void OnChangeEDITXgr();
	afx_msg void OnChangeEDITx0gr();
	afx_msg void OnChangeEDITx1gr();
	afx_msg void OnDeltaposSPINegr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINs0gr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINs1gr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINXgr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINx0gr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINx1gr(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif
