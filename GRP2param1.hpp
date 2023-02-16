//------------------------------------------------------------------------| GRP2param1.hpp                               //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#if !defined(AFX_GRP2PARAM1_H__1AA8F375_2EAE_4C13_A346_7E97A3329C49__INCLUDED_)
#define AFX_GRP2PARAM1_H__1AA8F375_2EAE_4C13_A346_7E97A3329C49__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class GRP2param1 : public CDialog
{
	public:
	GRP2param1(CWnd* pParent = NULL);
	
	int   GRP2param1::fwxXd;
	int   GRP2param1::fwyXd;
	int   GRP2param1::fwxYd;
	int   GRP2param1::fwyYd;

	//{{AFX_DATA(GRP2param1)
	enum { IDD = IDD_GRP2_Param_1 };
	CTabCtrl	m_tab;
	BOOL m_ch_Fk;
	BOOL m_ch_xy;
	int	 m_dez_W_x;
	int	 m_dez_W_y;
	BOOL	m_ch_x;
	BOOL	m_ch_y;
	BOOL	m_ch_xm;
	BOOL	m_ch_ym;
	BOOL	m_ch_y_;
	BOOL	m_ch_x_;
	BOOL	m_ch_ini;
	//}}AFX_DATA


	//{{AFX_VIRTUAL(GRP2param1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

	protected:
	//{{AFX_MSG(GRP2param1)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnCHECKFk();
	afx_msg void OnCHECKxy();
	afx_msg void OnChangeEDITdezWx();
	afx_msg void OnChangeEDITdezWy();
	afx_msg void OnDeltaposSPINdezWx(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINdezWy(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCHECKx();
	afx_msg void OnCHECKy();
	afx_msg void OnCHECKxm();
	afx_msg void OnCHECKym();
	afx_msg void OnCHECKx_();
	afx_msg void OnCHECKy_();
	afx_msg void OnCHECKini();
	afx_msg void OnVoreinstellungen();
	afx_msg void OnDeltaposSPINfwxX(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINfwxY(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINfwyX(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINfwyY(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
