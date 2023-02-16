//------------------------------------------------------------------------| GRP2fn1.hpp                                  //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//


#if !defined(AFX_GRP2FN1_H__60F8EED7_8A4D_420C_A0D8_5BB9302B0E40__INCLUDED_)
#define AFX_GRP2FN1_H__60F8EED7_8A4D_420C_A0D8_5BB9302B0E40__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class GRP2fn1 : public CDialog
{
	public:
	GRP2fn1(CWnd* pParent = NULL);  

	//{{AFX_DATA(GRP2fn1)
	enum { IDD = IDD_GRP2_Fn_1 };
	CEdit	m_mtlg_ctr;
	CEdit	m_int_ctr;
	CEdit	m_diff_ctr;
	CTabCtrl	m_tab;
	BOOL	m_ch_ini;
	int		m_diff_n;
	int		m_int_n;
	BOOL	m_ch_diff;
	BOOL	m_ch_int;
	BOOL	m_ch_mtlg;
	BOOL	m_ch_nwtn;
	BOOL	m_ch_qspl;
	int		m_mtlg_i;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(GRP2fn1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

	protected:

	//{{AFX_MSG(GRP2fn1)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnCHECKini();
	afx_msg void OnVoreinstellungen();
	afx_msg void OnCHECKdiff();
	afx_msg void OnCHECKint();
	afx_msg void OnCHECKmtlg();
	afx_msg void OnCHECKnwtn();
	afx_msg void OnCHECKqspl();
	afx_msg void OnChangeEDITdiffn();
	afx_msg void OnChangeEDITintn();
	afx_msg void OnDeltaposSPINdiffn(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINintn(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeEDITmtlgi();
	afx_msg void OnDeltaposSPINmtlgi(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnFxy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
