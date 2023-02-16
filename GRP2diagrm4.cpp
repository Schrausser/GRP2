//------------------------------------------------------------------------| GRP2diagrm4.cpp                              //
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

GRP2diagrm4::GRP2diagrm4(CWnd* pParent /*=NULL*/)
	: CDialog(GRP2diagrm4::IDD, pParent)
{
	//{{AFX_DATA_INIT(GRP2diagrm4)
	m_ch_ini = 1;
	m_rxy_art = _T("");
	m_ryx_art = _T("");
	m_s1xy_art = _T("");
	m_s1yx_art = _T("");
	m_srx_art = _T("");
	m_srxy_art = _T("");
	m_sry_art = _T("");
	m_sryx_art = _T("");
	m_sxy_art = _T("");
	m_syx_art = _T("");
	m_rxy_gr = 0;
	m_ryx_gr = 0;
	m_s1xy_gr = 0;
	m_s1yx_gr = 0;
	m_srx_gr = 0;
	m_srxy_gr = 0;
	m_sry_gr = 0;
	m_sryx_gr = 0;
	m_sxy_gr = 0;
	m_syx_gr = 0;
	m_ch_rxy = 1; //tristate 0,1,2
	m_ch_ryx = 1;
	m_ch_sgxy = 1;
	m_ch_sgyx = 1;
	m_ch_srx = 1;
	m_ch_srxy = 1;
	m_ch_sry = 1;
	m_ch_sryx = 1;
	m_ch_sxy = 1;
	m_ch_syx = 1;
	//}}AFX_DATA_INIT
}

void GRP2diagrm4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GRP2diagrm4)
	DDX_Control(pDX, IDC_TAB2, m_tab);
	DDX_Check(pDX, IDC_CHECK_ini, m_ch_ini);
	DDX_CBString(pDX, IDC_COMBO_rxy_art, m_rxy_art);
	DDX_CBString(pDX, IDC_COMBO_ryx_art, m_ryx_art);
	DDX_CBString(pDX, IDC_COMBO_s1xy_art, m_s1xy_art);
	DDX_CBString(pDX, IDC_COMBO_s1yx_art, m_s1yx_art);
	DDX_CBString(pDX, IDC_COMBO_srx_art, m_srx_art);
	DDX_CBString(pDX, IDC_COMBO_srxy_art, m_srxy_art);
	DDX_CBString(pDX, IDC_COMBO_sry_art, m_sry_art);
	DDX_CBString(pDX, IDC_COMBO_sryx_art, m_sryx_art);
	DDX_CBString(pDX, IDC_COMBO_sxy_art, m_sxy_art);
	DDX_CBString(pDX, IDC_COMBO_syx_art, m_syx_art);
	DDX_Text(pDX, IDC_EDIT_rxy_gr, m_rxy_gr);
	DDX_Text(pDX, IDC_EDIT_ryx_gr, m_ryx_gr);
	DDX_Text(pDX, IDC_EDIT_s1xy_gr, m_s1xy_gr);
	DDX_Text(pDX, IDC_EDIT_s1yx_gr, m_s1yx_gr);
	DDX_Text(pDX, IDC_EDIT_srx_gr, m_srx_gr);
	DDX_Text(pDX, IDC_EDIT_srxy_gr, m_srxy_gr);
	DDX_Text(pDX, IDC_EDIT_sry_gr, m_sry_gr);
	DDX_Text(pDX, IDC_EDIT_sryx_gr, m_sryx_gr);
	DDX_Text(pDX, IDC_EDIT_sxy_gr, m_sxy_gr);
	DDX_Text(pDX, IDC_EDIT_syx_gr, m_syx_gr);
	DDX_Check(pDX, IDC_CHECK_rxy, m_ch_rxy);
	DDX_Check(pDX, IDC_CHECK_ryx, m_ch_ryx);
	DDX_Check(pDX, IDC_CHECK_sgxy, m_ch_sgxy);
	DDX_Check(pDX, IDC_CHECK_sgyx, m_ch_sgyx);
	DDX_Check(pDX, IDC_CHECK_srx, m_ch_srx);
	DDX_Check(pDX, IDC_CHECK_srxy, m_ch_srxy);
	DDX_Check(pDX, IDC_CHECK_sry, m_ch_sry);
	DDX_Check(pDX, IDC_CHECK_sryx, m_ch_sryx);
	DDX_Check(pDX, IDC_CHECK_sxy, m_ch_sxy);
	DDX_Check(pDX, IDC_CHECK_syx, m_ch_syx);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(GRP2diagrm4, CDialog)
	//{{AFX_MSG_MAP(GRP2diagrm4)
	ON_BN_CLICKED(IDC_CHECK_ini, OnCHECKini)
	ON_WM_PAINT()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB2, OnSelchangeTab2)
	ON_BN_CLICKED(IDC_BUTTON_rxy_fb, OnBUTTONrxyfb)
	ON_BN_CLICKED(IDC_BUTTON_ryx_fb, OnBUTTONryxfb)
	ON_BN_CLICKED(IDC_BUTTON_s1xy_fb, OnBUTTONs1xyfb)
	ON_BN_CLICKED(IDC_BUTTON_s1yx_fb, OnBUTTONs1yxfb)
	ON_BN_CLICKED(IDC_BUTTON_srx_fb, OnBUTTONsrxfb)
	ON_BN_CLICKED(IDC_BUTTON_srxy_fb, OnBUTTONsrxyfb)
	ON_BN_CLICKED(IDC_BUTTON_sry_fb, OnBUTTONsryfb)
	ON_BN_CLICKED(IDC_BUTTON_sryx_fb, OnBUTTONsryxfb)
	ON_BN_CLICKED(IDC_BUTTON_sxy_fb, OnBUTTONsxyfb)
	ON_BN_CLICKED(IDC_BUTTON_syx_fb, OnBUTTONsyxfb)
	ON_CBN_SELCHANGE(IDC_COMBO_rxy_art, OnSelchangeCOMBOrxyart)
	ON_CBN_SELCHANGE(IDC_COMBO_ryx_art, OnSelchangeCOMBOryxart)
	ON_CBN_SELCHANGE(IDC_COMBO_s1xy_art, OnSelchangeCOMBOs1xyart)
	ON_CBN_SELCHANGE(IDC_COMBO_s1yx_art, OnSelchangeCOMBOs1yxart)
	ON_CBN_SELCHANGE(IDC_COMBO_srx_art, OnSelchangeCOMBOsrxart)
	ON_CBN_SELCHANGE(IDC_COMBO_srxy_art, OnSelchangeCOMBOsrxyart)
	ON_CBN_SELCHANGE(IDC_COMBO_sry_art, OnSelchangeCOMBOsryart)
	ON_CBN_SELCHANGE(IDC_COMBO_sryx_art, OnSelchangeCOMBOsryxart)
	ON_CBN_SELCHANGE(IDC_COMBO_sxy_art, OnSelchangeCOMBOsxyart)
	ON_CBN_SELCHANGE(IDC_COMBO_syx_art, OnSelchangeCOMBOsyxart)
	ON_EN_CHANGE(IDC_EDIT_rxy_gr, OnChangeEDITrxygr)
	ON_EN_CHANGE(IDC_EDIT_ryx_gr, OnChangeEDITryxgr)
	ON_EN_CHANGE(IDC_EDIT_s1xy_gr, OnChangeEDITs1xygr)
	ON_EN_CHANGE(IDC_EDIT_s1yx_gr, OnChangeEDITs1yxgr)
	ON_EN_CHANGE(IDC_EDIT_srx_gr, OnChangeEDITsrxgr)
	ON_EN_CHANGE(IDC_EDIT_srxy_gr, OnChangeEDITsrxygr)
	ON_EN_CHANGE(IDC_EDIT_sry_gr, OnChangeEDITsrygr)
	ON_EN_CHANGE(IDC_EDIT_sryx_gr, OnChangeEDITsryxgr)
	ON_EN_CHANGE(IDC_EDIT_sxy_gr, OnChangeEDITsxygr)
	ON_EN_CHANGE(IDC_EDIT_syx_gr, OnChangeEDITsyxgr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_rxy_gr, OnDeltaposSPINrxygr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ryx_gr, OnDeltaposSPINryxgr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_s1xy_gr, OnDeltaposSPINs1xygr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_s1yx_gr, OnDeltaposSPINs1yxgr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_srx_gr, OnDeltaposSPINsrxgr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_srxy_gr, OnDeltaposSPINsrxygr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_sry_gr, OnDeltaposSPINsrygr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_sryx_gr, OnDeltaposSPINsryxgr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_sxy_gr, OnDeltaposSPINsxygr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_syx_gr, OnDeltaposSPINsyxgr)
	ON_BN_CLICKED(IDC_CHECK_rxy, OnCHECKrxy)
	ON_BN_CLICKED(IDC_CHECK_ryx, OnCHECKryx)
	ON_BN_CLICKED(IDC_CHECK_sgxy, OnCHECKsgxy)
	ON_BN_CLICKED(IDC_CHECK_sgyx, OnCHECKsgyx)
	ON_BN_CLICKED(IDC_CHECK_srx, OnCHECKsrx)
	ON_BN_CLICKED(IDC_CHECK_srxy, OnCHECKsrxy)
	ON_BN_CLICKED(IDC_CHECK_sry, OnCHECKsry)
	ON_BN_CLICKED(IDC_CHECK_sryx, OnCHECKsryx)
	ON_BN_CLICKED(IDC_CHECK_sxy, OnCHECKsxy)
	ON_BN_CLICKED(IDC_CHECK_syx, OnCHECKsyx)
	ON_BN_CLICKED(ID_Voreinstellungen, OnVoreinstellungen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL GRP2diagrm4::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
		UpdateData(1);

	            CWinApp*  pApp = AfxGetApp(); // ini profil lesen 

			  m_rxy_gr=   pApp->GetProfileInt("Funktion","rxy_Linienbreite",1);
			  m_ryx_gr=   pApp->GetProfileInt("Funktion","ryx_Linienbreite",1);
			  m_srxy_gr=  pApp->GetProfileInt("Funktion","srxy_Linienbreite",1);
			  m_sryx_gr=  pApp->GetProfileInt("Funktion","sryx_Linienbreite",1);
			  m_srx_gr=   pApp->GetProfileInt("Funktion","srx_Linienbreite",1);
			  m_sry_gr=   pApp->GetProfileInt("Funktion","sry_Linienbreite",1);
			  m_sxy_gr=   pApp->GetProfileInt("Funktion","sxy_Linienbreite",1);
			  m_syx_gr=   pApp->GetProfileInt("Funktion","syx_Linienbreite",1);
			  m_s1xy_gr=  pApp->GetProfileInt("Funktion","s'xy_Linienbreite",1);
			  m_s1yx_gr=  pApp->GetProfileInt("Funktion","s'yx_Linienbreite",1);
			  rxy_clr=    pApp->GetProfileInt("Funktion","rxy_Farbe",8421504);
			  ryx_clr=    pApp->GetProfileInt("Funktion","ryx_Farbe",8421504);
			  srxy_clr=   pApp->GetProfileInt("Funktion","srxy_Farbe",8421504);
			  sryx_clr=   pApp->GetProfileInt("Funktion","sryx_Farbe",8421504);
			  srx_clr=    pApp->GetProfileInt("Funktion","sry_Farbe",8421504);
			  sry_clr=    pApp->GetProfileInt("Funktion","srx_Farbe",8421504);
			  sxy_clr=    pApp->GetProfileInt("Funktion","sxy_Farbe",8421504);
			  syx_clr=    pApp->GetProfileInt("Funktion","syx_Farbe",8421504);
			  s1xy_clr=   pApp->GetProfileInt("Funktion","s'xy_Farbe",8421504);
			  s1yx_clr=   pApp->GetProfileInt("Funktion","s'yx_Farbe",8421504);
		      mod_rxy=    pApp->GetProfileInt("Funktion","rxy_Modus",1);
		   if(mod_rxy==1)m_rxy_art="Linie";
		   if(mod_rxy==2)m_rxy_art="Punkt";
		   if(mod_rxy==3)m_rxy_art="Strich";
		   if(mod_rxy==4)m_rxy_art="Strichpunkt";
		   if(mod_rxy==5)m_rxy_art="Strichdoppelpkt.";
		      mod_ryx=    pApp->GetProfileInt("Funktion","ryx_Modus",1);
		   if(mod_ryx==1)m_ryx_art="Linie";
		   if(mod_ryx==2)m_ryx_art="Punkt";
		   if(mod_ryx==3)m_ryx_art="Strich";
		   if(mod_ryx==4)m_ryx_art="Strichpunkt";
		   if(mod_ryx==5)m_ryx_art="Strichdoppelpkt.";
		      mod_srxy=   pApp->GetProfileInt("Funktion","srxy_Modus",2);
		   if(mod_srxy==1)m_srxy_art="Linie";
		   if(mod_srxy==2)m_srxy_art="Punkt";
		   if(mod_srxy==3)m_srxy_art="Strich";
		   if(mod_srxy==4)m_srxy_art="Strichpunkt";
		   if(mod_srxy==5)m_srxy_art="Strichdoppelpkt.";
		      mod_sryx=   pApp->GetProfileInt("Funktion","sryx_Modus",2);
		   if(mod_sryx==1)m_sryx_art="Linie";
		   if(mod_sryx==2)m_sryx_art="Punkt";
		   if(mod_sryx==3)m_sryx_art="Strich";
		   if(mod_sryx==4)m_sryx_art="Strichpunkt";
		   if(mod_sryx==5)m_sryx_art="Strichdoppelpkt.";
		      mod_srx=    pApp->GetProfileInt("Funktion","sry_Modus",2);
		   if(mod_srx==1)m_srx_art="Linie";
		   if(mod_srx==2)m_srx_art="Punkt";
		   if(mod_srx==3)m_srx_art="Strich";
		   if(mod_srx==4)m_srx_art="Strichpunkt";
		   if(mod_srx==5)m_srx_art="Strichdoppelpkt.";
		      mod_sry=    pApp->GetProfileInt("Funktion","srx_Modus",2);
		   if(mod_sry==1)m_sry_art="Linie";
		   if(mod_sry==2)m_sry_art="Punkt";
		   if(mod_sry==3)m_sry_art="Strich";
		   if(mod_sry==4)m_sry_art="Strichpunkt";
		   if(mod_sry==5)m_sry_art="Strichdoppelpkt.";
		      mod_sxy=    pApp->GetProfileInt("Funktion","sxy_Modus",1);
		   if(mod_sxy==1)m_sxy_art="Linie";
		   if(mod_sxy==2)m_sxy_art="Punkt";
		   if(mod_sxy==3)m_sxy_art="Strich";
		   if(mod_sxy==4)m_sxy_art="Strichpunkt";
		   if(mod_sxy==5)m_sxy_art="Strichdoppelpkt.";
		      mod_syx=    pApp->GetProfileInt("Funktion","syx_Modus",1);
		   if(mod_syx==1)m_syx_art="Linie";
		   if(mod_syx==2)m_syx_art="Punkt";
		   if(mod_syx==3)m_syx_art="Strich";
		   if(mod_syx==4)m_syx_art="Strichpunkt";
		   if(mod_syx==5)m_syx_art="Strichdoppelpkt.";
		      mod_s1xy=   pApp->GetProfileInt("Funktion","s'xy_Modus",3);
		   if(mod_s1xy==1)m_s1xy_art="Linie";
		   if(mod_s1xy==2)m_s1xy_art="Punkt";
		   if(mod_s1xy==3)m_s1xy_art="Strich";
		   if(mod_s1xy==4)m_s1xy_art="Strichpunkt";
		   if(mod_s1xy==5)m_s1xy_art="Strichdoppelpkt.";
		      mod_s1yx=   pApp->GetProfileInt("Funktion","s'yx_Modus",3);
		   if(mod_s1yx==1)m_s1yx_art="Linie";
		   if(mod_s1yx==2)m_s1yx_art="Punkt";
		   if(mod_s1yx==3)m_s1yx_art="Strich";
		   if(mod_s1yx==4)m_s1yx_art="Strichpunkt";
		   if(mod_s1yx==5)m_s1yx_art="Strichdoppelpkt.";
		      m_ch_rxy=   pApp->GetProfileInt("Funktion","rxy_Theta_Darstellung",1);
	          m_ch_ryx=   pApp->GetProfileInt("Funktion","ryx_Theta_Darstellung",1); 
	          m_ch_syx=   pApp->GetProfileInt("Funktion","syx_Theta_Darstellung",1); 
	          m_ch_sxy=   pApp->GetProfileInt("Funktion","sxy_Theta_Darstellung",1); 
	          m_ch_sgyx=  pApp->GetProfileInt("Funktion","s'yx_Theta_Darstellung",1);
	          m_ch_sgxy=  pApp->GetProfileInt("Funktion","s'xy_Theta_Darstellung",1); 
	          m_ch_srxy=  pApp->GetProfileInt("Funktion","srxy_Theta_Darstellung",2); 
	          m_ch_sryx=  pApp->GetProfileInt("Funktion","sryx_Theta_Darstellung",2); 
	          m_ch_srx=   pApp->GetProfileInt("Funktion","srx_Theta_Darstellung",0);
	          m_ch_sry=   pApp->GetProfileInt("Funktion","sry_Theta_Darstellung",0); 

               m_ch_ini=  pApp->GetProfileInt("INI_schreiben","diagrm4",1);

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
				         
				m_tab.SetCurSel(  3);

	UpdateData(0);

	return 1;  	             
}

void GRP2diagrm4::OnPaint() 
{
	CPaintDC ooo(this);
	                              UINT pos=50;
			             CRect o1(197, pos, 211, pos+13);
			 ooo.FillSolidRect(o1, rxy_clr ); 

			             CRect o2(197, pos+23*1, 211, pos+23*1+13);
			 ooo.FillSolidRect(o2, ryx_clr ); 

			             CRect o3(197, pos+23*2, 211, pos+23*2+13);
			 ooo.FillSolidRect(o3, syx_clr ); 

			             CRect o4(197, pos+23*3-1, 211, pos+23*3+13-1);
			 ooo.FillSolidRect(o4, sxy_clr ); 

			             CRect o5(197, pos+23*4-1, 211, pos+23*4+13-1);
			 ooo.FillSolidRect(o5, s1yx_clr ); 

			             CRect o6(197, pos+23*5-1, 211, pos+23*5+13-1);
			 ooo.FillSolidRect(o6, s1xy_clr ); 

			             CRect o7(197, pos+23*6-1, 211, pos+23*6+13-1);
			 ooo.FillSolidRect(o7, srxy_clr ); 

			             CRect o8(197, pos+23*7-2, 211, pos+23*7+13-2);
			 ooo.FillSolidRect(o8, sryx_clr ); 

			             CRect o9(197, pos+23*8-2, 211, pos+23*8+13-2);
			 ooo.FillSolidRect(o9, srx_clr ); 

			             CRect o10(197, pos+23*9-2, 211, pos+23*9+13-2);
			 ooo.FillSolidRect(o10, sry_clr );	
}

void GRP2diagrm4::OnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if(m_tab.GetCurSel() ==0){OnOK();GRP2diagrm1 o;o.DoModal();}
	if(m_tab.GetCurSel() ==1){OnOK();GRP2diagrm2 o;o.DoModal();}
	if(m_tab.GetCurSel() ==2){OnOK();GRP2diagrm3 o;o.DoModal();}
	if(m_tab.GetCurSel() ==3);
	if(m_tab.GetCurSel() ==4){OnOK();GRP2diagrm5 o;o.DoModal();}
	if(m_tab.GetCurSel() ==5){OnOK();GRP2diagrm6 o;o.DoModal();}

	*pResult = 0;
}
  
void GRP2diagrm4::OnChangeEDITrxygr(){        UpdateData(1); CGRP2Dlg o;o.rxy_gr(m_rxy_gr) ;    UpdateData(0);}
void GRP2diagrm4::OnChangeEDITryxgr(){        UpdateData(1); CGRP2Dlg o;o.ryx_gr(m_ryx_gr) ;    UpdateData(0);}
void GRP2diagrm4::OnChangeEDITs1xygr(){       UpdateData(1); CGRP2Dlg o;o.s1xy_gr(m_s1xy_gr) ;  UpdateData(0);}
void GRP2diagrm4::OnChangeEDITs1yxgr(){       UpdateData(1); CGRP2Dlg o;o.s1yx_gr(m_s1yx_gr) ;  UpdateData(0);}
void GRP2diagrm4::OnChangeEDITsrxgr(){        UpdateData(1); CGRP2Dlg o;o.srx_gr(m_srx_gr) ;    UpdateData(0);}
void GRP2diagrm4::OnChangeEDITsrxygr(){       UpdateData(1); CGRP2Dlg o;o.srxy_gr(m_srxy_gr) ;  UpdateData(0);}
void GRP2diagrm4::OnChangeEDITsrygr(){        UpdateData(1); CGRP2Dlg o;o.sry_gr(m_sry_gr) ;    UpdateData(0);} 
void GRP2diagrm4::OnChangeEDITsryxgr(){       UpdateData(1); CGRP2Dlg o;o.sryx_gr(m_sryx_gr) ;  UpdateData(0);} 
void GRP2diagrm4::OnChangeEDITsxygr(){        UpdateData(1); CGRP2Dlg o;o.sxy_gr(m_sxy_gr) ;    UpdateData(0);}
void GRP2diagrm4::OnChangeEDITsyxgr(){        UpdateData(1); CGRP2Dlg o;o.syx_gr(m_syx_gr) ;    UpdateData(0);}
void GRP2diagrm4::OnSelchangeCOMBOrxyart(){   UpdateData(1); CGRP2Dlg o;o.rxy_art(m_rxy_art) ;  UpdateData(0);} 
void GRP2diagrm4::OnSelchangeCOMBOryxart(){   UpdateData(1); CGRP2Dlg o;o.ryx_art(m_ryx_art) ;  UpdateData(0);} 
void GRP2diagrm4::OnSelchangeCOMBOs1xyart(){  UpdateData(1); CGRP2Dlg o;o.s1xy_art(m_s1xy_art) ;UpdateData(0);} 
void GRP2diagrm4::OnSelchangeCOMBOs1yxart(){  UpdateData(1); CGRP2Dlg o;o.s1yx_art(m_s1yx_art) ;UpdateData(0);}
void GRP2diagrm4::OnSelchangeCOMBOsrxart(){   UpdateData(1); CGRP2Dlg o;o.srx_art(m_srx_art) ;  UpdateData(0);}
void GRP2diagrm4::OnSelchangeCOMBOsrxyart(){  UpdateData(1); CGRP2Dlg o;o.srxy_art(m_srxy_art) ;UpdateData(0);}
void GRP2diagrm4::OnSelchangeCOMBOsryart(){   UpdateData(1); CGRP2Dlg o;o.sry_art(m_sry_art) ;  UpdateData(0);}
void GRP2diagrm4::OnSelchangeCOMBOsryxart(){  UpdateData(1); CGRP2Dlg o;o.sryx_art(m_sryx_art) ;UpdateData(0);} 
void GRP2diagrm4::OnSelchangeCOMBOsxyart(){   UpdateData(1); CGRP2Dlg o;o.sxy_art(m_sxy_art);   UpdateData(0);} 
void GRP2diagrm4::OnSelchangeCOMBOsyxart(){   UpdateData(1); CGRP2Dlg o;o.syx_art(m_syx_art) ;  UpdateData(0);}

void GRP2diagrm4::OnDeltaposSPINrxygr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
		
	if(pNMUpDown->iDelta < 0)               m_rxy_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_rxy_gr>0) m_rxy_gr-=1;
		                   
	UpdateData(0); OnChangeEDITrxygr();
	
	*pResult = 0;
}

void GRP2diagrm4::OnDeltaposSPINryxgr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)               m_ryx_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_ryx_gr>0) m_ryx_gr-=1;
		                   
	UpdateData(0); OnChangeEDITryxgr();
	
	*pResult = 0;
}

void GRP2diagrm4::OnDeltaposSPINs1xygr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)                m_s1xy_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_s1xy_gr>0) m_s1xy_gr-=1;
		                   
	UpdateData(0); OnChangeEDITs1xygr();
	
	*pResult = 0;
}

void GRP2diagrm4::OnDeltaposSPINs1yxgr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)                m_s1yx_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_s1yx_gr>0) m_s1yx_gr-=1;
		                   
	UpdateData(0); OnChangeEDITs1yxgr();

	*pResult = 0;
}

void GRP2diagrm4::OnDeltaposSPINsrxgr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)               m_srx_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_srx_gr>0) m_srx_gr-=1;
		                   
	UpdateData(0); OnChangeEDITsrxgr();
	
	*pResult = 0;
}

void GRP2diagrm4::OnDeltaposSPINsrxygr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)                m_srxy_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_srxy_gr>0) m_srxy_gr-=1;
		                   
	UpdateData(0); OnChangeEDITsrxygr();
	
	*pResult = 0;
}

void GRP2diagrm4::OnDeltaposSPINsrygr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)               m_sry_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_sry_gr>0) m_sry_gr-=1;
		                   
	UpdateData(0); OnChangeEDITsrygr();
	
	*pResult = 0;
}

void GRP2diagrm4::OnDeltaposSPINsryxgr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)                m_sryx_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_sryx_gr>0) m_sryx_gr-=1;
		                   
	UpdateData(0); OnChangeEDITsryxgr();
	
	*pResult = 0;
}

void GRP2diagrm4::OnDeltaposSPINsxygr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)               m_sxy_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_sxy_gr>0) m_sxy_gr-=1;
		                   
	UpdateData(0); OnChangeEDITsxygr();
	
	*pResult = 0;
}

void GRP2diagrm4::OnDeltaposSPINsyxgr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)               m_syx_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_syx_gr>0) m_syx_gr-=1;
		                   
	UpdateData(0); OnChangeEDITsyxgr();
	
	*pResult = 0;
}

void GRP2diagrm4::OnBUTTONrxyfb(){ CColorDialog cl(rxy_clr,0,0); cl.DoModal();rxy_clr=cl.GetColor(); RedrawWindow();CGRP2Dlg o; o.clr_rxy(rxy_clr)  ;} 
void GRP2diagrm4::OnBUTTONryxfb(){ CColorDialog cl(ryx_clr,0,0); cl.DoModal();ryx_clr=cl.GetColor(); RedrawWindow();CGRP2Dlg o; o.clr_ryx(ryx_clr)  ;}  
void GRP2diagrm4::OnBUTTONs1xyfb(){CColorDialog cl(s1xy_clr,0,0);cl.DoModal();s1xy_clr=cl.GetColor();RedrawWindow();CGRP2Dlg o; o.clr_s1xy(s1xy_clr);}  
void GRP2diagrm4::OnBUTTONs1yxfb(){CColorDialog cl(s1yx_clr,0,0);cl.DoModal();s1yx_clr=cl.GetColor();RedrawWindow();CGRP2Dlg o; o.clr_s1yx(s1yx_clr);}  
void GRP2diagrm4::OnBUTTONsrxfb(){ CColorDialog cl(srx_clr,0,0); cl.DoModal();srx_clr=cl.GetColor(); RedrawWindow();CGRP2Dlg o; o.clr_srx(srx_clr)  ;}  
void GRP2diagrm4::OnBUTTONsrxyfb(){CColorDialog cl(srxy_clr,0,0);cl.DoModal();srxy_clr=cl.GetColor();RedrawWindow();CGRP2Dlg o; o.clr_srxy(srxy_clr);}  
void GRP2diagrm4::OnBUTTONsryfb(){ CColorDialog cl(sry_clr,0,0); cl.DoModal();sry_clr=cl.GetColor(); RedrawWindow();CGRP2Dlg o; o.clr_sry(sry_clr)  ;}  
void GRP2diagrm4::OnBUTTONsryxfb(){CColorDialog cl(sryx_clr,0,0);cl.DoModal();sryx_clr=cl.GetColor();RedrawWindow();CGRP2Dlg o; o.clr_sryx(sryx_clr);}  
void GRP2diagrm4::OnBUTTONsxyfb(){ CColorDialog cl(sxy_clr,0,0); cl.DoModal();sxy_clr=cl.GetColor(); RedrawWindow();CGRP2Dlg o; o.clr_sxy(sxy_clr)  ;}  
void GRP2diagrm4::OnBUTTONsyxfb(){ CColorDialog cl(syx_clr,0,0); cl.DoModal();syx_clr=cl.GetColor(); RedrawWindow();CGRP2Dlg o; o.clr_syx(syx_clr)  ;}  

void GRP2diagrm4::OnCHECKrxy() { UpdateData(1);CGRP2Dlg o;o.q_rxy(m_ch_rxy);  UpdateData(0);}
void GRP2diagrm4::OnCHECKryx() { UpdateData(1);CGRP2Dlg o;o.q_ryx(m_ch_ryx);  UpdateData(0);}
void GRP2diagrm4::OnCHECKsgxy() {UpdateData(1);CGRP2Dlg o;o.q_sgxy(m_ch_sgxy);UpdateData(0);}
void GRP2diagrm4::OnCHECKsgyx() {UpdateData(1);CGRP2Dlg o;o.q_sgyx(m_ch_sgyx);UpdateData(0);}
void GRP2diagrm4::OnCHECKsrx() { UpdateData(1);CGRP2Dlg o;o.q_srx(m_ch_srx);  UpdateData(0);}
void GRP2diagrm4::OnCHECKsrxy() {UpdateData(1);CGRP2Dlg o;o.q_srxy(m_ch_srxy);UpdateData(0);}
void GRP2diagrm4::OnCHECKsry() { UpdateData(1);CGRP2Dlg o;o.q_sry(m_ch_sry);  UpdateData(0);}
void GRP2diagrm4::OnCHECKsryx() {UpdateData(1);CGRP2Dlg o;o.q_sryx(m_ch_sryx);UpdateData(0);}
void GRP2diagrm4::OnCHECKsxy() { UpdateData(1);CGRP2Dlg o;o.q_sxy(m_ch_sxy);  UpdateData(0);}
void GRP2diagrm4::OnCHECKsyx() { UpdateData(1);CGRP2Dlg o;o.q_syx(m_ch_syx);  UpdateData(0);}

void GRP2diagrm4::OnCHECKini() { UpdateData(1);                               UpdateData(0);}

void GRP2diagrm4::OnVoreinstellungen() 
{
	UpdateData(1);

	m_rxy_gr=   1;      //rxy_Linienbreite
	m_ryx_gr=   1;      //ryx_Linienbreite
	m_srxy_gr=  1;      //srxy_Linienbreite
	m_sryx_gr=  1;      //sryx_Linienbreite
	m_srx_gr=   1;      //sry_Linienbreite
	m_sry_gr=   1;      //srx_Linienbreite
	m_sxy_gr=   1;      //sxy_Linienbreite
	m_syx_gr=   1;      //syx_Linienbreite
	m_s1xy_gr=  1;      //s'xy_Linienbreite
	m_s1yx_gr=  1;      //s'yx_Linienbreite
	rxy_clr=    8421504;//rxy_Farbe
	ryx_clr=    8421504;//ryx_Farbe
	srxy_clr=   8421504;//srxy_Farbe
	sryx_clr=   8421504;//sryx_Farbe
	srx_clr=    8421504;//sry_Farbe
	sry_clr=    8421504;//srx_Farbe
	sxy_clr=    8421504;//sxy_Farbe
	syx_clr=    8421504;//syx_Farbe
	s1xy_clr=   8421504;//s'xy_Farbe
	s1yx_clr=   8421504;//s'yx_Farbe
	mod_rxy=    1;      //rxy_Modus
	m_rxy_art= "Linie"; //
	mod_ryx=    1;      //ryx_Modus
    m_ryx_art= "Linie"; //
	mod_srxy=   2;      //srxy_Modus 
	m_srxy_art="Punkt"; //
	mod_sryx=   2;      //sryx_Modus
	m_sryx_art="Punkt"; //
	mod_srx=    2;      //srx_Modus
	m_srx_art= "Punkt"; //
	mod_sry=    2;      //sry_Modus
	m_sry_art= "Punkt"; //
	mod_sxy=    1;      //sxy_Modus
	m_sxy_art= "Linie"; //
	mod_syx=    1;      //syx_Modus
	m_syx_art= "Linie"; //
	mod_s1xy=   3;      //s'xy_Modus
	m_s1xy_art="Strich";//
	mod_s1yx=   3;      //s'yx_Modus
	m_s1yx_art="Strich";//
	m_ch_rxy=   1;      //rxy_Theta_Darstellung"
	m_ch_ryx=   1;      //ryx_Theta_Darstellung
	m_ch_syx=   1;      //syx_Theta_Darstellung
	m_ch_sxy=   1;      //sxy_Theta_Darstellung 
	m_ch_sgyx=  1;      //s'yx_Theta_Darstellung
	m_ch_sgxy=  1;      //s'xy_Theta_Darstellung 
	m_ch_srxy=  2;      //srxy_Theta_Darstellung 
	m_ch_sryx=  2;      //sryx_Theta_Darstellung 
	m_ch_srx=   0;      //srx_Theta_Darstellung
	m_ch_sry=   0;      //sry_Theta_Darstellung
	
	   CGRP2Dlg o;
				o.rxy_gr(m_rxy_gr) ;   
				o.ryx_gr(m_ryx_gr) ;   
				o.srxy_gr(m_srxy_gr) ;
				o.sryx_gr(m_sryx_gr) ;
				o.srx_gr(m_srx_gr) ;
				o.sry_gr(m_sry_gr) ;
				o.sxy_gr(m_sxy_gr) ;
                o.syx_gr(m_syx_gr) ;
				o.s1xy_gr(m_s1xy_gr) ; 
				o.s1yx_gr(m_s1yx_gr) ; 
				o.clr_rxy(rxy_clr)  ; 
				o.clr_ryx(ryx_clr)  ;
				o.clr_srxy(srxy_clr); 
				o.clr_sryx(sryx_clr);    
				o.clr_srx(srx_clr)  ;  
				o.clr_sry(sry_clr)  ;   
				o.clr_sxy(sxy_clr)  ;  
				o.clr_syx(syx_clr)  ; 
				o.clr_s1xy(s1xy_clr);  
				o.clr_s1yx(s1yx_clr);
				o.rxy_art(m_rxy_art) ;  
				o.ryx_art(m_ryx_art) ;  
				o.srxy_art(m_srxy_art) ;
				o.sryx_art(m_sryx_art) ;
				o.srx_art(m_srx_art) ;
				o.sry_art(m_sry_art) ;
				o.sxy_art(m_sxy_art);   
				o.syx_art(m_syx_art) ;
				o.s1xy_art(m_s1xy_art) ;
				o.s1yx_art(m_s1yx_art) ;
				o.q_rxy(m_ch_rxy);  
				o.q_ryx(m_ch_ryx);  
				o.q_syx(m_ch_syx); 
				o.q_sxy(m_ch_sxy); 
				o.q_sgyx(m_ch_sgyx);
				o.q_sgxy(m_ch_sgxy);
				o.q_srxy(m_ch_srxy);
				o.q_sryx(m_ch_sryx);
				o.q_srx(m_ch_srx);  
				o.q_sry(m_ch_sry);  
	
	RedrawWindow();	 

	UpdateData(0);
}

void GRP2diagrm4::OnOK() 
{	                                                 CRect coord;
	                                        GetWindowRect(&coord); 
	
	                             CWinApp* pApp = AfxGetApp(); // ini profil schreiben  
	if(m_ch_ini)
	{
		                                  pApp->WriteProfileInt("Funktion","rxy_Linienbreite",m_rxy_gr);
	                                      pApp->WriteProfileInt("Funktion","ryx_Linienbreite",m_ryx_gr);
	                                      pApp->WriteProfileInt("Funktion","srxy_Linienbreite",m_srxy_gr);
	                                      pApp->WriteProfileInt("Funktion","sryx_Linienbreite",m_sryx_gr);
	                                      pApp->WriteProfileInt("Funktion","srx_Linienbreite",m_srx_gr);
	                                      pApp->WriteProfileInt("Funktion","sry_Linienbreite",m_sry_gr);
	                                      pApp->WriteProfileInt("Funktion","sxy_Linienbreite",m_sxy_gr);
	                                      pApp->WriteProfileInt("Funktion","syx_Linienbreite",m_syx_gr);
	                                      pApp->WriteProfileInt("Funktion","s'xy_Linienbreite",m_s1xy_gr);
	                                      pApp->WriteProfileInt("Funktion","s'yx_Linienbreite",m_s1yx_gr);
		                                  pApp->WriteProfileInt("Funktion","rxy_Farbe",rxy_clr);
	                                      pApp->WriteProfileInt("Funktion","ryx_Farbe",ryx_clr);
	                                      pApp->WriteProfileInt("Funktion","srxy_Farbe",srxy_clr);
	                                      pApp->WriteProfileInt("Funktion","sryx_Farbe",sryx_clr);
	                                      pApp->WriteProfileInt("Funktion","sry_Farbe",srx_clr);
	                                      pApp->WriteProfileInt("Funktion","srx_Farbe",sry_clr);
	                                      pApp->WriteProfileInt("Funktion","sxy_Farbe",sxy_clr);
	                                      pApp->WriteProfileInt("Funktion","syx_Farbe",syx_clr);
	                                      pApp->WriteProfileInt("Funktion","s'xy_Farbe",s1xy_clr);
	                                      pApp->WriteProfileInt("Funktion","s'yx_Farbe",s1yx_clr);
		                                  //pApp->WriteProfileInt("Funktion","rxy_Modus",mod_rxy);
		if(m_rxy_art=="Linie")            pApp->WriteProfileInt("Funktion","rxy_Modus",1);
		if(m_rxy_art=="Punkt")            pApp->WriteProfileInt("Funktion","rxy_Modus",2);
		if(m_rxy_art=="Strich")           pApp->WriteProfileInt("Funktion","rxy_Modus",3);
		if(m_rxy_art=="Strichpunkt")      pApp->WriteProfileInt("Funktion","rxy_Modus",4);
		if(m_rxy_art=="Strichdoppelpkt.") pApp->WriteProfileInt("Funktion","rxy_Modus",5);
		if(m_ryx_art=="Linie")            pApp->WriteProfileInt("Funktion","ryx_Modus",1);
		if(m_ryx_art=="Punkt")            pApp->WriteProfileInt("Funktion","ryx_Modus",2);
		if(m_ryx_art=="Strich")           pApp->WriteProfileInt("Funktion","ryx_Modus",3);
		if(m_ryx_art=="Strichpunkt")      pApp->WriteProfileInt("Funktion","ryx_Modus",4);
		if(m_ryx_art=="Strichdoppelpkt.") pApp->WriteProfileInt("Funktion","ryx_Modus",5);
		if(m_srxy_art=="Linie")           pApp->WriteProfileInt("Funktion","srxy_Modus",1);
		if(m_srxy_art=="Punkt")           pApp->WriteProfileInt("Funktion","srxy_Modus",2);
		if(m_srxy_art=="Strich")          pApp->WriteProfileInt("Funktion","srxy_Modus",3);
		if(m_srxy_art=="Strichpunkt")     pApp->WriteProfileInt("Funktion","srxy_Modus",4);
		if(m_srxy_art=="Strichdoppelpkt.")pApp->WriteProfileInt("Funktion","srxy_Modus",5);
		if(m_sryx_art=="Linie")           pApp->WriteProfileInt("Funktion","sryx_Modus",1);
		if(m_sryx_art=="Punkt")           pApp->WriteProfileInt("Funktion","sryx_Modus",2);
		if(m_sryx_art=="Strich")          pApp->WriteProfileInt("Funktion","sryx_Modus",3);
		if(m_sryx_art=="Strichpunkt")     pApp->WriteProfileInt("Funktion","sryx_Modus",4);
		if(m_sryx_art=="Strichdoppelpkt.")pApp->WriteProfileInt("Funktion","sryx_Modus",5);
		if(m_srx_art=="Linie")            pApp->WriteProfileInt("Funktion","srx_Modus",1);
		if(m_srx_art=="Punkt")            pApp->WriteProfileInt("Funktion","srx_Modus",2);
		if(m_srx_art=="Strich")           pApp->WriteProfileInt("Funktion","srx_Modus",3);
		if(m_srx_art=="Strichpunkt")      pApp->WriteProfileInt("Funktion","srx_Modus",4);
		if(m_srx_art=="Strichdoppelpkt.") pApp->WriteProfileInt("Funktion","srx_Modus",5);
		if(m_sry_art=="Linie")            pApp->WriteProfileInt("Funktion","sry_Modus",1);
		if(m_sry_art=="Punkt")            pApp->WriteProfileInt("Funktion","sry_Modus",2);
		if(m_sry_art=="Strich")           pApp->WriteProfileInt("Funktion","sry_Modus",3);
		if(m_sry_art=="Strichpunkt")      pApp->WriteProfileInt("Funktion","sry_Modus",4);
		if(m_sry_art=="Strichdoppelpkt.") pApp->WriteProfileInt("Funktion","sry_Modus",5);
		if(m_sxy_art=="Linie")            pApp->WriteProfileInt("Funktion","sxy_Modus",1);
		if(m_sxy_art=="Punkt")            pApp->WriteProfileInt("Funktion","sxy_Modus",2);
		if(m_sxy_art=="Strich")           pApp->WriteProfileInt("Funktion","sxy_Modus",3);
		if(m_sxy_art=="Strichpunkt")      pApp->WriteProfileInt("Funktion","sxy_Modus",4);
		if(m_sxy_art=="Strichdoppelpkt.") pApp->WriteProfileInt("Funktion","sxy_Modus",5);
		if(m_syx_art=="Linie")            pApp->WriteProfileInt("Funktion","syx_Modus",1);
		if(m_syx_art=="Punkt")            pApp->WriteProfileInt("Funktion","syx_Modus",2);
		if(m_syx_art=="Strich")           pApp->WriteProfileInt("Funktion","syx_Modus",3);
		if(m_syx_art=="Strichpunkt")      pApp->WriteProfileInt("Funktion","syx_Modus",4);
		if(m_syx_art=="Strichdoppelpkt.") pApp->WriteProfileInt("Funktion","syx_Modus",5);
		if(m_s1xy_art=="Linie")           pApp->WriteProfileInt("Funktion","s'xy_Modus",1);
		if(m_s1xy_art=="Punkt")           pApp->WriteProfileInt("Funktion","s'xy_Modus",2);
		if(m_s1xy_art=="Strich")          pApp->WriteProfileInt("Funktion","s'xy_Modus",3);
		if(m_s1xy_art=="Strichpunkt")     pApp->WriteProfileInt("Funktion","s'xy_Modus",4);
		if(m_s1xy_art=="Strichdoppelpkt.")pApp->WriteProfileInt("Funktion","s'xy_Modus",5);
		if(m_s1yx_art=="Linie")           pApp->WriteProfileInt("Funktion","s'yx_Modus",1);
		if(m_s1yx_art=="Punkt")           pApp->WriteProfileInt("Funktion","s'yx_Modus",2);
		if(m_s1yx_art=="Strich")          pApp->WriteProfileInt("Funktion","s'yx_Modus",3);
		if(m_s1yx_art=="Strichpunkt")     pApp->WriteProfileInt("Funktion","s'yx_Modus",4);
		if(m_s1yx_art=="Strichdoppelpkt.")pApp->WriteProfileInt("Funktion","s'yx_Modus",5);	
		                                  pApp->WriteProfileInt("Funktion","rxy_Theta_Darstellung",m_ch_rxy);
	                                      pApp->WriteProfileInt("Funktion","ryx_Theta_Darstellung",m_ch_ryx); 
	                                      pApp->WriteProfileInt("Funktion","syx_Theta_Darstellung",m_ch_syx); 
	                                      pApp->WriteProfileInt("Funktion","sxy_Theta_Darstellung",m_ch_sxy); 
	                                      pApp->WriteProfileInt("Funktion","s'yx_Theta_Darstellung",m_ch_sgyx);
	                                      pApp->WriteProfileInt("Funktion","s'xy_Theta_Darstellung",m_ch_sgxy); 
	                                      pApp->WriteProfileInt("Funktion","srxy_Theta_Darstellung",m_ch_srxy); 
	                                      pApp->WriteProfileInt("Funktion","sryx_Theta_Darstellung",m_ch_sryx); 
	                                      pApp->WriteProfileInt("Funktion","srx_Theta_Darstellung",m_ch_srx );
	                                      pApp->WriteProfileInt("Funktion","sry_Theta_Darstellung",m_ch_sry);
	}
	                                      pApp->WriteProfileInt("INI_schreiben","diagrm4",m_ch_ini);
			                              pApp->WriteProfileInt("Diagramm","Tabelle",4);
			                              pApp->WriteProfileInt("Diagramm","Position_x",coord.left);
			                              pApp->WriteProfileInt("Diagramm","Position_y",coord.top);
	CDialog::OnOK();
}









