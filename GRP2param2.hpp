//------------------------------------------------------------------------| GRP2param2.hpp                               //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#if !defined(AFX_GRP2param2_H__1AA8F375_2EAE_4C13_A346_7E97A3329C49__INCLUDED_)
#define AFX_GRP2param2_H__1AA8F375_2EAE_4C13_A346_7E97A3329C49__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class GRP2param2 : public CDialog
{
	public:
	GRP2param2(CWnd* pParent = NULL); 

	CString GRP2param2::ftoc( double x0, int dez ); 

	float GRP2param2::tlgx_d;
	float GRP2param2::tlgy_d;
	int   GRP2param2::swxXd;
	int   GRP2param2::swyXd;
	int   GRP2param2::swxYd;
	int   GRP2param2::swyYd;
	int               scxd;
	int               scyd;
	int               Axxd;
	int               Axyd;
	int               Ayxd;
    int               Ayyd;

	//{{AFX_DATA(GRP2param2)
	enum { IDD = IDD_GRP2_Param_2 };
	CTabCtrl	m_tab;	
	BOOL	m_ch_xA;
	BOOL	m_ch_yA;
	BOOL	m_ch_xS;
	BOOL	m_ch_yS;
	BOOL	m_ch_xSw;
	BOOL	m_ch_ySw;
	int		m_dez_S_x;
	int		m_dez_S_y;
	CString	m_tlgx;
	CString	m_tlgx_d;
	CString	m_tlgy;
	CString	m_tlgy_d;
	BOOL	m_ch_ini;
	BOOL	m_ch_xGrd;
	BOOL	m_ch_yGrd;
	//}}AFX_DATA


	//{{AFX_VIRTUAL(GRP2param2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

	protected:

	//{{AFX_MSG(GRP2param2)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnCHECKxA();
	afx_msg void OnCHECKyA();
	afx_msg void OnCHECKxS();
	afx_msg void OnCHECKyS();
	afx_msg void OnCHECKxSw();
	afx_msg void OnCHECKySw();
	afx_msg void OnChangeEDITdezSx();
	afx_msg void OnChangeEDITdezSy();
	afx_msg void OnDeltaposSPINdezSx(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINdezSy(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeEDITtlgx();
	afx_msg void OnChangeEDITtlgxd();
	afx_msg void OnChangeEDITtlgy();
	afx_msg void OnChangeEDITtlgyd();
	afx_msg void OnBUTTONtlgxdreset();
	afx_msg void OnBUTTONtlgxreset();
	afx_msg void OnBUTTONtlgydreset();
	afx_msg void OnBUTTONtlgyreset();
	afx_msg void OnDeltaposSPINtlgx(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINtlgy(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINtlgxd(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINtlgyd(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCHECKini();
	afx_msg void OnVoreinstellungen();
	afx_msg void OnCHECKyGrd();
	afx_msg void OnCHECKxGrd();
	afx_msg void OnDeltaposSPINswx(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINswy(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINswx2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINswy2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINswscx(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINswscy(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINswAxx(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINswAxy(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINswAyy(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINswAyx(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBUTTONBx();
	afx_msg void OnBUTTONBy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
