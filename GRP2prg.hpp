//------------------------------------------------------------------------| GRP2prg.hpp                                  //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#if !defined(AFX_GRP2PRG_H__1C28D723_664A_4773_B467_BDEB087D4708__INCLUDED_)
#define AFX_GRP2PRG_H__1C28D723_664A_4773_B467_BDEB087D4708__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class GRP2prg : public CDialog
{
	public:
	GRP2prg(CWnd* pParent = NULL); 
	
	CString GRP2prg::ftoc( double x0, int dez );
	
	short sw;
	
	typedef struct tagSCHEMA
	{
		short p1_sw_Fk; //Kurve
		short p1_sw_xy; //Punkte
		BOOL  p1_W_x;   //x_Werte_Dezimalstellen
		BOOL  p1_W_y;   //y_Werte_Dezimalstellen
		short p1_ch_x;  //x_Beschriftung_Werte
		short p1_ch_y;  //y_Beschriftung_Werte
		short p1_ch_xm; //x_Beschriftung_MinMax
		short p1_ch_ym; //y_Beschriftung_MinMax
		int   p1_fwxXd; //X_Beschriftung_Werte_Position_x
		int   p1_fwyXd; //X_Beschriftung_Werte_Position_y
		int   p1_fwxYd; //Y_Beschriftung_Werte_Position_x
		int   p1_fwyYd; //Y_Beschriftung_Werte_Position_y
		
		short p2_ch_xA;   //x_Achse
		short p2_ch_yA;   //y_Achse
		short p2_ch_xS;   //x_Skala
		short p2_ch_yS;   //y_Skala
		short p2_ch_xSw;  //x_Skalenwerte
		short p2_ch_ySw;  //y_Skalenwerte
		BOOL p2_dez_S_x;  //x_Skalenwerte_Dezimalstellen
		BOOL p2_dez_S_y;  //y_Skalenwerte_Dezimalstellen
		short p2_ch_xGrd; //x_Grid
		short p2_ch_yGrd; //y_Grid
		CString p2_tlgx;  //x_Skala_Teilung
		CString p2_tlgy;  //y_Skala_Teilung
		int p2_swxXd;     //X_Skalenwerte_Position_x
		int p2_swyXd;     //X_Skalenwerte_Position_y
		int p2_swxYd;     //Y_Skalenwerte_Position_x
		int p2_swyYd;     //Y_Skalenwerte_Position_y
		
		short p3_ch_xV;   //x_Vektor
		short p3_ch_yV;   //y_Vektor
		short p3_ch_xK;   //x_Koordinate
		short p3_ch_yK;   //y_Koordinate
		BOOL p3_dez_K_x;  //x_Koordinaten_Dezimalstellen
		BOOL p3_dez_K_y;  //y_Koordinaten_Dezimalstellen
		CString p3_kjx;   //x_Justierung
		CString p3_kjy;   //y_Justierung
		int p3_kwx_d;     //X_Vektor_Koordinaten_Position
		int p3_kwy_d;     //Y_Vektor_Koordinaten_Position
		
		CString p4_sc;    //Diagramm_Skalierung_1
		CString p4_scy;   //Diagramm_Skalierung_2
        
		float f2_CI;      //rxy_CI
		short f2_ch_D;    //rxy_Darstellung_überschnitten
		short f2_ch_rxy;  //rxy_Darstellung
		short f2_ch_ryx;  //ryx_Darstellung
		short f2_ch_sxy;  //sxy_Darstellung
		short f2_ch_syx;  //syx_Darstellung
		short f2_ch_s1xy; //s'xy_Darstellung
		short f2_ch_s1yx; //s'yx_Darstellung
		short f2_ch_srxy; //srxy_Darstellung
		short f2_ch_sryx; //sryx_Darstellung
		short f2_ch_srx;  //srx_Darstellung
		short f2_ch_sry;  //sry_Darstellung
		
		//float f3_CI;      //Fp_CI
		short f3_ch_a3;   //a3_Darstellung
		short f3_ch_a4;   //a4_Darstellung
		short f3_ch_ag3;  //a3'_Darstellung
		short f3_ch_ag4;  //a4'_Darstellung
		short f3_ch_am;   //am_Darstellung
		short f3_ch_sd;   //sd_Darstellung
		short f3_ch_sdg;  //sd'_Darstellung
		short f3_ch_sga3; //s'a3_Darstellung
		short f3_ch_sga4; //s'a4_Darstellung
		short f3_ch_sgam; //s'am_Darstellung
		
		int d1_hg_clr;    //hintergrundfarbe
		int d1_K_clr;     //funktionskurvenfarbe
		int d1_P_clr;     //xypunktfarbe
		BOOL d1_K_gr;     //funktionskurvengrösse       
		BOOL d1_P_gr;     //xypunktgrösse
		CString d1_schr_x_fn;//schriftart funktionswerte x
		BOOL d1_schr_x_H;  //schriftgrösse H funktionswerte x
		BOOL d1_schr_x_W;  //schriftgrösse W funktionswerte x
		int d1_schr_x_clr; //schriftfarbe funktionswerte x
		CString d1_schr_y_fn;//schriftart funktionswerte y
		BOOL d1_schr_y_H;  //schriftgrösse H funktionswerte y
		BOOL d1_schr_y_W;  //schriftgrösse W funktionswerte y
		int d1_schr_y_clr; //schriftfarbe funktionswerte y
		CString d1_K_art;  //funktionskurvenmodus  art
		CString d1_P_art;  //xypunktmodus art
		
		int d2_X_clr;       //x achsenfarbe
		int d2_Y_clr;       //y achsenfarbe
		BOOL d2_X_gr;       //x achsengrösse
		BOOL d2_Y_gr;       //y achsengrösse
		short d2_ch_x;      //x achsenbezeichnung(sw)
		short d2_ch_y;      //y achsenbezeichnung(sw)
		short d2_Xgrid_gr;  //x grid(sw)
		short d2_Ygrid_gr;  //y grid(sw)
		CString d2_schr_x_fn;   //schriftart achsenwerte x
		BOOL d2_schr_x_H;       //schriftgrösse H achsenwerte x
		BOOL d2_schr_x_W;       //schriftgrösse W achsenwerte x
		int d2_schr_x_clr;      //schriftfarbe achsenwerte x
		CString d2_schr_y_fn;   //schriftart achsenwerte y
		BOOL d2_schr_y_H;       //schriftgrösse H achsenwerte y
		BOOL d2_schr_y_W;       //schriftgrösse W achsenwerte y
		int d2_schr_y_clr;      //schriftfarbe achsenwerte y 
		CString d2_X_art;     //x achsenmodus art
		CString d2_Y_art;     //y achsenmodus art
		CString d2_Xgrid_art; //x gridmodus art
		CString d2_Ygrid_art; //y gridmodus art
		int d2_Xgrid_clr;       //x gridfarbe
		int d2_Ygrid_clr;       //y gridfarbe
		
		int d3_Xv_clr;        //x vektorfarbe
		int d3_Yv_clr;        //y vektorfarbe
		BOOL d3_X_gr;         //x vektorgrösse
		BOOL d3_Y_gr;         //y vektorgrösse
		CString d3_schr_x_fn; //koordinatenschriftart
		BOOL d3_schr_x_H;     //koordinatenschriftgrösse H
		BOOL d3_schr_x_W;     //koordinatenschriftgrösse W
		int d3_schr_x_clr;    //koordinatenschriftfarbe
		CString d3_X_art;     //x vektormodus art
		CString d3_Y_art;     //y vektormodus art
		
		BOOL d4_rxy_gr;       //rxy_Linienbreite
		BOOL d4_ryx_gr;       //ryx_Linienbreite
		BOOL d4_srxy_gr;      //srxy_Linienbreite
		BOOL d4_sryx_gr;      //sryx_Linienbreite
		BOOL d4_srx_gr;       //sry_Linienbreite
		BOOL d4_sry_gr;       //srx_Linienbreite
		BOOL d4_sxy_gr;       //sxy_Linienbreite
		BOOL d4_syx_gr;       //syx_Linienbreite
		BOOL d4_s1xy_gr;      //s'xy_Linienbreite
		BOOL d4_s1yx_gr;      //s'yx_Linienbreite
		int d4_rxy_clr;       //rxy_Farbe
		int d4_ryx_clr;       //ryx_Farbe
		int d4_srxy_clr;      //srxy_Farbe
		int d4_sryx_clr;      //sryx_Farbe
		int d4_srx_clr;       //sry_Farbe
		int d4_sry_clr;       //srx_Farbe
		int d4_sxy_clr;       //sxy_Farbe
		int d4_syx_clr;       //syx_Farbe
		int d4_s1xy_clr;      //s'xy_Farbe
		int d4_s1yx_clr;      //s'yx_Farbe
		CString d4_rxy_art;   //rxy_Modus
		CString d4_ryx_art;   //ryx_Modus
		CString d4_srxy_art;  //srxy_Modus
		CString d4_sryx_art;  //sryx_Modus
		CString d4_srx_art;   //sry_Modus
		CString d4_sry_art;   //srx_Modus
		CString d4_sxy_art;   //sxy_Modus
		CString d4_syx_art;   //syx_Modus
		CString d4_s1xy_art;  //s'xy_Modus
		CString d4_s1yx_art;  //s'yx_Modus
		short d4_ch_rxy;      //rxy_Theta_Darstellung"
		short d4_ch_ryx;      //ryx_Theta_Darstellung
		short d4_ch_syx;      //syx_Theta_Darstellung
		short d4_ch_sxy;      //sxy_Theta_Darstellung 
		short d4_ch_sgyx;     //s'yx_Theta_Darstellung
		short d4_ch_sgxy;     //s'xy_Theta_Darstellung 
		short d4_ch_srxy;     //srxy_Theta_Darstellung 
		short d4_ch_sryx;     //sryx_Theta_Darstellung 
		short d4_ch_srx;      //srx_Theta_Darstellung
		short d4_ch_sry;      //sry_Theta_Darstellung
		
		BOOL d5_X_gr;         //am_Linienbreite
		BOOL d5_sd_gr;        //sd_Linienbreite
		BOOL d5_sgx_gr;       //s'am_Linienbreite 
		BOOL d5_sdg_gr;       //sd'_Linienbreite
		BOOL d5_a3_gr;        //a3_Linienbreite
		BOOL d5_ag3_gr;       //a3'_Linienbreite 
		BOOL d5_sa3g_gr;      //s'a3_Linienbreite
		BOOL d5_a4_gr;        //a4_Linienbreite
		BOOL d5_ag4_gr;       //a4'_Linienbreite
		BOOL d5_sa4g_gr;      //s'a4_Linienbreite
		int d5_Xp_clr;        //am_Farbe
		int d5_sd_clr;        //sd_Farbe
		int d5_sgx_clr;       //s'am_Farbe
		int d5_sdg_clr;       //sd'_Farbe 
		int d5_a3_clr;        //a3_Farbe
		int d5_ag3_clr;       //a3'_Farbe
		int d5_sa3g_clr;      //s'a3_Farbe
		int d5_a4_clr;        //a4_Farbe
		int d5_ag4_clr;       //a4'_Farbe
		int d5_sa4g_clr;      //s'a4_Farbe
		CString d5_X_art;     //am_Modus
		CString d5_sd_art;    //sd_Modus
		CString d5_sgx_art;   //s'am_Modus
		CString d5_sdg_art;   //sd'_Modus
		CString d5_a3_art;    //a3_Modus
		CString d5_ag3_art;   //a3'_Modus
		CString d5_sa3g_art;   //s'a3_Modus
		CString d5_a4_art;    //a4_Modus
		CString d5_ag4_art;   //a4'_Modus
		CString d5_sa4g_art;  //s'a4_Modus
		short d5_ch_x;        //am_Theta_Darstellung
		short d5_ch_s;        //sd_Theta_Darstellung
		short d5_ch_sg;       //sd'_Theta_Darstellung
		short d5_ch_sgx;      //s'am_Theta_Darstellung
		short d5_ch_a3;       //a3_Theta_Darstellung
		short d5_ch_ag3;      //a3'_Theta_Darstellung
		short d5_ch_sa3g;     //s'a3_Theta_Darstellung
		short d5_ch_a4;       //a4_Theta_Darstellung 
		short d5_ch_ag4;      //a4'_Theta_Darstellung 
		short d5_ch_sa4g;     //s'a4_Theta_Darstellung	
		
		int	d6_e_clr;         //e_Farbe
		int	d6_x_clr;         //x_Farbe
		int	d6_x0_clr;        //x0_Farbe
		int	d6_x1_clr;        //x1_Farbe
		int	d6_s0_clr;        //s0_Farbe
		int	d6_s1_clr;        //s1_Farbe
		BOOL d6_e_gr;         //e_Linienbreite
		BOOL d6_x_gr;         //x_Linienbreite
		BOOL d6_x0_gr;        //x0_Linienbreite
		BOOL d6_x1_gr;        //x1_Linienbreite
		BOOL d6_s0_gr;        //s0_Linienbreite
		BOOL d6_s1_gr;        //s1_Linienbreite
		BOOL d6_ch_e;         //e_Theta_Darstellung 
		BOOL d6_ch_x;         //x_Theta_Darstellung
		BOOL d6_ch_x0;        //x0_Theta_Darstellung
		BOOL d6_ch_x1;        //x1_Theta_Darstellung
		BOOL d6_ch_s0;        //s0_Theta_Darstellung
		BOOL d6_ch_s1;        //s1_Theta_Darstellung
		CString d6_e_art;     //e_Modus
		CString d6_x_art;     //x_Modus
		CString d6_x0_art;    //x0_Modus
		CString d6_x1_art;    //x1_Modus
		CString d6_s0_art;    //s0_Modus
		CString d6_s1_art;    //s1_Modus
	}

	SCHEMA;															  
	SCHEMA prm;	      						     					 
	                                                               
	//{{AFX_DATA(GRP2prg)
	enum { IDD = IDD_GRP2_Prg };
	BOOL	m_ch_ini;
	BOOL	m_ch_fsr;
	BOOL	m_ch_dnr;
	BOOL	m_ch_log;
	BOOL	m_ch_csr;
	BOOL	m_ch_splash;
	BOOL	m_ch_wnd_pos;
	CString	m_schema;
	//}}AFX_DATA


	//{{AFX_VIRTUAL(GRP2prg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

	protected:
	//{{AFX_MSG(GRP2prg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnCHECKini();
	afx_msg void OnVoreinstellungen();
	afx_msg void OnCHECKfstreamrnd();
	afx_msg void OnCHECKrnddyn();
	afx_msg void OnCHECKcsr();
	afx_msg void OnCHECKlog();
	afx_msg void OnCHECKsplash();
	afx_msg void OnCHECKwndpos();
	afx_msg void OnSelchangeCOMBOschema();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
