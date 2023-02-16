//------------------------------------------------------------------------| GRP2koord.hpp                               //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#if !defined(AFX_GRP2KOORD_H__9C5E1143_E438_4FEC_8197_17B9B6BA066D__INCLUDED_)
#define AFX_GRP2KOORD_H__9C5E1143_E438_4FEC_8197_17B9B6BA066D__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class GRP2Koord : public CDialog
{
	public:
	GRP2Koord(CWnd* pParent = NULL);
	
	void GRP2Koord::Koord_(float Ax,float Ay,float Vx,float Vy, float tx, float ty);
	void GRP2Koord::MinMax_(float xmin, float xmax, float ymin, float ymax);

	float Ax_,  Ay_,  Vx_, Vy_;        //koordinatenwertübernahmevariablen
	float Ax_0, Ay_0, Vx_0,Vy_0;       //
	float tx_, tx_0, ty_,ty_0;         //
	float xmin_, xmax_, ymin_, ymax_;  //kennwertübernahmevariablen

	//{{AFX_DATA(GRP2Koord)
	enum { IDD = IDD_GRP2_koord };
	CButton	m_Vx_min_ctr;
	CButton	m_Vx_max_ctr;
	CButton	m_Ax_min_ctr;
	CButton	m_Ax_max_ctr;
	CButton	m_Vy_min_ctr;
	CButton	m_Vy_max_ctr;
	CButton	m_AY_min_ctr;
	CButton	m_Ay_max_ctr;
	CButton	m_Vx_0_ctr;
	CButton	m_Ax_0_ctr;
	BOOL	m_ch_ini;
	float	m_Ax;
	float	m_Ay;
	float	m_Vx;
	float	m_Vy;
	float	m_Ax_d;
	float	m_Ay_d;
	float	m_Vx_d;
	float	m_Vy_d;
	//}}AFX_DATA


	//{{AFX_VIRTUAL(GRP2Koord)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

	protected:

	//{{AFX_MSG(GRP2Koord)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnCHECKini();
	afx_msg void OnVoreinstellungen();
	afx_msg void OnChangeEDITAx();
	afx_msg void OnChangeEDITAy();
	afx_msg void OnDeltaposSPINAx(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINAy(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeEDITVx();
	afx_msg void OnChangeEDITVy();
	afx_msg void OnDeltaposSPINVx(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINVy(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeEDITAxd();
	afx_msg void OnChangeEDITAyd();
	afx_msg void OnBUTTONAx0();
	afx_msg void OnBUTTONVx0();
	afx_msg void OnBUTTONAxmax();
	afx_msg void OnBUTTONAxmin();
	afx_msg void OnBUTTONAymin();
	afx_msg void OnBUTTONAymax();
	afx_msg void OnBUTTONVxmax();
	afx_msg void OnBUTTONVxmin();
	afx_msg void OnBUTTONVymax();
	afx_msg void OnBUTTONVymin();
	afx_msg void OnChangeEDITVxd();
	afx_msg void OnChangeEDITVyd();
	afx_msg void OnDeltaposSPINAxd(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINAyd(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINVxd(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSPINVyd(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
