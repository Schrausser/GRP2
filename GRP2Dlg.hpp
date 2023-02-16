//------------------------------------------------------------------------| GRP2Dlg.hpp                                  //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//


#if !defined(AFX_GRP2DLG_H__7C293CF5_09EC_4BCD_95EE_78D6E62BB11D__INCLUDED_)
#define AFX_GRP2DLG_H__7C293CF5_09EC_4BCD_95EE_78D6E62BB11D__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class CAboutDlg : public CDialog
{
	public:
	CAboutDlg();

	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

	protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


class CGRP2Dlg : public CDialog
{
	public:
	CGRP2Dlg(CWnd* pParent = NULL);	

	POINT dlg;

	CString filename, filename0, filename_0, filename_, filename_z, filename_p, filename_i, filename_d, filename_tmp;
	CString emf_filename, emf_filename0,log_filename;
	CString emfname;
	
	float x_, y_;
	float min_x,max_x, min_y, max_y;

	int swli; //erster funktionswert schalter

	short sw_As, sw_Vs; //achsen vektorenshiftlock schalter
	
	void CGRP2Dlg::cmdline(CString f);

	void CGRP2Dlg::Fenstertext(CString fText);
	void CGRP2Dlg::MINMAX();
	void CGRP2Dlg::fn_THETA_1();
	void CGRP2Dlg::fn_THETA_2(); 
	void CGRP2Dlg::fn_THETA_3(short sw);
	void CGRP2Dlg::fn_THETA_4(); 
	void CGRP2Dlg::fn_THETA_5(); 

	
	typedef struct tagTHETA{double sum; double sd;    double am;
	                                    double sdg;   double sgam;
										double a3;    double a4;
										double ag3;   double ag4;
										double sga3;  double sga4;
	                                    double e;     double sw;  }THETA;
																   THETA qX;	      						     					 
	                                                               THETA qY;
																   THETA qE;
					                                          
	double qR, qS, qsS, qsR;

	void CGRP2Dlg::GRP_Diagramm();

	void CGRP2Dlg::x_scala(int x);
	void CGRP2Dlg::y_scala(int y);
	void CGRP2Dlg::x_Sw(int x);
	void CGRP2Dlg::y_Sw(int y);
	void CGRP2Dlg::x_minmax(int x);
	void CGRP2Dlg::y_minmax(int y);
	void CGRP2Dlg::x_Achse(int x);
	void CGRP2Dlg::y_Achse(int y);
	void CGRP2Dlg::x_Vektor(int x);
	void CGRP2Dlg::y_Vektor(int y);
	void CGRP2Dlg::x_Skala(int x);
	void CGRP2Dlg::y_Skala(int y);
	void CGRP2Dlg::x_Koor(int x);
	void CGRP2Dlg::y_Koor(int y);
	void CGRP2Dlg::_FnKu(int x);
	void CGRP2Dlg::_xyPkt(int y);
	void CGRP2Dlg::x_kj(CString x);
	void CGRP2Dlg::y_kj(CString y);
	void CGRP2Dlg::x_tlg(CString x);
	void CGRP2Dlg::y_tlg(CString y);
	void CGRP2Dlg::sc_(CString x);
	void CGRP2Dlg::sc_y(CString x);
	void CGRP2Dlg::x_emf(CString x);
	void CGRP2Dlg::y_emf(CString y);
	void CGRP2Dlg::xK_ds(int x); 
	void CGRP2Dlg::yK_ds(int y); 
	void CGRP2Dlg::xS_ds(int x); 
	void CGRP2Dlg::yS_ds(int y); 
	void CGRP2Dlg::xW_ds(int x);
	void CGRP2Dlg::yW_ds(int y);
	void CGRP2Dlg::clr_hg(int fb);
	void CGRP2Dlg::clr_K(int fb);
	void CGRP2Dlg::clr_P(int fb);
	void CGRP2Dlg::K_gr(int gr);
	void CGRP2Dlg::P_gr(int gr);
	void CGRP2Dlg::fn_font_x(CString font,int h, int w, int fb);
	void CGRP2Dlg::fn_font_y(CString font,int h, int w, int fb);
	void CGRP2Dlg::K_art(CString art);
	void CGRP2Dlg::P_art(CString art);
	void CGRP2Dlg::X_gr(int gr);
	void CGRP2Dlg::Y_gr(int gr); 
	void CGRP2Dlg::X_art(CString art);
	void CGRP2Dlg::Y_art(CString art);
	void CGRP2Dlg::Xv_gr(int gr);
	void CGRP2Dlg::Yv_gr(int gr); 
	void CGRP2Dlg::Xgrd_gr(int gr);
	void CGRP2Dlg::Ygrd_gr(int gr);
	void CGRP2Dlg::Xv_art(CString art);
	void CGRP2Dlg::Yv_art(CString art);
	void CGRP2Dlg::clr_X(int fb);
	void CGRP2Dlg::clr_Y(int fb);
	void CGRP2Dlg::clr_Xgrd(int fb);
	void CGRP2Dlg::clr_Ygrd(int fb);
	void CGRP2Dlg::clr_Xv(int fb);
	void CGRP2Dlg::clr_Yv(int fb);
	void CGRP2Dlg::font_Ax(CString font,int h, int w, int fb);
	void CGRP2Dlg::font_Ay(CString font,int h, int w, int fb);
	void CGRP2Dlg::font_V(CString font,int h, int w, int fb);
	void CGRP2Dlg::D_rxy(int sw);
	void CGRP2Dlg::r_rxy(int sw);
	void CGRP2Dlg::r_ryx(int sw);
	void CGRP2Dlg::r_sxy(int sw);
	void CGRP2Dlg::r_syx(int sw);
	void CGRP2Dlg::r_s1xy(int sw);
	void CGRP2Dlg::r_s1yx(int sw);
	void CGRP2Dlg::r_srxy(int sw);
	void CGRP2Dlg::r_sryx(int sw);	
	void CGRP2Dlg::r_srx(int sw);
	void CGRP2Dlg::r_sry(int sw);
	void CGRP2Dlg::p_q_sw(short sw);
	void CGRP2Dlg::x_Grid(short sw);
	void CGRP2Dlg::y_Grid(short sw);
	void CGRP2Dlg::X_gridart(CString art);
	void CGRP2Dlg::Y_gridart(CString art);
	void CGRP2Dlg::p_a3(short sw);   
	void CGRP2Dlg::p_a4(short sw );    
	void CGRP2Dlg::p_ag3(short sw );    
	void CGRP2Dlg::p_ag4(short sw );    
	void CGRP2Dlg::p_am(short sw );    
	void CGRP2Dlg::p_sd(short sw );    
	void CGRP2Dlg::p_sdg(short sw );    
	void CGRP2Dlg::p_sga3(short sw );   
	void CGRP2Dlg::p_sga4(short sw );    
	void CGRP2Dlg::p_sgam(short sw );
	void CGRP2Dlg::CI_Fp(double p);
	void CGRP2Dlg::CI_rxy(double p);
	void CGRP2Dlg::CI_Fe(BOOL sw, double p, int df);
	void CGRP2Dlg::rnd_dyn(short sw);
	void CGRP2Dlg::rnd_fsr(short sw);
	void CGRP2Dlg::w_pos_(short sw);
	void CGRP2Dlg::csr_sw(short sw); 
	void CGRP2Dlg::m_AX_(float x);
	void CGRP2Dlg::m_AY_(float y);
	void CGRP2Dlg::m_VX_(float x);
	void CGRP2Dlg::m_VY_(float y);
	void CGRP2Dlg::posVx_(float x);
	void CGRP2Dlg::posVy_(float y);
	void CGRP2Dlg::posAXx_(float x);
	void CGRP2Dlg::posAXy_(float y);
	void CGRP2Dlg::posAYx_(float x);
	void CGRP2Dlg::posAYy_(float y);
	void CGRP2Dlg::posFXx_(float x);
	void CGRP2Dlg::posFXy_(float y);
	void CGRP2Dlg::posFYx_(float x);
	void CGRP2Dlg::posFYy_(float y);
	void CGRP2Dlg::pos_Dx_(short sw);        
	void CGRP2Dlg::pos_Dy_(short sw);
	void CGRP2Dlg::frm_Dx_(float sw);       
	void CGRP2Dlg::frm_Dy_(float sw);
	void CGRP2Dlg::clr_rxy(int fb);
	void CGRP2Dlg::clr_ryx(int fb);
	void CGRP2Dlg::clr_s1xy(int fb);
	void CGRP2Dlg::clr_s1yx(int fb);
	void CGRP2Dlg::clr_srx(int fb);
	void CGRP2Dlg::clr_srxy(int fb);
	void CGRP2Dlg::clr_sry(int fb);
	void CGRP2Dlg::clr_sryx(int fb);
	void CGRP2Dlg::clr_sxy(int fb);
	void CGRP2Dlg::clr_syx(int fb);
	void CGRP2Dlg::clr_a3(int fb);  
	void CGRP2Dlg::clr_a4(int fb);  
	void CGRP2Dlg::clr_ag3(int fb);  
	void CGRP2Dlg::clr_ag4(int fb);  
	void CGRP2Dlg::clr_sa3g(int fb);  
	void CGRP2Dlg::clr_sa4g(int fb);  
	void CGRP2Dlg::clr_sd(int fb);  
	void CGRP2Dlg::clr_sdg(int fb);  
	void CGRP2Dlg::clr_sgx(int fb);  
	void CGRP2Dlg::clr_Xp(int fb);  
	void CGRP2Dlg::rxy_gr(int gr);
	void CGRP2Dlg::ryx_gr(int gr);
	void CGRP2Dlg::s1xy_gr(int gr);
	void CGRP2Dlg::s1yx_gr(int gr);
	void CGRP2Dlg::srx_gr(int gr);
	void CGRP2Dlg::srxy_gr(int gr);
	void CGRP2Dlg::sry_gr(int gr); 
	void CGRP2Dlg::sryx_gr(int gr); 
	void CGRP2Dlg::sxy_gr(int gr);
	void CGRP2Dlg::syx_gr(int gr);
	void CGRP2Dlg::a3_gr(int gr);
	void CGRP2Dlg::a4_gr(int gr);
	void CGRP2Dlg::ag3_gr(int gr); 
	void CGRP2Dlg::ag4_gr(int gr);
	void CGRP2Dlg::sa3g_gr(int gr); 
	void CGRP2Dlg::sa4g_gr(int gr); 
	void CGRP2Dlg::sd_gr(int gr);
	void CGRP2Dlg::sdg_gr(int gr);
	void CGRP2Dlg::sgx_gr(int gr); 
	void CGRP2Dlg::Xp_gr(int gr);
	void CGRP2Dlg::rxy_art(CString art); 
	void CGRP2Dlg::ryx_art(CString art); 
	void CGRP2Dlg::s1xy_art(CString art); 
	void CGRP2Dlg::s1yx_art(CString art);
	void CGRP2Dlg::srx_art(CString art);
	void CGRP2Dlg::srxy_art(CString art);
	void CGRP2Dlg::sry_art(CString art);
	void CGRP2Dlg::sryx_art(CString art); 
	void CGRP2Dlg::sxy_art(CString art);
	void CGRP2Dlg::syx_art(CString art);
	void CGRP2Dlg::a3_art(CString art);
	void CGRP2Dlg::a4_art(CString art);
	void CGRP2Dlg::ag3_art(CString art); 
	void CGRP2Dlg::ag4_art(CString art);
	void CGRP2Dlg::sa3g_art(CString art); 
	void CGRP2Dlg::sa4g_art(CString art); 
	void CGRP2Dlg::sd_art(CString art);
	void CGRP2Dlg::sdg_art(CString art);
	void CGRP2Dlg::sgx_art(CString art); 
	void CGRP2Dlg::Xp_art(CString art); 
	void CGRP2Dlg::q_rxy(short sw);
	void CGRP2Dlg::q_ryx(short sw);
	void CGRP2Dlg::q_sgxy(short sw);
	void CGRP2Dlg::q_sgyx(short sw);
	void CGRP2Dlg::q_srx(short sw);
	void CGRP2Dlg::q_srxy(short sw);
	void CGRP2Dlg::q_sry(short sw);
	void CGRP2Dlg::q_sryx(short sw);
	void CGRP2Dlg::q_sxy(short sw);
	void CGRP2Dlg::q_syx(short sw);
	void CGRP2Dlg::q_a3(short sw);
	void CGRP2Dlg::q_a4(short sw);
	void CGRP2Dlg::q_ag3(short sw);
	void CGRP2Dlg::q_ag4(short sw); 
	void CGRP2Dlg::q_sd(short sw);
	void CGRP2Dlg::q_sa3g(short sw);
	void CGRP2Dlg::q_sa4g(short sw);
	void CGRP2Dlg::q_sdg(short sw);
	void CGRP2Dlg::q_sgam(short sw);
	void CGRP2Dlg::q_am(short sw);
	void CGRP2Dlg::X_bez(short sw);
	void CGRP2Dlg::Y_bez(short sw);
	void CGRP2Dlg::sw_p_e(short sw);
	void CGRP2Dlg::sw_p_p(short sw);
	void CGRP2Dlg::pos_scx_(short sw);
	void CGRP2Dlg::pos_scy_(short sw);	
	void CGRP2Dlg::pos_Axx_(short sw);
	void CGRP2Dlg::pos_Axy_(short sw);
	void CGRP2Dlg::pos_Ayx_(short sw);
	void CGRP2Dlg::pos_Ayy_(short sw);
	void CGRP2Dlg::e_gr(int gr);
	void CGRP2Dlg::s0_gr(int gr);
	void CGRP2Dlg::s1_gr(int gr);
	void CGRP2Dlg::xe_gr(int gr);
	void CGRP2Dlg::x0_gr(int gr);
	void CGRP2Dlg::x1_gr(int gr);
	void CGRP2Dlg::e_art(CString art);  
	void CGRP2Dlg::s0_art(CString art);  
	void CGRP2Dlg::s1_art(CString art); 
	void CGRP2Dlg::xe_art(CString art);  
	void CGRP2Dlg::x0_art(CString art);  
	void CGRP2Dlg::x1_art(CString art); 
	void CGRP2Dlg::clr_e(int fb);
	void CGRP2Dlg::clr_s0(int fb);  
	void CGRP2Dlg::clr_s1(int fb);  
	void CGRP2Dlg::clr_xe(int fb);
	void CGRP2Dlg::clr_x0(int fb); 
	void CGRP2Dlg::clr_x1(int fb);  
	void CGRP2Dlg::q_e(short sw);
	void CGRP2Dlg::q_s0(short sw);
	void CGRP2Dlg::q_s1(short sw);
	void CGRP2Dlg::q_xe(short sw);
	void CGRP2Dlg::q_x0(short sw);
	void CGRP2Dlg::q_x1(short sw);
	void CGRP2Dlg::p_e(short sw );
	void CGRP2Dlg::p_s0(short sw );
	void CGRP2Dlg::p_s1(short sw );
	void CGRP2Dlg::p_x0(short sw );
	void CGRP2Dlg::p_x1(short sw );
	void CGRP2Dlg::p_x(short sw);
	void CGRP2Dlg::AxBez_(short sw, CString x);
	void CGRP2Dlg::AyBez_(short sw, CString y);

	void CGRP2Dlg::int_sw(int n);
	void CGRP2Dlg::diff_sw(int n);
	void CGRP2Dlg::kgl_sw(int i);
	void CGRP2Dlg::fxy_sw( );
	void CGRP2Dlg::integral();
	void CGRP2Dlg::differential();
	void CGRP2Dlg::kgl();
	void CGRP2Dlg::fx_0();
	void CGRP2Dlg::fx_1();

	void CGRP2Dlg::log_file(BOOL sw);

	void CGRP2Dlg::menue_mod(); 

	void CGRP2Dlg::OnEinstellungenCursor_(); 

    CDialog m_InfoDlg;
	CDialog m_StatusDlg;	
	CDialog m_FxyDlg;
	CDialog m_ThetaDlg;
	CDialog m_LogDlg;

	//{{AFX_DATA(CGRP2Dlg)
	enum { IDD = IDD_GRP2_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CGRP2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	//}}AFX_VIRTUAL

	protected:
	HICON m_hIcon;
	HCURSOR m_Csr1; 
	HCURSOR m_Csr2;
	HCURSOR m_Csr3;

	//{{AFX_MSG(CGRP2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnFunktionsmatrixFfnen();
	afx_msg void OnFunktionEmfspeichern();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnClose();
	afx_msg void OnModusFp();
	afx_msg void OnModusFx();
	afx_msg void OnModusRxy();
	afx_msg void OnFunktionEmfffnen();
	afx_msg void OnModusInv();
	afx_msg void OnEINSTELLUNGENParameter();
	afx_msg void OnInfo();
	afx_msg void OnEinstellungenCursorSchwarz();
	afx_msg void OnEinstellungenCursorWeiss();
	afx_msg void OnEINSTELLUNGENDiagramm();
	afx_msg void OnEINSTELLUNGENFunktion();
	afx_msg void OnEinstellungenKoordinaten();
	afx_msg void OnEinstellungenApp();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnModusEpsilon();
	afx_msg void OnEinstellungenCursorAchsenverschub();
	afx_msg void OnEinstellungenCursorVektorenverschub();
	afx_msg void OnFunktionSpeichernunter();
	afx_msg void OnAnsichtFunktionsmatrixfxy(UINT sw);
	afx_msg void OnModusFzx();
	afx_msg void OnAnsichtThetafensterq(UINT sw);
	afx_msg void OnFunktionSpeichern();
	afx_msg void OnFunktionEmfspeichernunter();
	afx_msg void OnAnsichtGrp2log(UINT sw);
	afx_msg void OnAnsichtStatusleiste();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
