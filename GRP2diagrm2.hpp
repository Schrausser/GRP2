//------------------------------------------------------------------------| GRP2diagrm2.hpp                              //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#if !defined(AFX_GRP2DIAGRM2_H__EE4381C0_D8C1_43E6_B03A_C8D4D0FC1857__INCLUDED_)
#define AFX_GRP2DIAGRM2_H__EE4381C0_D8C1_43E6_B03A_C8D4D0FC1857__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class GRP2diagrm2 : public CDialog
{
	public:
	GRP2diagrm2(CWnd* pParent = NULL); 

    LOGFONT lfx, lfy; //Font strukturen

	BOOL X_clr, Y_clr, Xgrid_clr, Ygrid_clr,schr_x_clr;
	BOOL schr_y_clr, schr_x_H, schr_x_W, schr_y_H, schr_y_W,  schr_x_sz, schr_y_sz;

	BOOL mod_X;
	BOOL mod_Y;
	BOOL mod_Xgrd;
	BOOL mod_Ygrd;

	CString schr_x_fn, schr_y_fn;

	//{{AFX_DATA(GRP2diagrm2)
	enum { IDD = IDD_GRP2_Diagrm_2 };
	CTabCtrl	m_tab;
	BOOL	m_ch_ini;
	CString	m_X_art;
	CString	m_Y_art;
	int		m_X_gr;
	int		m_Y_gr;
	CString	m_Xgrid_art;
	CString	m_Ygrid_art;
	int		m_Xgrid_gr;
	int		m_Ygrid_gr;
	BOOL	m_ch_x;
	BOOL	m_ch_y;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(GRP2diagrm2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

	protected:
	//{{AFX_MSG(GRP2diagrm2)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnCHECKini();
	afx_msg void OnPaint();
	afx_msg void OnBUTTONXfb();
	afx_msg void OnBUTTONYfb();
	afx_msg void OnSelchangeCOMBOXart();
	afx_msg void OnSelchangeCOMBOYart();
	afx_msg void OnChangeEDITXgr();
	afx_msg void OnChangeEDITYgr();
	afx_msg void OnDeltaposSPINXgr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINYgr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBUTTONschrx();
	afx_msg void OnBUTTONschry();
	afx_msg void OnVoreinstellungen();
	afx_msg void OnSelchangeCOMBOXgridart();
	afx_msg void OnSelchangeCOMBOYgridart();
	afx_msg void OnBUTTONXgridfb();
	afx_msg void OnBUTTONYgridfb();
	afx_msg void OnChangeEDITYgridgr();
	afx_msg void OnChangeEDITXgridgr();
	afx_msg void OnDeltaposSPINXgridgr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINYgridgr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCHECKx();
	afx_msg void OnCHECKy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
