//------------------------------------------------------------------------| GRP2param4.hpp                               //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#if !defined(AFX_GRP2param4_H__1AA8F375_2EAE_4C13_A346_7E97A3329C49__INCLUDED_)
#define AFX_GRP2param4_H__1AA8F375_2EAE_4C13_A346_7E97A3329C49__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class GRP2param4 : public CDialog
{
	public:
	GRP2param4(CWnd* pParent = NULL);  
	
	CString GRP2param4::ftoc( double x0, int dez );
	CString GRP2param4::itoc(int x_);
	double GRP2param4::itof(int x_);
	int GRP2param4::ftoi(double x_); 
	
	float GRP2param4::sc_d;
	float GRP2param4::scy_d;
	
	//{{AFX_DATA(GRP2param4)
	enum { IDD = IDD_GRP2_Param_4 };
	CTabCtrl	m_tab;
	CString	m_sc;
	CString	m_scy;
	CString	m_sc_d;
	CString	m_scy_d;
	BOOL	m_ch_ini;
	int		m_shift_y;
	int		m_shift_x;
	float	m_shift_x2;
	float	m_shift_y2;
	//}}AFX_DATA


	//{{AFX_VIRTUAL(GRP2param4)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);   
	//}}AFX_VIRTUAL

	protected:

	//{{AFX_MSG(GRP2param4)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnChangeEDITsc();
	afx_msg void OnChangeEDITscy();
	afx_msg void OnBUTTONscdreset();
	afx_msg void OnBUTTONscreset();
	afx_msg void OnBUTTONscydreset();
	afx_msg void OnBUTTONscyreset();
	afx_msg void OnChangeEDITscd();
	afx_msg void OnChangeEDITscyd();
	afx_msg void OnDeltaposSPINsc(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINscy(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINscd(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINscyd(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnVoreinstellungen();
	afx_msg void OnCHECKini();
	afx_msg void OnChangeEDITshiftx();
	afx_msg void OnChangeEDITshifty();
	afx_msg void OnDeltaposSPINshiftx(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINshifty(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBUTTONshiftxreset();
	afx_msg void OnBUTTONshiftyreset();
	afx_msg void OnBUTTONshiftxreset2();
	afx_msg void OnBUTTONshiftyreset2();
	afx_msg void OnChangeEDITshiftx2();
	afx_msg void OnChangeEDITshifty2();
	afx_msg void OnDeltaposSPINshiftx2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINshifty2(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
