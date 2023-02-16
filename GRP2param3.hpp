//------------------------------------------------------------------------| GRP2param3.hpp                               //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#if !defined(AFX_GRP2param3_H__1AA8F375_2EAE_4C13_A346_7E97A3329C49__INCLUDED_)
#define AFX_GRP2param3_H__1AA8F375_2EAE_4C13_A346_7E97A3329C49__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class GRP2param3 : public CDialog
{
	public:
	GRP2param3(CWnd* pParent = NULL);
	
	CString GRP2param3::ftoc( double x0, int dez );

	float GRP2param3::kjx_d;
	float GRP2param3::kjy_d;
	int   GRP2param3::kwx_d;
	int   GRP2param3::kwy_d;

	//{{AFX_DATA(GRP2param3)
	enum { IDD = IDD_GRP2_Param_3 };
	CTabCtrl	m_tab;
	BOOL	m_ch_xV;
	BOOL	m_ch_yV;
	BOOL	m_ch_xK;
	BOOL	m_ch_yK;
	int		m_dez_K_x;
	int		m_dez_K_y;
	CString	m_kjy;
	CString	m_kjx;
	CString	m_kjx_d;
	CString	m_kjy_d;
	BOOL	m_ch_ini;
	//}}AFX_DATA


	//{{AFX_VIRTUAL(GRP2param3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

	protected:

	//{{AFX_MSG(GRP2param3)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnCHECKxV();
	afx_msg void OnCHECKyV();
	afx_msg void OnCHECKxK();
	afx_msg void OnCHECKyK();
	afx_msg void OnChangeEDITdezKx();
	afx_msg void OnChangeEDITdezKy();
	afx_msg void OnDeltaposSPINdezKx(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINdezKy(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeEDITkjx();
	afx_msg void OnChangeEDITkjy();
	afx_msg void OnBUTTONkjxreset();
	afx_msg void OnChangeEDITkjxd();
	afx_msg void OnBUTTONkjyreset();
	afx_msg void OnChangeEDITkjyd();
	afx_msg void OnBUTTONkjxdreset();
	afx_msg void OnBUTTONkjydreset();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnDeltaposSPINkjx(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINkjy(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINkjxd(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINkjyd(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCHECKini();
	afx_msg void OnVoreinstellungen();
	afx_msg void OnDeltaposSPINkwx(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINkwy(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
