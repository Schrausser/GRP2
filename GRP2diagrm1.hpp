//------------------------------------------------------------------------| GRP2diagrm1.hpp                              //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#if !defined(AFX_GRP2DIAGRM1_H__CBADF1B5_668D_4137_AD3E_C44C831597D4__INCLUDED_)
#define AFX_GRP2DIAGRM1_H__CBADF1B5_668D_4137_AD3E_C44C831597D4__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class GRP2diagrm1 : public CDialog
{
	public:
	GRP2diagrm1(CWnd* pParent = NULL); 
	
	LOGFONT lfx, lfy; //Font strukturen

	BOOL K_clr, P_clr, hg_clr; 
	BOOL schr_x_clr, schr_y_clr, schr_x_H,  schr_x_W; 
	BOOL schr_y_H,   schr_y_W,   schr_x_sz, schr_y_sz;

	BOOL mod_K;
	BOOL mod_P;

	CString schr_x_fn, schr_y_fn;

	//{{AFX_DATA(GRP2diagrm1)
	enum { IDD = IDD_GRP2_Diagrm_1 };
	CTabCtrl	m_tab;
	CString	m_K_art;
	CString	m_P_art;
	int		m_K_gr;
	int		m_P_gr;
	BOOL	m_ch_ini;
	//}}AFX_DATA


	//{{AFX_VIRTUAL(GRP2diagrm1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

	protected:

	//{{AFX_MSG(GRP2diagrm1)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnDeltaposSPINKgr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINPgr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeEDITKgr();
	afx_msg void OnChangeEDITPgr();
	afx_msg void OnBUTTONKfb();
	afx_msg void OnBUTTONPfb();
	afx_msg void OnBUTTONhgfb();
	afx_msg void OnBUTTONschrx();
	afx_msg void OnBUTTONschry();
	afx_msg void OnPaint();
	afx_msg void OnBUTTONhg();
	afx_msg void OnCHECKini();
	afx_msg void OnSelchangeCOMBOKart();
	afx_msg void OnSelchangeCOMBOPart();
	afx_msg void OnVoreinstellungen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
