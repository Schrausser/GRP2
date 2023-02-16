//------------------------------------------------------------------------| GRP2fn4.hpp                                  //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//


#if !defined(AFX_GRP2FN4_HPP__E3BC591B_B602_42D0_91F0_FD5EE4DB339B__INCLUDED_)
#define AFX_GRP2FN4_HPP__E3BC591B_B602_42D0_91F0_FD5EE4DB339B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class GRP2fn4 : public CDialog
{
	public:
	GRP2fn4(CWnd* pParent = NULL);  
	
	CString GRP2fn4::ftoc( double x0, int dez );

	double GRP2fn4::zp_funktion(double wert);
	double GRP2fn4::pz_funktion(double wert);
	double GRP2fn4::tp_funktion(long double p_wert, double n_);
	double GRP2fn4::pt_funktion(long double t_wert, double n_);

	void GRP2fn4::QP_();
	void GRP2fn4::QP_z();
	void GRP2fn4::QP_t();

	int GRP2fn4::ftoi(double x_);

	void GRP2fn4::SetCh01();


	//int df_;
	BOOL m_p;
	BOOL sw;

	//{{AFX_DATA(GRP2fn4)
	enum { IDD = IDD_GRP2_Fn_4 };
	CEdit	m_CI_ctr;
	CButton	m_cht_ctr;
	CButton	m_chz_ctr;
	CEdit	m_z_ctr;
	CEdit	m_t_ctr;
	CEdit	m_df_ctr;
	CTabCtrl	m_tab;
	BOOL	m_ch_ini;
	BOOL	m_ch_p;
	BOOL	m_ch_p1;
	BOOL	m_ch_p2;
	BOOL	m_ch_s0;
	BOOL	m_ch_s1;
	BOOL	m_ch_x0;
	BOOL	m_ch_x1;
	BOOL	m_ch_x;
	BOOL	m_ch_e;
	float	m_CI;
	float	m_CI_t;
	float	m_CI_z;
	BOOL	m_ch_t;
	BOOL	m_ch_z;
	int		m_df;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(GRP2fn4)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);   
	//}}AFX_VIRTUAL

	protected:
	//{{AFX_MSG(GRP2fn4)
	afx_msg void OnCHECKini();
	afx_msg void OnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnVoreinstellungen();
	virtual BOOL OnInitDialog();
	afx_msg void OnCHECKp();
	afx_msg void OnCHECKpa1();
	afx_msg void OnCHECKpa2();
	afx_msg void OnCHECKe();
	afx_msg void OnCHECKs0();
	afx_msg void OnCHECKs1();
	afx_msg void OnCHECKx0();
	afx_msg void OnCHECKx1();
	afx_msg void OnCHECKxcrit();
	afx_msg void OnChangeEDITCIz();
	afx_msg void OnChangeEDITCIt();
	afx_msg void OnChangeEditCi();
	afx_msg void OnDeltaposSpinCi(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINCIFet(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINCIFez(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCHECKt();
	afx_msg void OnCHECKz();
	afx_msg void OnChangeEDITdf();
	afx_msg void OnFxy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
