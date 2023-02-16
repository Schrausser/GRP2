//------------------------------------------------------------------------| GRP2diagrm3.hpp                              //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#if !defined(AFX_GRP2DIAGRM3_H__09327B37_6B7A_471F_84FF_842B0B733848__INCLUDED_)
#define AFX_GRP2DIAGRM3_H__09327B37_6B7A_471F_84FF_842B0B733848__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class GRP2diagrm3 : public CDialog
{
	public:
	GRP2diagrm3(CWnd* pParent = NULL); 
	
	LOGFONT lfx; //Font struktur

	BOOL Xv_clr, Yv_clr, schr_x_clr, schr_x_H, schr_x_W, schr_x_sz;

	BOOL mod_Xv;
	BOOL mod_Yv;

	CString schr_x_fn;

	//{{AFX_DATA(GRP2diagrm3)
	enum { IDD = IDD_GRP2_Diagrm_3 };
	CTabCtrl	m_tab;
	BOOL	m_ch_ini;
	CString	m_X_art;
	CString	m_Y_art;
	int		m_X_gr;
	int		m_Y_gr;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(GRP2diagrm3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

	protected:
	//{{AFX_MSG(GRP2diagrm3)
	afx_msg void OnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnCHECKini();
	afx_msg void OnPaint();
	afx_msg void OnBUTTONXfb();
	afx_msg void OnBUTTONYfb();
	afx_msg void OnSelchangeCOMBOXart();
	afx_msg void OnSelchangeCOMBOYart();
	afx_msg void OnDeltaposSPINXgr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINYgr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeEDITXgr();
	afx_msg void OnChangeEDITYgr();
	afx_msg void OnBUTTONschrx();
	afx_msg void OnVoreinstellungen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
