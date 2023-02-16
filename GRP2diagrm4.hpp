//------------------------------------------------------------------------| GRP2diagrm4.hpp                              //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//


#if !defined(AFX_GRP2DIAGRM4_H__08971797_C6FA_4D44_B123_091F65EC3977__INCLUDED_)
#define AFX_GRP2DIAGRM4_H__08971797_C6FA_4D44_B123_091F65EC3977__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 


class GRP2diagrm4 : public CDialog
{
	public:
	GRP2diagrm4(CWnd* pParent = NULL);  
	
	BOOL rxy_clr, syx_clr, s1yx_clr, srxy_clr, srx_clr;
	BOOL ryx_clr, sxy_clr, s1xy_clr, sryx_clr, sry_clr;

	BOOL mod_rxy;
	BOOL mod_ryx;
	BOOL mod_syx;
	BOOL mod_sxy;
	BOOL mod_s1yx;
	BOOL mod_s1xy;
	BOOL mod_srxy;
	BOOL mod_sryx;
	BOOL mod_srx;
	BOOL mod_sry;
	
	//{{AFX_DATA(GRP2diagrm4)
	enum { IDD = IDD_GRP2_Diagrm_4 };
	CTabCtrl	m_tab;
	BOOL	m_ch_ini;
	CString	m_rxy_art;
	CString	m_ryx_art;
	CString	m_s1xy_art;
	CString	m_s1yx_art;
	CString	m_srx_art;
	CString	m_srxy_art;
	CString	m_sry_art;
	CString	m_sryx_art;
	CString	m_sxy_art;
	CString	m_syx_art;
	int		m_rxy_gr;
	int		m_ryx_gr;
	int		m_s1xy_gr;
	int		m_s1yx_gr;
	int		m_srx_gr;
	int		m_srxy_gr;
	int		m_sry_gr;
	int		m_sryx_gr;
	int		m_sxy_gr;
	int		m_syx_gr;
	int		m_ch_rxy;
	int		m_ch_ryx;
	int		m_ch_sgxy;
	int		m_ch_sgyx;
	int		m_ch_srx;
	int		m_ch_srxy;
	int		m_ch_sry;
	int		m_ch_sryx;
	int		m_ch_sxy;
	int		m_ch_syx;
	//}}AFX_DATA


	//{{AFX_VIRTUAL(GRP2diagrm4)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

	protected:

	//{{AFX_MSG(GRP2diagrm4)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnCHECKini();
	afx_msg void OnPaint();
	afx_msg void OnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBUTTONrxyfb();
	afx_msg void OnBUTTONryxfb();
	afx_msg void OnBUTTONs1xyfb();
	afx_msg void OnBUTTONs1yxfb();
	afx_msg void OnBUTTONsrxfb();
	afx_msg void OnBUTTONsrxyfb();
	afx_msg void OnBUTTONsryfb();
	afx_msg void OnBUTTONsryxfb();
	afx_msg void OnBUTTONsxyfb();
	afx_msg void OnBUTTONsyxfb();
	afx_msg void OnSelchangeCOMBOrxyart();
	afx_msg void OnSelchangeCOMBOryxart();
	afx_msg void OnSelchangeCOMBOs1xyart();
	afx_msg void OnSelchangeCOMBOs1yxart();
	afx_msg void OnSelchangeCOMBOsrxart();
	afx_msg void OnSelchangeCOMBOsrxyart();
	afx_msg void OnSelchangeCOMBOsryart();
	afx_msg void OnSelchangeCOMBOsryxart();
	afx_msg void OnSelchangeCOMBOsxyart();
	afx_msg void OnSelchangeCOMBOsyxart();
	afx_msg void OnChangeEDITrxygr();
	afx_msg void OnChangeEDITryxgr();
	afx_msg void OnChangeEDITs1xygr();
	afx_msg void OnChangeEDITs1yxgr();
	afx_msg void OnChangeEDITsrxgr();
	afx_msg void OnChangeEDITsrxygr();
	afx_msg void OnChangeEDITsrygr();
	afx_msg void OnChangeEDITsryxgr();
	afx_msg void OnChangeEDITsxygr();
	afx_msg void OnChangeEDITsyxgr();
	afx_msg void OnDeltaposSPINrxygr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINryxgr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINs1xygr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINs1yxgr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINsrxgr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINsrxygr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINsrygr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINsryxgr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINsxygr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINsyxgr(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCHECKrxy();
	afx_msg void OnCHECKryx();
	afx_msg void OnCHECKsgxy();
	afx_msg void OnCHECKsgyx();
	afx_msg void OnCHECKsrx();
	afx_msg void OnCHECKsrxy();
	afx_msg void OnCHECKsry();
	afx_msg void OnCHECKsryx();
	afx_msg void OnCHECKsxy();
	afx_msg void OnCHECKsyx();
	afx_msg void OnVoreinstellungen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
