//------------------------------------------------------------------------| GRP2fn2.hpp                                  //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#if !defined(AFX_GRP2FN2_H__96AC1E58_99D2_4FC5_88D1_87A8270768D0__INCLUDED_)
#define AFX_GRP2FN2_H__96AC1E58_99D2_4FC5_88D1_87A8270768D0__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class GRP2fn2 : public CDialog
{
	public:
	GRP2fn2(CWnd* pParent = NULL); 
	
	CString GRP2fn2::ftoc( double x0, int dez );

	double GRP2fn2::zp_funktion(double wert);
	double GRP2fn2::pz_funktion(double wert);
	double GRP2fn2::tp_funktion(long double p_wert, double n_);
	double GRP2fn2::pt_funktion(long double t_wert, double n_);
	
	void GRP2fn2::QP_();
	void GRP2fn2::QP_z();
	void GRP2fn2::QP_t();

	void GRP2fn2::sw_edit();
	
	int GRP2fn2::ftoi(double x_);
	
	int df_;

	BOOL swz1,swz2,swz3,swz4;
	BOOL swt1,swt2,swt3,swt4;

	//{{AFX_DATA(GRP2fn2)
	enum { IDD = IDD_GRP2_Fn_2 };
	CEdit	m_CI_ctr;
	CEdit	m_CIt_ctr;
	CEdit	m_CIz_ctr;
	CTabCtrl	m_tab;
	BOOL	m_ch_ini;
	float	m_CI;
	BOOL	m_ch_D;
	BOOL	m_ch_rxy;
	BOOL	m_ch_ryx;
	BOOL	m_ch_sxy;
	BOOL	m_ch_syx;
	BOOL	m_ch_s1yx;
	BOOL	m_ch_s1xy;
	BOOL	m_ch_srx;
	BOOL	m_ch_srxy;
	BOOL	m_ch_sry;
	BOOL	m_ch_sryx;
	float	m_CI_t;
	float	m_CI_z;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(GRP2fn2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL


	protected:
	//{{AFX_MSG(GRP2fn2)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnCHECKini();
	afx_msg void OnChangeEditCi();
	afx_msg void OnDeltaposSpinCi(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnVoreinstellungen();
	afx_msg void OnCheckD();
	afx_msg void OnCHECKrxy();
	afx_msg void OnCHECKryx();
	afx_msg void OnCHECKsxy();
	afx_msg void OnCHECKsyx();
	afx_msg void OnCHECKs1xy();
	afx_msg void OnCHECKs1yx();
	afx_msg void OnCHECKsryx();
	afx_msg void OnCHECKsry();
	afx_msg void OnCHECKsrxy();
	afx_msg void OnCHECKsrx();
	afx_msg void OnButtonP();
	afx_msg void OnButtonSp();
	afx_msg void OnChangeEDITCIt();
	afx_msg void OnChangeEDITCIz();
	afx_msg void OnDeltaposSPINCIt(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINCIz(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnPaint();
	afx_msg void OnFxy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
