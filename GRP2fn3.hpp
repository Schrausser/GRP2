//------------------------------------------------------------------------| GRP2fn3.hpp                                  //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#if !defined(AFX_GRP2FN3_H__6E80CBF5_42EC_48FD_A2F8_DEF71F129AFA__INCLUDED_)
#define AFX_GRP2FN3_H__6E80CBF5_42EC_48FD_A2F8_DEF71F129AFA__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class GRP2fn3 : public CDialog
{
	public:
	GRP2fn3(CWnd* pParent = NULL);

	CString GRP2fn3::ftoc( double x0, int dez );

	double GRP2fn3::zp_funktion(double wert);
	double GRP2fn3::pz_funktion(double wert);
	double GRP2fn3::tp_funktion(long double p_wert, double n_);
	double GRP2fn3::pt_funktion(long double t_wert, double n_);

	void GRP2fn3::QP_();
	void GRP2fn3::QP_z();
	void GRP2fn3::QP_t();

	void GRP2fn3::sw_edit();

	int GRP2fn3::ftoi(double x_);

	int df_;

	BOOL m_p;

	BOOL swz1,swz2;
	BOOL swt1,swt2,swt3;
	
	//{{AFX_DATA(GRP2fn3)
	enum { IDD = IDD_GRP2_Fn_3 };
	CEdit	m_CI_ctr;
	CEdit	m_CIz_ctr;
	CEdit	m_CIt_ctr;
	CTabCtrl	m_tab;
	BOOL	m_ch_ini;
	BOOL	m_ch_vx;
	BOOL	m_ch_vy;
	BOOL	m_ch_a3;
	BOOL	m_ch_a4;
	BOOL	m_ch_ag3;
	BOOL	m_ch_ag4;
	BOOL	m_ch_am;
	BOOL	m_ch_sd;
	BOOL	m_ch_sdg;
	BOOL	m_ch_sga3;
	BOOL	m_ch_sga4;
	BOOL	m_ch_sgam;
	float	m_CI;
	float	m_CI_t;
	float	m_CI_z;
	BOOL	m_ch_p;
	BOOL	m_ch_p1;
	BOOL	m_ch_p2;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(GRP2fn3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

	protected:
	//{{AFX_MSG(GRP2fn3)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnCHECKini();
	afx_msg void OnCHECKvx();
	afx_msg void OnCHECKvy();
	afx_msg void OnButtonP1();
	afx_msg void OnButtonSp1();
	afx_msg void OnCHECKa3();
	afx_msg void OnCHECKa4();
	afx_msg void OnCHECKag3();
	afx_msg void OnCHECKag4();
	afx_msg void OnCHECKam();
	afx_msg void OnCHECKsd();
	afx_msg void OnCHECKsdg();
	afx_msg void OnCHECKsga3();
	afx_msg void OnCHECKsga4();
	afx_msg void OnCHECKsgam();
	afx_msg void OnChangeEditCi();
	afx_msg void OnChangeEDITCIt1();
	afx_msg void OnChangeEDITCIz1();
	afx_msg void OnDeltaposSpinCi(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINCIt1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINCIz1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnVoreinstellungen();
	afx_msg void OnCHECKp();
	afx_msg void OnCHECKpa1();
	afx_msg void OnCHECKpa2();
	afx_msg void OnFxy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
