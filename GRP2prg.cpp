//------------------------------------------------------------------------| GRP2prg.cpp                                  //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#include "stdafx.h"
#include "grp2.hpp"
#include "GRP2Dlg.hpp"
#include "GRP2prg.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


GRP2prg::GRP2prg(CWnd* pParent ): CDialog(GRP2prg::IDD, pParent)
{
	//{{AFX_DATA_INIT(GRP2prg)
	m_ch_fsr = 0;
	m_ch_dnr = 0;
	m_ch_log = 0;
	m_ch_csr = 0;
	m_ch_splash = 0;
	m_ch_wnd_pos = 0;
	m_schema = "Standard";
	//}}AFX_DATA_INIT
}

void GRP2prg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GRP2prg)
	DDX_Check(pDX, IDC_CHECK_ini, m_ch_ini);
	DDX_Check(pDX, IDC_CHECK_fstream_rnd, m_ch_fsr);
	DDX_Check(pDX, IDC_CHECK_rnd_dyn, m_ch_dnr);
	DDX_Check(pDX, IDC_CHECK_log, m_ch_log);
	DDX_Check(pDX, IDC_CHECK_csr, m_ch_csr);
	DDX_Check(pDX, IDC_CHECK_splash, m_ch_splash);
	DDX_Check(pDX, IDC_CHECK_wnd_pos, m_ch_wnd_pos);
	DDX_CBString(pDX, IDC_COMBO_schema, m_schema);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(GRP2prg, CDialog)
	//{{AFX_MSG_MAP(GRP2prg)
	ON_BN_CLICKED(IDC_CHECK_ini, OnCHECKini)
	ON_BN_CLICKED(ID_Voreinstellungen, OnVoreinstellungen)
	ON_BN_CLICKED(IDC_CHECK_fstream_rnd, OnCHECKfstreamrnd)
	ON_BN_CLICKED(IDC_CHECK_rnd_dyn, OnCHECKrnddyn)
	ON_BN_CLICKED(IDC_CHECK_csr, OnCHECKcsr)
	ON_BN_CLICKED(IDC_CHECK_log, OnCHECKlog)
	ON_BN_CLICKED(IDC_CHECK_splash, OnCHECKsplash)
	ON_BN_CLICKED(IDC_CHECK_wnd_pos, OnCHECKwndpos)
	ON_CBN_SELCHANGE(IDC_COMBO_schema, OnSelchangeCOMBOschema)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



BOOL GRP2prg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	UpdateData(1);

	            CWinApp*  pApp = AfxGetApp(); // ini profil lesen 

	           m_ch_ini=  pApp->GetProfileInt("INI_schreiben","prg",1);
	           m_ch_dnr=  pApp->GetProfileInt("Programm","Dynamisch_rendern",1);
	           m_ch_fsr=  pApp->GetProfileInt("Programm","Filestream_rendern",1);
	        m_ch_splash=  pApp->GetProfileInt("Programm","Splash",1);
	       m_ch_wnd_pos=  pApp->GetProfileInt("Programm","Fensterposition_speichern",1);
		       m_ch_log=  pApp->GetProfileInt("Programm","Logfile",0);
			   m_ch_csr=  pApp->GetProfileInt("Programm","Cursor",1);
			   m_schema=  pApp->GetProfileString("Programm","Schema","Standard");

	SetWindowPos(&wndTop, pApp->GetProfileInt("Programm","Position_x",100),
		                  pApp->GetProfileInt("Programm","Position_y",100), 200+8,100+27, SWP_NOSIZE);

	UpdateData(0);
	
	sw=1;OnSelchangeCOMBOschema();sw=0;
	
	return 1;               
}

void GRP2prg::OnCHECKcsr(){          UpdateData(1); UpdateData(0); } 
void GRP2prg::OnCHECKlog(){          UpdateData(1); UpdateData(0); } 
void GRP2prg::OnCHECKsplash(){       UpdateData(1); UpdateData(0); } 
void GRP2prg::OnCHECKwndpos(){       UpdateData(1); UpdateData(0); } 

void GRP2prg::OnCHECKfstreamrnd() {  UpdateData(1); UpdateData(0); }
void GRP2prg::OnCHECKrnddyn(){       UpdateData(1); UpdateData(0); } 

void GRP2prg::OnVoreinstellungen() 
{
	UpdateData(1);

	m_ch_fsr = 1;
	m_ch_dnr = 0;
	m_ch_log = 0;
	m_ch_csr = 1;
	m_ch_splash = 0;
	m_ch_wnd_pos = 1;

	UpdateData(0);
}

void GRP2prg::OnSelchangeCOMBOschema() 
{
	UpdateData(1);
	
	if(m_schema=="Standard")
	{
		prm.p1_sw_Fk = 0 ; //Kurve
		prm.p1_sw_xy = 1 ; //Punkte
		prm.p1_W_x   = 3 ; //x_Werte_Dezimalstellen
		prm.p1_W_y   = 3 ; //y_Werte_Dezimalstellen
		prm.p1_ch_x  = 0 ; //x_Beschriftung_Werte
		prm.p1_ch_y  = 0 ; //y_Beschriftung_Werte
		prm.p1_ch_xm = 0 ; //x_Beschriftung_MinMax
		prm.p1_ch_ym = 0 ; //y_Beschriftung_MinMax
		prm.p1_fwxXd = 0 ; //X_Beschriftung_Werte_Position_x
		prm.p1_fwyXd = -12 ; //X_Beschriftung_Werte_Position_y
		prm.p1_fwxYd = 6 ; //Y_Beschriftung_Werte_Position_x
		prm.p1_fwyYd = -8 ; //Y_Beschriftung_Werte_Position_y

		prm.p2_ch_xA   = 1 ; //x_Achse
		prm.p2_ch_yA   = 1 ; //y_Achse
		prm.p2_ch_xS   = 1 ; //x_Skala
		prm.p2_ch_yS   = 1 ; //y_Skala
		prm.p2_ch_xSw  = 1 ; //x_Skalenwerte
		prm.p2_ch_ySw  = 1 ; //y_Skalenwerte
		prm.p2_dez_S_x = 2 ; //x_Skalenwerte_Dezimalstellen
		prm.p2_dez_S_y = 2 ; //y_Skalenwerte_Dezimalstellen
		prm.p2_ch_xGrd = 0 ; //x_Grid
		prm.p2_ch_yGrd = 0 ; //y_Grid
		prm.p2_tlgx    = "4"; //x_Skala_Teilung
		prm.p2_tlgy    = "4"; //y_Skala_Teilung
		prm.p2_swxXd   = 0 ; //X_Skalenwerte_Position_x
		prm.p2_swyXd   = 3 ; //X_Skalenwerte_Position_y
		prm.p2_swxYd   = -39 ; //Y_Skalenwerte_Position_x
		prm.p2_swyYd   = -10 ; //Y_Skalenwerte_Position_y

		prm.p3_ch_xV   = 1 ; //x_Vektor
		prm.p3_ch_yV   = 1 ; //y_Vektor
		prm.p3_ch_xK   = 1 ; //x_Koordinate
		prm.p3_ch_yK   = 1 ; //y_Koordinate
		prm.p3_dez_K_x = 2 ; //x_Koordinaten_Dezimalstellen
		prm.p3_dez_K_y = 2 ; //y_Koordinaten_Dezimalstellen
		prm.p3_kjx     = "0"; //x_Justierung
		prm.p3_kjy     = "0"; //y_Justierung
		prm.p3_kwx_d   = 3 ; //X_Vektor_Koordinaten_Position
		prm.p3_kwy_d   = -13 ; //Y_Vektor_Koordinaten_Position

		prm.p4_sc      = "1.2"; //Diagramm_Skalierung_1
		prm.p4_scy     = "30"; //Diagramm_Skalierung_2

		prm.f2_CI      = 95.0 ; //rxy_CI
		prm.f2_ch_D    = 0 ; //rxy_Darstellung_überschnitten
		prm.f2_ch_rxy  = 1 ; //rxy_Darstellung
		prm.f2_ch_ryx  = 1 ; //ryx_Darstellung
		prm.f2_ch_sxy  = 1 ; //sxy_Darstellung
		prm.f2_ch_syx  = 1 ; //syx_Darstellung
		prm.f2_ch_s1xy = 0 ; //s'xy_Darstellung
		prm.f2_ch_s1yx = 0 ; //s'yx_Darstellung
		prm.f2_ch_srxy = 0 ; //srxy_Darstellung
		prm.f2_ch_sryx = 0 ; //sryx_Darstellung
		prm.f2_ch_srx  = 1 ; //srx_Darstellung
		prm.f2_ch_sry  = 1 ; //sry_Darstellung

		prm.f3_ch_a3   = 0 ; //a3_Darstellung 
		prm.f3_ch_a4   = 0 ; //a4_Darstellung
		prm.f3_ch_ag3  = 0 ; //a3'_Darstellung 
		prm.f3_ch_ag4  = 0 ; //a4'_Darstellung  
		prm.f3_ch_am   = 1 ; //am_Darstellung
		prm.f3_ch_sd   = 0 ; //sd_Darstellung 
		prm.f3_ch_sdg  = 1 ; //sd'_Darstellung 
		prm.f3_ch_sga3 = 1 ; //s'a3_Darstellung  
		prm.f3_ch_sga4 = 0 ; //s'a4_Darstellung 
		prm.f3_ch_sgam = 0 ; //s'am_Darstellung

		prm.d1_hg_clr     = 13357270 ; //hintergrundfarbe
		prm.d1_K_clr      = 0 ; //funktionskurvenfarbe
		prm.d1_P_clr      = 0 ; //xypunktfarbe
		prm.d1_K_gr       = 1 ; //funktionskurvengrösse      
		prm.d1_P_gr       = 2 ; //xypunktgrösse
		prm.d1_schr_x_fn  = "Arial"; //schriftart funktionswerte x
		prm.d1_schr_x_H   = 13 ; //schriftgrösse H funktionswerte x
		prm.d1_schr_x_W   = 4 ; //schriftgrösse W funktionswerte x
		prm.d1_schr_x_clr = 8421504 ; //schriftfarbe funktionswerte x								         
		prm.d1_schr_y_fn  = "Arial"; //schriftart funktionswerte y
		prm.d1_schr_y_H   = 13 ; //schriftgrösse H funktionswerte y
		prm.d1_schr_y_W   = 4 ; //schriftgrösse W funktionswerte y
		prm.d1_schr_y_clr = 8421504 ; //schriftfarbe funktionswerte y								         
		prm.d1_K_art      = "Linie"; //funktionskurvenmodus  art
		prm.d1_P_art      = "rund"; //xypunktmodus art

		prm.d2_X_clr      = 8421504 ; //x achsenfarbe
		prm.d2_Y_clr      = 8421504 ; //y achsenfarbe
		prm.d2_X_gr       = 1 ; //x achsengrösse
		prm.d2_Y_gr       = 1 ; //y achsengrösse
		prm.d2_ch_x       = 1 ; //x achsenbezeichnung(sw)
		prm.d2_ch_y       = 1 ; //y achsenbezeichnung(sw)
		prm.d2_Xgrid_gr   = 0 ; //x grid(sw)
		prm.d2_Ygrid_gr   = 0 ; //y grid(sw)
		prm.d2_schr_x_fn  = "Arial"; //schriftart achsenwerte x
		prm.d2_schr_x_H   = 13 ; //schriftgrösse H achsenwerte x
		prm.d2_schr_x_W   = 4 ; //schriftgrösse W achsenwerte x
		prm.d2_schr_x_clr = 8421504 ; //schriftfarbe achsenwerte x							          
		prm.d2_schr_y_fn  = "Arial"; //schriftart achsenwerte y
		prm.d2_schr_y_H   = 13 ; //schriftgrösse H achsenwerte y
		prm.d2_schr_y_W   = 4 ; //schriftgrösse W achsenwerte y
		prm.d2_schr_y_clr = 8421504 ; //schriftfarbe achsenwerte y 							           
		prm.d2_X_art    = "1"; //x achsenmodus art
		prm.d2_Y_art    = "1"; //y achsenmodus art
		prm.d2_Xgrid_art= "2"; //x gridmodus art
		prm.d2_Ygrid_art= "2"; //y gridmodus art
		prm.d2_Xgrid_clr  = 12632256 ; //x gridfarbe
		prm.d2_Ygrid_clr  = 12632256 ; //y gridfarbe

		prm.d3_Xv_clr     = 8421504 ; //x vektorfarbe
		prm.d3_Yv_clr     = 8421504 ; //y vektorfarbe
		prm.d3_X_gr       = 1 ; //x vektorgrösse
		prm.d3_Y_gr       = 1 ; //y vektorgrösse
		prm.d3_schr_x_fn  = "Arial";  //koordinatenschriftart
		prm.d3_schr_x_H   = 13 ;  //koordinatenschriftgrösse H
		prm.d3_schr_x_W   = 4 ; //koordinatenschriftgrösse W
		prm.d3_schr_x_clr = 8421504 ; //koordinatenschriftfarbe				                       
		prm.d3_X_art      = "Punkt"; //x vektormodus art
		prm.d3_Y_art      = "Punkt"; //y vektormodus art

		prm.d4_rxy_gr     = 1 ; //rxy_Linienbreite  
		prm.d4_ryx_gr     = 1 ; //ryx_Linienbreite
		prm.d4_srxy_gr    = 1 ; //srxy_Linienbreite
		prm.d4_sryx_gr    = 1 ; //sryx_Linienbreite
		prm.d4_srx_gr     = 1 ; //sry_Linienbreite
		prm.d4_sry_gr     = 1 ; //srx_Linienbreite
		prm.d4_sxy_gr     = 1 ; //sxy_Linienbreite
		prm.d4_syx_gr     = 1 ; //syx_Linienbreite
		prm.d4_s1xy_gr    = 1 ; //s'xy_Linienbreite
		prm.d4_s1yx_gr    = 1 ; //s'yx_Linienbreite
		prm.d4_rxy_clr    = 8421504 ; //rxy_Farbe 
		prm.d4_ryx_clr    = 8421504 ; //ryx_Farbe
		prm.d4_srxy_clr   = 8421504 ; //srxy_Farbe
		prm.d4_sryx_clr   = 8421504 ; //sryx_Farbe  
		prm.d4_srx_clr    = 8421504 ; //sry_Farbe
		prm.d4_sry_clr    = 8421504 ; //srx_Farbe 
		prm.d4_sxy_clr    = 8421504 ; //sxy_Farbe
		prm.d4_syx_clr    = 8421504 ; //syx_Farbe
		prm.d4_s1xy_clr   = 8421504 ; //s'xy_Farbe 
		prm.d4_s1yx_clr   = 8421504 ; //s'yx_Farbe
		prm.d4_rxy_art    = "1"; //rxy_Modus
		prm.d4_ryx_art    = "1"; //ryx_Modus
		prm.d4_srxy_art   = "2"; //srxy_Modus
		prm.d4_sryx_art   = "2"; //sryx_Modus
		prm.d4_srx_art    = "2"; //sry_Modus
		prm.d4_sry_art    = "2"; //srx_Modus
		prm.d4_sxy_art    = "1"; //sxy_Modus   
		prm.d4_syx_art    = "1"; //syx_Modus
		prm.d4_s1xy_art   = "3"; //s'xy_Modus
		prm.d4_s1yx_art   = "3"; //s'yx_Modus
		prm.d4_ch_rxy     = 1 ; //rxy_Theta_Darstellung 
		prm.d4_ch_ryx     = 1 ; //ryx_Theta_Darstellung  
		prm.d4_ch_syx     = 1 ; //syx_Theta_Darstellung
		prm.d4_ch_sxy     = 1 ; //sxy_Theta_Darstellung 
		prm.d4_ch_sgyx    = 1 ; //s'yx_Theta_Darstellung
		prm.d4_ch_sgxy    = 1 ; //s'xy_Theta_Darstellung
		prm.d4_ch_srxy    = 2 ; //srxy_Theta_Darstellung 
		prm.d4_ch_sryx    = 2 ; //sryx_Theta_Darstellung
		prm.d4_ch_srx     = 0 ; //srx_Theta_Darstellung
		prm.d4_ch_sry     = 0 ; //sry_Theta_Darstellung

		prm.d5_X_gr       = 1 ; //am_Linienbreite
		prm.d5_sd_gr      = 1 ; //sd_Linienbreite
		prm.d5_sgx_gr     = 1 ; //s'am_Linienbreite
		prm.d5_sdg_gr     = 1 ; //sd'_Linienbreite
		prm.d5_a3_gr      = 1 ; //a3_Linienbreite
		prm.d5_ag3_gr     = 1 ; //a3'_Linienbreite 
		prm.d5_sa3g_gr    = 1 ; //s'a3_Linienbreite  
		prm.d5_a4_gr      = 1 ; //a4_Linienbreite        
		prm.d5_ag4_gr     = 1 ; //a4'_Linienbreite     
		prm.d5_sa4g_gr    = 1 ; //s'a4_Linienbreite  
		prm.d5_Xp_clr     = 8421504 ; //am_Farbe 
		prm.d5_sd_clr     = 8421504 ; //sd_Farbe
		prm.d5_sgx_clr    = 8421504 ; //s'am_Farbe
		prm.d5_sdg_clr    = 8421504 ; //sd'_Farbe 
		prm.d5_a3_clr     = 8421504 ; //a3_Farbe 
		prm.d5_ag3_clr    = 8421504 ; //a3'_Farbe
		prm.d5_sa3g_clr   = 8421504 ; //s'a3_Farbe
		prm.d5_a4_clr     = 8421504 ; //a4_Farbe  
		prm.d5_ag4_clr     = 8421504 ; //a4'_Farbe  
		prm.d5_sa4g_clr   = 8421504 ; //s'a4_Farbe
		prm.d5_X_art      = "1"; //am_Modus 
		prm.d5_sd_art     = "1"; //sd_Modus  
		prm.d5_sgx_art    = "2"; //s'am_Modus 
		prm.d5_sdg_art    = "3"; //sd'_Modus        
		prm.d5_a3_art     = "1"; //a3_Modus   
		prm.d5_ag3_art    = "3"; //a3'_Modus
		prm.d5_sa3g_art   = "2"; //s'a3_Modus
		prm.d5_a4_art     = "1"; //a4_Modus  
		prm.d5_ag4_art    = "3"; //a4'_Modus 
		prm.d5_sa4g_art   = "2"; //s'a4_Modus 
		prm.d5_ch_x       = 1 ; //am_Theta_Darstellung 
		prm.d5_ch_s       = 1 ; //sd_Theta_Darstellung
		prm.d5_ch_sg      = 1 ; //sd'_Theta_Darstellung
		prm.d5_ch_sgx     = 2 ; //s'am_Theta_Darstellung
		prm.d5_ch_a3      = 2 ; //a3_Theta_Darstellung  
		prm.d5_ch_ag3     = 2 ; //a3'_Theta_Darstellung
		prm.d5_ch_sa3g    = 1 ; //s'a3_Theta_Darstellung
		prm.d5_ch_a4      = 2 ; //a4_Theta_Darstellung 
		prm.d5_ch_ag4     = 2 ; //a4'_Theta_Darstellung  
		prm.d5_ch_sa4g    = 1 ; //s'a4_Theta_Darstellung

		prm.d6_e_clr      = 8421504 ; //e_Farbe
		prm.d6_x_clr      = 8421504 ; //x_Farbe
		prm.d6_x0_clr     = 8421504 ; //x0_Farbe
		prm.d6_x1_clr     = 8421504 ; //x1_Farbe
		prm.d6_s0_clr     = 8421504 ; //s0_Farbe
		prm.d6_s1_clr     = 8421504 ; //s1_Farbe
		prm.d6_e_gr       = 1; //e_Linienbreite
		prm.d6_x_gr       = 1; //x_Linienbreite
		prm.d6_x0_gr      = 1; //x0_Linienbreite
		prm.d6_x1_gr      = 1; //x1_Linienbreite
		prm.d6_s0_gr      = 1; //s0_Linienbreite
		prm.d6_s1_gr      = 1; //s1_Linienbreite
		prm.d6_ch_e       = 1; //e_Theta_Darstellung 
		prm.d6_ch_x       = 1; //x_Theta_Darstellung
		prm.d6_ch_x0      = 1; //x0_Theta_Darstellung
		prm.d6_ch_x1      = 1; //x1_Theta_Darstellung
		prm.d6_ch_s0      = 1; //s0_Theta_Darstellung
		prm.d6_ch_s1      = 1; //s1_Theta_Darstellung
		prm.d6_e_art      = "Punkt"; //e_Modus
		prm.d6_x_art      = "Linie"; //x_Modus
		prm.d6_x0_art     = "Linie"; //x0_Modus
		prm.d6_x1_art     = "Linie"; //x1_Modus
		prm.d6_s0_art     = "Linie"; //s0_Modus
		prm.d6_s1_art     = "Linie"; //s1_Modus	
	}

	if(m_schema=="Schwarz auf Weiss")
	{
		prm.p1_sw_Fk = 0 ; //Kurve
		prm.p1_sw_xy = 1 ; //Punkte
		prm.p1_W_x   = 3 ; //x_Werte_Dezimalstellen
		prm.p1_W_y   = 3 ; //y_Werte_Dezimalstellen
		prm.p1_ch_x  = 0 ; //x_Beschriftung_Werte
		prm.p1_ch_y  = 0 ; //y_Beschriftung_Werte
		prm.p1_ch_xm = 0 ; //x_Beschriftung_MinMax
		prm.p1_ch_ym = 0 ; //y_Beschriftung_MinMax
		prm.p1_fwxXd = 0 ; //X_Beschriftung_Werte_Position_x
		prm.p1_fwyXd = -12 ; //X_Beschriftung_Werte_Position_y
		prm.p1_fwxYd = 6 ; //Y_Beschriftung_Werte_Position_x
		prm.p1_fwyYd = -8 ; //Y_Beschriftung_Werte_Position_y

		prm.p2_ch_xA   = 1 ; //x_Achse
		prm.p2_ch_yA   = 1 ; //y_Achse
		prm.p2_ch_xS   = 1 ; //x_Skala
		prm.p2_ch_yS   = 1 ; //y_Skala
		prm.p2_ch_xSw  = 1 ; //x_Skalenwerte
		prm.p2_ch_ySw  = 1 ; //y_Skalenwerte
		prm.p2_dez_S_x = 2 ; //x_Skalenwerte_Dezimalstellen
		prm.p2_dez_S_y = 2 ; //y_Skalenwerte_Dezimalstellen
		prm.p2_ch_xGrd = 0 ; //x_Grid
		prm.p2_ch_yGrd = 0 ; //y_Grid
		prm.p2_tlgx    = "4"; //x_Skala_Teilung
		prm.p2_tlgy    = "4"; //y_Skala_Teilung
		prm.p2_swxXd   = 0 ; //X_Skalenwerte_Position_x
		prm.p2_swyXd   = 3 ; //X_Skalenwerte_Position_y
		prm.p2_swxYd   = -26 ; //Y_Skalenwerte_Position_x
		prm.p2_swyYd   = -8 ; //Y_Skalenwerte_Position_y

		prm.p3_ch_xV   = 1 ; //x_Vektor
		prm.p3_ch_yV   = 1 ; //y_Vektor
		prm.p3_ch_xK   = 1 ; //x_Koordinate
		prm.p3_ch_yK   = 1 ; //y_Koordinate
		prm.p3_dez_K_x = 2 ; //x_Koordinaten_Dezimalstellen
		prm.p3_dez_K_y = 2 ; //y_Koordinaten_Dezimalstellen
		prm.p3_kjx     = "0"; //x_Justierung
		prm.p3_kjy     = "0"; //y_Justierung
		prm.p3_kwx_d   = 3 ; //X_Vektor_Koordinaten_Position
		prm.p3_kwy_d   = -11 ; //Y_Vektor_Koordinaten_Position

		prm.p4_sc      = "1.2"; //Diagramm_Skalierung_1
		prm.p4_scy     = "30"; //Diagramm_Skalierung_2

		prm.f2_CI      = 95.0 ; //rxy_CI
		prm.f2_ch_D    = 0 ; //rxy_Darstellung_überschnitten
		prm.f2_ch_rxy  = 1 ; //rxy_Darstellung
		prm.f2_ch_ryx  = 1 ; //ryx_Darstellung
		prm.f2_ch_sxy  = 1 ; //sxy_Darstellung
		prm.f2_ch_syx  = 1 ; //syx_Darstellung
		prm.f2_ch_s1xy = 0 ; //s'xy_Darstellung
		prm.f2_ch_s1yx = 0 ; //s'yx_Darstellung
		prm.f2_ch_srxy = 0 ; //srxy_Darstellung
		prm.f2_ch_sryx = 0 ; //sryx_Darstellung
		prm.f2_ch_srx  = 1 ; //srx_Darstellung
		prm.f2_ch_sry  = 1 ; //sry_Darstellung

		prm.f3_ch_a3   = 0 ; //a3_Darstellung 
		prm.f3_ch_a4   = 0 ; //a4_Darstellung
		prm.f3_ch_ag3  = 0 ; //a3'_Darstellung 
		prm.f3_ch_ag4  = 0 ; //a4'_Darstellung  
		prm.f3_ch_am   = 1 ; //am_Darstellung
		prm.f3_ch_sd   = 0 ; //sd_Darstellung 
		prm.f3_ch_sdg  = 1 ; //sd'_Darstellung 
		prm.f3_ch_sga3 = 1 ; //s'a3_Darstellung  
		prm.f3_ch_sga4 = 0 ; //s'a4_Darstellung 
		prm.f3_ch_sgam = 0 ; //s'am_Darstellung

		prm.d1_hg_clr     = 16777215 ; //hintergrundfarbe
		prm.d1_K_clr      = 0 ; //funktionskurvenfarbe
		prm.d1_P_clr      = 0 ; //xypunktfarbe
		prm.d1_K_gr       = 1 ; //funktionskurvengrösse      
		prm.d1_P_gr       = 2 ; //xypunktgrösse
		prm.d1_schr_x_fn  = "Times New Roman"; //schriftart funktionswerte x
		prm.d1_schr_x_H   = 11 ; //schriftgrösse H funktionswerte x
		prm.d1_schr_x_W   = 4 ; //schriftgrösse W funktionswerte x
		prm.d1_schr_x_clr = 0 ; //schriftfarbe funktionswerte x								         
		prm.d1_schr_y_fn  = "Times New Roman"; //schriftart funktionswerte y
		prm.d1_schr_y_H   = 11 ; //schriftgrösse H funktionswerte y
		prm.d1_schr_y_W   = 4 ; //schriftgrösse W funktionswerte y
		prm.d1_schr_y_clr = 0 ; //schriftfarbe funktionswerte y								         
		prm.d1_K_art      = "Linie"; //funktionskurvenmodus  art
		prm.d1_P_art      = "rund"; //xypunktmodus art

		prm.d2_X_clr      = 0 ; //x achsenfarbe
		prm.d2_Y_clr      = 0 ; //y achsenfarbe
		prm.d2_X_gr       = 1 ; //x achsengrösse
		prm.d2_Y_gr       = 1 ; //y achsengrösse
		prm.d2_ch_x       = 1 ; //x achsenbezeichnung(sw)
		prm.d2_ch_y       = 1 ; //y achsenbezeichnung(sw)
		prm.d2_Xgrid_gr   = 0 ; //x grid(sw)
		prm.d2_Ygrid_gr   = 0 ; //y grid(sw)
		prm.d2_schr_x_fn  = "Times New Roman"; //schriftart achsenwerte x
		prm.d2_schr_x_H   = 11 ; //schriftgrösse H achsenwerte x
		prm.d2_schr_x_W   = 4 ; //schriftgrösse W achsenwerte x
		prm.d2_schr_x_clr = 0 ; //schriftfarbe achsenwerte x							          
		prm.d2_schr_y_fn  = "Times New Roman"; //schriftart achsenwerte y
		prm.d2_schr_y_H   = 11 ; //schriftgrösse H achsenwerte y
		prm.d2_schr_y_W   = 4 ; //schriftgrösse W achsenwerte y
		prm.d2_schr_y_clr = 0 ; //schriftfarbe achsenwerte y 							           
		prm.d2_X_art    = "1"; //x achsenmodus art
		prm.d2_Y_art    = "1"; //y achsenmodus art
		prm.d2_Xgrid_art= "2"; //x gridmodus art
		prm.d2_Ygrid_art= "2"; //y gridmodus art
		prm.d2_Xgrid_clr  = 12632256 ; //x gridfarbe
		prm.d2_Ygrid_clr  = 12632256 ; //y gridfarbe

		prm.d3_Xv_clr     = 0 ; //x vektorfarbe
		prm.d3_Yv_clr     = 0 ; //y vektorfarbe
		prm.d3_X_gr       = 1 ; //x vektorgrösse
		prm.d3_Y_gr       = 1 ; //y vektorgrösse
		prm.d3_schr_x_fn  = "Times New Roman";  //koordinatenschriftart
		prm.d3_schr_x_H   = 11 ;  //koordinatenschriftgrösse H
		prm.d3_schr_x_W   = 4 ; //koordinatenschriftgrösse W
		prm.d3_schr_x_clr = 0 ; //koordinatenschriftfarbe				                       
		prm.d3_X_art      = "Punkt"; //x vektormodus art
		prm.d3_Y_art      = "Punkt"; //y vektormodus art

		prm.d4_rxy_gr     = 0 ; //rxy_Linienbreite  
		prm.d4_ryx_gr     = 0 ; //ryx_Linienbreite
		prm.d4_srxy_gr    = 0 ; //srxy_Linienbreite
		prm.d4_sryx_gr    = 0 ; //sryx_Linienbreite
		prm.d4_srx_gr     = 0 ; //sry_Linienbreite
		prm.d4_sry_gr     = 0 ; //srx_Linienbreite
		prm.d4_sxy_gr     = 0 ; //sxy_Linienbreite
		prm.d4_syx_gr     = 0 ; //syx_Linienbreite
		prm.d4_s1xy_gr    = 0 ; //s'xy_Linienbreite
		prm.d4_s1yx_gr    = 0 ; //s'yx_Linienbreite
		prm.d4_rxy_clr    = 0 ; //rxy_Farbe 
		prm.d4_ryx_clr    = 0 ; //ryx_Farbe
		prm.d4_srxy_clr   = 0 ; //srxy_Farbe
		prm.d4_sryx_clr   = 0 ; //sryx_Farbe  
		prm.d4_srx_clr    = 0 ; //sry_Farbe
		prm.d4_sry_clr    = 0 ; //srx_Farbe 
		prm.d4_sxy_clr    = 0 ; //sxy_Farbe
		prm.d4_syx_clr    = 0 ; //syx_Farbe
		prm.d4_s1xy_clr   = 0 ; //s'xy_Farbe 
		prm.d4_s1yx_clr   = 0 ; //s'yx_Farbe
		prm.d4_rxy_art    = "1"; //rxy_Modus
		prm.d4_ryx_art    = "1"; //ryx_Modus
		prm.d4_srxy_art   = "2"; //srxy_Modus
		prm.d4_sryx_art   = "2"; //sryx_Modus
		prm.d4_srx_art    = "2"; //sry_Modus
		prm.d4_sry_art    = "2"; //srx_Modus
		prm.d4_sxy_art    = "1"; //sxy_Modus   
		prm.d4_syx_art    = "1"; //syx_Modus
		prm.d4_s1xy_art   = "3"; //s'xy_Modus
		prm.d4_s1yx_art   = "3"; //s'yx_Modus
		prm.d4_ch_rxy     = 1 ; //rxy_Theta_Darstellung 
		prm.d4_ch_ryx     = 1 ; //ryx_Theta_Darstellung  
		prm.d4_ch_syx     = 1 ; //syx_Theta_Darstellung
		prm.d4_ch_sxy     = 1 ; //sxy_Theta_Darstellung 
		prm.d4_ch_sgyx    = 1 ; //s'yx_Theta_Darstellung
		prm.d4_ch_sgxy    = 1 ; //s'xy_Theta_Darstellung
		prm.d4_ch_srxy    = 2 ; //srxy_Theta_Darstellung 
		prm.d4_ch_sryx    = 2 ; //sryx_Theta_Darstellung
		prm.d4_ch_srx     = 0 ; //srx_Theta_Darstellung
		prm.d4_ch_sry     = 0 ; //sry_Theta_Darstellung

		prm.d5_X_gr       = 0 ; //am_Linienbreite
		prm.d5_sd_gr      = 0 ; //sd_Linienbreite
		prm.d5_sgx_gr     = 0 ; //s'am_Linienbreite
		prm.d5_sdg_gr     = 0 ; //sd'_Linienbreite
		prm.d5_a3_gr      = 0 ; //a3_Linienbreite
		prm.d5_ag3_gr     = 0 ; //a3'_Linienbreite 
		prm.d5_sa3g_gr    = 0 ; //s'a3_Linienbreite  
		prm.d5_a4_gr      = 0 ; //a4_Linienbreite        
		prm.d5_ag4_gr     = 0 ; //a4'_Linienbreite     
		prm.d5_sa4g_gr    = 0 ; //s'a4_Linienbreite  
		prm.d5_Xp_clr     = 0 ; //am_Farbe 
		prm.d5_sd_clr     = 0 ; //sd_Farbe
		prm.d5_sgx_clr    = 0 ; //s'am_Farbe
		prm.d5_sdg_clr    = 0 ; //sd'_Farbe 
		prm.d5_a3_clr     = 0 ; //a3_Farbe 
		prm.d5_ag3_clr    = 0 ; //a3'_Farbe
		prm.d5_sa3g_clr   = 0 ; //s'a3_Farbe
		prm.d5_a4_clr     = 0 ; //a4_Farbe  
		prm.d5_ag4_clr     = 0 ; //a4'_Farbe  
		prm.d5_sa4g_clr   = 0 ; //s'a4_Farbe
		prm.d5_X_art      = "1"; //am_Modus 
		prm.d5_sd_art     = "1"; //sd_Modus  
		prm.d5_sgx_art    = "2"; //s'am_Modus 
		prm.d5_sdg_art    = "3"; //sd'_Modus        
		prm.d5_a3_art     = "1"; //a3_Modus   
		prm.d5_ag3_art    = "3"; //a3'_Modus
		prm.d5_sa3g_art   = "2"; //s'a3_Modus
		prm.d5_a4_art     = "1"; //a4_Modus  
		prm.d5_ag4_art    = "3"; //a4'_Modus 
		prm.d5_sa4g_art   = "2"; //s'a4_Modus 
		prm.d5_ch_x       = 1 ; //am_Theta_Darstellung 
		prm.d5_ch_s       = 1 ; //sd_Theta_Darstellung
		prm.d5_ch_sg      = 1 ; //sd'_Theta_Darstellung
		prm.d5_ch_sgx     = 2 ; //s'am_Theta_Darstellung
		prm.d5_ch_a3      = 2 ; //a3_Theta_Darstellung  
		prm.d5_ch_ag3     = 2 ; //a3'_Theta_Darstellung
		prm.d5_ch_sa3g    = 1 ; //s'a3_Theta_Darstellung
		prm.d5_ch_a4      = 2 ; //a4_Theta_Darstellung 
		prm.d5_ch_ag4     = 2 ; //a4'_Theta_Darstellung  
		prm.d5_ch_sa4g    = 1 ; //s'a4_Theta_Darstellung

		prm.d6_e_clr      = 0 ; //e_Farbe
		prm.d6_x_clr      = 0 ; //x_Farbe
		prm.d6_x0_clr     = 0 ; //x0_Farbe
		prm.d6_x1_clr     = 0 ; //x1_Farbe
		prm.d6_s0_clr     = 0 ; //s0_Farbe
		prm.d6_s1_clr     = 0 ; //s1_Farbe
		prm.d6_e_gr       = 1; //e_Linienbreite
		prm.d6_x_gr       = 1; //x_Linienbreite
		prm.d6_x0_gr      = 1; //x0_Linienbreite
		prm.d6_x1_gr      = 1; //x1_Linienbreite
		prm.d6_s0_gr      = 1; //s0_Linienbreite
		prm.d6_s1_gr      = 1; //s1_Linienbreite
		prm.d6_ch_e       = 1; //e_Theta_Darstellung 
		prm.d6_ch_x       = 1; //x_Theta_Darstellung
		prm.d6_ch_x0      = 1; //x0_Theta_Darstellung
		prm.d6_ch_x1      = 1; //x1_Theta_Darstellung
		prm.d6_ch_s0      = 1; //s0_Theta_Darstellung
		prm.d6_ch_s1      = 1; //s1_Theta_Darstellung
		prm.d6_e_art      = "Punkt"; //e_Modus
		prm.d6_x_art      = "Linie"; //x_Modus
		prm.d6_x0_art     = "Linie"; //x0_Modus
		prm.d6_x1_art     = "Linie"; //x1_Modus
		prm.d6_s0_art     = "Linie"; //s0_Modus
		prm.d6_s1_art     = "Linie"; //s1_Modus	
	}

	if(m_schema=="Invers")
	{
		prm.p1_sw_Fk = 0 ; //Kurve
		prm.p1_sw_xy = 1 ; //Punkte
		prm.p1_W_x   = 3 ; //x_Werte_Dezimalstellen
		prm.p1_W_y   = 3 ; //y_Werte_Dezimalstellen
		prm.p1_ch_x  = 0 ; //x_Beschriftung_Werte
		prm.p1_ch_y  = 0 ; //y_Beschriftung_Werte
		prm.p1_ch_xm = 0 ; //x_Beschriftung_MinMax
		prm.p1_ch_ym = 0 ; //y_Beschriftung_MinMax
		prm.p1_fwxXd = 0 ; //X_Beschriftung_Werte_Position_x
		prm.p1_fwyXd = -12 ; //X_Beschriftung_Werte_Position_y
		prm.p1_fwxYd = 6 ; //Y_Beschriftung_Werte_Position_x
		prm.p1_fwyYd = -8 ; //Y_Beschriftung_Werte_Position_y

		prm.p2_ch_xA   = 1 ; //x_Achse
		prm.p2_ch_yA   = 1 ; //y_Achse
		prm.p2_ch_xS   = 1 ; //x_Skala
		prm.p2_ch_yS   = 1 ; //y_Skala
		prm.p2_ch_xSw  = 1 ; //x_Skalenwerte
		prm.p2_ch_ySw  = 1 ; //y_Skalenwerte
		prm.p2_dez_S_x = 2 ; //x_Skalenwerte_Dezimalstellen
		prm.p2_dez_S_y = 2 ; //y_Skalenwerte_Dezimalstellen
		prm.p2_ch_xGrd = 0 ; //x_Grid
		prm.p2_ch_yGrd = 0 ; //y_Grid
		prm.p2_tlgx    = "4"; //x_Skala_Teilung
		prm.p2_tlgy    = "4"; //y_Skala_Teilung
		prm.p2_swxXd   = 0 ; //X_Skalenwerte_Position_x
		prm.p2_swyXd   = 3 ; //X_Skalenwerte_Position_y
		prm.p2_swxYd   = -39 ; //Y_Skalenwerte_Position_x
		prm.p2_swyYd   = -10 ; //Y_Skalenwerte_Position_y

		prm.p3_ch_xV   = 1 ; //x_Vektor
		prm.p3_ch_yV   = 1 ; //y_Vektor
		prm.p3_ch_xK   = 1 ; //x_Koordinate
		prm.p3_ch_yK   = 1 ; //y_Koordinate
		prm.p3_dez_K_x = 2 ; //x_Koordinaten_Dezimalstellen
		prm.p3_dez_K_y = 2 ; //y_Koordinaten_Dezimalstellen
		prm.p3_kjx     = "0"; //x_Justierung
		prm.p3_kjy     = "0"; //y_Justierung
		prm.p3_kwx_d   = 3 ; //X_Vektor_Koordinaten_Position
		prm.p3_kwy_d   = -13 ; //Y_Vektor_Koordinaten_Position

		prm.p4_sc      = "1.2"; //Diagramm_Skalierung_1
		prm.p4_scy     = "30"; //Diagramm_Skalierung_2

		prm.f2_CI      = 95.0 ; //rxy_CI
		prm.f2_ch_D    = 0 ; //rxy_Darstellung_überschnitten
		prm.f2_ch_rxy  = 1 ; //rxy_Darstellung
		prm.f2_ch_ryx  = 1 ; //ryx_Darstellung
		prm.f2_ch_sxy  = 1 ; //sxy_Darstellung
		prm.f2_ch_syx  = 1 ; //syx_Darstellung
		prm.f2_ch_s1xy = 0 ; //s'xy_Darstellung
		prm.f2_ch_s1yx = 0 ; //s'yx_Darstellung
		prm.f2_ch_srxy = 0 ; //srxy_Darstellung
		prm.f2_ch_sryx = 0 ; //sryx_Darstellung
		prm.f2_ch_srx  = 1 ; //srx_Darstellung
		prm.f2_ch_sry  = 1 ; //sry_Darstellung

		prm.f3_ch_a3   = 0 ; //a3_Darstellung 
		prm.f3_ch_a4   = 0 ; //a4_Darstellung
		prm.f3_ch_ag3  = 0 ; //a3'_Darstellung 
		prm.f3_ch_ag4  = 0 ; //a4'_Darstellung  
		prm.f3_ch_am   = 1 ; //am_Darstellung
		prm.f3_ch_sd   = 0 ; //sd_Darstellung 
		prm.f3_ch_sdg  = 1 ; //sd'_Darstellung 
		prm.f3_ch_sga3 = 1 ; //s'a3_Darstellung  
		prm.f3_ch_sga4 = 0 ; //s'a4_Darstellung 
		prm.f3_ch_sgam = 0 ; //s'am_Darstellung

		prm.d1_hg_clr     = 0 ; //hintergrundfarbe
		prm.d1_K_clr      = 16777215 ; //funktionskurvenfarbe
		prm.d1_P_clr      = 16777215 ; //xypunktfarbe
		prm.d1_K_gr       = 1 ; //funktionskurvengrösse      
		prm.d1_P_gr       = 2 ; //xypunktgrösse
		prm.d1_schr_x_fn  = "Arial"; //schriftart funktionswerte x
		prm.d1_schr_x_H   = 13 ; //schriftgrösse H funktionswerte x
		prm.d1_schr_x_W   = 4 ; //schriftgrösse W funktionswerte x
		prm.d1_schr_x_clr = 8421504 ; //schriftfarbe funktionswerte x								         
		prm.d1_schr_y_fn  = "Arial"; //schriftart funktionswerte y
		prm.d1_schr_y_H   = 13 ; //schriftgrösse H funktionswerte y
		prm.d1_schr_y_W   = 4 ; //schriftgrösse W funktionswerte y
		prm.d1_schr_y_clr = 8421504 ; //schriftfarbe funktionswerte y								         
		prm.d1_K_art      = "Linie"; //funktionskurvenmodus  art
		prm.d1_P_art      = "rund"; //xypunktmodus art

		prm.d2_X_clr      = 8421504 ; //x achsenfarbe
		prm.d2_Y_clr      = 8421504 ; //y achsenfarbe
		prm.d2_X_gr       = 1 ; //x achsengrösse
		prm.d2_Y_gr       = 1 ; //y achsengrösse
		prm.d2_ch_x       = 1 ; //x achsenbezeichnung(sw)
		prm.d2_ch_y       = 1 ; //y achsenbezeichnung(sw)
		prm.d2_Xgrid_gr   = 0 ; //x grid(sw)
		prm.d2_Ygrid_gr   = 0 ; //y grid(sw)
		prm.d2_schr_x_fn  = "Arial"; //schriftart achsenwerte x
		prm.d2_schr_x_H   = 13 ; //schriftgrösse H achsenwerte x
		prm.d2_schr_x_W   = 4 ; //schriftgrösse W achsenwerte x
		prm.d2_schr_x_clr = 8421504 ; //schriftfarbe achsenwerte x							          
		prm.d2_schr_y_fn  = "Arial"; //schriftart achsenwerte y
		prm.d2_schr_y_H   = 13 ; //schriftgrösse H achsenwerte y
		prm.d2_schr_y_W   = 4 ; //schriftgrösse W achsenwerte y
		prm.d2_schr_y_clr = 8421504 ; //schriftfarbe achsenwerte y 							           
		prm.d2_X_art    = "1"; //x achsenmodus art
		prm.d2_Y_art    = "1"; //y achsenmodus art
		prm.d2_Xgrid_art= "2"; //x gridmodus art
		prm.d2_Ygrid_art= "2"; //y gridmodus art
		prm.d2_Xgrid_clr  = 8421504 ; //x gridfarbe
		prm.d2_Ygrid_clr  = 8421504 ; //y gridfarbe

		prm.d3_Xv_clr     = 8421504 ; //x vektorfarbe
		prm.d3_Yv_clr     = 8421504 ; //y vektorfarbe
		prm.d3_X_gr       = 1 ; //x vektorgrösse
		prm.d3_Y_gr       = 1 ; //y vektorgrösse
		prm.d3_schr_x_fn  = "Arial";  //koordinatenschriftart
		prm.d3_schr_x_H   = 13 ;  //koordinatenschriftgrösse H
		prm.d3_schr_x_W   = 4 ; //koordinatenschriftgrösse W
		prm.d3_schr_x_clr = 8421504 ; //koordinatenschriftfarbe				                       
		prm.d3_X_art      = "Punkt"; //x vektormodus art
		prm.d3_Y_art      = "Punkt"; //y vektormodus art

		prm.d4_rxy_gr     = 1 ; //rxy_Linienbreite  
		prm.d4_ryx_gr     = 1 ; //ryx_Linienbreite
		prm.d4_srxy_gr    = 1 ; //srxy_Linienbreite
		prm.d4_sryx_gr    = 1 ; //sryx_Linienbreite
		prm.d4_srx_gr     = 1 ; //sry_Linienbreite
		prm.d4_sry_gr     = 1 ; //srx_Linienbreite
		prm.d4_sxy_gr     = 1 ; //sxy_Linienbreite
		prm.d4_syx_gr     = 1 ; //syx_Linienbreite
		prm.d4_s1xy_gr    = 1 ; //s'xy_Linienbreite
		prm.d4_s1yx_gr    = 1 ; //s'yx_Linienbreite
		prm.d4_rxy_clr    = 8421504 ; //rxy_Farbe 
		prm.d4_ryx_clr    = 8421504 ; //ryx_Farbe
		prm.d4_srxy_clr   = 8421504 ; //srxy_Farbe
		prm.d4_sryx_clr   = 8421504 ; //sryx_Farbe  
		prm.d4_srx_clr    = 8421504 ; //sry_Farbe
		prm.d4_sry_clr    = 8421504 ; //srx_Farbe 
		prm.d4_sxy_clr    = 8421504 ; //sxy_Farbe
		prm.d4_syx_clr    = 8421504 ; //syx_Farbe
		prm.d4_s1xy_clr   = 8421504 ; //s'xy_Farbe 
		prm.d4_s1yx_clr   = 8421504 ; //s'yx_Farbe
		prm.d4_rxy_art    = "1"; //rxy_Modus
		prm.d4_ryx_art    = "1"; //ryx_Modus
		prm.d4_srxy_art   = "2"; //srxy_Modus
		prm.d4_sryx_art   = "2"; //sryx_Modus
		prm.d4_srx_art    = "2"; //sry_Modus
		prm.d4_sry_art    = "2"; //srx_Modus
		prm.d4_sxy_art    = "1"; //sxy_Modus   
		prm.d4_syx_art    = "1"; //syx_Modus
		prm.d4_s1xy_art   = "3"; //s'xy_Modus
		prm.d4_s1yx_art   = "3"; //s'yx_Modus
		prm.d4_ch_rxy     = 1 ; //rxy_Theta_Darstellung 
		prm.d4_ch_ryx     = 1 ; //ryx_Theta_Darstellung  
		prm.d4_ch_syx     = 1 ; //syx_Theta_Darstellung
		prm.d4_ch_sxy     = 1 ; //sxy_Theta_Darstellung 
		prm.d4_ch_sgyx    = 1 ; //s'yx_Theta_Darstellung
		prm.d4_ch_sgxy    = 1 ; //s'xy_Theta_Darstellung
		prm.d4_ch_srxy    = 2 ; //srxy_Theta_Darstellung 
		prm.d4_ch_sryx    = 2 ; //sryx_Theta_Darstellung
		prm.d4_ch_srx     = 0 ; //srx_Theta_Darstellung
		prm.d4_ch_sry     = 0 ; //sry_Theta_Darstellung

		prm.d5_X_gr       = 1 ; //am_Linienbreite
		prm.d5_sd_gr      = 1 ; //sd_Linienbreite
		prm.d5_sgx_gr     = 1 ; //s'am_Linienbreite
		prm.d5_sdg_gr     = 1 ; //sd'_Linienbreite
		prm.d5_a3_gr      = 1 ; //a3_Linienbreite
		prm.d5_ag3_gr     = 1 ; //a3'_Linienbreite 
		prm.d5_sa3g_gr    = 1 ; //s'a3_Linienbreite  
		prm.d5_a4_gr      = 1 ; //a4_Linienbreite        
		prm.d5_ag4_gr     = 1 ; //a4'_Linienbreite     
		prm.d5_sa4g_gr    = 1 ; //s'a4_Linienbreite  
		prm.d5_Xp_clr     = 8421504 ; //am_Farbe 
		prm.d5_sd_clr     = 8421504 ; //sd_Farbe
		prm.d5_sgx_clr    = 8421504 ; //s'am_Farbe
		prm.d5_sdg_clr    = 8421504 ; //sd'_Farbe 
		prm.d5_a3_clr     = 8421504 ; //a3_Farbe 
		prm.d5_ag3_clr    = 8421504 ; //a3'_Farbe
		prm.d5_sa3g_clr   = 8421504 ; //s'a3_Farbe
		prm.d5_a4_clr     = 8421504 ; //a4_Farbe  
		prm.d5_ag4_clr     = 8421504 ; //a4'_Farbe  
		prm.d5_sa4g_clr   = 8421504 ; //s'a4_Farbe
		prm.d5_X_art      = "1"; //am_Modus 
		prm.d5_sd_art     = "1"; //sd_Modus  
		prm.d5_sgx_art    = "2"; //s'am_Modus 
		prm.d5_sdg_art    = "3"; //sd'_Modus        
		prm.d5_a3_art     = "1"; //a3_Modus   
		prm.d5_ag3_art    = "3"; //a3'_Modus
		prm.d5_sa3g_art   = "2"; //s'a3_Modus
		prm.d5_a4_art     = "1"; //a4_Modus  
		prm.d5_ag4_art    = "3"; //a4'_Modus 
		prm.d5_sa4g_art   = "2"; //s'a4_Modus 
		prm.d5_ch_x       = 1 ; //am_Theta_Darstellung 
		prm.d5_ch_s       = 1 ; //sd_Theta_Darstellung
		prm.d5_ch_sg      = 1 ; //sd'_Theta_Darstellung
		prm.d5_ch_sgx     = 2 ; //s'am_Theta_Darstellung
		prm.d5_ch_a3      = 2 ; //a3_Theta_Darstellung  
		prm.d5_ch_ag3     = 2 ; //a3'_Theta_Darstellung
		prm.d5_ch_sa3g    = 1 ; //s'a3_Theta_Darstellung
		prm.d5_ch_a4      = 2 ; //a4_Theta_Darstellung 
		prm.d5_ch_ag4     = 2 ; //a4'_Theta_Darstellung  
		prm.d5_ch_sa4g    = 1 ; //s'a4_Theta_Darstellung

		prm.d6_e_clr      = 8421504 ; //e_Farbe
		prm.d6_x_clr      = 8421504 ; //x_Farbe
		prm.d6_x0_clr     = 8421504 ; //x0_Farbe
		prm.d6_x1_clr     = 8421504 ; //x1_Farbe
		prm.d6_s0_clr     = 8421504 ; //s0_Farbe
		prm.d6_s1_clr     = 8421504 ; //s1_Farbe
		prm.d6_e_gr       = 1; //e_Linienbreite
		prm.d6_x_gr       = 1; //x_Linienbreite
		prm.d6_x0_gr      = 1; //x0_Linienbreite
		prm.d6_x1_gr      = 1; //x1_Linienbreite
		prm.d6_s0_gr      = 1; //s0_Linienbreite
		prm.d6_s1_gr      = 1; //s1_Linienbreite
		prm.d6_ch_e       = 1; //e_Theta_Darstellung 
		prm.d6_ch_x       = 1; //x_Theta_Darstellung
		prm.d6_ch_x0      = 1; //x0_Theta_Darstellung
		prm.d6_ch_x1      = 1; //x1_Theta_Darstellung
		prm.d6_ch_s0      = 1; //s0_Theta_Darstellung
		prm.d6_ch_s1      = 1; //s1_Theta_Darstellung
		prm.d6_e_art      = "Punkt"; //e_Modus
		prm.d6_x_art      = "Linie"; //x_Modus
		prm.d6_x0_art     = "Linie"; //x0_Modus
		prm.d6_x1_art     = "Linie"; //x1_Modus
		prm.d6_s0_art     = "Linie"; //s0_Modus
		prm.d6_s1_art     = "Linie"; //s1_Modus	
	}

	if(m_schema=="LCD")
	{
		prm.p1_sw_Fk = 0 ; //Kurve
		prm.p1_sw_xy = 1 ; //Punkte
		prm.p1_W_x   = 3 ; //x_Werte_Dezimalstellen
		prm.p1_W_y   = 3 ; //y_Werte_Dezimalstellen
		prm.p1_ch_x  = 0 ; //x_Beschriftung_Werte
		prm.p1_ch_y  = 0 ; //y_Beschriftung_Werte
		prm.p1_ch_xm = 0 ; //x_Beschriftung_MinMax
		prm.p1_ch_ym = 0 ; //y_Beschriftung_MinMax
		prm.p1_fwxXd = 0 ; //X_Beschriftung_Werte_Position_x
		prm.p1_fwyXd = -12 ; //X_Beschriftung_Werte_Position_y
		prm.p1_fwxYd = 6 ; //Y_Beschriftung_Werte_Position_x
		prm.p1_fwyYd = -8 ; //Y_Beschriftung_Werte_Position_y

		prm.p2_ch_xA   = 1 ; //x_Achse
		prm.p2_ch_yA   = 1 ; //y_Achse
		prm.p2_ch_xS   = 1 ; //x_Skala
		prm.p2_ch_yS   = 1 ; //y_Skala
		prm.p2_ch_xSw  = 1 ; //x_Skalenwerte
		prm.p2_ch_ySw  = 1 ; //y_Skalenwerte
		prm.p2_dez_S_x = 2 ; //x_Skalenwerte_Dezimalstellen
		prm.p2_dez_S_y = 2 ; //y_Skalenwerte_Dezimalstellen
		prm.p2_ch_xGrd = 0 ; //x_Grid
		prm.p2_ch_yGrd = 0 ; //y_Grid
		prm.p2_tlgx    = "4"; //x_Skala_Teilung
		prm.p2_tlgy    = "4"; //y_Skala_Teilung
		prm.p2_swxXd   = 0 ; //X_Skalenwerte_Position_x
		prm.p2_swyXd   = 7 ; //X_Skalenwerte_Position_y
		prm.p2_swxYd   = -53 ; //Y_Skalenwerte_Position_x
		prm.p2_swyYd   = -10 ; //Y_Skalenwerte_Position_y

		prm.p3_ch_xV   = 1 ; //x_Vektor
		prm.p3_ch_yV   = 1 ; //y_Vektor
		prm.p3_ch_xK   = 1 ; //x_Koordinate
		prm.p3_ch_yK   = 1 ; //y_Koordinate
		prm.p3_dez_K_x = 2 ; //x_Koordinaten_Dezimalstellen
		prm.p3_dez_K_y = 2 ; //y_Koordinaten_Dezimalstellen
		prm.p3_kjx     = "0"; //x_Justierung
		prm.p3_kjy     = "0"; //y_Justierung
		prm.p3_kwx_d   = 3 ; //X_Vektor_Koordinaten_Position
		prm.p3_kwy_d   = -15 ; //Y_Vektor_Koordinaten_Position

		prm.p4_sc      = "1.2"; //Diagramm_Skalierung_1
		prm.p4_scy     = "30"; //Diagramm_Skalierung_2

		prm.f2_CI      = 95.0 ; //rxy_CI
		prm.f2_ch_D    = 0 ; //rxy_Darstellung_überschnitten
		prm.f2_ch_rxy  = 1 ; //rxy_Darstellung
		prm.f2_ch_ryx  = 1 ; //ryx_Darstellung
		prm.f2_ch_sxy  = 1 ; //sxy_Darstellung
		prm.f2_ch_syx  = 1 ; //syx_Darstellung
		prm.f2_ch_s1xy = 0 ; //s'xy_Darstellung
		prm.f2_ch_s1yx = 0 ; //s'yx_Darstellung
		prm.f2_ch_srxy = 0 ; //srxy_Darstellung
		prm.f2_ch_sryx = 0 ; //sryx_Darstellung
		prm.f2_ch_srx  = 1 ; //srx_Darstellung
		prm.f2_ch_sry  = 1 ; //sry_Darstellung

		prm.f3_ch_a3   = 0 ; //a3_Darstellung 
		prm.f3_ch_a4   = 0 ; //a4_Darstellung
		prm.f3_ch_ag3  = 0 ; //a3'_Darstellung 
		prm.f3_ch_ag4  = 0 ; //a4'_Darstellung  
		prm.f3_ch_am   = 1 ; //am_Darstellung
		prm.f3_ch_sd   = 0 ; //sd_Darstellung 
		prm.f3_ch_sdg  = 1 ; //sd'_Darstellung 
		prm.f3_ch_sga3 = 1 ; //s'a3_Darstellung  
		prm.f3_ch_sga4 = 0 ; //s'a4_Darstellung 
		prm.f3_ch_sgam = 0 ; //s'am_Darstellung

		prm.d1_hg_clr     = 10857119 ; //hintergrundfarbe
		prm.d1_K_clr      = 16777215 ; //funktionskurvenfarbe
		prm.d1_P_clr      = 16777215 ; //xypunktfarbe
		prm.d1_K_gr       = 4 ; //funktionskurvengrösse      
		prm.d1_P_gr       = 0 ; //xypunktgrösse
		prm.d1_schr_x_fn  = "MS SystemEx"; //schriftart funktionswerte x
		prm.d1_schr_x_H   = -11 ; //schriftgrösse H funktionswerte x
		prm.d1_schr_x_W   = 0 ; //schriftgrösse W funktionswerte x
		prm.d1_schr_x_clr = 16777215 ; //schriftfarbe funktionswerte x								         
		prm.d1_schr_y_fn  = "MS SystemEx"; //schriftart funktionswerte y
		prm.d1_schr_y_H   = -11 ; //schriftgrösse H funktionswerte y
		prm.d1_schr_y_W   = 0 ; //schriftgrösse W funktionswerte y
		prm.d1_schr_y_clr = 16777215 ; //schriftfarbe funktionswerte y								         
		prm.d1_K_art      = "Linie"; //funktionskurvenmodus  art
		prm.d1_P_art      = "Kreuz"; //xypunktmodus art

		prm.d2_X_clr      = 16777215 ; //x achsenfarbe
		prm.d2_Y_clr      = 16777215 ; //y achsenfarbe
		prm.d2_X_gr       = 2 ; //x achsengrösse
		prm.d2_Y_gr       = 2 ; //y achsengrösse
		prm.d2_ch_x       = 1 ; //x achsenbezeichnung(sw)
		prm.d2_ch_y       = 1 ; //y achsenbezeichnung(sw)
		prm.d2_Xgrid_gr   = 0 ; //x grid(sw)
		prm.d2_Ygrid_gr   = 0 ; //y grid(sw)
		prm.d2_schr_x_fn  = "MS SystemEx"; //schriftart achsenwerte x
		prm.d2_schr_x_H   = -11 ; //schriftgrösse H achsenwerte x
		prm.d2_schr_x_W   = 0 ; //schriftgrösse W achsenwerte x
		prm.d2_schr_x_clr = 16777215 ; //schriftfarbe achsenwerte x							          
		prm.d2_schr_y_fn  = "MS SystemEx"; //schriftart achsenwerte y
		prm.d2_schr_y_H   = -11 ; //schriftgrösse H achsenwerte y
		prm.d2_schr_y_W   = 0 ; //schriftgrösse W achsenwerte y
		prm.d2_schr_y_clr = 16777215 ; //schriftfarbe achsenwerte y 							           
		prm.d2_X_art    = "Linie"; //x achsenmodus art
		prm.d2_Y_art    = "Linie"; //y achsenmodus art
		prm.d2_Xgrid_art= "Linie"; //x gridmodus art
		prm.d2_Ygrid_art= "Linie"; //y gridmodus art
		prm.d2_Xgrid_clr  = 16777215 ; //x gridfarbe
		prm.d2_Ygrid_clr  = 16777215 ; //y gridfarbe

		prm.d3_Xv_clr     = 16777215 ; //x vektorfarbe
		prm.d3_Yv_clr     = 16777215 ; //y vektorfarbe
		prm.d3_X_gr       = 2 ; //x vektorgrösse
		prm.d3_Y_gr       = 2 ; //y vektorgrösse
		prm.d3_schr_x_fn  = "MS SystemEx";  //koordinatenschriftart
		prm.d3_schr_x_H   = -11 ;  //koordinatenschriftgrösse H
		prm.d3_schr_x_W   = 0 ; //koordinatenschriftgrösse W
		prm.d3_schr_x_clr = 16777215 ; //koordinatenschriftfarbe				                       
		prm.d3_X_art      = "Linie"; //x vektormodus art
		prm.d3_Y_art      = "Linie"; //y vektormodus art

		prm.d4_rxy_gr     = 2 ; //rxy_Linienbreite  
		prm.d4_ryx_gr     = 2 ; //ryx_Linienbreite
		prm.d4_srxy_gr    = 2 ; //srxy_Linienbreite
		prm.d4_sryx_gr    = 2 ; //sryx_Linienbreite
		prm.d4_srx_gr     = 2 ; //sry_Linienbreite
		prm.d4_sry_gr     = 2 ; //srx_Linienbreite
		prm.d4_sxy_gr     = 2 ; //sxy_Linienbreite
		prm.d4_syx_gr     = 2 ; //syx_Linienbreite
		prm.d4_s1xy_gr    = 2 ; //s'xy_Linienbreite
		prm.d4_s1yx_gr    = 2 ; //s'yx_Linienbreite
		prm.d4_rxy_clr    = 16777215 ; //rxy_Farbe 
		prm.d4_ryx_clr    = 16777215 ; //ryx_Farbe
		prm.d4_srxy_clr   = 16777215 ; //srxy_Farbe
		prm.d4_sryx_clr   = 16777215 ; //sryx_Farbe  
		prm.d4_srx_clr    = 16777215 ; //sry_Farbe
		prm.d4_sry_clr    = 16777215 ; //srx_Farbe 
		prm.d4_sxy_clr    = 16777215 ; //sxy_Farbe
		prm.d4_syx_clr    = 16777215 ; //syx_Farbe
		prm.d4_s1xy_clr   = 16777215 ; //s'xy_Farbe 
		prm.d4_s1yx_clr   = 16777215 ; //s'yx_Farbe
		prm.d4_rxy_art    = "Linie"; //rxy_Modus
		prm.d4_ryx_art    = "Linie"; //ryx_Modus
		prm.d4_srxy_art   = "Linie"; //srxy_Modus
		prm.d4_sryx_art   = "Linie"; //sryx_Modus
		prm.d4_srx_art    = "Linie"; //sry_Modus
		prm.d4_sry_art    = "Linie"; //srx_Modus
		prm.d4_sxy_art    = "Linie"; //sxy_Modus   
		prm.d4_syx_art    = "Linie"; //syx_Modus
		prm.d4_s1xy_art   = "Linie"; //s'xy_Modus
		prm.d4_s1yx_art   = "Linie"; //s'yx_Modus
		prm.d4_ch_rxy     = 1 ; //rxy_Theta_Darstellung 
		prm.d4_ch_ryx     = 1 ; //ryx_Theta_Darstellung  
		prm.d4_ch_syx     = 1 ; //syx_Theta_Darstellung
		prm.d4_ch_sxy     = 1 ; //sxy_Theta_Darstellung 
		prm.d4_ch_sgyx    = 1 ; //s'yx_Theta_Darstellung
		prm.d4_ch_sgxy    = 1 ; //s'xy_Theta_Darstellung
		prm.d4_ch_srxy    = 2 ; //srxy_Theta_Darstellung 
		prm.d4_ch_sryx    = 2 ; //sryx_Theta_Darstellung
		prm.d4_ch_srx     = 0 ; //srx_Theta_Darstellung
		prm.d4_ch_sry     = 0 ; //sry_Theta_Darstellung

		prm.d5_X_gr       = 2 ; //am_Linienbreite
		prm.d5_sd_gr      = 2 ; //sd_Linienbreite
		prm.d5_sgx_gr     = 2 ; //s'am_Linienbreite
		prm.d5_sdg_gr     = 2 ; //sd'_Linienbreite
		prm.d5_a3_gr      = 2 ; //a3_Linienbreite
		prm.d5_ag3_gr     = 2 ; //a3'_Linienbreite 
		prm.d5_sa3g_gr    = 2 ; //s'a3_Linienbreite  
		prm.d5_a4_gr      = 2 ; //a4_Linienbreite        
		prm.d5_ag4_gr     = 2 ; //a4'_Linienbreite     
		prm.d5_sa4g_gr    = 2 ; //s'a4_Linienbreite  
		prm.d5_Xp_clr     = 16777215 ; //am_Farbe 
		prm.d5_sd_clr     = 16777215 ; //sd_Farbe
		prm.d5_sgx_clr    = 16777215 ; //s'am_Farbe
		prm.d5_sdg_clr    = 16777215 ; //sd'_Farbe 
		prm.d5_a3_clr     = 16777215 ; //a3_Farbe 
		prm.d5_ag3_clr    = 16777215 ; //a3'_Farbe
		prm.d5_sa3g_clr   = 16777215 ; //s'a3_Farbe
		prm.d5_a4_clr     = 16777215 ; //a4_Farbe  
		prm.d5_ag4_clr     = 16777215 ; //a4'_Farbe  
		prm.d5_sa4g_clr   = 16777215 ; //s'a4_Farbe
		prm.d5_X_art      = "Linie"; //am_Modus 
		prm.d5_sd_art     = "Linie"; //sd_Modus  
		prm.d5_sgx_art    = "Linie"; //s'am_Modus 
		prm.d5_sdg_art    = "Linie"; //sd'_Modus        
		prm.d5_a3_art     = "Linie"; //a3_Modus   
		prm.d5_ag3_art    = "Linie"; //a3'_Modus
		prm.d5_sa3g_art   = "Linie"; //s'a3_Modus
		prm.d5_a4_art     = "Linie"; //a4_Modus  
		prm.d5_ag4_art    = "Linie"; //a4'_Modus 
		prm.d5_sa4g_art   = "Linie"; //s'a4_Modus 
		prm.d5_ch_x       = 1 ; //am_Theta_Darstellung 
		prm.d5_ch_s       = 1 ; //sd_Theta_Darstellung
		prm.d5_ch_sg      = 1 ; //sd'_Theta_Darstellung
		prm.d5_ch_sgx     = 2 ; //s'am_Theta_Darstellung
		prm.d5_ch_a3      = 2 ; //a3_Theta_Darstellung  
		prm.d5_ch_ag3     = 2 ; //a3'_Theta_Darstellung
		prm.d5_ch_sa3g    = 1 ; //s'a3_Theta_Darstellung
		prm.d5_ch_a4      = 2 ; //a4_Theta_Darstellung 
		prm.d5_ch_ag4     = 2 ; //a4'_Theta_Darstellung  
		prm.d5_ch_sa4g    = 1 ; //s'a4_Theta_Darstellung

		prm.d6_e_clr      = 16777215 ; //e_Farbe
		prm.d6_x_clr      = 16777215 ; //x_Farbe
		prm.d6_x0_clr     = 16777215 ; //x0_Farbe
		prm.d6_x1_clr     = 16777215 ; //x1_Farbe
		prm.d6_s0_clr     = 16777215 ; //s0_Farbe
		prm.d6_s1_clr     = 16777215 ; //s1_Farbe
		prm.d6_e_gr       = 1; //e_Linienbreite
		prm.d6_x_gr       = 1; //x_Linienbreite
		prm.d6_x0_gr      = 1; //x0_Linienbreite
		prm.d6_x1_gr      = 1; //x1_Linienbreite
		prm.d6_s0_gr      = 1; //s0_Linienbreite
		prm.d6_s1_gr      = 1; //s1_Linienbreite
		prm.d6_ch_e       = 1; //e_Theta_Darstellung 
		prm.d6_ch_x       = 1; //x_Theta_Darstellung
		prm.d6_ch_x0      = 1; //x0_Theta_Darstellung
		prm.d6_ch_x1      = 1; //x1_Theta_Darstellung
		prm.d6_ch_s0      = 1; //s0_Theta_Darstellung
		prm.d6_ch_s1      = 1; //s1_Theta_Darstellung
		prm.d6_e_art      = "Punkt"; //e_Modus
		prm.d6_x_art      = "Linie"; //x_Modus
		prm.d6_x0_art     = "Linie"; //x0_Modus
		prm.d6_x1_art     = "Linie"; //x1_Modus
		prm.d6_s0_art     = "Linie"; //s0_Modus
		prm.d6_s1_art     = "Linie"; //s1_Modus	
	}

	if(m_schema=="Grün")
	{
		prm.p1_sw_Fk = 0 ; //Kurve
		prm.p1_sw_xy = 1 ; //Punkte
		prm.p1_W_x   = 3 ; //x_Werte_Dezimalstellen
		prm.p1_W_y   = 3 ; //y_Werte_Dezimalstellen
		prm.p1_ch_x  = 0 ; //x_Beschriftung_Werte
		prm.p1_ch_y  = 0 ; //y_Beschriftung_Werte
		prm.p1_ch_xm = 0 ; //x_Beschriftung_MinMax
		prm.p1_ch_ym = 0 ; //y_Beschriftung_MinMax
		prm.p1_fwxXd = 0 ; //X_Beschriftung_Werte_Position_x
		prm.p1_fwyXd = -12 ; //X_Beschriftung_Werte_Position_y
		prm.p1_fwxYd = 6 ; //Y_Beschriftung_Werte_Position_x
		prm.p1_fwyYd = -8 ; //Y_Beschriftung_Werte_Position_y

		prm.p2_ch_xA   = 1 ; //x_Achse
		prm.p2_ch_yA   = 1 ; //y_Achse
		prm.p2_ch_xS   = 1 ; //x_Skala
		prm.p2_ch_yS   = 1 ; //y_Skala
		prm.p2_ch_xSw  = 1 ; //x_Skalenwerte
		prm.p2_ch_ySw  = 1 ; //y_Skalenwerte
		prm.p2_dez_S_x = 2 ; //x_Skalenwerte_Dezimalstellen
		prm.p2_dez_S_y = 2 ; //y_Skalenwerte_Dezimalstellen
		prm.p2_ch_xGrd = 0 ; //x_Grid
		prm.p2_ch_yGrd = 0 ; //y_Grid
		prm.p2_tlgx    = "4"; //x_Skala_Teilung
		prm.p2_tlgy    = "4"; //y_Skala_Teilung
		prm.p2_swxXd   = 0 ; //X_Skalenwerte_Position_x
		prm.p2_swyXd   = 3 ; //X_Skalenwerte_Position_y
		prm.p2_swxYd   = -34 ; //Y_Skalenwerte_Position_x
		prm.p2_swyYd   = -9 ; //Y_Skalenwerte_Position_y

		prm.p3_ch_xV   = 1 ; //x_Vektor
		prm.p3_ch_yV   = 1 ; //y_Vektor
		prm.p3_ch_xK   = 1 ; //x_Koordinate
		prm.p3_ch_yK   = 1 ; //y_Koordinate
		prm.p3_dez_K_x = 2 ; //x_Koordinaten_Dezimalstellen
		prm.p3_dez_K_y = 2 ; //y_Koordinaten_Dezimalstellen
		prm.p3_kjx     = "0"; //x_Justierung
		prm.p3_kjy     = "0"; //y_Justierung
		prm.p3_kwx_d   = 4 ; //X_Vektor_Koordinaten_Position
		prm.p3_kwy_d   = -13 ; //Y_Vektor_Koordinaten_Position

		prm.p4_sc      = "1.2"; //Diagramm_Skalierung_1
		prm.p4_scy     = "30"; //Diagramm_Skalierung_2

		prm.f2_CI      = 95.0 ; //rxy_CI
		prm.f2_ch_D    = 0 ; //rxy_Darstellung_überschnitten
		prm.f2_ch_rxy  = 1 ; //rxy_Darstellung
		prm.f2_ch_ryx  = 1 ; //ryx_Darstellung
		prm.f2_ch_sxy  = 1 ; //sxy_Darstellung
		prm.f2_ch_syx  = 1 ; //syx_Darstellung
		prm.f2_ch_s1xy = 0 ; //s'xy_Darstellung
		prm.f2_ch_s1yx = 0 ; //s'yx_Darstellung
		prm.f2_ch_srxy = 0 ; //srxy_Darstellung
		prm.f2_ch_sryx = 0 ; //sryx_Darstellung
		prm.f2_ch_srx  = 1 ; //srx_Darstellung
		prm.f2_ch_sry  = 1 ; //sry_Darstellung

		prm.f3_ch_a3   = 0 ; //a3_Darstellung 
		prm.f3_ch_a4   = 0 ; //a4_Darstellung
		prm.f3_ch_ag3  = 0 ; //a3'_Darstellung 
		prm.f3_ch_ag4  = 0 ; //a4'_Darstellung  
		prm.f3_ch_am   = 1 ; //am_Darstellung
		prm.f3_ch_sd   = 0 ; //sd_Darstellung 
		prm.f3_ch_sdg  = 1 ; //sd'_Darstellung 
		prm.f3_ch_sga3 = 1 ; //s'a3_Darstellung  
		prm.f3_ch_sga4 = 0 ; //s'a4_Darstellung 
		prm.f3_ch_sgam = 0 ; //s'am_Darstellung

		prm.d1_hg_clr     = 32768 ; //hintergrundfarbe
		prm.d1_K_clr      = 65280 ; //funktionskurvenfarbe
		prm.d1_P_clr      = 65280 ; //xypunktfarbe
		prm.d1_K_gr       = 2 ; //funktionskurvengrösse      
		prm.d1_P_gr       = 2 ; //xypunktgrösse
		prm.d1_schr_x_fn  = "Lucida Sans Unicode"; //schriftart funktionswerte x
		prm.d1_schr_x_H   = -8 ; //schriftgrösse H funktionswerte x
		prm.d1_schr_x_W   = 0 ; //schriftgrösse W funktionswerte x
		prm.d1_schr_x_clr = 65280 ; //schriftfarbe funktionswerte x								         
		prm.d1_schr_y_fn  = "Lucida Sans Unicode"; //schriftart funktionswerte y
		prm.d1_schr_y_H   = -8 ; //schriftgrösse H funktionswerte y
		prm.d1_schr_y_W   = 0 ; //schriftgrösse W funktionswerte y
		prm.d1_schr_y_clr = 65280 ; //schriftfarbe funktionswerte y								         
		prm.d1_K_art      = "Linie"; //funktionskurvenmodus  art
		prm.d1_P_art      = "eckig"; //xypunktmodus art

		prm.d2_X_clr      = 65280 ; //x achsenfarbe
		prm.d2_Y_clr      = 65280 ; //y achsenfarbe
		prm.d2_X_gr       = 1 ; //x achsengrösse
		prm.d2_Y_gr       = 1 ; //y achsengrösse
		prm.d2_ch_x       = 1 ; //x achsenbezeichnung(sw)
		prm.d2_ch_y       = 1 ; //y achsenbezeichnung(sw)
		prm.d2_Xgrid_gr   = 0 ; //x grid(sw)
		prm.d2_Ygrid_gr   = 0 ; //y grid(sw)
		prm.d2_schr_x_fn  = "Lucida Sans Unicode"; //schriftart achsenwerte x
		prm.d2_schr_x_H   = -8 ; //schriftgrösse H achsenwerte x
		prm.d2_schr_x_W   = 0 ; //schriftgrösse W achsenwerte x
		prm.d2_schr_x_clr = 65280 ; //schriftfarbe achsenwerte x							          
		prm.d2_schr_y_fn  = "Lucida Sans Unicode"; //schriftart achsenwerte y
		prm.d2_schr_y_H   = -8 ; //schriftgrösse H achsenwerte y
		prm.d2_schr_y_W   = 0 ; //schriftgrösse W achsenwerte y
		prm.d2_schr_y_clr = 65280 ; //schriftfarbe achsenwerte y 							           
		prm.d2_X_art    = "Linie"; //x achsenmodus art
		prm.d2_Y_art    = "Linie"; //y achsenmodus art
		prm.d2_Xgrid_art= "Punkt"; //x gridmodus art
		prm.d2_Ygrid_art= "Punkt"; //y gridmodus art
		prm.d2_Xgrid_clr  = 65280 ; //x gridfarbe
		prm.d2_Ygrid_clr  = 65280 ; //y gridfarbe

		prm.d3_Xv_clr     = 65280 ; //x vektorfarbe
		prm.d3_Yv_clr     = 65280 ; //y vektorfarbe
		prm.d3_X_gr       = 1 ; //x vektorgrösse
		prm.d3_Y_gr       = 1 ; //y vektorgrösse
		prm.d3_schr_x_fn  = "Lucida Sans Unicode";  //koordinatenschriftart
		prm.d3_schr_x_H   = -8 ;  //koordinatenschriftgrösse H
		prm.d3_schr_x_W   = 0 ; //koordinatenschriftgrösse W
		prm.d3_schr_x_clr = 65280 ; //koordinatenschriftfarbe				                       
		prm.d3_X_art      = "Punkt"; //x vektormodus art
		prm.d3_Y_art      = "Punkt"; //y vektormodus art

		prm.d4_rxy_gr     = 1 ; //rxy_Linienbreite  
		prm.d4_ryx_gr     = 1 ; //ryx_Linienbreite
		prm.d4_srxy_gr    = 1 ; //srxy_Linienbreite
		prm.d4_sryx_gr    = 1 ; //sryx_Linienbreite
		prm.d4_srx_gr     = 1 ; //sry_Linienbreite
		prm.d4_sry_gr     = 1 ; //srx_Linienbreite
		prm.d4_sxy_gr     = 1 ; //sxy_Linienbreite
		prm.d4_syx_gr     = 1 ; //syx_Linienbreite
		prm.d4_s1xy_gr    = 1 ; //s'xy_Linienbreite
		prm.d4_s1yx_gr    = 1 ; //s'yx_Linienbreite
		prm.d4_rxy_clr    = 65280 ; //rxy_Farbe 
		prm.d4_ryx_clr    = 65280 ; //ryx_Farbe
		prm.d4_srxy_clr   = 65280 ; //srxy_Farbe
		prm.d4_sryx_clr   = 65280 ; //sryx_Farbe  
		prm.d4_srx_clr    = 65280 ; //sry_Farbe
		prm.d4_sry_clr    = 65280 ; //srx_Farbe 
		prm.d4_sxy_clr    = 65280 ; //sxy_Farbe
		prm.d4_syx_clr    = 65280 ; //syx_Farbe
		prm.d4_s1xy_clr   = 65280 ; //s'xy_Farbe 
		prm.d4_s1yx_clr   = 65280 ; //s'yx_Farbe
		prm.d4_rxy_art    = "1"; //rxy_Modus
		prm.d4_ryx_art    = "1"; //ryx_Modus
		prm.d4_srxy_art   = "2"; //srxy_Modus
		prm.d4_sryx_art   = "2"; //sryx_Modus
		prm.d4_srx_art    = "2"; //sry_Modus
		prm.d4_sry_art    = "2"; //srx_Modus
		prm.d4_sxy_art    = "1"; //sxy_Modus   
		prm.d4_syx_art    = "1"; //syx_Modus
		prm.d4_s1xy_art   = "3"; //s'xy_Modus
		prm.d4_s1yx_art   = "3"; //s'yx_Modus
		prm.d4_ch_rxy     = 1 ; //rxy_Theta_Darstellung 
		prm.d4_ch_ryx     = 1 ; //ryx_Theta_Darstellung  
		prm.d4_ch_syx     = 1 ; //syx_Theta_Darstellung
		prm.d4_ch_sxy     = 1 ; //sxy_Theta_Darstellung 
		prm.d4_ch_sgyx    = 1 ; //s'yx_Theta_Darstellung
		prm.d4_ch_sgxy    = 1 ; //s'xy_Theta_Darstellung
		prm.d4_ch_srxy    = 2 ; //srxy_Theta_Darstellung 
		prm.d4_ch_sryx    = 2 ; //sryx_Theta_Darstellung
		prm.d4_ch_srx     = 0 ; //srx_Theta_Darstellung
		prm.d4_ch_sry     = 0 ; //sry_Theta_Darstellung

		prm.d5_X_gr       = 1 ; //am_Linienbreite
		prm.d5_sd_gr      = 1 ; //sd_Linienbreite
		prm.d5_sgx_gr     = 1 ; //s'am_Linienbreite
		prm.d5_sdg_gr     = 1 ; //sd'_Linienbreite
		prm.d5_a3_gr      = 1 ; //a3_Linienbreite
		prm.d5_ag3_gr     = 1 ; //a3'_Linienbreite 
		prm.d5_sa3g_gr    = 1 ; //s'a3_Linienbreite  
		prm.d5_a4_gr      = 1 ; //a4_Linienbreite        
		prm.d5_ag4_gr     = 1 ; //a4'_Linienbreite     
		prm.d5_sa4g_gr    = 1 ; //s'a4_Linienbreite  
		prm.d5_Xp_clr     = 65280 ; //am_Farbe 
		prm.d5_sd_clr     = 65280 ; //sd_Farbe
		prm.d5_sgx_clr    = 65280 ; //s'am_Farbe
		prm.d5_sdg_clr    = 65280 ; //sd'_Farbe 
		prm.d5_a3_clr     = 65280 ; //a3_Farbe 
		prm.d5_ag3_clr    = 65280 ; //a3'_Farbe
		prm.d5_sa3g_clr   = 65280 ; //s'a3_Farbe
		prm.d5_a4_clr     = 65280 ; //a4_Farbe  
		prm.d5_ag4_clr     = 65280 ; //a4'_Farbe  
		prm.d5_sa4g_clr   = 65280 ; //s'a4_Farbe
		prm.d5_X_art      = "1"; //am_Modus 
		prm.d5_sd_art     = "1"; //sd_Modus  
		prm.d5_sgx_art    = "2"; //s'am_Modus 
		prm.d5_sdg_art    = "3"; //sd'_Modus        
		prm.d5_a3_art     = "1"; //a3_Modus   
		prm.d5_ag3_art    = "3"; //a3'_Modus
		prm.d5_sa3g_art   = "2"; //s'a3_Modus
		prm.d5_a4_art     = "1"; //a4_Modus  
		prm.d5_ag4_art    = "3"; //a4'_Modus 
		prm.d5_sa4g_art   = "2"; //s'a4_Modus 
		prm.d5_ch_x       = 1 ; //am_Theta_Darstellung 
		prm.d5_ch_s       = 1 ; //sd_Theta_Darstellung
		prm.d5_ch_sg      = 1 ; //sd'_Theta_Darstellung
		prm.d5_ch_sgx     = 2 ; //s'am_Theta_Darstellung
		prm.d5_ch_a3      = 2 ; //a3_Theta_Darstellung  
		prm.d5_ch_ag3     = 2 ; //a3'_Theta_Darstellung
		prm.d5_ch_sa3g    = 1 ; //s'a3_Theta_Darstellung
		prm.d5_ch_a4      = 2 ; //a4_Theta_Darstellung 
		prm.d5_ch_ag4     = 2 ; //a4'_Theta_Darstellung  
		prm.d5_ch_sa4g    = 1 ; //s'a4_Theta_Darstellung

		prm.d6_e_clr      = 65280 ; //e_Farbe
		prm.d6_x_clr      = 65280 ; //x_Farbe
		prm.d6_x0_clr     = 65280 ; //x0_Farbe
		prm.d6_x1_clr     = 65280 ; //x1_Farbe
		prm.d6_s0_clr     = 65280 ; //s0_Farbe
		prm.d6_s1_clr     = 65280 ; //s1_Farbe
		prm.d6_e_gr       = 1; //e_Linienbreite
		prm.d6_x_gr       = 1; //x_Linienbreite
		prm.d6_x0_gr      = 1; //x0_Linienbreite
		prm.d6_x1_gr      = 1; //x1_Linienbreite
		prm.d6_s0_gr      = 1; //s0_Linienbreite
		prm.d6_s1_gr      = 1; //s1_Linienbreite
		prm.d6_ch_e       = 1; //e_Theta_Darstellung 
		prm.d6_ch_x       = 1; //x_Theta_Darstellung
		prm.d6_ch_x0      = 1; //x0_Theta_Darstellung
		prm.d6_ch_x1      = 1; //x1_Theta_Darstellung
		prm.d6_ch_s0      = 1; //s0_Theta_Darstellung
		prm.d6_ch_s1      = 1; //s1_Theta_Darstellung
		prm.d6_e_art      = "Punkt"; //e_Modus
		prm.d6_x_art      = "Linie"; //x_Modus
		prm.d6_x0_art     = "Linie"; //x0_Modus
		prm.d6_x1_art     = "Linie"; //x1_Modus
		prm.d6_s0_art     = "Linie"; //s0_Modus
		prm.d6_s1_art     = "Linie"; //s1_Modus
	}

	if(m_schema=="Rot")
	{
		prm.p1_sw_Fk = 0 ; //Kurve
		prm.p1_sw_xy = 1 ; //Punkte
		prm.p1_W_x   = 3 ; //x_Werte_Dezimalstellen
		prm.p1_W_y   = 3 ; //y_Werte_Dezimalstellen
		prm.p1_ch_x  = 0 ; //x_Beschriftung_Werte
		prm.p1_ch_y  = 0 ; //y_Beschriftung_Werte
		prm.p1_ch_xm = 0 ; //x_Beschriftung_MinMax
		prm.p1_ch_ym = 0 ; //y_Beschriftung_MinMax
		prm.p1_fwxXd = 0 ; //X_Beschriftung_Werte_Position_x
		prm.p1_fwyXd = -12 ; //X_Beschriftung_Werte_Position_y
		prm.p1_fwxYd = 6 ; //Y_Beschriftung_Werte_Position_x
		prm.p1_fwyYd = -8 ; //Y_Beschriftung_Werte_Position_y

		prm.p2_ch_xA   = 1 ; //x_Achse
		prm.p2_ch_yA   = 1 ; //y_Achse
		prm.p2_ch_xS   = 1 ; //x_Skala
		prm.p2_ch_yS   = 1 ; //y_Skala
		prm.p2_ch_xSw  = 1 ; //x_Skalenwerte
		prm.p2_ch_ySw  = 1 ; //y_Skalenwerte
		prm.p2_dez_S_x = 2 ; //x_Skalenwerte_Dezimalstellen
		prm.p2_dez_S_y = 2 ; //y_Skalenwerte_Dezimalstellen
		prm.p2_ch_xGrd = 0 ; //x_Grid
		prm.p2_ch_yGrd = 0 ; //y_Grid
		prm.p2_tlgx    = "4"; //x_Skala_Teilung
		prm.p2_tlgy    = "4"; //y_Skala_Teilung
		prm.p2_swxXd   = 0 ; //X_Skalenwerte_Position_x
		prm.p2_swyXd   = 3 ; //X_Skalenwerte_Position_y
		prm.p2_swxYd   = -34 ; //Y_Skalenwerte_Position_x
		prm.p2_swyYd   = -9 ; //Y_Skalenwerte_Position_y

		prm.p3_ch_xV   = 1 ; //x_Vektor
		prm.p3_ch_yV   = 1 ; //y_Vektor
		prm.p3_ch_xK   = 1 ; //x_Koordinate
		prm.p3_ch_yK   = 1 ; //y_Koordinate
		prm.p3_dez_K_x = 2 ; //x_Koordinaten_Dezimalstellen
		prm.p3_dez_K_y = 2 ; //y_Koordinaten_Dezimalstellen
		prm.p3_kjx     = "0"; //x_Justierung
		prm.p3_kjy     = "0"; //y_Justierung
		prm.p3_kwx_d   = 4 ; //X_Vektor_Koordinaten_Position
		prm.p3_kwy_d   = -13 ; //Y_Vektor_Koordinaten_Position

		prm.p4_sc      = "1.2"; //Diagramm_Skalierung_1
		prm.p4_scy     = "30"; //Diagramm_Skalierung_2

		prm.f2_CI      = 95.0 ; //rxy_CI
		prm.f2_ch_D    = 0 ; //rxy_Darstellung_überschnitten
		prm.f2_ch_rxy  = 1 ; //rxy_Darstellung
		prm.f2_ch_ryx  = 1 ; //ryx_Darstellung
		prm.f2_ch_sxy  = 1 ; //sxy_Darstellung
		prm.f2_ch_syx  = 1 ; //syx_Darstellung
		prm.f2_ch_s1xy = 0 ; //s'xy_Darstellung
		prm.f2_ch_s1yx = 0 ; //s'yx_Darstellung
		prm.f2_ch_srxy = 0 ; //srxy_Darstellung
		prm.f2_ch_sryx = 0 ; //sryx_Darstellung
		prm.f2_ch_srx  = 1 ; //srx_Darstellung
		prm.f2_ch_sry  = 1 ; //sry_Darstellung

		prm.f3_ch_a3   = 0 ; //a3_Darstellung 
		prm.f3_ch_a4   = 0 ; //a4_Darstellung
		prm.f3_ch_ag3  = 0 ; //a3'_Darstellung 
		prm.f3_ch_ag4  = 0 ; //a4'_Darstellung  
		prm.f3_ch_am   = 1 ; //am_Darstellung
		prm.f3_ch_sd   = 0 ; //sd_Darstellung 
		prm.f3_ch_sdg  = 1 ; //sd'_Darstellung 
		prm.f3_ch_sga3 = 1 ; //s'a3_Darstellung  
		prm.f3_ch_sga4 = 0 ; //s'a4_Darstellung 
		prm.f3_ch_sgam = 0 ; //s'am_Darstellung

		prm.d1_hg_clr     = 656 ; //hintergrundfarbe
		prm.d1_K_clr      = 255 ; //funktionskurvenfarbe
		prm.d1_P_clr      = 255 ; //xypunktfarbe
		prm.d1_K_gr       = 2 ; //funktionskurvengrösse      
		prm.d1_P_gr       = 2 ; //xypunktgrösse
		prm.d1_schr_x_fn  = "Lucida Sans Unicode"; //schriftart funktionswerte x
		prm.d1_schr_x_H   = -8 ; //schriftgrösse H funktionswerte x
		prm.d1_schr_x_W   = 0 ; //schriftgrösse W funktionswerte x
		prm.d1_schr_x_clr = 255 ; //schriftfarbe funktionswerte x								         
		prm.d1_schr_y_fn  = "Lucida Sans Unicode"; //schriftart funktionswerte y
		prm.d1_schr_y_H   = -8 ; //schriftgrösse H funktionswerte y
		prm.d1_schr_y_W   = 0 ; //schriftgrösse W funktionswerte y
		prm.d1_schr_y_clr = 255 ; //schriftfarbe funktionswerte y								         
		prm.d1_K_art      = "Linie"; //funktionskurvenmodus  art
		prm.d1_P_art      = "eckig"; //xypunktmodus art

		prm.d2_X_clr      = 255 ; //x achsenfarbe
		prm.d2_Y_clr      = 255 ; //y achsenfarbe
		prm.d2_X_gr       = 1 ; //x achsengrösse
		prm.d2_Y_gr       = 1 ; //y achsengrösse
		prm.d2_ch_x       = 1 ; //x achsenbezeichnung(sw)
		prm.d2_ch_y       = 1 ; //y achsenbezeichnung(sw)
		prm.d2_Xgrid_gr   = 0 ; //x grid(sw)
		prm.d2_Ygrid_gr   = 0 ; //y grid(sw)
		prm.d2_schr_x_fn  = "Lucida Sans Unicode"; //schriftart achsenwerte x
		prm.d2_schr_x_H   = -8 ; //schriftgrösse H achsenwerte x
		prm.d2_schr_x_W   = 0 ; //schriftgrösse W achsenwerte x
		prm.d2_schr_x_clr = 255 ; //schriftfarbe achsenwerte x							          
		prm.d2_schr_y_fn  = "Lucida Sans Unicode"; //schriftart achsenwerte y
		prm.d2_schr_y_H   = -8 ; //schriftgrösse H achsenwerte y
		prm.d2_schr_y_W   = 0 ; //schriftgrösse W achsenwerte y
		prm.d2_schr_y_clr = 255 ; //schriftfarbe achsenwerte y 							           
		prm.d2_X_art    = "1"; //x achsenmodus art
		prm.d2_Y_art    = "1"; //y achsenmodus art
		prm.d2_Xgrid_art= "2"; //x gridmodus art
		prm.d2_Ygrid_art= "2"; //y gridmodus art
		prm.d2_Xgrid_clr  = 255 ; //x gridfarbe
		prm.d2_Ygrid_clr  = 255 ; //y gridfarbe

		prm.d3_Xv_clr     = 255 ; //x vektorfarbe
		prm.d3_Yv_clr     = 255 ; //y vektorfarbe
		prm.d3_X_gr       = 1 ; //x vektorgrösse
		prm.d3_Y_gr       = 1 ; //y vektorgrösse
		prm.d3_schr_x_fn  = "Lucida Sans Unicode";  //koordinatenschriftart
		prm.d3_schr_x_H   = -8 ;  //koordinatenschriftgrösse H
		prm.d3_schr_x_W   = 0 ; //koordinatenschriftgrösse W
		prm.d3_schr_x_clr = 255 ; //koordinatenschriftfarbe				                       
		prm.d3_X_art      = "Punkt"; //x vektormodus art
		prm.d3_Y_art      = "Punkt"; //y vektormodus art

		prm.d4_rxy_gr     = 1 ; //rxy_Linienbreite  
		prm.d4_ryx_gr     = 1 ; //ryx_Linienbreite
		prm.d4_srxy_gr    = 1 ; //srxy_Linienbreite
		prm.d4_sryx_gr    = 1 ; //sryx_Linienbreite
		prm.d4_srx_gr     = 1 ; //sry_Linienbreite
		prm.d4_sry_gr     = 1 ; //srx_Linienbreite
		prm.d4_sxy_gr     = 1 ; //sxy_Linienbreite
		prm.d4_syx_gr     = 1 ; //syx_Linienbreite
		prm.d4_s1xy_gr    = 1 ; //s'xy_Linienbreite
		prm.d4_s1yx_gr    = 1 ; //s'yx_Linienbreite
		prm.d4_rxy_clr    = 255 ; //rxy_Farbe 
		prm.d4_ryx_clr    = 255 ; //ryx_Farbe
		prm.d4_srxy_clr   = 255 ; //srxy_Farbe
		prm.d4_sryx_clr   = 255 ; //sryx_Farbe  
		prm.d4_srx_clr    = 255 ; //sry_Farbe
		prm.d4_sry_clr    = 255 ; //srx_Farbe 
		prm.d4_sxy_clr    = 255 ; //sxy_Farbe
		prm.d4_syx_clr    = 255 ; //syx_Farbe
		prm.d4_s1xy_clr   = 255 ; //s'xy_Farbe 
		prm.d4_s1yx_clr   = 255 ; //s'yx_Farbe
		prm.d4_rxy_art    = "1"; //rxy_Modus
		prm.d4_ryx_art    = "1"; //ryx_Modus
		prm.d4_srxy_art   = "2"; //srxy_Modus
		prm.d4_sryx_art   = "2"; //sryx_Modus
		prm.d4_srx_art    = "2"; //sry_Modus
		prm.d4_sry_art    = "2"; //srx_Modus
		prm.d4_sxy_art    = "1"; //sxy_Modus   
		prm.d4_syx_art    = "1"; //syx_Modus
		prm.d4_s1xy_art   = "3"; //s'xy_Modus
		prm.d4_s1yx_art   = "3"; //s'yx_Modus
		prm.d4_ch_rxy     = 1 ; //rxy_Theta_Darstellung 
		prm.d4_ch_ryx     = 1 ; //ryx_Theta_Darstellung  
		prm.d4_ch_syx     = 1 ; //syx_Theta_Darstellung
		prm.d4_ch_sxy     = 1 ; //sxy_Theta_Darstellung 
		prm.d4_ch_sgyx    = 1 ; //s'yx_Theta_Darstellung
		prm.d4_ch_sgxy    = 1 ; //s'xy_Theta_Darstellung
		prm.d4_ch_srxy    = 2 ; //srxy_Theta_Darstellung 
		prm.d4_ch_sryx    = 2 ; //sryx_Theta_Darstellung
		prm.d4_ch_srx     = 0 ; //srx_Theta_Darstellung
		prm.d4_ch_sry     = 0 ; //sry_Theta_Darstellung

		prm.d5_X_gr       = 1 ; //am_Linienbreite
		prm.d5_sd_gr      = 1 ; //sd_Linienbreite
		prm.d5_sgx_gr     = 1 ; //s'am_Linienbreite
		prm.d5_sdg_gr     = 1 ; //sd'_Linienbreite
		prm.d5_a3_gr      = 1 ; //a3_Linienbreite
		prm.d5_ag3_gr     = 1 ; //a3'_Linienbreite 
		prm.d5_sa3g_gr    = 1 ; //s'a3_Linienbreite  
		prm.d5_a4_gr      = 1 ; //a4_Linienbreite        
		prm.d5_ag4_gr     = 1 ; //a4'_Linienbreite     
		prm.d5_sa4g_gr    = 1 ; //s'a4_Linienbreite  
		prm.d5_Xp_clr     = 255 ; //am_Farbe 
		prm.d5_sd_clr     = 255 ; //sd_Farbe
		prm.d5_sgx_clr    = 255 ; //s'am_Farbe
		prm.d5_sdg_clr    = 255 ; //sd'_Farbe 
		prm.d5_a3_clr     = 255 ; //a3_Farbe 
		prm.d5_ag3_clr    = 255 ; //a3'_Farbe
		prm.d5_sa3g_clr   = 255 ; //s'a3_Farbe
		prm.d5_a4_clr     = 255 ; //a4_Farbe  
		prm.d5_ag4_clr    = 255 ; //a4'_Farbe  
		prm.d5_sa4g_clr   = 255 ; //s'a4_Farbe
		prm.d5_X_art      = "1"; //am_Modus 
		prm.d5_sd_art     = "1"; //sd_Modus  
		prm.d5_sgx_art    = "2"; //s'am_Modus 
		prm.d5_sdg_art    = "3"; //sd'_Modus        
		prm.d5_a3_art     = "1"; //a3_Modus   
		prm.d5_ag3_art    = "3"; //a3'_Modus
		prm.d5_sa3g_art   = "2"; //s'a3_Modus
		prm.d5_a4_art     = "1"; //a4_Modus  
		prm.d5_ag4_art    = "3"; //a4'_Modus 
		prm.d5_sa4g_art   = "2"; //s'a4_Modus 
		prm.d5_ch_x       = 1 ; //am_Theta_Darstellung 
		prm.d5_ch_s       = 1 ; //sd_Theta_Darstellung
		prm.d5_ch_sg      = 1 ; //sd'_Theta_Darstellung
		prm.d5_ch_sgx     = 2 ; //s'am_Theta_Darstellung
		prm.d5_ch_a3      = 2 ; //a3_Theta_Darstellung  
		prm.d5_ch_ag3     = 2 ; //a3'_Theta_Darstellung
		prm.d5_ch_sa3g    = 1 ; //s'a3_Theta_Darstellung
		prm.d5_ch_a4      = 2 ; //a4_Theta_Darstellung 
		prm.d5_ch_ag4     = 2 ; //a4'_Theta_Darstellung  
		prm.d5_ch_sa4g    = 1 ; //s'a4_Theta_Darstellung

		prm.d6_e_clr      = 255 ; //e_Farbe
		prm.d6_x_clr      = 255 ; //x_Farbe
		prm.d6_x0_clr     = 255 ; //x0_Farbe
		prm.d6_x1_clr     = 255 ; //x1_Farbe
		prm.d6_s0_clr     = 255 ; //s0_Farbe
		prm.d6_s1_clr     = 255 ; //s1_Farbe
		prm.d6_e_gr       = 1; //e_Linienbreite
		prm.d6_x_gr       = 1; //x_Linienbreite
		prm.d6_x0_gr      = 1; //x0_Linienbreite
		prm.d6_x1_gr      = 1; //x1_Linienbreite
		prm.d6_s0_gr      = 1; //s0_Linienbreite
		prm.d6_s1_gr      = 1; //s1_Linienbreite
		prm.d6_ch_e       = 1; //e_Theta_Darstellung 
		prm.d6_ch_x       = 1; //x_Theta_Darstellung
		prm.d6_ch_x0      = 1; //x0_Theta_Darstellung
		prm.d6_ch_x1      = 1; //x1_Theta_Darstellung
		prm.d6_ch_s0      = 1; //s0_Theta_Darstellung
		prm.d6_ch_s1      = 1; //s1_Theta_Darstellung
		prm.d6_e_art      = "Punkt"; //e_Modus
		prm.d6_x_art      = "Linie"; //x_Modus
		prm.d6_x0_art     = "Linie"; //x0_Modus
		prm.d6_x1_art     = "Linie"; //x1_Modus
		prm.d6_s0_art     = "Linie"; //s0_Modus
		prm.d6_s1_art     = "Linie"; //s1_Modus
	}
	if(m_schema=="Def1")
	{
	}
	if(m_schema=="Def2")
	{
	}
	if(m_schema=="Def3")
	{
	}
	if(m_schema=="Def4")
	{
	}

	if(sw==0)
	{
		CGRP2Dlg o;
				 o._FnKu(   prm.p1_sw_Fk ); //Kurve
				 o._xyPkt(  prm.p1_sw_xy ); //Punkte
				 o.xW_ds(   prm.p1_W_x   ); //x_Werte_Dezimalstellen
				 o.yW_ds(   prm.p1_W_y   ); //y_Werte_Dezimalstellen
				 o.x_scala( prm.p1_ch_x  ); //x_Beschriftung_Werte
				 o.y_scala( prm.p1_ch_y  ); //y_Beschriftung_Werte
				 o.x_minmax(prm.p1_ch_xm ); //x_Beschriftung_MinMax
				 o.y_minmax(prm.p1_ch_ym ); //y_Beschriftung_MinMax
				 o.posFXx_( prm.p1_fwxXd ); //X_Beschriftung_Werte_Position_x
				 o.posFXy_( prm.p1_fwyXd ); //X_Beschriftung_Werte_Position_y
				 o.posFYx_( prm.p1_fwxYd ); //Y_Beschriftung_Werte_Position_x
				 o.posFYy_( prm.p1_fwyYd ); //Y_Beschriftung_Werte_Position_y

				 o.x_Achse( prm.p2_ch_xA   ); //x_Achse
				 o.x_Achse( prm.p2_ch_yA   ); //y_Achse
				 o.x_Skala( prm.p2_ch_xS   ); //x_Skala
				 o.y_Skala( prm.p2_ch_yS   ); //y_Skala
				 o.x_Sw(    prm.p2_ch_xSw  ); //x_Skalenwerte
				 o.y_Sw(    prm.p2_ch_ySw  ); //y_Skalenwerte
				 o.xS_ds(   prm.p2_dez_S_x ); //x_Skalenwerte_Dezimalstellen
				 o.yS_ds(   prm.p2_dez_S_y ); //y_Skalenwerte_Dezimalstellen
				 o.x_Grid(  prm.p2_ch_xGrd ); //x_Grid
				 o.y_Grid(  prm.p2_ch_yGrd ); //y_Grid
				 o.x_tlg(   prm.p2_tlgx    ); //x_Skala_Teilung
				 o.y_tlg(   prm.p2_tlgy    ); //y_Skala_Teilung
				 o.posAXx_( prm.p2_swxXd   ); //X_Skalenwerte_Position_x
				 o.posAXy_( prm.p2_swyXd   ); //X_Skalenwerte_Position_y
				 o.posAYx_( prm.p2_swxYd   ); //Y_Skalenwerte_Position_x
				 o.posAYy_( prm.p2_swyYd   ); //Y_Skalenwerte_Position_y
  
				 o.x_Vektor(prm.p3_ch_xV   ); //x_Vektor
				 o.y_Vektor(prm.p3_ch_yV   ); //y_Vektor
				 o.x_Koor(  prm.p3_ch_xK   ); //x_Koordinate
				 o.y_Koor(  prm.p3_ch_yK   ); //y_Koordinate
				 o.xK_ds(   prm.p3_dez_K_x ); //x_Koordinaten_Dezimalstellen
				 o.yK_ds(   prm.p3_dez_K_y ); //y_Koordinaten_Dezimalstellen
				 o.x_kj(    prm.p3_kjx     ); //x_Justierung
				 o.y_kj(    prm.p3_kjy     ); //y_Justierung
				 o.posVx_(  prm.p3_kwx_d   ); //X_Vektor_Koordinaten_Position
				 o.posVy_(  prm.p3_kwy_d   ); //Y_Vektor_Koordinaten_Position

				 o.sc_(     prm.p4_sc      ); //Diagramm_Skalierung_1
				 o.sc_y(    prm.p4_scy     ); //Diagramm_Skalierung_2

				 o.CI_rxy(  prm.f2_CI      ); //rxy_CI
				 o.D_rxy(   prm.f2_ch_D    ); //rxy_Darstellung_überschnitten
				 o.r_rxy(   prm.f2_ch_rxy  ); //rxy_Darstellung
				 o.r_ryx(   prm.f2_ch_ryx  ); //ryx_Darstellung
				 o.r_sxy(   prm.f2_ch_sxy  ); //sxy_Darstellung
				 o.r_syx(   prm.f2_ch_syx  ); //syx_Darstellung
				 o.r_s1xy(  prm.f2_ch_s1xy ); //s'xy_Darstellung
				 o.r_s1yx(  prm.f2_ch_s1yx ); //s'yx_Darstellung
				 o.r_srxy(  prm.f2_ch_srxy ); //srxy_Darstellung
				 o.r_sryx(  prm.f2_ch_sryx ); //sryx_Darstellung
				 o.r_srx(   prm.f2_ch_srx  ); //srx_Darstellung
				 o.r_sry(   prm.f2_ch_sry  ); //sry_Darstellung

				 o.p_a3(    prm.f3_ch_a3   ); //a3_Darstellung 
				 o.p_a4(    prm.f3_ch_a4   ); //a4_Darstellung
				 o.p_ag3(   prm.f3_ch_ag3  ); //a3'_Darstellung 
				 o.p_ag4(   prm.f3_ch_ag4  ); //a4'_Darstellung  
				 o.p_am(    prm.f3_ch_am   ); //am_Darstellung
				 o.p_sd(    prm.f3_ch_sd   ); //sd_Darstellung 
				 o.p_sdg(   prm.f3_ch_sdg  ); //sd'_Darstellung 
				 o.p_sga3(  prm.f3_ch_sga3 ); //s'a3_Darstellung  
				 o.p_sga4(  prm.f3_ch_sga4 ); //s'a4_Darstellung 
				 o.p_sgam(  prm.f3_ch_sgam ); //s'am_Darstellung

				 o.clr_hg(   prm.d1_hg_clr     ); //hintergrundfarbe
				 o.clr_K(    prm.d1_K_clr      ); //funktionskurvenfarbe
				 o.clr_P(    prm.d1_P_clr      ); //xypunktfarbe
				 o.K_gr(     prm.d1_K_gr       ); //funktionskurvengrösse      
				 o.P_gr(     prm.d1_P_gr       ); //xypunktgrösse
				 o.fn_font_x(prm.d1_schr_x_fn,    //schriftart funktionswerte x
							 prm.d1_schr_x_H,     //schriftgrösse H funktionswerte x
							 prm.d1_schr_x_W,     //schriftgrösse W funktionswerte x
							 prm.d1_schr_x_clr    //schriftfarbe funktionswerte x
											   );
				 o.fn_font_y(prm.d1_schr_y_fn,    //schriftart funktionswerte y
							 prm.d1_schr_y_H,     //schriftgrösse H funktionswerte y
							 prm.d1_schr_y_W,     //schriftgrösse W funktionswerte y
							 prm.d1_schr_y_clr    //schriftfarbe funktionswerte y
											   );
				 o.K_art(    prm.d1_K_art      ); //funktionskurvenmodus  art
				 o.P_art(    prm.d1_P_art      ); //xypunktmodus art

				 o.clr_X(    prm.d2_X_clr      ); //x achsenfarbe
				 o.clr_Y(    prm.d2_Y_clr      ); //y achsenfarbe
				 o.X_gr(     prm.d2_X_gr       ); //x achsengrösse
				 o.Y_gr(     prm.d2_Y_gr       ); //y achsengrösse
				 o.X_bez(    prm.d2_ch_x       ); //x achsenbezeichnung(sw)
				 o.Y_bez(    prm.d2_ch_y       ); //y achsenbezeichnung(sw)
				 o.Xgrd_gr(  prm.d2_Xgrid_gr   ); //x grid(sw)
				 o.Ygrd_gr(  prm.d2_Ygrid_gr   ); //y grid(sw)
				 o.font_Ax(  prm.d2_schr_x_fn,    //schriftart achsenwerte x
							 prm.d2_schr_x_H,     //schriftgrösse H achsenwerte x
							 prm.d2_schr_x_W,     //schriftgrösse W achsenwerte x
							 prm.d2_schr_x_clr    //schriftfarbe achsenwerte x
											   );
				 o.font_Ay(  prm.d2_schr_y_fn,    //schriftart achsenwerte y
							 prm.d2_schr_y_H,     //schriftgrösse H achsenwerte y
							 prm.d2_schr_y_W,     //schriftgrösse W achsenwerte y
							 prm.d2_schr_y_clr    //schriftfarbe achsenwerte y 
											   );
				 o.X_art(    prm.d2_X_art      ); //x achsenmodus art
				 o.Y_art(    prm.d2_Y_art      ); //y achsenmodus art
				 o.X_gridart(prm.d2_Xgrid_art  ); //x gridmodus art
				 o.Y_gridart(prm.d2_Ygrid_art  ); //y gridmodus art
				 o.clr_Xgrd( prm.d2_Xgrid_clr  ); //x gridfarbe
				 o.clr_Ygrd( prm.d2_Ygrid_clr  ); //y gridfarbe

				 o.clr_Xv(   prm.d3_Xv_clr     ); //x vektorfarbe
				 o.clr_Yv(   prm.d3_Yv_clr     ); //y vektorfarbe
				 o.Xv_gr(    prm.d3_X_gr       ); //x vektorgrösse
				 o.Yv_gr(    prm.d3_Y_gr       ); //y vektorgrösse
				 o.font_V(   prm.d3_schr_x_fn,    //koordinatenschriftart
							 prm.d3_schr_x_H,     //koordinatenschriftgrösse H
							 prm.d3_schr_x_W,     //koordinatenschriftgrösse W
							 prm.d3_schr_x_clr    //koordinatenschriftfarbe
											   );
				 o.Xv_art(   prm.d3_X_art      ); //x vektormodus art
				 o.Yv_art(   prm.d3_Y_art      ); //y vektormodus art
				 
				 o.rxy_gr(   prm.d4_rxy_gr     ); //rxy_Linienbreite  
				 o.ryx_gr(   prm.d4_ryx_gr     ); //ryx_Linienbreite
				 o.srxy_gr(  prm.d4_srxy_gr    ); //srxy_Linienbreite
				 o.sryx_gr(  prm.d4_sryx_gr    ); //sryx_Linienbreite
				 o.srx_gr(   prm.d4_srx_gr     ); //sry_Linienbreite
				 o.sry_gr(   prm.d4_sry_gr     ); //srx_Linienbreite
				 o.sxy_gr(   prm.d4_sxy_gr     ); //sxy_Linienbreite
				 o.syx_gr(   prm.d4_syx_gr     ); //syx_Linienbreite
				 o.s1xy_gr(  prm.d4_s1xy_gr    ); //s'xy_Linienbreite
				 o.s1yx_gr(  prm.d4_s1yx_gr    ); //s'yx_Linienbreite
				 o.clr_rxy(  prm.d4_rxy_clr    ); //rxy_Farbe 
				 o.clr_ryx(  prm.d4_ryx_clr    ); //ryx_Farbe
				 o.clr_srxy( prm.d4_srxy_clr   ); //srxy_Farbe
		 		 o.clr_sryx( prm.d4_sryx_clr   ); //sryx_Farbe  
				 o.clr_srx(  prm.d4_srx_clr    ); //sry_Farbe
				 o.clr_sry(  prm.d4_sry_clr    ); //srx_Farbe 
				 o.clr_sxy(  prm.d4_sxy_clr    ); //sxy_Farbe
				 o.clr_syx(  prm.d4_syx_clr    ); //syx_Farbe
				 o.clr_s1xy( prm.d4_s1xy_clr   ); //s'xy_Farbe 
				 o.clr_s1yx( prm.d4_s1yx_clr   ); //s'yx_Farbe
				 o.rxy_art(  prm.d4_rxy_art    ); //rxy_Modus
				 o.ryx_art(  prm.d4_ryx_art    ); //ryx_Modus
				 o.srxy_art( prm.d4_srxy_art   ); //srxy_Modus
				 o.sryx_art( prm.d4_sryx_art   ); //sryx_Modus
				 o.srx_art(  prm.d4_srx_art    ); //sry_Modus
				 o.sry_art(  prm.d4_sry_art    ); //srx_Modus
				 o.sxy_art(  prm.d4_sxy_art    ); //sxy_Modus   
				 o.syx_art(  prm.d4_syx_art    ); //syx_Modus
				 o.s1xy_art( prm.d4_s1xy_art   ); //s'xy_Modus
				 o.s1yx_art( prm.d4_s1yx_art   ); //s'yx_Modus
				 o.q_rxy(    prm.d4_ch_rxy     ); //rxy_Theta_Darstellung 
				 o.q_ryx(    prm.d4_ch_ryx     ); //ryx_Theta_Darstellung  
				 o.q_syx(    prm.d4_ch_syx     ); //syx_Theta_Darstellung
				 o.q_sxy(    prm.d4_ch_sxy     ); //sxy_Theta_Darstellung 
				 o.q_sgyx(   prm.d4_ch_sgyx    ); //s'yx_Theta_Darstellung
				 o.q_sgxy(   prm.d4_ch_sgxy    ); //s'xy_Theta_Darstellung
				 o.q_srxy(   prm.d4_ch_srxy    ); //srxy_Theta_Darstellung 
				 o.q_sryx(   prm.d4_ch_sryx    ); //sryx_Theta_Darstellung
				 o.q_srx(    prm.d4_ch_srx     ); //srx_Theta_Darstellung
				 o.q_sry(    prm.d4_ch_sry     ); //sry_Theta_Darstellung

				 o.Xp_gr(    prm.d5_X_gr       ); //am_Linienbreite
				 o.sd_gr(    prm.d5_sd_gr      ); //sd_Linienbreite
				 o.sgx_gr(   prm.d5_sgx_gr     ); //s'am_Linienbreite
				 o.sdg_gr(   prm.d5_sdg_gr     ); //sd'_Linienbreite
				 o.a3_gr(    prm.d5_a3_gr      ); //a3_Linienbreite
				 o.ag3_gr(   prm.d5_ag3_gr     ); //a3'_Linienbreite 
				 o.sa3g_gr(  prm.d5_sa3g_gr    ); //s'a3_Linienbreite  
				 o.a4_gr(    prm.d5_a4_gr      ); //a4_Linienbreite        
				 o.ag4_gr(   prm.d5_ag4_gr     ); //a4'_Linienbreite     
				 o.sa4g_gr(  prm.d5_sa4g_gr    ); //s'a4_Linienbreite  
				 o.clr_Xp(   prm.d5_Xp_clr     ); //am_Farbe 
				 o.clr_sd(   prm.d5_sd_clr     ); //sd_Farbe
				 o.clr_sgx(  prm.d5_sgx_clr    ); //s'am_Farbe
				 o.clr_sdg(  prm.d5_sdg_clr    ); //sd'_Farbe 
				 o.clr_a3(   prm.d5_a3_clr     ); //a3_Farbe 
				 o.clr_ag3(  prm.d5_ag3_clr    ); //a3'_Farbe
				 o.clr_sa3g( prm.d5_sa3g_clr   ); //s'a3_Farbe
				 o.clr_a4(   prm.d5_a4_clr     ); //a4_Farbe  
				 o.clr_ag4(  prm.d5_ag4_clr    ); //a4'_Farbe  
				 o.clr_sa4g( prm.d5_sa4g_clr   ); //s'a4_Farbe
				 o.Xp_art(   prm.d5_X_art      ); //am_Modus 
				 o.sd_art(   prm.d5_sd_art     ); //sd_Modus  
				 o.sgx_art(  prm.d5_sgx_art    ); //s'am_Modus 
				 o.sdg_art(  prm.d5_sdg_art    ); //sd'_Modus        
				 o.a3_art(   prm.d5_a3_art     ); //a3_Modus   
				 o.ag3_art(  prm.d5_ag3_art    ); //a3'_Modus
				 o.sa3g_art( prm.d5_sa3g_art   ); //s'a3_Modus
				 o.a4_art(   prm.d5_a4_art     ); //a4_Modus  
				 o.ag4_art(  prm.d5_ag4_art    ); //a4'_Modus 
				 o.sa4g_art( prm.d5_sa4g_art   ); //s'a4_Modus 
				 o.q_am(     prm.d5_ch_x       ); //am_Theta_Darstellung 
				 o.q_sd(     prm.d5_ch_s       ); //sd_Theta_Darstellung
				 o.q_sdg(    prm.d5_ch_sg      ); //sd'_Theta_Darstellung
				 o.q_sgam(   prm.d5_ch_sgx     ); //s'am_Theta_Darstellung
				 o.q_a3(     prm.d5_ch_a3      ); //a3_Theta_Darstellung  
				 o.q_ag3(    prm.d5_ch_ag3     ); //a3'_Theta_Darstellung
				 o.q_sa3g(   prm.d5_ch_sa3g    ); //s'a3_Theta_Darstellung
				 o.q_a4(     prm.d5_ch_a4      ); //a4_Theta_Darstellung 
				 o.q_ag4(    prm.d5_ch_ag4     ); //a4'_Theta_Darstellung  
				 o.q_sa4g(   prm.d5_ch_sa4g    ); //s'a4_Theta_Darstellung	  

				 o.e_gr(     prm.d6_e_gr       ); //e_Farbe   
				 o.s0_gr(    prm.d6_s0_gr      ); //x_Farbe   
				 o.s1_gr(    prm.d6_s1_gr      ); //x0_Farbe   
				 o.xe_gr(    prm.d6_x_gr       ); //x1_Farbe   
				 o.x0_gr(    prm.d6_x0_gr      ); //s0_Farbe   
				 o.x1_gr(    prm.d6_x1_gr      ); //s1_Farbe   
				 o.e_art(    prm.d6_e_art      ); //e_Linienbreite
				 o.s0_art(   prm.d6_s0_art     ); //x_Linienbreite
				 o.s1_art(   prm.d6_s1_art     ); //x0_Linienbreite 
				 o.xe_art(   prm.d6_x_art      ); //x1_Linienbreite
				 o.x0_art(   prm.d6_x0_art     ); //s0_Linienbreite  
				 o.x1_art(   prm.d6_x1_art     ); //s1_Linienbreite  
				 o.clr_e(    prm.d6_e_clr      ); //e_Theta_Darstellung
				 o.clr_s0(   prm.d6_s0_clr     ); //x_Theta_Darstellung
				 o.clr_s1(   prm.d6_s1_clr     ); //x0_Theta_Darstellung
				 o.clr_xe(   prm.d6_x_clr      ); //x1_Theta_Darstellung
				 o.clr_x0(   prm.d6_x0_clr     ); //s0_Theta_Darstellung
				 o.clr_x1(   prm.d6_x1_clr     ); //s1_Theta_Darstellung
				 o.q_e(      prm.d6_ch_e       ); //e_Modus
				 o.q_s0(     prm.d6_ch_s0      ); //x_Modus
				 o.q_s1(     prm.d6_ch_s1      ); //x0_Modus
				 o.q_xe(     prm.d6_ch_x       ); //x1_Modus
				 o.q_x0(     prm.d6_ch_x0      ); //s0_Modus 
				 o.q_x1(     prm.d6_ch_x1      ); //s1_Modus
	}

	UpdateData(0);
}

void GRP2prg::OnCHECKini() {UpdateData(1);UpdateData(0);}

void GRP2prg::OnOK() 
{
	CGRP2Dlg o;
		     o.rnd_dyn(m_ch_dnr);
			 o.rnd_fsr(m_ch_fsr);
			 o.w_pos_(m_ch_wnd_pos);
			 o.csr_sw(m_ch_csr);
				                                     CRect coord;
	                                        GetWindowRect(&coord); 
	
	                                       CWinApp* pApp = AfxGetApp(); // ini profil schreiben  
	if(m_ch_ini)
	{
												    pApp->WriteProfileInt("Programm","Dynamisch_rendern",m_ch_dnr);
												    pApp->WriteProfileInt("Programm","Filestream_rendern",m_ch_fsr);
												    pApp->WriteProfileInt("Programm","Splash",m_ch_splash);
												    pApp->WriteProfileInt("Programm","Fensterposition_speichern",m_ch_wnd_pos);
												    pApp->WriteProfileInt("Programm","Logfile",m_ch_log);
												    pApp->WriteProfileInt("Programm","Cursor",m_ch_csr);
												    pApp->WriteProfileString("Programm","Schema",m_schema);

												    pApp->WriteProfileInt("Funktion","Kurve",prm.p1_sw_Fk);
												    pApp->WriteProfileInt("Funktion","Punkte",prm.p1_sw_xy);
												    pApp->WriteProfileInt("Achsen","x_Werte_Dezimalstellen",prm.p1_W_x);
												    pApp->WriteProfileInt("Achsen","y_Werte_Dezimalstellen",prm.p1_W_y);
												    pApp->WriteProfileInt("Achsen","x_Beschriftung_Werte",prm.p1_ch_x);
												    pApp->WriteProfileInt("Achsen","y_Beschriftung_Werte",prm.p1_ch_y);
												    pApp->WriteProfileInt("Achsen","x_Beschriftung_MinMax",prm.p1_ch_xm);
												    pApp->WriteProfileInt("Achsen","y_Beschriftung_MinMax",prm.p1_ch_ym);
												    pApp->WriteProfileInt("Achsen","X_Beschriftung_Werte_Position_x",prm.p1_fwxXd);
												    pApp->WriteProfileInt("Achsen","X_Beschriftung_Werte_Position_y",prm.p1_fwyXd);
												    pApp->WriteProfileInt("Achsen","Y_Beschriftung_Werte_Position_x",prm.p1_fwxYd);
												    pApp->WriteProfileInt("Achsen","Y_Beschriftung_Werte_Position_y",prm.p1_fwyYd);

												    pApp->WriteProfileInt("Achsen","x_",prm.p2_ch_xA);
												    pApp->WriteProfileInt("Achsen","y_",prm.p2_ch_yA);
												    pApp->WriteProfileInt("Achsen","x_Skala",prm.p2_ch_xS);
												    pApp->WriteProfileInt("Achsen","y_Skala",prm.p2_ch_yS);
												    pApp->WriteProfileInt("Achsen","x_Skalenwerte",prm.p2_ch_xSw);
												    pApp->WriteProfileInt("Achsen","y_Skalenwerte",prm.p2_ch_ySw);
												    pApp->WriteProfileInt("Achsen","x_Skalenwerte_Dezimalstellen",prm.p2_dez_S_x);
												    pApp->WriteProfileInt("Achsen","y_Skalenwerte_Dezimalstellen",prm.p2_dez_S_y);
												    pApp->WriteProfileString("Achsen","x_Skala_Teilung",prm.p2_tlgx);
												    pApp->WriteProfileString("Achsen","y_Skala_Teilung",prm.p2_tlgy);
												    pApp->WriteProfileInt("Achsen","x_Grid",prm.p2_ch_xGrd);
												    pApp->WriteProfileInt("Achsen","y_Grid",prm.p2_ch_yGrd);
												    pApp->WriteProfileInt("Achsen","X_Skalenwerte_Position_x",prm.p2_swxXd);
												    pApp->WriteProfileInt("Achsen","X_Skalenwerte_Position_y",prm.p2_swyXd);
												    pApp->WriteProfileInt("Achsen","Y_Skalenwerte_Position_x",prm.p2_swxYd);
												    pApp->WriteProfileInt("Achsen","Y_Skalenwerte_Position_y",prm.p2_swyYd);

												    pApp->WriteProfileInt("Achsen","x_Vektor",prm.p3_ch_xV);
												    pApp->WriteProfileInt("Achsen","y_Vektor",prm.p3_ch_yV);
												    pApp->WriteProfileInt("Achsen","x_Koordinate",prm.p3_ch_xK);
												    pApp->WriteProfileInt("Achsen","y_Koordinate",prm.p3_ch_yK);
												    pApp->WriteProfileInt("Achsen","x_Koordinaten_Dezimalstellen",prm.p3_dez_K_x);
												    pApp->WriteProfileInt("Achsen","y_Koordinaten_Dezimalstellen",prm.p3_dez_K_y);
												    pApp->WriteProfileString("Achsen","x_Justierung",prm.p3_kjx);
												    pApp->WriteProfileString("Achsen","y_Justierung",prm.p3_kjy);
												    pApp->WriteProfileInt("Achsen","X_Vektor_Koordinaten_Position",prm.p3_kwx_d);
												    pApp->WriteProfileInt("Achsen","Y_Vektor_Koordinaten_Position",prm.p3_kwy_d);

												    pApp->WriteProfileString("Dialog","Diagramm_Skalierung_1",prm.p4_sc);
												    pApp->WriteProfileString("Dialog","Diagramm_Skalierung_2",prm.p4_scy);

												    pApp->WriteProfileString("Funktion","rxy_CI",ftoc(prm.f2_CI,3));
												    pApp->WriteProfileInt("Funktion","rxy_Darstellung_überschnitten",prm.f2_ch_D);
												    pApp->WriteProfileInt("Funktion","rxy_Darstellung",prm.f2_ch_rxy);
												    pApp->WriteProfileInt("Funktion","ryx_Darstellung",prm.f2_ch_ryx);
												    pApp->WriteProfileInt("Funktion","sxy_Darstellung",prm.f2_ch_sxy);
												    pApp->WriteProfileInt("Funktion","syx_Darstellung",prm.f2_ch_syx);
												    pApp->WriteProfileInt("Funktion","s'xy_Darstellung",prm.f2_ch_s1xy);
												    pApp->WriteProfileInt("Funktion","s'yx_Darstellung",prm.f2_ch_s1yx);
												    pApp->WriteProfileInt("Funktion","srxy_Darstellung",prm.f2_ch_srxy);
												    pApp->WriteProfileInt("Funktion","sryx_Darstellung",prm.f2_ch_sryx);
												    pApp->WriteProfileInt("Funktion","srx_Darstellung",prm.f2_ch_srx);
												    pApp->WriteProfileInt("Funktion","sry_Darstellung",prm.f2_ch_sry);

												    pApp->WriteProfileInt("Funktion","aprm.f3_Darstellung",prm.f3_ch_am);
												    pApp->WriteProfileInt("Funktion","sd_Darstellung",prm.f3_ch_sd);
												    pApp->WriteProfileInt("Funktion","sd'_Darstellung",prm.f3_ch_sdg);
												    pApp->WriteProfileInt("Funktion","s'aprm.f3_Darstellung",prm.f3_ch_sgam);
												    pApp->WriteProfileInt("Funktion","a3_Darstellung",prm.f3_ch_a3);
												    pApp->WriteProfileInt("Funktion","a4_Darstellung",prm.f3_ch_a4);
												    pApp->WriteProfileInt("Funktion","a3'_Darstellung",prm.f3_ch_ag3);
												    pApp->WriteProfileInt("Funktion","a4'_Darstellung",prm.f3_ch_ag4);
												    pApp->WriteProfileInt("Funktion","s'a3_Darstellung",prm.f3_ch_sga3);
												    pApp->WriteProfileInt("Funktion","s'a4_Darstellung",prm.f3_ch_sga4);

												    pApp->WriteProfileInt("Diagramm","Hintergrundfarbe",prm.d1_hg_clr);
												    pApp->WriteProfileInt("Funktion","Linienfarbe",prm.d1_K_clr);
												    pApp->WriteProfileInt("Funktion","Punktfarbe",prm.d1_P_clr);
												    pApp->WriteProfileInt("Funktion","Kurvenlinienbreite",prm.d1_K_gr);
												    pApp->WriteProfileInt("Funktion","Punktbreite",prm.d1_P_gr);
												    pApp->WriteProfileString("Schriftart","Funktion_x",prm.d1_schr_x_fn);
												    pApp->WriteProfileString("Schriftart","Funktion_y",prm.d1_schr_y_fn);
												    pApp->WriteProfileInt("Schriftart","Farbe_Funktion_x",prm.d1_schr_x_clr);
												    pApp->WriteProfileInt("Schriftart","Farbe_Funktion_y",prm.d1_schr_y_clr);
												    pApp->WriteProfileInt("Schriftart","Höhe_Funktion_x",prm.d1_schr_x_H);
												    pApp->WriteProfileInt("Schriftart","Höhe_Funktion_y",prm.d1_schr_y_H);
												    pApp->WriteProfileInt("Schriftart","Breite_Funktion_x",prm.d1_schr_x_W);
												    pApp->WriteProfileInt("Schriftart","Breite_Funktion_y",prm.d1_schr_y_W);
			if(prm.d1_K_art=="Linie")               pApp->WriteProfileInt("Funktion","Kurvenmodus",1);
			if(prm.d1_K_art=="Punkt")               pApp->WriteProfileInt("Funktion","Kurvenmodus",2);
			if(prm.d1_K_art=="Strich")              pApp->WriteProfileInt("Funktion","Kurvenmodus",3);
			if(prm.d1_K_art=="Strichpunkt")         pApp->WriteProfileInt("Funktion","Kurvenmodus",4);
			if(prm.d1_K_art=="Strichdoppelpkt.")    pApp->WriteProfileInt("Funktion","Kurvenmodus",5);
			if(prm.d1_P_art=="rund")                pApp->WriteProfileInt("Funktion","Punktmodus",1);
			if(prm.d1_P_art=="eckig")               pApp->WriteProfileInt("Funktion","Punktmodus",2);
			if(prm.d1_P_art=="Kreuz")               pApp->WriteProfileInt("Funktion","Punktmodus",3);

													pApp->WriteProfileInt("Achsen","X_Farbe",prm.d2_X_clr);
													pApp->WriteProfileInt("Achsen","Y_Farbe",prm.d2_Y_clr);
													pApp->WriteProfileInt("Achsen","X_Grid_Farbe",prm.d2_Xgrid_clr);
													pApp->WriteProfileInt("Achsen","Y_Grid_Farbe",prm.d2_Ygrid_clr);
													pApp->WriteProfileInt("Achsen","X_Linienbreite",prm.d2_X_gr);
													pApp->WriteProfileInt("Achsen","Y_Linienbreite",prm.d2_Y_gr);
													pApp->WriteProfileInt("Achsen","X_Grid_Linienbreite",prm.d2_Xgrid_gr);
													pApp->WriteProfileInt("Achsen","Y_Grid_Linienbreite",prm.d2_Ygrid_gr);
													pApp->WriteProfileInt("Achsen","X_Bezeichnung",prm.d2_ch_x);
													pApp->WriteProfileInt("Achsen","Y_Bezeichnung",prm.d2_ch_y);
													pApp->WriteProfileString("Schriftart","Achsen_x",prm.d2_schr_x_fn);
													pApp->WriteProfileString("Schriftart","Achsen_y",prm.d2_schr_y_fn);
													pApp->WriteProfileInt("Schriftart","Farbe_Achsen_x",prm.d2_schr_x_clr);
													pApp->WriteProfileInt("Schriftart","Farbe_Achsen_y",prm.d2_schr_y_clr);
													pApp->WriteProfileInt("Schriftart","Höhe_Achsen_x",prm.d2_schr_x_H);
													pApp->WriteProfileInt("Schriftart","Höhe_Achsen_y",prm.d2_schr_y_H);
													pApp->WriteProfileInt("Schriftart","Breite_Achsen_x",prm.d2_schr_x_W);
													pApp->WriteProfileInt("Schriftart","Breite_Achsen_y",prm.d2_schr_y_W);
			if(prm.d2_X_art=="Linie")               pApp->WriteProfileInt("Achsen","X_Modus",1);
			if(prm.d2_X_art=="Punkt")               pApp->WriteProfileInt("Achsen","X_Modus",2);
			if(prm.d2_X_art=="Strich")              pApp->WriteProfileInt("Achsen","X_Modus",3);
			if(prm.d2_X_art=="Strichpunkt")         pApp->WriteProfileInt("Achsen","X_Modus",4);
			if(prm.d2_X_art=="Strichdoppelpkt.")    pApp->WriteProfileInt("Achsen","X_Modus",5);
			if(prm.d2_Y_art=="Linie")               pApp->WriteProfileInt("Achsen","Y_Modus",1);
			if(prm.d2_Y_art=="Punkt")               pApp->WriteProfileInt("Achsen","Y_Modus",2);
			if(prm.d2_Y_art=="Strich")              pApp->WriteProfileInt("Achsen","Y_Modus",3);
			if(prm.d2_Y_art=="Strichpunkt")         pApp->WriteProfileInt("Achsen","Y_Modus",4);
			if(prm.d2_Y_art=="Strichdoppelpkt.")    pApp->WriteProfileInt("Achsen","Y_Modus",5);
			if(prm.d2_Xgrid_art=="Linie")           pApp->WriteProfileInt("Achsen","X_Grid_Modus",1);
			if(prm.d2_Xgrid_art=="Punkt")           pApp->WriteProfileInt("Achsen","X_Grid_Modus",2);
			if(prm.d2_Xgrid_art=="Strich")          pApp->WriteProfileInt("Achsen","X_Grid_Modus",3);
			if(prm.d2_Xgrid_art=="Strichpunkt")     pApp->WriteProfileInt("Achsen","X_Grid_Modus",4);
			if(prm.d2_Xgrid_art=="Strichdoppelpkt.")pApp->WriteProfileInt("Achsen","X_Grid_Modus",5);
			if(prm.d2_Ygrid_art=="Linie")           pApp->WriteProfileInt("Achsen","Y_Grid_Modus",1);
			if(prm.d2_Ygrid_art=="Punkt")           pApp->WriteProfileInt("Achsen","Y_Grid_Modus",2);
			if(prm.d2_Ygrid_art=="Strich")          pApp->WriteProfileInt("Achsen","Y_Grid_Modus",3);
			if(prm.d2_Ygrid_art=="Strichpunkt")     pApp->WriteProfileInt("Achsen","Y_Grid_Modus",4);
			if(prm.d2_Ygrid_art=="Strichdoppelpkt.")pApp->WriteProfileInt("Achsen","Y_Grid_Modus",5);

											        pApp->WriteProfileInt("Achsen","X_Vektor_Farbe",prm.d3_Xv_clr);
											        pApp->WriteProfileInt("Achsen","Y_Vektor_Farbe",prm.d3_Yv_clr);
											        pApp->WriteProfileInt("Achsen","X_Vektor_Linienbreite",prm.d3_X_gr);
											        pApp->WriteProfileInt("Achsen","Y_Vektor_Linienbreite",prm.d3_Y_gr);
											        pApp->WriteProfileString("Schriftart","Vektor",prm.d3_schr_x_fn);
											        pApp->WriteProfileInt("Schriftart","Farbe_Vektor",prm.d3_schr_x_clr);
											        pApp->WriteProfileInt("Schriftart","Höhe_Vektor",prm.d3_schr_x_H);
											        pApp->WriteProfileInt("Schriftart","Breite_Vektor",prm.d3_schr_x_W);
			if(prm.d3_X_art=="Linie")               pApp->WriteProfileInt("Achsen","X_Vektor_Modus",1);
			if(prm.d3_X_art=="Punkt")               pApp->WriteProfileInt("Achsen","X_Vektor_Modus",2);
			if(prm.d3_X_art=="Strich")              pApp->WriteProfileInt("Achsen","X_Vektor_Modus",3);
			if(prm.d3_X_art=="Strichpunkt")         pApp->WriteProfileInt("Achsen","X_Vektor_Modus",4);
			if(prm.d3_X_art=="Strichdoppelpkt.")    pApp->WriteProfileInt("Achsen","X_Vektor_Modus",5);
			if(prm.d3_Y_art=="Linie")               pApp->WriteProfileInt("Achsen","Y_Vektor_Modus",1);
			if(prm.d3_Y_art=="Punkt")               pApp->WriteProfileInt("Achsen","Y_Vektor_Modus",2);
			if(prm.d3_Y_art=="Strich")              pApp->WriteProfileInt("Achsen","Y_Vektor_Modus",3);
			if(prm.d3_Y_art=="Strichpunkt")         pApp->WriteProfileInt("Achsen","Y_Vektor_Modus",4);
			if(prm.d3_Y_art=="Strichdoppelpkt.")    pApp->WriteProfileInt("Achsen","Y_Vektor_Modus",5);

													pApp->WriteProfileInt("Funktion","rxy_Linienbreite",prm.d4_rxy_gr);
													pApp->WriteProfileInt("Funktion","ryx_Linienbreite",prm.d4_ryx_gr);
													pApp->WriteProfileInt("Funktion","srxy_Linienbreite",prm.d4_srxy_gr);
													pApp->WriteProfileInt("Funktion","sryx_Linienbreite",prm.d4_sryx_gr);
													pApp->WriteProfileInt("Funktion","srx_Linienbreite",prm.d4_srx_gr);
													pApp->WriteProfileInt("Funktion","sry_Linienbreite",prm.d4_sry_gr);
													pApp->WriteProfileInt("Funktion","sxy_Linienbreite",prm.d4_sxy_gr);
													pApp->WriteProfileInt("Funktion","syx_Linienbreite",prm.d4_syx_gr);
													pApp->WriteProfileInt("Funktion","s'xy_Linienbreite",prm.d4_s1xy_gr);
													pApp->WriteProfileInt("Funktion","s'yx_Linienbreite",prm.d4_s1yx_gr);
													pApp->WriteProfileInt("Funktion","rxy_Farbe",prm.d4_rxy_clr);
													pApp->WriteProfileInt("Funktion","ryx_Farbe",prm.d4_ryx_clr);
													pApp->WriteProfileInt("Funktion","srxy_Farbe",prm.d4_srxy_clr);
													pApp->WriteProfileInt("Funktion","sryx_Farbe",prm.d4_sryx_clr);
													pApp->WriteProfileInt("Funktion","sry_Farbe",prm.d4_srx_clr);
													pApp->WriteProfileInt("Funktion","srx_Farbe",prm.d4_sry_clr);
													pApp->WriteProfileInt("Funktion","sxy_Farbe",prm.d4_sxy_clr);
													pApp->WriteProfileInt("Funktion","syx_Farbe",prm.d4_syx_clr);
													pApp->WriteProfileInt("Funktion","s'xy_Farbe",prm.d4_s1xy_clr);
													pApp->WriteProfileInt("Funktion","s'yx_Farbe",prm.d4_s1yx_clr);
			if(prm.d4_rxy_art=="Linie")             pApp->WriteProfileInt("Funktion","rxy_Modus",1);
			if(prm.d4_rxy_art=="Punkt")             pApp->WriteProfileInt("Funktion","rxy_Modus",2);
			if(prm.d4_rxy_art=="Strich")            pApp->WriteProfileInt("Funktion","rxy_Modus",3);
			if(prm.d4_rxy_art=="Strichpunkt")       pApp->WriteProfileInt("Funktion","rxy_Modus",4);
			if(prm.d4_rxy_art=="Strichdoppelpkt.")  pApp->WriteProfileInt("Funktion","rxy_Modus",5);
			if(prm.d4_ryx_art=="Linie")             pApp->WriteProfileInt("Funktion","ryx_Modus",1);
			if(prm.d4_ryx_art=="Punkt")             pApp->WriteProfileInt("Funktion","ryx_Modus",2);
			if(prm.d4_ryx_art=="Strich")            pApp->WriteProfileInt("Funktion","ryx_Modus",3);
			if(prm.d4_ryx_art=="Strichpunkt")       pApp->WriteProfileInt("Funktion","ryx_Modus",4);
			if(prm.d4_ryx_art=="Strichdoppelpkt.")  pApp->WriteProfileInt("Funktion","ryx_Modus",5);
			if(prm.d4_srxy_art=="Linie")            pApp->WriteProfileInt("Funktion","srxy_Modus",1);
			if(prm.d4_srxy_art=="Punkt")            pApp->WriteProfileInt("Funktion","srxy_Modus",2);
			if(prm.d4_srxy_art=="Strich")           pApp->WriteProfileInt("Funktion","srxy_Modus",3);
			if(prm.d4_srxy_art=="Strichpunkt")      pApp->WriteProfileInt("Funktion","srxy_Modus",4);
			if(prm.d4_srxy_art=="Strichdoppelpkt.") pApp->WriteProfileInt("Funktion","srxy_Modus",5);
			if(prm.d4_sryx_art=="Linie")            pApp->WriteProfileInt("Funktion","sryx_Modus",1);
			if(prm.d4_sryx_art=="Punkt")            pApp->WriteProfileInt("Funktion","sryx_Modus",2);
			if(prm.d4_sryx_art=="Strich")           pApp->WriteProfileInt("Funktion","sryx_Modus",3);
			if(prm.d4_sryx_art=="Strichpunkt")      pApp->WriteProfileInt("Funktion","sryx_Modus",4);
			if(prm.d4_sryx_art=="Strichdoppelpkt.") pApp->WriteProfileInt("Funktion","sryx_Modus",5);
			if(prm.d4_srx_art=="Linie")             pApp->WriteProfileInt("Funktion","srx_Modus",1);
			if(prm.d4_srx_art=="Punkt")             pApp->WriteProfileInt("Funktion","srx_Modus",2);
			if(prm.d4_srx_art=="Strich")            pApp->WriteProfileInt("Funktion","srx_Modus",3);
			if(prm.d4_srx_art=="Strichpunkt")       pApp->WriteProfileInt("Funktion","srx_Modus",4);
			if(prm.d4_srx_art=="Strichdoppelpkt.")  pApp->WriteProfileInt("Funktion","srx_Modus",5);
			if(prm.d4_sry_art=="Linie")             pApp->WriteProfileInt("Funktion","sry_Modus",1);
			if(prm.d4_sry_art=="Punkt")             pApp->WriteProfileInt("Funktion","sry_Modus",2);
			if(prm.d4_sry_art=="Strich")            pApp->WriteProfileInt("Funktion","sry_Modus",3);
			if(prm.d4_sry_art=="Strichpunkt")       pApp->WriteProfileInt("Funktion","sry_Modus",4);
			if(prm.d4_sry_art=="Strichdoppelpkt.")  pApp->WriteProfileInt("Funktion","sry_Modus",5);
			if(prm.d4_sxy_art=="Linie")             pApp->WriteProfileInt("Funktion","sxy_Modus",1);
			if(prm.d4_sxy_art=="Punkt")             pApp->WriteProfileInt("Funktion","sxy_Modus",2);
			if(prm.d4_sxy_art=="Strich")            pApp->WriteProfileInt("Funktion","sxy_Modus",3);
			if(prm.d4_sxy_art=="Strichpunkt")       pApp->WriteProfileInt("Funktion","sxy_Modus",4);
			if(prm.d4_sxy_art=="Strichdoppelpkt.")  pApp->WriteProfileInt("Funktion","sxy_Modus",5);
			if(prm.d4_syx_art=="Linie")             pApp->WriteProfileInt("Funktion","syx_Modus",1);
			if(prm.d4_syx_art=="Punkt")             pApp->WriteProfileInt("Funktion","syx_Modus",2);
			if(prm.d4_syx_art=="Strich")            pApp->WriteProfileInt("Funktion","syx_Modus",3);
			if(prm.d4_syx_art=="Strichpunkt")       pApp->WriteProfileInt("Funktion","syx_Modus",4);
			if(prm.d4_syx_art=="Strichdoppelpkt.")  pApp->WriteProfileInt("Funktion","syx_Modus",5);
			if(prm.d4_s1xy_art=="Linie")            pApp->WriteProfileInt("Funktion","s'xy_Modus",1);
			if(prm.d4_s1xy_art=="Punkt")            pApp->WriteProfileInt("Funktion","s'xy_Modus",2);
			if(prm.d4_s1xy_art=="Strich")           pApp->WriteProfileInt("Funktion","s'xy_Modus",3);
			if(prm.d4_s1xy_art=="Strichpunkt")      pApp->WriteProfileInt("Funktion","s'xy_Modus",4);
			if(prm.d4_s1xy_art=="Strichdoppelpkt.") pApp->WriteProfileInt("Funktion","s'xy_Modus",5);
			if(prm.d4_s1yx_art=="Linie")            pApp->WriteProfileInt("Funktion","s'yx_Modus",1);
			if(prm.d4_s1yx_art=="Punkt")            pApp->WriteProfileInt("Funktion","s'yx_Modus",2);
			if(prm.d4_s1yx_art=="Strich")           pApp->WriteProfileInt("Funktion","s'yx_Modus",3);
			if(prm.d4_s1yx_art=="Strichpunkt")      pApp->WriteProfileInt("Funktion","s'yx_Modus",4);
			if(prm.d4_s1yx_art=="Strichdoppelpkt.") pApp->WriteProfileInt("Funktion","s'yx_Modus",5);	
												    pApp->WriteProfileInt("Funktion","rxy_Theta_Darstellung",prm.d4_ch_rxy);
												    pApp->WriteProfileInt("Funktion","ryx_Theta_Darstellung",prm.d4_ch_ryx); 
												    pApp->WriteProfileInt("Funktion","syx_Theta_Darstellung",prm.d4_ch_syx); 
												    pApp->WriteProfileInt("Funktion","sxy_Theta_Darstellung",prm.d4_ch_sxy); 
												    pApp->WriteProfileInt("Funktion","s'yx_Theta_Darstellung",prm.d4_ch_sgyx);
												    pApp->WriteProfileInt("Funktion","s'xy_Theta_Darstellung",prm.d4_ch_sgxy); 
												    pApp->WriteProfileInt("Funktion","srxy_Theta_Darstellung",prm.d4_ch_srxy); 
												    pApp->WriteProfileInt("Funktion","sryx_Theta_Darstellung",prm.d4_ch_sryx); 
												    pApp->WriteProfileInt("Funktion","srx_Theta_Darstellung",prm.d4_ch_srx );
												    pApp->WriteProfileInt("Funktion","sry_Theta_Darstellung",prm.d4_ch_sry);

											        pApp->WriteProfileInt("Funktion","am_Linienbreite",prm.d5_X_gr);
												    pApp->WriteProfileInt("Funktion","sd_Linienbreite",prm.d5_sd_gr);
												    pApp->WriteProfileInt("Funktion","s'am_Linienbreite",prm.d5_sgx_gr);
												    pApp->WriteProfileInt("Funktion","sd'_Linienbreite",prm.d5_sdg_gr);
											  	    pApp->WriteProfileInt("Funktion","a3_Linienbreite",prm.d5_a3_gr);
												    pApp->WriteProfileInt("Funktion","a3'_Linienbreite",prm.d5_ag3_gr);
											        pApp->WriteProfileInt("Funktion","s'a3_Linienbreite",prm.d5_sa3g_gr );
												    pApp->WriteProfileInt("Funktion","a4_Linienbreite",prm.d5_a4_gr);
												    pApp->WriteProfileInt("Funktion","a4'_Linienbreite",prm.d5_ag4_gr );
												    pApp->WriteProfileInt("Funktion","s'a4_Linienbreite", prm.d5_sa4g_gr);
												    pApp->WriteProfileInt("Funktion","am_Farbe",prm.d5_Xp_clr);
												    pApp->WriteProfileInt("Funktion","sd_Farbe",prm.d5_sd_clr);
												    pApp->WriteProfileInt("Funktion","s'am_Farbe",prm.d5_sgx_clr );
												    pApp->WriteProfileInt("Funktion","sd'_Farbe",prm.d5_sdg_clr );
												    pApp->WriteProfileInt("Funktion","a3_Farbe",prm.d5_a3_clr);
												    pApp->WriteProfileInt("Funktion","a3'_Farbe",prm.d5_ag3_clr );
												    pApp->WriteProfileInt("Funktion","s'a3_Farbe",prm.d5_sa3g_clr);
												    pApp->WriteProfileInt("Funktion","a4_Farbe",prm.d5_a4_clr );
												    pApp->WriteProfileInt("Funktion","a4'_Farbe",prm.d5_ag4_clr);
												    pApp->WriteProfileInt("Funktion","s'a4_Farbe",prm.d5_sa4g_clr );	
			if(prm.d5_X_art=="Linie")               pApp->WriteProfileInt("Funktion","am_Modus",1);
			if(prm.d5_X_art=="Punkt")               pApp->WriteProfileInt("Funktion","am_Modus",2);
			if(prm.d5_X_art=="Strich")              pApp->WriteProfileInt("Funktion","am_Modus",3);
			if(prm.d5_X_art=="Strichpunkt")         pApp->WriteProfileInt("Funktion","am_Modus",4);
			if(prm.d5_X_art=="Strichdoppelpkt.")    pApp->WriteProfileInt("Funktion","am_Modus",5);
			if(prm.d5_sd_art=="Linie")              pApp->WriteProfileInt("Funktion","sd_Modus",1);
			if(prm.d5_sd_art=="Punkt")              pApp->WriteProfileInt("Funktion","sd_Modus",2);
			if(prm.d5_sd_art=="Strich")             pApp->WriteProfileInt("Funktion","sd_Modus",3);
			if(prm.d5_sd_art=="Strichpunkt")        pApp->WriteProfileInt("Funktion","sd_Modus",4);
			if(prm.d5_sd_art=="Strichdoppelpkt.")   pApp->WriteProfileInt("Funktion","sd_Modus",5);
			if(prm.d5_sgx_art=="Linie")             pApp->WriteProfileInt("Funktion","s'am_Modus",1);
			if(prm.d5_sgx_art=="Punkt")             pApp->WriteProfileInt("Funktion","s'am_Modus",2);
			if(prm.d5_sgx_art=="Strich")            pApp->WriteProfileInt("Funktion","s'am_Modus",3);
			if(prm.d5_sgx_art=="Strichpunkt")       pApp->WriteProfileInt("Funktion","s'am_Modus",4);
			if(prm.d5_sgx_art=="Strichdoppelpkt.")  pApp->WriteProfileInt("Funktion","s'am_Modus",5);
			if(prm.d5_sdg_art=="Linie")             pApp->WriteProfileInt("Funktion","sd'_Modus",1);
			if(prm.d5_sdg_art=="Punkt")             pApp->WriteProfileInt("Funktion","sd'_Modus",2);
			if(prm.d5_sdg_art=="Strich")            pApp->WriteProfileInt("Funktion","sd'_Modus",3);
			if(prm.d5_sdg_art=="Strichpunkt")       pApp->WriteProfileInt("Funktion","sd'_Modus",4);
			if(prm.d5_sdg_art=="Strichdoppelpkt.")  pApp->WriteProfileInt("Funktion","sd'_Modus",5);
			if(prm.d5_a3_art=="Linie")              pApp->WriteProfileInt("Funktion","a3_Modus",1);
			if(prm.d5_a3_art=="Punkt")              pApp->WriteProfileInt("Funktion","a3_Modus",2);
			if(prm.d5_a3_art=="Strich")             pApp->WriteProfileInt("Funktion","a3_Modus",3);
			if(prm.d5_a3_art=="Strichpunkt")        pApp->WriteProfileInt("Funktion","a3_Modus",4);
			if(prm.d5_a3_art=="Strichdoppelpkt.")   pApp->WriteProfileInt("Funktion","a3_Modus",5);
			if(prm.d5_ag3_art=="Linie")             pApp->WriteProfileInt("Funktion","a3'_Modus",1);
			if(prm.d5_ag3_art=="Punkt")             pApp->WriteProfileInt("Funktion","a3'_Modus",2);
			if(prm.d5_ag3_art=="Strich")            pApp->WriteProfileInt("Funktion","a3'_Modus",3);
			if(prm.d5_ag3_art=="Strichpunkt")       pApp->WriteProfileInt("Funktion","a3'_Modus",4);
			if(prm.d5_ag3_art=="Strichdoppelpkt.")  pApp->WriteProfileInt("Funktion","a3'_Modus",5);
			if(prm.d5_sa3g_art=="Linie")            pApp->WriteProfileInt("Funktion","s'a3_Modus",1);
			if(prm.d5_sa3g_art=="Punkt")            pApp->WriteProfileInt("Funktion","s'a3_Modus",2);
			if(prm.d5_sa3g_art=="Strich")           pApp->WriteProfileInt("Funktion","s'a3_Modus",3);
			if(prm.d5_sa3g_art=="Strichpunkt")      pApp->WriteProfileInt("Funktion","s'a3_Modus",4);
			if(prm.d5_sa3g_art=="Strichdoppelpkt.") pApp->WriteProfileInt("Funktion","s'a3_Modus",5);
			if(prm.d5_a4_art=="Linie")              pApp->WriteProfileInt("Funktion","a4_Modus",1);
			if(prm.d5_a4_art=="Punkt")              pApp->WriteProfileInt("Funktion","a4_Modus",2);
			if(prm.d5_a4_art=="Strich")             pApp->WriteProfileInt("Funktion","a4_Modus",3);
			if(prm.d5_a4_art=="Strichpunkt")        pApp->WriteProfileInt("Funktion","a4_Modus",4);
			if(prm.d5_a4_art=="Strichdoppelpkt.")   pApp->WriteProfileInt("Funktion","a4_Modus",5);
			if(prm.d5_ag4_art=="Linie")             pApp->WriteProfileInt("Funktion","a4'_Modus",1);
			if(prm.d5_ag4_art=="Punkt")             pApp->WriteProfileInt("Funktion","a4'_Modus",2);
			if(prm.d5_ag4_art=="Strich")            pApp->WriteProfileInt("Funktion","a4'_Modus",3);
			if(prm.d5_ag4_art=="Strichpunkt")       pApp->WriteProfileInt("Funktion","a4'_Modus",4);
			if(prm.d5_ag4_art=="Strichdoppelpkt.")  pApp->WriteProfileInt("Funktion","a4'_Modus",5);
			if(prm.d5_sa4g_art=="Linie")            pApp->WriteProfileInt("Funktion","sa4'_Modus",1);
			if(prm.d5_sa4g_art=="Punkt")            pApp->WriteProfileInt("Funktion","sa4'_Modus",2);
			if(prm.d5_sa4g_art=="Strich")           pApp->WriteProfileInt("Funktion","sa4'_Modus",3);
			if(prm.d5_sa4g_art=="Strichpunkt")      pApp->WriteProfileInt("Funktion","sa4'_Modus",4);
			if(prm.d5_sa4g_art=="Strichdoppelpkt.") pApp->WriteProfileInt("Funktion","sa4'_Modus",5);
												    pApp->WriteProfileInt("Funktion","am_Theta_Darstellung",prm.d5_ch_x ); 
												    pApp->WriteProfileInt("Funktion","sd_Theta_Darstellung",prm.d5_ch_s); 
												    pApp->WriteProfileInt("Funktion","sd'_Theta_Darstellung",prm.d5_ch_sg); 
												    pApp->WriteProfileInt("Funktion","s'am_Theta_Darstellung",prm.d5_ch_sgx); 
												    pApp->WriteProfileInt("Funktion","a3_Theta_Darstellung",prm.d5_ch_a3);
												    pApp->WriteProfileInt("Funktion","a3'_Theta_Darstellung",prm.d5_ch_ag3); 
												    pApp->WriteProfileInt("Funktion","s'a3_Theta_Darstellung",prm.d5_ch_sa3g); 
												    pApp->WriteProfileInt("Funktion","a4_Theta_Darstellung",prm.d5_ch_a4); 
												    pApp->WriteProfileInt("Funktion","a4'_Theta_Darstellung",prm.d5_ch_ag4);
												    pApp->WriteProfileInt("Funktion","s'a4_Theta_Darstellung",prm.d5_ch_sa4g);
													
												    pApp->WriteProfileInt("Funktion","e_Farbe",prm.d6_e_clr);
													pApp->WriteProfileInt("Funktion","x_Farbe",prm.d6_x_clr);
													pApp->WriteProfileInt("Funktion","x0_Farbe",prm.d6_x0_clr);
													pApp->WriteProfileInt("Funktion","x1_Farbe",prm.d6_x1_clr);
													pApp->WriteProfileInt("Funktion","s0_Farbe", prm.d6_s0_clr);
													pApp->WriteProfileInt("Funktion","s1_Farbe",prm.d6_s1_clr);
													pApp->WriteProfileInt("Funktion","e_Linienbreite",prm.d6_e_gr);
													pApp->WriteProfileInt("Funktion","x_Linienbreite",prm.d6_x_gr);
													pApp->WriteProfileInt("Funktion","x0_Linienbreite",prm.d6_x0_gr);
													pApp->WriteProfileInt("Funktion","x1_Linienbreite",prm.d6_x1_gr);
													pApp->WriteProfileInt("Funktion","s0_Linienbreite",prm.d6_s0_gr);
													pApp->WriteProfileInt("Funktion","s1_Linienbreite", prm.d6_s1_gr);
													pApp->WriteProfileInt("Funktion","e_Theta_Darstellung",prm.d6_ch_e ); 
													pApp->WriteProfileInt("Funktion","x_Theta_Darstellung",prm.d6_ch_x);
													pApp->WriteProfileInt("Funktion","x0_Theta_Darstellung",prm.d6_ch_x0);
													pApp->WriteProfileInt("Funktion","x1_Theta_Darstellung", prm.d6_ch_x1);
													pApp->WriteProfileInt("Funktion","s0_Theta_Darstellung", prm.d6_ch_s0 );
													pApp->WriteProfileInt("Funktion","s1_Theta_Darstellung",prm.d6_ch_s1);
			if(prm.d6_e_art=="Linie")               pApp->WriteProfileInt("Funktion","e_Modus",1);
			if(prm.d6_e_art=="Punkt")               pApp->WriteProfileInt("Funktion","e_Modus",2);
			if(prm.d6_e_art=="Strich")              pApp->WriteProfileInt("Funktion","e_Modus",3);
			if(prm.d6_e_art=="Strichpunkt")         pApp->WriteProfileInt("Funktion","e_Modus",4);
			if(prm.d6_e_art=="Strichdoppelpkt.")    pApp->WriteProfileInt("Funktion","e_Modus",5);
			if(prm.d6_x_art=="Linie")               pApp->WriteProfileInt("Funktion","x_Modus",1);
			if(prm.d6_x_art=="Punkt")               pApp->WriteProfileInt("Funktion","x_Modus",2);
			if(prm.d6_x_art=="Strich")              pApp->WriteProfileInt("Funktion","x_Modus",3);
			if(prm.d6_x_art=="Strichpunkt")         pApp->WriteProfileInt("Funktion","x_Modus",4);
			if(prm.d6_x_art=="Strichdoppelpkt.")    pApp->WriteProfileInt("Funktion","x_Modus",5);
			if(prm.d6_x0_art=="Linie")              pApp->WriteProfileInt("Funktion","x0_Modus",1);
			if(prm.d6_x0_art=="Punkt")              pApp->WriteProfileInt("Funktion","x0_Modus",2);
			if(prm.d6_x0_art=="Strich")             pApp->WriteProfileInt("Funktion","x0_Modus",3);
			if(prm.d6_x0_art=="Strichpunkt")        pApp->WriteProfileInt("Funktion","x0_Modus",4);
			if(prm.d6_x0_art=="Strichdoppelpkt.")   pApp->WriteProfileInt("Funktion","x0_Modus",5);
			if(prm.d6_s0_art=="Linie")              pApp->WriteProfileInt("Funktion","s0_Modus",1);
			if(prm.d6_s0_art=="Punkt")              pApp->WriteProfileInt("Funktion","s0_Modus",2);
			if(prm.d6_s0_art=="Strich")             pApp->WriteProfileInt("Funktion","s0_Modus",3);
			if(prm.d6_s0_art=="Strichpunkt")        pApp->WriteProfileInt("Funktion","s0_Modus",4);
			if(prm.d6_s0_art=="Strichdoppelpkt.")   pApp->WriteProfileInt("Funktion","s0_Modus",5);
			if(prm.d6_x1_art=="Linie")              pApp->WriteProfileInt("Funktion","x1_Modus",1);
			if(prm.d6_x1_art=="Punkt")              pApp->WriteProfileInt("Funktion","x1_Modus",2);
			if(prm.d6_x1_art=="Strich")             pApp->WriteProfileInt("Funktion","x1_Modus",3);
			if(prm.d6_x1_art=="Strichpunkt")        pApp->WriteProfileInt("Funktion","x1_Modus",4);
			if(prm.d6_x1_art=="Strichdoppelpkt.")   pApp->WriteProfileInt("Funktion","x1_Modus",5);
			if(prm.d6_s1_art=="Linie")              pApp->WriteProfileInt("Funktion","s1_Modus",1);
			if(prm.d6_s1_art=="Punkt")              pApp->WriteProfileInt("Funktion","s1_Modus",2);
			if(prm.d6_s1_art=="Strich")             pApp->WriteProfileInt("Funktion","s1_Modus",3);
			if(prm.d6_s1_art=="Strichpunkt")        pApp->WriteProfileInt("Funktion","s1_Modus",4);
			if(prm.d6_s1_art=="Strichdoppelpkt.")   pApp->WriteProfileInt("Funktion","s1_Modus",5);		 
	}
												    pApp->WriteProfileInt("INI_schreiben","prg",m_ch_ini);
												    pApp->WriteProfileInt("Programm","Position_x",coord.left);
												    pApp->WriteProfileInt("Programm","Position_y",coord.top);
	CDialog::OnOK();
}

CString GRP2prg::ftoc( double x0, int dez ) 
{
	                 int nZ=100, npkt,  vz;
	char *str = ecvt(x0, nZ,    &npkt, &vz  );

		                             CString c_=""; 
	if(vz!=0)                                c_+='-';   // x<0
	
	if(npkt<=0)                                         // x<1
	{
		                                     c_+='0';
										     c_+='.';
		for(int i_=1;i_<=-npkt;i_++)         c_+='0'; 
		for(    i_=0;i_<dez+npkt;i_++)       c_+=str[i_]; 
	}

	if(npkt>0)                                         // x>=1
	{
		for(int i_=0;i_<npkt;i_++)           c_+=str[i_];  
										     c_+='.'; 
		for(    i_=npkt;i_<=dez+npkt-1;i_++) c_+=str[i_]; 
	}

	                                  return c_;     // CString
}







