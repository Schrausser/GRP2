//------------------------------------------------------------------------| GRP2diagrm5.hpp                              //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              


#if !defined(AFX_GRP2DIAGRM5_H__D50E6561_FF51_4BA9_9B03_54F51F46F154__INCLUDED_)
#define AFX_GRP2DIAGRM5_H__D50E6561_FF51_4BA9_9B03_54F51F46F154__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class GRP2diagrm5 : public CDialog
{
	public:
	GRP2diagrm5(CWnd* pParent = NULL); 
	
	BOOL Xp_clr, sd_clr, sdg_clr, sgx_clr;
	BOOL a3_clr, ag3_clr, sa3g_clr;
	BOOL a4_clr, ag4_clr, sa4g_clr;

	BOOL mod_X;
	BOOL mod_sd;
	BOOL mod_sdg;
	BOOL mod_sgx;
	BOOL mod_a3;
	BOOL mod_ag3;
	BOOL mod_sa3g;
	BOOL mod_a4;
	BOOL mod_ag4;
	BOOL mod_sa4g;

	//{{AFX_DATA(GRP2diagrm5)
	enum { IDD = IDD_GRP2_Diagrm_5 };
	CTabCtrl	m_tab;
	BOOL	m_ch_ini;
	CString	m_a3_art;
	CString	m_a4_art;
	CString	m_ag3_art;
	CString	m_ag4_art;
	CString	m_sa3g_art;
	CString	m_sa4g_art;
	CString	m_sd_art;
	CString	m_sdg_art;
	CString	m_sgx_art;
	CString	m_X_art;
	int		m_a3_gr;
	int		m_a4_gr;
	int		m_ag3_gr;
	int		m_ag4_gr;
	int		m_sa3g_gr;
	int		m_sa4g_gr;
	int		m_sd_gr;
	int		m_sdg_gr;
	int		m_sgx_gr;
	int		m_X_gr;
	int		m_ch_a3;
	int		m_ch_a4;
	int		m_ch_ag3;
	int		m_ch_ag4;
	int		m_ch_s;
	int		m_ch_sa3g;
	int		m_ch_sa4g;
	int		m_ch_sg;
	int		m_ch_sgx;
	int		m_ch_x;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(GRP2diagrm5)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	protected:

	//{{AFX_MSG(GRP2diagrm5)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnCHECKini();
	afx_msg void OnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnPaint();
	afx_msg void OnBUTTONa3fb();
	afx_msg void OnBUTTONa4fb();
	afx_msg void OnBUTTONag3fb();
	afx_msg void OnBUTTONag4fb();
	afx_msg void OnBUTTONsa3gfb();
	afx_msg void OnBUTTONsa4gfb();
	afx_msg void OnBUTTONsdfb();
	afx_msg void OnBUTTONsdgfb();
	afx_msg void OnBUTTONsgxfb();
	afx_msg void OnBUTTONXfb();
	afx_msg void OnSelchangeCOMBOa3art();
	afx_msg void OnSelchangeCOMBOa4art();
	afx_msg void OnSelchangeCOMBOag3art();
	afx_msg void OnSelchangeCOMBOag4art();
	afx_msg void OnSelchangeCOMBOsa3gart();
	afx_msg void OnSelchangeCOMBOsa4gart();
	afx_msg void OnSelchangeCOMBOsdart();
	afx_msg void OnSelchangeCOMBOsdgart();
	afx_msg void OnSelchangeCOMBOsgxart();
	afx_msg void OnSelchangeCOMBOXart();
	afx_msg void OnChangeEDITa3gr();
	afx_msg void OnChangeEDITa4gr();
	afx_msg void OnChangeEDITag3gr();
	afx_msg void OnChangeEDITag4gr();
	afx_msg void OnChangeEDITsa3ggr();
	afx_msg void OnChangeEDITsa4ggr();
	afx_msg void OnChangeEDITsdgr();
	afx_msg void OnChangeEDITsdggr();
	afx_msg void OnChangeEDITsgxgr();
	afx_msg void OnChangeEDITXgr();
	afx_msg void OnDeltaposSPINa3gr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINa4gr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINag3gr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINag4gr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINsa3ggr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINsa4ggr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINsdgr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINsdggr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINsgxgr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINXgr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCHECKa31();
	afx_msg void OnCHECKa41();
	afx_msg void OnCHECKag3();
	afx_msg void OnCHECKag41();
	afx_msg void OnCHECKs();
	afx_msg void OnCHECKsa3g();
	afx_msg void OnCHECKsa4g();
	afx_msg void OnCHECKsg();
	afx_msg void OnCHECKsgx();
	afx_msg void OnCHECKx();
	afx_msg void OnVoreinstellungen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
