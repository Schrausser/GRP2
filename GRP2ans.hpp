//------------------------------------------------------------------------| GRP2ans.hpp                                  //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#if !defined(AFX_GRP2ANS_H__5C0AF540_86D2_41EC_A3AC_A85C4527D8F5__INCLUDED_)
#define AFX_GRP2ANS_H__5C0AF540_86D2_41EC_A3AC_A85C4527D8F5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class GRP2ans : public CDialog
{
	public:
	GRP2ans(CWnd* pParent = NULL);
	
	
	CString GRP2ans::ftoc( double x0, int dez ); 


	
	float GRP2ans::kjx_d;
	float GRP2ans::kjy_d;
	float GRP2ans::tlgx_d;
	float GRP2ans::tlgy_d;
	float GRP2ans::sc_d;
	float GRP2ans::scy_d;

	int GRP2ans::spin_;


	//{{AFX_DATA(GRP2ans)
	enum { IDD = IDD_Ansicht };
	BOOL	m_ch_x;
	BOOL	m_ch_y;
	BOOL	m_ch_xm;
	BOOL	m_ch_ym;
	BOOL	m_ch_xA;
	BOOL	m_ch_xS;
	BOOL	m_ch_xV;
	BOOL	m_ch_yA;
	BOOL	m_ch_yS;
	BOOL	m_ch_yV;
	BOOL	m_ch_Fk;
	BOOL	m_ch_xK;
	BOOL	m_ch_xy;
	BOOL	m_ch_yK;
	CString	m_kjy;
	CString	m_kjx;
	CString	m_emfx;
	CString	m_emfy;
	BOOL	m_ch_y_;
	CString	m_sc;
	CString	m_scy;
	BOOL	m_ch_x_;
	BOOL	m_ch_xSw;
	BOOL	m_ch_ySw;
	CString	m_kjx_d;
	CString	m_kjy_d;
	CString	m_sc_d;
	CString	m_scy_d;
	CString	m_tlgx;
	CString	m_tlgx_d;
	CString	m_tlgy;
	CString	m_tlgy_d;
	int		m_dez_K_x;
	int		m_dez_K_y;
	int		m_dez_S_x;
	int		m_dez_S_y;
	int		m_dez_W_x;
	int		m_dez_W_y;
	BOOL	m_ch_inv;
	//}}AFX_DATA


	//{{AFX_VIRTUAL(GRP2ans)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);   
	//}}AFX_VIRTUAL

	protected:

	//{{AFX_MSG(GRP2ans)
	afx_msg void OnCHECKx();
	afx_msg void OnCHECKy();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnCHECKxm();
	afx_msg void OnCHECKym();
	afx_msg void OnCHECKxA();
	afx_msg void OnCHECKxS();
	afx_msg void OnCHECKyA();
	afx_msg void OnCHECKyS();
	afx_msg void OnCHECKxV();
	afx_msg void OnCHECKyV();
	afx_msg void OnCHECKFk();
	afx_msg void OnCHECKxK();
	afx_msg void OnCHECKyK();
	afx_msg void OnCHECKxy();
	afx_msg void OnSelchangeCOMBOemfy();
	afx_msg void OnSelchangeCOMBOemfx();
	afx_msg void OnChangeEDITkjx();
	afx_msg void OnChangeEDITkjy();
	afx_msg void OnChangeEDITsc();
	afx_msg void OnChangeEDITscy();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnCHECKx_();
	afx_msg void OnCHECKy_();
	afx_msg void OnCHECKxSw();
	afx_msg void OnCHECKySw();
	afx_msg void OnBUTTONkjxdwn();
	afx_msg void OnBUTTONkjxreset();
	afx_msg void OnBUTTONkjxup();
	afx_msg void OnChangeEDITkjxd();
	afx_msg void OnBUTTONkjydwn();
	afx_msg void OnBUTTONkjyreset();
	afx_msg void OnBUTTONkjyup();
	afx_msg void OnChangeEDITkjyd();
	afx_msg void OnBUTTONkjxdreset();
	afx_msg void OnBUTTONkjydreset();
	afx_msg void OnBUTTONscdreset();
	afx_msg void OnBUTTONscdwn();
	afx_msg void OnBUTTONscreset();
	afx_msg void OnBUTTONscup();
	afx_msg void OnBUTTONscydreset();
	afx_msg void OnBUTTONscydwn();
	afx_msg void OnBUTTONscyreset();
	afx_msg void OnBUTTONscyup();
	afx_msg void OnChangeEDITscd();
	afx_msg void OnChangeEDITscyd();
	afx_msg void OnChangeEDITtlgx();
	afx_msg void OnChangeEDITtlgxd();
	afx_msg void OnChangeEDITtlgy();
	afx_msg void OnChangeEDITtlgyd();
	afx_msg void OnBUTTONtlgxdreset();
	afx_msg void OnBUTTONtlgxdwn();
	afx_msg void OnBUTTONtlgxreset();
	afx_msg void OnBUTTONtlgxup();
	afx_msg void OnBUTTONtlgydreset();
	afx_msg void OnBUTTONtlgydwn();
	afx_msg void OnBUTTONtlgyreset();
	afx_msg void OnBUTTONtlgyup();
	afx_msg void OnChangeEDITdezKx();
	afx_msg void OnChangeEDITdezKy();
	afx_msg void OnChangeEDITdezSx();
	afx_msg void OnChangeEDITdezSy();
	afx_msg void OnChangeEDITdezWx();
	afx_msg void OnChangeEDITdezWy();
	afx_msg void OnDeltaposSPINdezKx(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINdezKy(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINdezSx(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINdezSy(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINdezWx(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINdezWy(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
