//------------------------------------------------------------------------| GRP2diagrm5.cpp                              //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#include "stdafx.h"
#include "grp2.hpp"
#include "GRP2Dlg.hpp"
#include "GRP2diagrm1.hpp"
#include "GRP2diagrm2.hpp"
#include "GRP2diagrm3.hpp"
#include "GRP2diagrm4.hpp"
#include "GRP2diagrm5.hpp"
#include "GRP2diagrm6.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

GRP2diagrm5::GRP2diagrm5(CWnd* pParent /*=NULL*/)
	: CDialog(GRP2diagrm5::IDD, pParent)
{
	//{{AFX_DATA_INIT(GRP2diagrm5)
	m_ch_ini = 1;
	m_a3_art = _T("");
	m_a4_art = _T("");
	m_ag3_art = _T("");
	m_ag4_art = _T("");
	m_sa3g_art = _T("");
	m_sa4g_art = _T("");
	m_sd_art = _T("");
	m_sdg_art = _T("");
	m_sgx_art = _T("");
	m_X_art = _T("");
	m_a3_gr = 0;
	m_a4_gr = 0;
	m_ag3_gr = 0;
	m_ag4_gr = 0;
	m_sa3g_gr = 0;
	m_sa4g_gr = 0;
	m_sd_gr = 0;
	m_sdg_gr = 0;
	m_sgx_gr = 0;
	m_X_gr = 0;
	m_ch_a3 = 1;
	m_ch_a4 = 1;
	m_ch_ag3 = 1;
	m_ch_ag4 = 1;
	m_ch_s = 1;
	m_ch_sa3g = 1;
	m_ch_sa4g = 1;
	m_ch_sg = 1;
	m_ch_sgx = 1;
	m_ch_x = 1;
	//}}AFX_DATA_INIT
}

void GRP2diagrm5::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GRP2diagrm5)
	DDX_Control(pDX, IDC_TAB2, m_tab);
	DDX_Check(pDX, IDC_CHECK_ini, m_ch_ini);
	DDX_CBString(pDX, IDC_COMBO_a3_art, m_a3_art);
	DDX_CBString(pDX, IDC_COMBO_a4_art, m_a4_art);
	DDX_CBString(pDX, IDC_COMBO_ag3_art, m_ag3_art);
	DDX_CBString(pDX, IDC_COMBO_ag4_art, m_ag4_art);
	DDX_CBString(pDX, IDC_COMBO_sa3g_art, m_sa3g_art);
	DDX_CBString(pDX, IDC_COMBO_sa4g_art, m_sa4g_art);
	DDX_CBString(pDX, IDC_COMBO_sd_art, m_sd_art);
	DDX_CBString(pDX, IDC_COMBO_sdg_art, m_sdg_art);
	DDX_CBString(pDX, IDC_COMBO_sgx_art, m_sgx_art);
	DDX_CBString(pDX, IDC_COMBO_X_art, m_X_art);
	DDX_Text(pDX, IDC_EDIT_a3_gr, m_a3_gr);
	DDX_Text(pDX, IDC_EDIT_a4_gr, m_a4_gr);
	DDX_Text(pDX, IDC_EDIT_ag3_gr, m_ag3_gr);
	DDX_Text(pDX, IDC_EDIT_ag4_gr, m_ag4_gr);
	DDX_Text(pDX, IDC_EDIT_sa3g_gr, m_sa3g_gr);
	DDX_Text(pDX, IDC_EDIT_sa4g_gr, m_sa4g_gr);
	DDX_Text(pDX, IDC_EDIT_sd_gr, m_sd_gr);
	DDX_Text(pDX, IDC_EDIT_sdg_gr, m_sdg_gr);
	DDX_Text(pDX, IDC_EDIT_sgx_gr, m_sgx_gr);
	DDX_Text(pDX, IDC_EDIT_X_gr, m_X_gr);
	DDX_Check(pDX, IDC_CHECK_a31, m_ch_a3);
	DDX_Check(pDX, IDC_CHECK_a41, m_ch_a4);
	DDX_Check(pDX, IDC_CHECK_ag3, m_ch_ag3);
	DDX_Check(pDX, IDC_CHECK_ag41, m_ch_ag4);
	DDX_Check(pDX, IDC_CHECK_s, m_ch_s);
	DDX_Check(pDX, IDC_CHECK_sa3g, m_ch_sa3g);
	DDX_Check(pDX, IDC_CHECK_sa4g, m_ch_sa4g);
	DDX_Check(pDX, IDC_CHECK_sg, m_ch_sg);
	DDX_Check(pDX, IDC_CHECK_sgx, m_ch_sgx);
	DDX_Check(pDX, IDC_CHECK_x, m_ch_x);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(GRP2diagrm5, CDialog)
	//{{AFX_MSG_MAP(GRP2diagrm5)
	ON_BN_CLICKED(IDC_CHECK_ini, OnCHECKini)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB2, OnSelchangeTab2)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_a3_fb, OnBUTTONa3fb)
	ON_BN_CLICKED(IDC_BUTTON_a4_fb, OnBUTTONa4fb)
	ON_BN_CLICKED(IDC_BUTTON_ag3_fb, OnBUTTONag3fb)
	ON_BN_CLICKED(IDC_BUTTON_ag4_fb, OnBUTTONag4fb)
	ON_BN_CLICKED(IDC_BUTTON_sa3g_fb, OnBUTTONsa3gfb)
	ON_BN_CLICKED(IDC_BUTTON_sa4g_fb, OnBUTTONsa4gfb)
	ON_BN_CLICKED(IDC_BUTTON_sd_fb, OnBUTTONsdfb)
	ON_BN_CLICKED(IDC_BUTTON_sdg_fb, OnBUTTONsdgfb)
	ON_BN_CLICKED(IDC_BUTTON_sgx_fb, OnBUTTONsgxfb)
	ON_BN_CLICKED(IDC_BUTTON_X_fb, OnBUTTONXfb)
	ON_CBN_SELCHANGE(IDC_COMBO_a3_art, OnSelchangeCOMBOa3art)
	ON_CBN_SELCHANGE(IDC_COMBO_a4_art, OnSelchangeCOMBOa4art)
	ON_CBN_SELCHANGE(IDC_COMBO_ag3_art, OnSelchangeCOMBOag3art)
	ON_CBN_SELCHANGE(IDC_COMBO_ag4_art, OnSelchangeCOMBOag4art)
	ON_CBN_SELCHANGE(IDC_COMBO_sa3g_art, OnSelchangeCOMBOsa3gart)
	ON_CBN_SELCHANGE(IDC_COMBO_sa4g_art, OnSelchangeCOMBOsa4gart)
	ON_CBN_SELCHANGE(IDC_COMBO_sd_art, OnSelchangeCOMBOsdart)
	ON_CBN_SELCHANGE(IDC_COMBO_sdg_art, OnSelchangeCOMBOsdgart)
	ON_CBN_SELCHANGE(IDC_COMBO_sgx_art, OnSelchangeCOMBOsgxart)
	ON_CBN_SELCHANGE(IDC_COMBO_X_art, OnSelchangeCOMBOXart)
	ON_EN_CHANGE(IDC_EDIT_a3_gr, OnChangeEDITa3gr)
	ON_EN_CHANGE(IDC_EDIT_a4_gr, OnChangeEDITa4gr)
	ON_EN_CHANGE(IDC_EDIT_ag3_gr, OnChangeEDITag3gr)
	ON_EN_CHANGE(IDC_EDIT_ag4_gr, OnChangeEDITag4gr)
	ON_EN_CHANGE(IDC_EDIT_sa3g_gr, OnChangeEDITsa3ggr)
	ON_EN_CHANGE(IDC_EDIT_sa4g_gr, OnChangeEDITsa4ggr)
	ON_EN_CHANGE(IDC_EDIT_sd_gr, OnChangeEDITsdgr)
	ON_EN_CHANGE(IDC_EDIT_sdg_gr, OnChangeEDITsdggr)
	ON_EN_CHANGE(IDC_EDIT_sgx_gr, OnChangeEDITsgxgr)
	ON_EN_CHANGE(IDC_EDIT_X_gr, OnChangeEDITXgr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_a3_gr, OnDeltaposSPINa3gr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_a4_gr, OnDeltaposSPINa4gr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ag3_gr, OnDeltaposSPINag3gr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ag4_gr, OnDeltaposSPINag4gr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_sa3g_gr, OnDeltaposSPINsa3ggr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_sa4g_gr, OnDeltaposSPINsa4ggr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_sd_gr, OnDeltaposSPINsdgr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_sdg_gr, OnDeltaposSPINsdggr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_sgx_gr, OnDeltaposSPINsgxgr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_X_gr, OnDeltaposSPINXgr)
	ON_BN_CLICKED(IDC_CHECK_a31, OnCHECKa31)
	ON_BN_CLICKED(IDC_CHECK_a41, OnCHECKa41)
	ON_BN_CLICKED(IDC_CHECK_ag3, OnCHECKag3)
	ON_BN_CLICKED(IDC_CHECK_ag41, OnCHECKag41)
	ON_BN_CLICKED(IDC_CHECK_s, OnCHECKs)
	ON_BN_CLICKED(IDC_CHECK_sa3g, OnCHECKsa3g)
	ON_BN_CLICKED(IDC_CHECK_sa4g, OnCHECKsa4g)
	ON_BN_CLICKED(IDC_CHECK_sg, OnCHECKsg)
	ON_BN_CLICKED(IDC_CHECK_sgx, OnCHECKsgx)
	ON_BN_CLICKED(IDC_CHECK_x, OnCHECKx)
	ON_BN_CLICKED(ID_Voreinstellungen, OnVoreinstellungen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL GRP2diagrm5::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
		UpdateData(1);

	            CWinApp*  pApp = AfxGetApp(); // ini profil lesen 

		   m_X_gr=        pApp->GetProfileInt("Funktion","am_Linienbreite",1);
		   m_sd_gr=       pApp->GetProfileInt("Funktion","sd_Linienbreite",1);
		   m_sgx_gr=      pApp->GetProfileInt("Funktion","s'am_Linienbreite",1);
		   m_sdg_gr=      pApp->GetProfileInt("Funktion","sd'_Linienbreite",1);
		   m_a3_gr=       pApp->GetProfileInt("Funktion","a3_Linienbreite",1);
		   m_ag3_gr=      pApp->GetProfileInt("Funktion","a3'_Linienbreite",1);
		   m_sa3g_gr=     pApp->GetProfileInt("Funktion","s'a3_Linienbreite",1);
		   m_a4_gr=       pApp->GetProfileInt("Funktion","a4_Linienbreite",1);
		   m_ag4_gr=      pApp->GetProfileInt("Funktion","a4'_Linienbreite",1);
		   m_sa4g_gr=     pApp->GetProfileInt("Funktion","s'a4_Linienbreite",1);
		   Xp_clr=        pApp->GetProfileInt("Funktion","am_Farbe",8421504);
	       sd_clr=        pApp->GetProfileInt("Funktion","sd_Farbe",8421504);
	       sgx_clr=       pApp->GetProfileInt("Funktion","s'am_Farbe",8421504);
	       sdg_clr=       pApp->GetProfileInt("Funktion","sd'_Farbe",8421504);
	       a3_clr=        pApp->GetProfileInt("Funktion","a3_Farbe",8421504);
	       ag3_clr=       pApp->GetProfileInt("Funktion","a3'_Farbe",8421504);
	       sa3g_clr=      pApp->GetProfileInt("Funktion","s'a3_Farbe",8421504);
           a4_clr=        pApp->GetProfileInt("Funktion","a4_Farbe",8421504);
	       ag4_clr=       pApp->GetProfileInt("Funktion","a4'_Farbe",8421504);
	       sa4g_clr=      pApp->GetProfileInt("Funktion","s'a4_Farbe",8421504);
		   mod_X=         pApp->GetProfileInt("Funktion","am_Modus",1);
		   if(mod_X==1)m_X_art="Linie";
		   if(mod_X==2)m_X_art="Punkt";
		   if(mod_X==3)m_X_art="Strich";
		   if(mod_X==4)m_X_art="Strichpunkt";
		   if(mod_X==5)m_X_art="Strichdoppelpkt.";
		   mod_sd=        pApp->GetProfileInt("Funktion","sd_Modus",1);
		   if(mod_sd==1)m_sd_art="Linie";
		   if(mod_sd==2)m_sd_art="Punkt";
		   if(mod_sd==3)m_sd_art="Strich";
		   if(mod_sd==4)m_sd_art="Strichpunkt";
		   if(mod_sd==5)m_sd_art="Strichdoppelpkt.";
		   mod_sgx=       pApp->GetProfileInt("Funktion","s'am_Modus",2);
		   if(mod_sgx==1)m_sgx_art="Linie";
		   if(mod_sgx==2)m_sgx_art="Punkt";
		   if(mod_sgx==3)m_sgx_art="Strich";
		   if(mod_sgx==4)m_sgx_art="Strichpunkt";
		   if(mod_sgx==5)m_sgx_art="Strichdoppelpkt.";
		   mod_sdg=       pApp->GetProfileInt("Funktion","sd'_Modus",3);
		   if(mod_sdg==1)m_sdg_art="Linie";
		   if(mod_sdg==2)m_sdg_art="Punkt";
		   if(mod_sdg==3)m_sdg_art="Strich";
		   if(mod_sdg==4)m_sdg_art="Strichpunkt";
		   if(mod_sdg==5)m_sdg_art="Strichdoppelpkt.";
		   mod_a3=        pApp->GetProfileInt("Funktion","a3_Modus",1);
		   if(mod_a3==1)m_a3_art="Linie";
		   if(mod_a3==2)m_a3_art="Punkt";
		   if(mod_a3==3)m_a3_art="Strich";
		   if(mod_a3==4)m_a3_art="Strichpunkt";
		   if(mod_a3==5)m_a3_art="Strichdoppelpkt.";
		   mod_ag3=       pApp->GetProfileInt("Funktion","a3'_Modus",3);
		   if(mod_ag3==1)m_ag3_art="Linie";
		   if(mod_ag3==2)m_ag3_art="Punkt";
		   if(mod_ag3==3)m_ag3_art="Strich";
		   if(mod_ag3==4)m_ag3_art="Strichpunkt";
		   if(mod_ag3==5)m_ag3_art="Strichdoppelpkt.";
		   mod_sa3g=      pApp->GetProfileInt("Funktion","s'a3_Modus",2);
		   if(mod_sa3g==1)m_sa3g_art="Linie";
		   if(mod_sa3g==2)m_sa3g_art="Punkt";
		   if(mod_sa3g==3)m_sa3g_art="Strich";
		   if(mod_sa3g==4)m_sa3g_art="Strichpunkt";
		   if(mod_sa3g==5)m_sa3g_art="Strichdoppelpkt.";
		   mod_a4=        pApp->GetProfileInt("Funktion","a4_Modus",1);
		   if(mod_a4==1)m_a4_art="Linie";
		   if(mod_a4==2)m_a4_art="Punkt";
		   if(mod_a4==3)m_a4_art="Strich";
		   if(mod_a4==4)m_a4_art="Strichpunkt";
		   if(mod_a4==5)m_a4_art="Strichdoppelpkt.";
		   mod_ag4=       pApp->GetProfileInt("Funktion","a4'_Modus",3);
		   if(mod_ag4==1)m_ag4_art="Linie";
		   if(mod_ag4==2)m_ag4_art="Punkt";
		   if(mod_ag4==3)m_ag4_art="Strich";
		   if(mod_ag4==4)m_ag4_art="Strichpunkt";
		   if(mod_ag4==5)m_ag4_art="Strichdoppelpkt.";
		   mod_sa4g=      pApp->GetProfileInt("Funktion","s'a4_Modus",2);
		   if(mod_sa4g==1)m_sa4g_art="Linie";
		   if(mod_sa4g==2)m_sa4g_art="Punkt";
		   if(mod_sa4g==3)m_sa4g_art="Strich";
		   if(mod_sa4g==4)m_sa4g_art="Strichpunkt";
		   if(mod_sa4g==5)m_sa4g_art="Strichdoppelpkt.";
	       m_ch_x=        pApp->GetProfileInt("Funktion","am_Theta_Darstellung",1); 
	       m_ch_s=        pApp->GetProfileInt("Funktion","sd_Theta_Darstellung",1); 
	       m_ch_sg=       pApp->GetProfileInt("Funktion","sd'_Theta_Darstellung",1); 
	       m_ch_sgx=      pApp->GetProfileInt("Funktion","s'am_Theta_Darstellung",2); 
	       m_ch_a3=       pApp->GetProfileInt("Funktion","a3_Theta_Darstellung",2);
	       m_ch_ag3=      pApp->GetProfileInt("Funktion","a3'_Theta_Darstellung",2); 
	       m_ch_sa3g=     pApp->GetProfileInt("Funktion","s'a3_Theta_Darstellung",1); 
	       m_ch_a4=       pApp->GetProfileInt("Funktion","a4_Theta_Darstellung",2); 
	       m_ch_ag4=      pApp->GetProfileInt("Funktion","a4'_Theta_Darstellung",2);
	       m_ch_sa4g=     pApp->GetProfileInt("Funktion","s'a4_Theta_Darstellung",1);   

           m_ch_ini=      pApp->GetProfileInt("INI_schreiben","diagrm5",1);

	SetWindowPos(&wndTop, pApp->GetProfileInt("Diagramm","Position_x",100),
		                  pApp->GetProfileInt("Diagramm","Position_y",100), 200+8,100+27, SWP_NOSIZE);

	                          TC_ITEM o;
	                                  o.mask = TCIF_TEXT;
	/*CTabCtrl	m_tab;*/              o.pszText = "Funktion"; 
				m_tab.InsertItem( 0, &o );   
				                      o.pszText = "Achsen";
				m_tab.InsertItem( 1, &o );
				                      o.pszText = "Vektoren";
				m_tab.InsertItem( 2, &o );
				                      o.pszText = "r(x,y)";
				m_tab.InsertItem( 3, &o );
				                      o.pszText = "F(p)";
				m_tab.InsertItem( 4, &o );
				                      o.pszText = "F(e)";
				m_tab.InsertItem( 5, &o );
				         
				m_tab.SetCurSel(  4);

	UpdateData(0);
	
	return 1;            
}

void GRP2diagrm5::OnPaint() 
{
	CPaintDC ooo(this); 
	                              UINT pos=50;
			             CRect o1(197, pos, 211, pos+13);
			 ooo.FillSolidRect(o1, Xp_clr ); 

			             CRect o2(197, pos+23*1, 211, pos+23*1+13);
			 ooo.FillSolidRect(o2, sd_clr ); 

			             CRect o3(197, pos+23*2, 211, pos+23*2+13);
			 ooo.FillSolidRect(o3, sdg_clr ); 

			             CRect o4(197, pos+23*3-1, 211, pos+23*3+13-1);
			 ooo.FillSolidRect(o4, sgx_clr ); 

			             CRect o5(197, pos+23*4-1, 211, pos+23*4+13-1);
			 ooo.FillSolidRect(o5, a3_clr ); 

			             CRect o6(197, pos+23*5-1, 211, pos+23*5+13-1);
			 ooo.FillSolidRect(o6, ag3_clr ); 

			             CRect o7(197, pos+23*6-1, 211, pos+23*6+13-1);
			 ooo.FillSolidRect(o7, sa3g_clr ); 

			             CRect o8(197, pos+23*7-2, 211, pos+23*7+13-2);
			 ooo.FillSolidRect(o8, a4_clr ); 

			             CRect o9(197, pos+23*8-2, 211, pos+23*8+13-2);
			 ooo.FillSolidRect(o9, ag4_clr ); 

			             CRect o10(197, pos+23*9-2, 211, pos+23*9+13-2);
			 ooo.FillSolidRect(o10, sa4g_clr );
}

void GRP2diagrm5::OnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if(m_tab.GetCurSel() ==0){OnOK();GRP2diagrm1 o;o.DoModal();}
	if(m_tab.GetCurSel() ==1){OnOK();GRP2diagrm2 o;o.DoModal();}
	if(m_tab.GetCurSel() ==2){OnOK();GRP2diagrm3 o;o.DoModal();}
	if(m_tab.GetCurSel() ==3){OnOK();GRP2diagrm4 o;o.DoModal();}
	if(m_tab.GetCurSel() ==4);
	if(m_tab.GetCurSel() ==5){OnOK();GRP2diagrm6 o;o.DoModal();}
	
	*pResult = 0;
}

void GRP2diagrm5::OnChangeEDITa3gr() {       UpdateData(1); CGRP2Dlg o;o.a3_gr(m_a3_gr) ;      UpdateData(0);}
void GRP2diagrm5::OnChangeEDITa4gr() {       UpdateData(1); CGRP2Dlg o;o.a4_gr(m_a4_gr) ;      UpdateData(0);}
void GRP2diagrm5::OnChangeEDITag3gr(){       UpdateData(1); CGRP2Dlg o;o.ag3_gr(m_ag3_gr) ;    UpdateData(0);} 
void GRP2diagrm5::OnChangeEDITag4gr(){       UpdateData(1); CGRP2Dlg o;o.ag4_gr(m_ag4_gr) ;    UpdateData(0);}
void GRP2diagrm5::OnChangeEDITsa3ggr(){      UpdateData(1); CGRP2Dlg o;o.sa3g_gr(m_sa3g_gr) ;  UpdateData(0);} 
void GRP2diagrm5::OnChangeEDITsa4ggr(){      UpdateData(1); CGRP2Dlg o;o.sa4g_gr(m_sa4g_gr) ;  UpdateData(0);} 
void GRP2diagrm5::OnChangeEDITsdgr() {       UpdateData(1); CGRP2Dlg o;o.sd_gr(m_sd_gr) ;      UpdateData(0);}
void GRP2diagrm5::OnChangeEDITsdggr() {      UpdateData(1); CGRP2Dlg o;o.sdg_gr(m_sdg_gr) ;    UpdateData(0);}
void GRP2diagrm5::OnChangeEDITsgxgr(){       UpdateData(1); CGRP2Dlg o;o.sgx_gr(m_sgx_gr) ;    UpdateData(0);} 
void GRP2diagrm5::OnChangeEDITXgr() {        UpdateData(1); CGRP2Dlg o;o.Xp_gr(m_X_gr) ;       UpdateData(0);}
void GRP2diagrm5::OnSelchangeCOMBOa3art() {  UpdateData(1); CGRP2Dlg o;o.a3_art(m_a3_art) ;    UpdateData(0);}
void GRP2diagrm5::OnSelchangeCOMBOa4art() {  UpdateData(1); CGRP2Dlg o;o.a4_art(m_a4_art) ;    UpdateData(0);}
void GRP2diagrm5::OnSelchangeCOMBOag3art(){  UpdateData(1); CGRP2Dlg o;o.ag3_art(m_ag3_art) ;  UpdateData(0);} 
void GRP2diagrm5::OnSelchangeCOMBOag4art() { UpdateData(1); CGRP2Dlg o;o.ag4_art(m_ag4_art) ;  UpdateData(0);}
void GRP2diagrm5::OnSelchangeCOMBOsa3gart(){ UpdateData(1); CGRP2Dlg o;o.sa3g_art(m_sa3g_art) ;UpdateData(0);} 
void GRP2diagrm5::OnSelchangeCOMBOsa4gart(){ UpdateData(1); CGRP2Dlg o;o.sa4g_art(m_sa4g_art) ;UpdateData(0);} 
void GRP2diagrm5::OnSelchangeCOMBOsdart() {  UpdateData(1); CGRP2Dlg o;o.sd_art(m_sd_art) ;    UpdateData(0);}
void GRP2diagrm5::OnSelchangeCOMBOsdgart(){  UpdateData(1); CGRP2Dlg o;o.sdg_art(m_sdg_art) ;  UpdateData(0);}
void GRP2diagrm5::OnSelchangeCOMBOsgxart(){  UpdateData(1); CGRP2Dlg o;o.sgx_art(m_sgx_art) ;  UpdateData(0);} 
void GRP2diagrm5::OnSelchangeCOMBOXart(){    UpdateData(1); CGRP2Dlg o;o.Xp_art(m_X_art) ;     UpdateData(0);} 

void GRP2diagrm5::OnDeltaposSPINa3gr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)              m_a3_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_a3_gr>0) m_a3_gr-=1;
		                   
	UpdateData(0); OnChangeEDITa3gr();
	
	*pResult = 0;
}

void GRP2diagrm5::OnDeltaposSPINa4gr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)              m_a4_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_a4_gr>0) m_a4_gr-=1;
		                   
	UpdateData(0); OnChangeEDITa4gr();
	
	*pResult = 0;
}

void GRP2diagrm5::OnDeltaposSPINag3gr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)               m_ag3_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_ag3_gr>0) m_ag3_gr-=1;
		                   
	UpdateData(0); OnChangeEDITag3gr();
	
	*pResult = 0;
}

void GRP2diagrm5::OnDeltaposSPINag4gr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)               m_ag4_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_ag4_gr>0) m_ag4_gr-=1;
		                   
	UpdateData(0); OnChangeEDITag4gr();
	
	*pResult = 0;
}

void GRP2diagrm5::OnDeltaposSPINsa3ggr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)                m_sa3g_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_sa3g_gr>0) m_sa3g_gr-=1;
		                   
	UpdateData(0); OnChangeEDITsa3ggr();
	
	*pResult = 0;
}

void GRP2diagrm5::OnDeltaposSPINsa4ggr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)                m_sa4g_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_sa4g_gr>0) m_sa4g_gr-=1;
		                   
	UpdateData(0); OnChangeEDITsa4ggr();
	
	*pResult = 0;
}

void GRP2diagrm5::OnDeltaposSPINsdgr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)              m_sd_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_sd_gr>0) m_sd_gr-=1;
		                   
	UpdateData(0); OnChangeEDITsdgr();
	
	*pResult = 0;
}

void GRP2diagrm5::OnDeltaposSPINsdggr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)               m_sdg_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_sdg_gr>0) m_sdg_gr-=1;
		                   
	UpdateData(0); OnChangeEDITsdggr();
	
	*pResult = 0;
}

void GRP2diagrm5::OnDeltaposSPINsgxgr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)               m_sgx_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_sgx_gr>0) m_sgx_gr-=1;
		                   
	UpdateData(0); OnChangeEDITsgxgr();
	
	*pResult = 0;
}

void GRP2diagrm5::OnDeltaposSPINXgr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)             m_X_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_X_gr>0) m_X_gr-=1;
		                   
	UpdateData(0); OnChangeEDITXgr();
	
	*pResult = 0;
}

void GRP2diagrm5::OnBUTTONa3fb()  {CColorDialog cl(a3_clr,0,0);cl.DoModal();  a3_clr=cl.GetColor();RedrawWindow();  CGRP2Dlg o; o.clr_a3(a3_clr)    ;}  
void GRP2diagrm5::OnBUTTONa4fb()  {CColorDialog cl(a4_clr,0,0);cl.DoModal();  a4_clr=cl.GetColor();RedrawWindow();  CGRP2Dlg o; o.clr_a4(a4_clr)    ;}  
void GRP2diagrm5::OnBUTTONag3fb() {CColorDialog cl(ag3_clr,0,0);cl.DoModal(); ag3_clr=cl.GetColor();RedrawWindow(); CGRP2Dlg o; o.clr_ag3(ag3_clr)  ;}  
void GRP2diagrm5::OnBUTTONag4fb() {CColorDialog cl(ag4_clr,0,0);cl.DoModal(); ag4_clr=cl.GetColor();RedrawWindow(); CGRP2Dlg o; o.clr_ag4(ag4_clr)  ;}  
void GRP2diagrm5::OnBUTTONsa3gfb(){CColorDialog cl(sa3g_clr,0,0);cl.DoModal();sa3g_clr=cl.GetColor();RedrawWindow();CGRP2Dlg o; o.clr_sa3g(sa3g_clr);}  
void GRP2diagrm5::OnBUTTONsa4gfb(){CColorDialog cl(sa4g_clr,0,0);cl.DoModal();sa4g_clr=cl.GetColor();RedrawWindow();CGRP2Dlg o; o.clr_sa4g(sa4g_clr);}  
void GRP2diagrm5::OnBUTTONsdfb()  {CColorDialog cl(sd_clr,0,0);cl.DoModal();  sd_clr=cl.GetColor();RedrawWindow();  CGRP2Dlg o; o.clr_sd(sd_clr)    ;}  
void GRP2diagrm5::OnBUTTONsdgfb() {CColorDialog cl(sdg_clr,0,0);cl.DoModal(); sdg_clr=cl.GetColor();RedrawWindow(); CGRP2Dlg o; o.clr_sdg(sdg_clr)  ;}  
void GRP2diagrm5::OnBUTTONsgxfb() {CColorDialog cl(sgx_clr,0,0);cl.DoModal(); sgx_clr=cl.GetColor();RedrawWindow(); CGRP2Dlg o; o.clr_sgx(sgx_clr)  ;}  
void GRP2diagrm5::OnBUTTONXfb()   {CColorDialog cl(Xp_clr,0,0);cl.DoModal();  Xp_clr=cl.GetColor();RedrawWindow();  CGRP2Dlg o; o.clr_Xp(Xp_clr)    ;}  
void GRP2diagrm5::OnCHECKa31() { UpdateData(1);CGRP2Dlg o;o.q_a3(m_ch_a3);    UpdateData(0);}
void GRP2diagrm5::OnCHECKa41() { UpdateData(1);CGRP2Dlg o;o.q_a4(m_ch_a4);    UpdateData(0);}
void GRP2diagrm5::OnCHECKag3() { UpdateData(1);CGRP2Dlg o;o.q_ag3(m_ch_ag3);  UpdateData(0);}
void GRP2diagrm5::OnCHECKag41(){ UpdateData(1);CGRP2Dlg o;o.q_ag4(m_ch_ag4);  UpdateData(0);} 
void GRP2diagrm5::OnCHECKs() {   UpdateData(1);CGRP2Dlg o;o.q_sd(m_ch_s);     UpdateData(0);}
void GRP2diagrm5::OnCHECKsa3g() {UpdateData(1);CGRP2Dlg o;o.q_sa3g(m_ch_sa3g);UpdateData(0);}
void GRP2diagrm5::OnCHECKsa4g() {UpdateData(1);CGRP2Dlg o;o.q_sa4g(m_ch_sa4g);UpdateData(0);}
void GRP2diagrm5::OnCHECKsg() {  UpdateData(1);CGRP2Dlg o;o.q_sdg(m_ch_sg);   UpdateData(0);}
void GRP2diagrm5::OnCHECKsgx() { UpdateData(1);CGRP2Dlg o;o.q_sgam(m_ch_sgx); UpdateData(0);}
void GRP2diagrm5::OnCHECKx(){    UpdateData(1);CGRP2Dlg o;o.q_am(m_ch_x);     UpdateData(0);}

void GRP2diagrm5::OnCHECKini() { UpdateData(1);                               UpdateData(0);}

void GRP2diagrm5::OnVoreinstellungen() 
{
	UpdateData(1);

	m_X_gr=         1;       //am_Linienbreite
	m_sd_gr=        1;       //sd_Linienbreite
	m_sgx_gr=       1;       //s'am_Linienbreite 
	m_sdg_gr=       1;       //sd'_Linienbreite
	m_a3_gr=        1;       //a3_Linienbreite
	m_ag3_gr=       1;       //a3'_Linienbreite 
	m_sa3g_gr=      1;       //s'a3_Linienbreite
	m_a4_gr=        1;       //a4_Linienbreite
	m_ag4_gr=       1;       //a4'_Linienbreite
	m_sa4g_gr=      1;       //s'a4_Linienbreite
	Xp_clr=         8421504; //am_Farbe
	sd_clr=         8421504; //sd_Farbe
	sgx_clr=        8421504; //s'am_Farbe
	sdg_clr=        8421504; //sd'_Farbe 
	a3_clr=         8421504; //a3_Farbe
	ag3_clr=        8421504; //a3'_Farbe
	sa3g_clr=       8421504; //s'a3_Farbe
	a4_clr=         8421504; //a4_Farbe
	ag4_clr=        8421504; //a4'_Farbe
	sa4g_clr=       8421504; //s'a4_Farbe
	mod_X=          1;       //am_Modus
	m_X_art=       "Linie";  //
	mod_sd=         1;       //sd_Modus
	m_sd_art=      "Linie";  //
	mod_sgx=        2;       //s'am_Modus
	m_sgx_art=     "Punkt";  //
	mod_sdg=        3;       //sd'_Modus
	m_sdg_art=     "Strich"; //
	mod_a3=         1;       //a3_Modus
	m_a3_art=      "Linie";  //
	mod_ag3=        3;       //a3'_Modus
	m_ag3_art=     "Strich"; //
	mod_sa3g=       2;       //s'a3_Modus
	m_sa3g_art=    "Punkt";  //
	mod_a4=         1;       //a4_Modus
	m_a4_art=      "Linie";  //
	mod_ag4=        3;       //a4'_Modus
	m_ag4_art=     "Strich"; //
	mod_sa4g=       2;       //s'a4_Modus
	m_sa4g_art=    "Punkt";  //
	m_ch_x=         1;       //am_Theta_Darstellung
	m_ch_s=         1;       //sd_Theta_Darstellung
	m_ch_sg=        1;       //sd'_Theta_Darstellung
	m_ch_sgx=       2;       //s'am_Theta_Darstellung
	m_ch_a3=        2;       //a3_Theta_Darstellung
	m_ch_ag3=       2;       //a3'_Theta_Darstellung
	m_ch_sa3g=      1;       //s'a3_Theta_Darstellung
	m_ch_a4=        2;       //a4_Theta_Darstellung 
	m_ch_ag4=       2;       //a4'_Theta_Darstellung 
	m_ch_sa4g=      1;       //s'a4_Theta_Darstellung

	   CGRP2Dlg o;
				o.Xp_gr(m_X_gr) ; 
	            o.sd_gr(m_sd_gr) ;
	            o.sgx_gr(m_sgx_gr) ;
	            o.sdg_gr(m_sdg_gr) ;
	            o.a3_gr(m_a3_gr) ;
	            o.ag3_gr(m_ag3_gr) ;
	            o.sa3g_gr(m_sa3g_gr) ;   
				o.a4_gr(m_a4_gr) ;         
				o.ag4_gr(m_ag4_gr) ;      
				o.sa4g_gr(m_sa4g_gr) ;   
				o.clr_Xp(Xp_clr)    ; 
                o.clr_sd(sd_clr)    ;
                o.clr_sgx(sgx_clr)  ;
                o.clr_sdg(sdg_clr)  ;
				o.clr_a3(a3_clr)    ;  
				o.clr_ag3(ag3_clr)  ;
				o.clr_sa3g(sa3g_clr);
				o.clr_a4(a4_clr)    ;  
				o.clr_ag4(ag4_clr)  ;  
				o.clr_sa4g(sa4g_clr);  
				o.Xp_art(m_X_art) ;  
				o.sd_art(m_sd_art);   
				o.sgx_art(m_sgx_art) ;  
				o.sdg_art(m_sdg_art) ;         
				o.a3_art(m_a3_art) ;    
				o.ag3_art(m_ag3_art) ;
				o.sa3g_art(m_sa3g_art) ;
				o.a4_art(m_a4_art) ;    
				o.ag4_art(m_ag4_art) ;  
				o.sa4g_art(m_sa4g_art) ;  
				o.q_am(m_ch_x);  
				o.q_sd(m_ch_s);  
			    o.q_sdg(m_ch_sg); 
			    o.q_sgam(m_ch_sgx); 
			    o.q_a3(m_ch_a3);    
				o.q_ag3(m_ch_ag3);
			    o.q_sa3g(m_ch_sa3g);
			    o.q_a4(m_ch_a4);    
				o.q_ag4(m_ch_ag4);   
				o.q_sa4g(m_ch_sa4g);

	RedrawWindow();
				
	UpdateData(0);
}

void GRP2diagrm5::OnOK() 
{
	                                                 CRect coord;
	                                        GetWindowRect(&coord); 
	
	                             CWinApp* pApp = AfxGetApp(); // ini profil schreiben  
	if(m_ch_ini)
	{
										  pApp->WriteProfileInt("Funktion","am_Linienbreite",m_X_gr);
										  pApp->WriteProfileInt("Funktion","sd_Linienbreite",m_sd_gr);
										  pApp->WriteProfileInt("Funktion","s'am_Linienbreite",m_sgx_gr);
										  pApp->WriteProfileInt("Funktion","sd'_Linienbreite",m_sdg_gr);
										  pApp->WriteProfileInt("Funktion","a3_Linienbreite",m_a3_gr);
										  pApp->WriteProfileInt("Funktion","a3'_Linienbreite",m_ag3_gr);
									      pApp->WriteProfileInt("Funktion","s'a3_Linienbreite",m_sa3g_gr );
										  pApp->WriteProfileInt("Funktion","a4_Linienbreite",m_a4_gr);
										  pApp->WriteProfileInt("Funktion","a4'_Linienbreite",m_ag4_gr );
									      pApp->WriteProfileInt("Funktion","s'a4_Linienbreite", m_sa4g_gr);
										  pApp->WriteProfileInt("Funktion","am_Farbe",Xp_clr);
										  pApp->WriteProfileInt("Funktion","sd_Farbe",sd_clr);
										  pApp->WriteProfileInt("Funktion","s'am_Farbe",sgx_clr );
										  pApp->WriteProfileInt("Funktion","sd'_Farbe",sdg_clr );
										  pApp->WriteProfileInt("Funktion","a3_Farbe",a3_clr);
										  pApp->WriteProfileInt("Funktion","a3'_Farbe",ag3_clr );
										  pApp->WriteProfileInt("Funktion","s'a3_Farbe",sa3g_clr);
										  pApp->WriteProfileInt("Funktion","a4_Farbe",a4_clr );
	                                      pApp->WriteProfileInt("Funktion","a4'_Farbe",ag4_clr);
	                                      pApp->WriteProfileInt("Funktion","s'a4_Farbe",sa4g_clr );	
		if(m_X_art=="Linie")              pApp->WriteProfileInt("Funktion","am_Modus",1);
		if(m_X_art=="Punkt")              pApp->WriteProfileInt("Funktion","am_Modus",2);
		if(m_X_art=="Strich")             pApp->WriteProfileInt("Funktion","am_Modus",3);
		if(m_X_art=="Strichpunkt")        pApp->WriteProfileInt("Funktion","am_Modus",4);
		if(m_X_art=="Strichdoppelpkt.")   pApp->WriteProfileInt("Funktion","am_Modus",5);
		if(m_sd_art=="Linie")             pApp->WriteProfileInt("Funktion","sd_Modus",1);
		if(m_sd_art=="Punkt")             pApp->WriteProfileInt("Funktion","sd_Modus",2);
		if(m_sd_art=="Strich")            pApp->WriteProfileInt("Funktion","sd_Modus",3);
		if(m_sd_art=="Strichpunkt")       pApp->WriteProfileInt("Funktion","sd_Modus",4);
		if(m_sd_art=="Strichdoppelpkt.")  pApp->WriteProfileInt("Funktion","sd_Modus",5);
		if(m_sgx_art=="Linie")            pApp->WriteProfileInt("Funktion","s'am_Modus",1);
		if(m_sgx_art=="Punkt")            pApp->WriteProfileInt("Funktion","s'am_Modus",2);
		if(m_sgx_art=="Strich")           pApp->WriteProfileInt("Funktion","s'am_Modus",3);
		if(m_sgx_art=="Strichpunkt")      pApp->WriteProfileInt("Funktion","s'am_Modus",4);
		if(m_sgx_art=="Strichdoppelpkt.") pApp->WriteProfileInt("Funktion","s'am_Modus",5);
		if(m_sdg_art=="Linie")            pApp->WriteProfileInt("Funktion","sd'_Modus",1);
		if(m_sdg_art=="Punkt")            pApp->WriteProfileInt("Funktion","sd'_Modus",2);
		if(m_sdg_art=="Strich")           pApp->WriteProfileInt("Funktion","sd'_Modus",3);
		if(m_sdg_art=="Strichpunkt")      pApp->WriteProfileInt("Funktion","sd'_Modus",4);
		if(m_sdg_art=="Strichdoppelpkt.") pApp->WriteProfileInt("Funktion","sd'_Modus",5);
		if(m_a3_art=="Linie")             pApp->WriteProfileInt("Funktion","a3_Modus",1);
		if(m_a3_art=="Punkt")             pApp->WriteProfileInt("Funktion","a3_Modus",2);
		if(m_a3_art=="Strich")            pApp->WriteProfileInt("Funktion","a3_Modus",3);
		if(m_a3_art=="Strichpunkt")       pApp->WriteProfileInt("Funktion","a3_Modus",4);
		if(m_a3_art=="Strichdoppelpkt.")  pApp->WriteProfileInt("Funktion","a3_Modus",5);
		if(m_ag3_art=="Linie")            pApp->WriteProfileInt("Funktion","a3'_Modus",1);
		if(m_ag3_art=="Punkt")            pApp->WriteProfileInt("Funktion","a3'_Modus",2);
		if(m_ag3_art=="Strich")           pApp->WriteProfileInt("Funktion","a3'_Modus",3);
		if(m_ag3_art=="Strichpunkt")      pApp->WriteProfileInt("Funktion","a3'_Modus",4);
		if(m_ag3_art=="Strichdoppelpkt.") pApp->WriteProfileInt("Funktion","a3'_Modus",5);
		if(m_sa3g_art=="Linie")           pApp->WriteProfileInt("Funktion","s'a3_Modus",1);
		if(m_sa3g_art=="Punkt")           pApp->WriteProfileInt("Funktion","s'a3_Modus",2);
		if(m_sa3g_art=="Strich")          pApp->WriteProfileInt("Funktion","s'a3_Modus",3);
		if(m_sa3g_art=="Strichpunkt")     pApp->WriteProfileInt("Funktion","s'a3_Modus",4);
		if(m_sa3g_art=="Strichdoppelpkt.")pApp->WriteProfileInt("Funktion","s'a3_Modus",5);
		if(m_a4_art=="Linie")             pApp->WriteProfileInt("Funktion","a4_Modus",1);
		if(m_a4_art=="Punkt")             pApp->WriteProfileInt("Funktion","a4_Modus",2);
		if(m_a4_art=="Strich")            pApp->WriteProfileInt("Funktion","a4_Modus",3);
		if(m_a4_art=="Strichpunkt")       pApp->WriteProfileInt("Funktion","a4_Modus",4);
		if(m_a4_art=="Strichdoppelpkt.")  pApp->WriteProfileInt("Funktion","a4_Modus",5);
		if(m_ag4_art=="Linie")            pApp->WriteProfileInt("Funktion","a4'_Modus",1);
		if(m_ag4_art=="Punkt")            pApp->WriteProfileInt("Funktion","a4'_Modus",2);
		if(m_ag4_art=="Strich")           pApp->WriteProfileInt("Funktion","a4'_Modus",3);
		if(m_ag4_art=="Strichpunkt")      pApp->WriteProfileInt("Funktion","a4'_Modus",4);
		if(m_ag4_art=="Strichdoppelpkt.") pApp->WriteProfileInt("Funktion","a4'_Modus",5);
		if(m_sa4g_art=="Linie")           pApp->WriteProfileInt("Funktion","sa4'_Modus",1);
		if(m_sa4g_art=="Punkt")           pApp->WriteProfileInt("Funktion","sa4'_Modus",2);
		if(m_sa4g_art=="Strich")          pApp->WriteProfileInt("Funktion","sa4'_Modus",3);
		if(m_sa4g_art=="Strichpunkt")     pApp->WriteProfileInt("Funktion","sa4'_Modus",4);
		if(m_sa4g_art=="Strichdoppelpkt.")pApp->WriteProfileInt("Funktion","sa4'_Modus",5);
	                                      pApp->WriteProfileInt("Funktion","am_Theta_Darstellung",m_ch_x ); 
	                                      pApp->WriteProfileInt("Funktion","sd_Theta_Darstellung",m_ch_s); 
	                                      pApp->WriteProfileInt("Funktion","sd'_Theta_Darstellung",m_ch_sg); 
	                                      pApp->WriteProfileInt("Funktion","s'am_Theta_Darstellung",m_ch_sgx); 
	                                      pApp->WriteProfileInt("Funktion","a3_Theta_Darstellung",m_ch_a3);
	                                      pApp->WriteProfileInt("Funktion","a3'_Theta_Darstellung",m_ch_ag3); 
	                                      pApp->WriteProfileInt("Funktion","s'a3_Theta_Darstellung",m_ch_sa3g); 
	                                      pApp->WriteProfileInt("Funktion","a4_Theta_Darstellung",m_ch_a4); 
	                                      pApp->WriteProfileInt("Funktion","a4'_Theta_Darstellung",m_ch_ag4);
	                                      pApp->WriteProfileInt("Funktion","s'a4_Theta_Darstellung",m_ch_sa4g); 
	}
	                                      pApp->WriteProfileInt("INI_schreiben","diagrm5",m_ch_ini);
			                              pApp->WriteProfileInt("Diagramm","Tabelle",5);
			                              pApp->WriteProfileInt("Diagramm","Position_x",coord.left);
			                              pApp->WriteProfileInt("Diagramm","Position_y",coord.top);
	CDialog::OnOK();
}








