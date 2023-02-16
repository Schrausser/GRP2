//------------------------------------------------------------------------| GRP2ans.cpp                                  //
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
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
