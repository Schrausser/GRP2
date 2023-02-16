//------------------------------------------------------------------------| GRP2diagrm6.cpp                              //
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

GRP2diagrm6::GRP2diagrm6(CWnd* pParent )
	: CDialog(GRP2diagrm6::IDD, pParent)
{
	//{{AFX_DATA_INIT(GRP2diagrm6)
	m_ch_ini = 1;
	m_e_art = _T("");
	m_s0_art = _T("");
	m_x_art = _T("");
	m_x0_art = _T("");
	m_s1_art = _T("");
	m_x1_art = _T("");
	m_e_gr = 0;
	m_s0_gr = 0;
	m_s1_gr = 0;
	m_x_gr = 0;
	m_x0_gr = 0;
	m_x1_gr = 0;
	m_ch_e = 1;
	m_ch_s0 = 1;
	m_ch_s1 = 1;
	m_ch_x = 1;
	m_ch_x0 = 1;
	m_ch_x1 = 1;
	//}}AFX_DATA_INIT
}


void GRP2diagrm6::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GRP2diagrm6)
	DDX_Control(pDX, IDC_TAB2, m_tab);
	DDX_Check(pDX, IDC_CHECK_ini, m_ch_ini);
	DDX_CBString(pDX, IDC_COMBO_e_art, m_e_art);
	DDX_CBString(pDX, IDC_COMBO_s0_art, m_s0_art);
	DDX_CBString(pDX, IDC_COMBO_X_art, m_x_art);
	DDX_CBString(pDX, IDC_COMBO_x0_art, m_x0_art);
	DDX_CBString(pDX, IDC_COMBO_s1_art, m_s1_art);
	DDX_CBString(pDX, IDC_COMBO_x1_art, m_x1_art);
	DDX_Text(pDX, IDC_EDIT_e_gr, m_e_gr);
	DDX_Text(pDX, IDC_EDIT_s0_gr, m_s0_gr);
	DDX_Text(pDX, IDC_EDIT_s1_gr, m_s1_gr);
	DDX_Text(pDX, IDC_EDIT_X_gr, m_x_gr);
	DDX_Text(pDX, IDC_EDIT_x0_gr, m_x0_gr);
	DDX_Text(pDX, IDC_EDIT_x1_gr, m_x1_gr);
	DDX_Check(pDX, IDC_CHECK_e, m_ch_e);
	DDX_Check(pDX, IDC_CHECK_s0, m_ch_s0);
	DDX_Check(pDX, IDC_CHECK_s1, m_ch_s1);
	DDX_Check(pDX, IDC_CHECK_x, m_ch_x);
	DDX_Check(pDX, IDC_CHECK_x0, m_ch_x0);
	DDX_Check(pDX, IDC_CHECK_x1, m_ch_x1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(GRP2diagrm6, CDialog)
	//{{AFX_MSG_MAP(GRP2diagrm6)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB2, OnSelchangeTab2)
	ON_BN_CLICKED(IDC_CHECK_ini, OnCHECKini)
	ON_WM_PAINT()
	ON_BN_CLICKED(ID_Voreinstellungen, OnVoreinstellungen)
	ON_BN_CLICKED(IDC_BUTTON_e_fb, OnBUTTONefb)
	ON_BN_CLICKED(IDC_BUTTON_s0_fb, OnBUTTONs0fb)
	ON_BN_CLICKED(IDC_BUTTON_s1_fb, OnBUTTONs1fb)
	ON_BN_CLICKED(IDC_BUTTON_X_fb, OnBUTTONXfb)
	ON_BN_CLICKED(IDC_BUTTON_x0_fb, OnBUTTONx0fb)
	ON_BN_CLICKED(IDC_BUTTON_x1_fb, OnBUTTONx1fb)
	ON_BN_CLICKED(IDC_CHECK_e, OnCHECKe)
	ON_BN_CLICKED(IDC_CHECK_s0, OnCHECKs0)
	ON_BN_CLICKED(IDC_CHECK_s1, OnCHECKs1)
	ON_BN_CLICKED(IDC_CHECK_x, OnCHECKx)
	ON_BN_CLICKED(IDC_CHECK_x0, OnCHECKx0)
	ON_BN_CLICKED(IDC_CHECK_x1, OnCHECKx1)
	ON_CBN_SELCHANGE(IDC_COMBO_e_art, OnSelchangeCOMBOeart)
	ON_CBN_SELCHANGE(IDC_COMBO_s0_art, OnSelchangeCOMBOs0art)
	ON_CBN_SELCHANGE(IDC_COMBO_s1_art, OnSelchangeCOMBOs1art)
	ON_CBN_SELCHANGE(IDC_COMBO_X_art, OnSelchangeCOMBOXart)
	ON_CBN_SELCHANGE(IDC_COMBO_x0_art, OnSelchangeCOMBOx0art)
	ON_CBN_SELCHANGE(IDC_COMBO_x1_art, OnSelchangeCOMBOx1art)
	ON_EN_CHANGE(IDC_EDIT_e_gr, OnChangeEDITegr)
	ON_EN_CHANGE(IDC_EDIT_s0_gr, OnChangeEDITs0gr)
	ON_EN_CHANGE(IDC_EDIT_s1_gr, OnChangeEDITs1gr)
	ON_EN_CHANGE(IDC_EDIT_X_gr, OnChangeEDITXgr)
	ON_EN_CHANGE(IDC_EDIT_x0_gr, OnChangeEDITx0gr)
	ON_EN_CHANGE(IDC_EDIT_x1_gr, OnChangeEDITx1gr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_e_gr, OnDeltaposSPINegr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_s0_gr, OnDeltaposSPINs0gr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_s1_gr, OnDeltaposSPINs1gr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_X_gr, OnDeltaposSPINXgr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_x0_gr, OnDeltaposSPINx0gr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_x1_gr, OnDeltaposSPINx1gr)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL GRP2diagrm6::OnInitDialog() 
{
	CDialog::OnInitDialog();

	UpdateData(1);

	            CWinApp*  pApp = AfxGetApp(); // ini profil lesen 

	       e_clr=         pApp->GetProfileInt("Funktion","e_Farbe",8421504);
	       x_clr=         pApp->GetProfileInt("Funktion","x_Farbe",8421504);
	      x0_clr=         pApp->GetProfileInt("Funktion","x0_Farbe",8421504);
	      x1_clr=         pApp->GetProfileInt("Funktion","x1_Farbe",8421504);
	      s0_clr=         pApp->GetProfileInt("Funktion","s0_Farbe",8421504);
	      s1_clr=         pApp->GetProfileInt("Funktion","s1_Farbe",8421504);
		  m_e_gr=         pApp->GetProfileInt("Funktion","e_Linienbreite",1);
	      m_x_gr=         pApp->GetProfileInt("Funktion","x_Linienbreite",1);
	      m_x0_gr=        pApp->GetProfileInt("Funktion","x0_Linienbreite",1);
	      m_x1_gr=        pApp->GetProfileInt("Funktion","x1_Linienbreite",1);
	      m_s0_gr=        pApp->GetProfileInt("Funktion","s0_Linienbreite",1);
	      m_s1_gr=        pApp->GetProfileInt("Funktion","s1_Linienbreite",1);
		m_ch_e  =         pApp->GetProfileInt("Funktion","e_Theta_Darstellung",1); 
     	m_ch_x  =         pApp->GetProfileInt("Funktion","x_Theta_Darstellung",1);
	   m_ch_x0  =         pApp->GetProfileInt("Funktion","x0_Theta_Darstellung",1);
	   m_ch_x1  =         pApp->GetProfileInt("Funktion","x1_Theta_Darstellung",1);
	   m_ch_s0  =         pApp->GetProfileInt("Funktion","s0_Theta_Darstellung",1);
	   m_ch_s1  =         pApp->GetProfileInt("Funktion","s1_Theta_Darstellung",1);
	   	      mod_e=      pApp->GetProfileInt("Funktion","e_Modus",2);
		   if(mod_e==1)m_e_art="Linie";
		   if(mod_e==2)m_e_art="Punkt";
		   if(mod_e==3)m_e_art="Strich";
		   if(mod_e==4)m_e_art="Strichpunkt";
		   if(mod_e==5)m_e_art="Strichdoppelpkt.";
	          mod_x=      pApp->GetProfileInt("Funktion","x_Modus",1);
		   if(mod_x==1)m_x_art="Linie";
		   if(mod_x==2)m_x_art="Punkt";
		   if(mod_x==3)m_x_art="Strich";
		   if(mod_x==4)m_x_art="Strichpunkt";
		   if(mod_x==5)m_x_art="Strichdoppelpkt.";
	          mod_x0=     pApp->GetProfileInt("Funktion","x0_Modus",1);
		   if(mod_x0==1)m_x0_art="Linie";
		   if(mod_x0==2)m_x0_art="Punkt";
		   if(mod_x0==3)m_x0_art="Strich";
		   if(mod_x0==4)m_x0_art="Strichpunkt";
		   if(mod_x0==5)m_x0_art="Strichdoppelpkt.";
	          mod_x1=     pApp->GetProfileInt("Funktion","x1_Modus",1);
		   if(mod_x1==1)m_x1_art="Linie";
		   if(mod_x1==2)m_x1_art="Punkt";
		   if(mod_x1==3)m_x1_art="Strich";
		   if(mod_x1==4)m_x1_art="Strichpunkt";
		   if(mod_x1==5)m_x1_art="Strichdoppelpkt.";
	          mod_s0=     pApp->GetProfileInt("Funktion","s0_Modus",1);
		   if(mod_s0==1)m_s0_art="Linie";
		   if(mod_s0==2)m_s0_art="Punkt";
		   if(mod_s0==3)m_s0_art="Strich";
		   if(mod_s0==4)m_s0_art="Strichpunkt";
		   if(mod_s0==5)m_s0_art="Strichdoppelpkt.";
	          mod_s1=     pApp->GetProfileInt("Funktion","s1_Modus",1);
		   if(mod_s1==1)m_s1_art="Linie";
		   if(mod_s1==2)m_s1_art="Punkt";
		   if(mod_s1==3)m_s1_art="Strich";
		   if(mod_s1==4)m_s1_art="Strichpunkt";
		   if(mod_s1==5)m_s1_art="Strichdoppelpkt.";

               m_ch_ini=  pApp->GetProfileInt("INI_schreiben","diagrm6",1);

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
				         
				m_tab.SetCurSel(  5);

	UpdateData(0);
	
	return 1;  	              
}

void GRP2diagrm6::OnPaint() 
{
	CPaintDC ooo(this); 
	                              UINT pos=50;
			             CRect o1(197, pos, 211, pos+13);
			 ooo.FillSolidRect(o1,  x0_clr ); 

			             CRect o2(197, pos+23*1, 211, pos+23*1+13);
			 ooo.FillSolidRect(o2,  s0_clr );

			             CRect o3(197, pos+23*2, 211, pos+23*2+13);
			 ooo.FillSolidRect(o3,  x1_clr );

			             CRect o4(197, pos+23*3-1, 211, pos+23*3+13-1);
			 ooo.FillSolidRect(o4,  s1_clr );

			             CRect o5(197, pos+23*4-1, 211, pos+23*4+13-1);
			 ooo.FillSolidRect(o5,  e_clr );

			             CRect o6(197, pos+23*5-1, 211, pos+23*5+13-1);
			 ooo.FillSolidRect(o6,  x_clr );
}

void GRP2diagrm6::OnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if(m_tab.GetCurSel() ==0){OnOK();GRP2diagrm1 o;o.DoModal();}
	if(m_tab.GetCurSel() ==1){OnOK();GRP2diagrm2 o;o.DoModal();}
	if(m_tab.GetCurSel() ==2){OnOK();GRP2diagrm3 o;o.DoModal();}
	if(m_tab.GetCurSel() ==3){OnOK();GRP2diagrm4 o;o.DoModal();}
	if(m_tab.GetCurSel() ==4){OnOK();GRP2diagrm5 o;o.DoModal();}
	if(m_tab.GetCurSel() ==5);
	
	*pResult = 0;
}

void GRP2diagrm6::OnChangeEDITegr() {       UpdateData(1); CGRP2Dlg o;o.e_gr(m_e_gr) ;      UpdateData(0);}
void GRP2diagrm6::OnChangeEDITs0gr() {      UpdateData(1); CGRP2Dlg o;o.s0_gr(m_s0_gr) ;    UpdateData(0);}
void GRP2diagrm6::OnChangeEDITs1gr() {      UpdateData(1); CGRP2Dlg o;o.s1_gr(m_s1_gr) ;    UpdateData(0);}
void GRP2diagrm6::OnChangeEDITXgr() {       UpdateData(1); CGRP2Dlg o;o.xe_gr(m_x_gr) ;     UpdateData(0);}
void GRP2diagrm6::OnChangeEDITx0gr() {      UpdateData(1); CGRP2Dlg o;o.x0_gr(m_x0_gr) ;    UpdateData(0);}
void GRP2diagrm6::OnChangeEDITx1gr(){       UpdateData(1); CGRP2Dlg o;o.x1_gr(m_x1_gr) ;    UpdateData(0);}
void GRP2diagrm6::OnSelchangeCOMBOeart() {  UpdateData(1); CGRP2Dlg o;o.e_art(m_e_art) ;    UpdateData(0);}
void GRP2diagrm6::OnSelchangeCOMBOs0art(){  UpdateData(1); CGRP2Dlg o;o.s0_art(m_s0_art) ;  UpdateData(0);} 
void GRP2diagrm6::OnSelchangeCOMBOs1art(){  UpdateData(1); CGRP2Dlg o;o.s1_art(m_s1_art) ;  UpdateData(0);} 
void GRP2diagrm6::OnSelchangeCOMBOXart() {  UpdateData(1); CGRP2Dlg o;o.xe_art(m_x_art) ;   UpdateData(0);}
void GRP2diagrm6::OnSelchangeCOMBOx0art(){  UpdateData(1); CGRP2Dlg o;o.x0_art(m_x0_art) ;  UpdateData(0);} 
void GRP2diagrm6::OnSelchangeCOMBOx1art(){  UpdateData(1); CGRP2Dlg o;o.x1_art(m_x1_art) ;  UpdateData(0);} 

void GRP2diagrm6::OnBUTTONefb() {CColorDialog cl(e_clr,0,0); cl.DoModal();e_clr=cl.GetColor(); RedrawWindow(); CGRP2Dlg o;o.clr_e(e_clr)  ;} 
void GRP2diagrm6::OnBUTTONs0fb(){CColorDialog cl(s0_clr,0,0);cl.DoModal();s0_clr=cl.GetColor();RedrawWindow(); CGRP2Dlg o;o.clr_s0(s0_clr);}  
void GRP2diagrm6::OnBUTTONs1fb(){CColorDialog cl(s1_clr,0,0);cl.DoModal();s1_clr=cl.GetColor();RedrawWindow(); CGRP2Dlg o;o.clr_s1(s1_clr);}  
void GRP2diagrm6::OnBUTTONXfb(){ CColorDialog cl(x_clr,0,0); cl.DoModal();x_clr=cl.GetColor(); RedrawWindow(); CGRP2Dlg o;o.clr_xe(x_clr) ;}  
void GRP2diagrm6::OnBUTTONx0fb(){CColorDialog cl(x0_clr,0,0);cl.DoModal();x0_clr=cl.GetColor();RedrawWindow(); CGRP2Dlg o;o.clr_x0(x0_clr);} 
void GRP2diagrm6::OnBUTTONx1fb(){CColorDialog cl(x1_clr,0,0);cl.DoModal();x1_clr=cl.GetColor();RedrawWindow(); CGRP2Dlg o;o.clr_x1(x1_clr);}  

void GRP2diagrm6::OnCHECKe() {  UpdateData(1);CGRP2Dlg o;o.q_e(m_ch_e);   UpdateData(0);}
void GRP2diagrm6::OnCHECKs0() { UpdateData(1);CGRP2Dlg o;o.q_s0(m_ch_s0); UpdateData(0);}
void GRP2diagrm6::OnCHECKs1() { UpdateData(1);CGRP2Dlg o;o.q_s1(m_ch_s1); UpdateData(0);}
void GRP2diagrm6::OnCHECKx() {  UpdateData(1);CGRP2Dlg o;o.q_xe(m_ch_x);  UpdateData(0);}
void GRP2diagrm6::OnCHECKx0(){  UpdateData(1);CGRP2Dlg o;o.q_x0(m_ch_x0); UpdateData(0);} 
void GRP2diagrm6::OnCHECKx1() { UpdateData(1);CGRP2Dlg o;o.q_x1(m_ch_x1); UpdateData(0);}

void GRP2diagrm6::OnDeltaposSPINegr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)              m_e_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_e_gr>0) m_e_gr-=1;
		                   
	UpdateData(0); OnChangeEDITegr();
	
	*pResult = 0;
}

void GRP2diagrm6::OnDeltaposSPINs0gr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)              m_s0_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_s0_gr>0) m_s0_gr-=1;
		                   
	UpdateData(0); OnChangeEDITs0gr();
	
	*pResult = 0;
}

void GRP2diagrm6::OnDeltaposSPINs1gr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)              m_s1_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_s1_gr>0) m_s1_gr-=1;
		                   
	UpdateData(0); OnChangeEDITs1gr();
	
	*pResult = 0;
}

void GRP2diagrm6::OnDeltaposSPINXgr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)             m_x_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_x_gr>0) m_x_gr-=1;
		                   
	UpdateData(0); OnChangeEDITXgr();
	
	*pResult = 0;
}

void GRP2diagrm6::OnDeltaposSPINx0gr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)              m_x0_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_x0_gr>0) m_x0_gr-=1;
		                   
	UpdateData(0); OnChangeEDITx0gr();
	
	*pResult = 0;
}

void GRP2diagrm6::OnDeltaposSPINx1gr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)              m_x1_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_x1_gr>0) m_x1_gr-=1;
		                   
	UpdateData(0); OnChangeEDITx1gr();
	
	*pResult = 0;
}

void GRP2diagrm6::OnCHECKini() {UpdateData(1);UpdateData(0);}

void GRP2diagrm6::OnVoreinstellungen() 
{
	UpdateData(1);

	e_clr=    8421504; //e_Farbe
	x_clr=    8421504; //x_Farbe
	x0_clr=   8421504; //x0_Farbe
	x1_clr=   8421504; //x1_Farbe
	s0_clr=   8421504; //s0_Farbe
	s1_clr=   8421504; //s1_Farbe
	m_e_gr=   1;       //e_Linienbreite
	m_x_gr=   1;       //x_Linienbreite
	m_x0_gr=  1;       //x0_Linienbreite
	m_x1_gr=  1;       //x1_Linienbreite
	m_s0_gr=  1;       //s0_Linienbreite
	m_s1_gr=  1;       //s1_Linienbreite
	m_ch_e=   1;       //e_Theta_Darstellung 
	m_ch_x=   1;       //x_Theta_Darstellung
	m_ch_x0=  1;       //x0_Theta_Darstellung
	m_ch_x1=  1;       //x1_Theta_Darstellung
	m_ch_s0=  1;       //s0_Theta_Darstellung
	m_ch_s1=  1;       //s1_Theta_Darstellung
	mod_e=    2;       //e_Modus
	m_e_art= "Punkt";  //
	mod_x=    1;       //x_Modus
	m_x_art= "Linie";  //
	mod_x0=   1;       //x0_Modus
	m_x0_art="Linie";  //
	mod_x1=   1;       //x1_Modus
	m_x1_art="Linie";  //
	mod_s0=   1;       //s0_Modus
	m_s0_art="Linie";  //
	mod_s1=   1;       //s1_Modus
	m_s1_art="Linie";  //
		  
	CGRP2Dlg o;
			 o.e_gr(m_e_gr) ;      
			 o.s0_gr(m_s0_gr) ;      
			 o.s1_gr(m_s1_gr) ;      
			 o.xe_gr(m_x_gr) ;      
			 o.x0_gr(m_x0_gr) ;      
			 o.x1_gr(m_x1_gr) ;      
			 o.e_art(m_e_art) ;    
			 o.s0_art(m_s0_art) ;     
			 o.s1_art(m_s1_art) ;     
			 o.xe_art(m_x_art) ;    
			 o.x0_art(m_x0_art) ;     
			 o.x1_art(m_x1_art) ;     
			 o.clr_e(e_clr); 
			 o.clr_s0(s0_clr);  
			 o.clr_s1(s1_clr);  
		     o.clr_xe(x_clr);  
			 o.clr_x0(x0_clr); 
			 o.clr_x1(x1_clr); 
			 o.q_e(m_ch_e);    
			 o.q_s0(m_ch_s0);    
			 o.q_s1(m_ch_s1);    
			 o.q_xe(m_ch_x);    
			 o.q_x0(m_ch_x0);     
			 o.q_x1(m_ch_x1);    

	RedrawWindow();

	UpdateData(0);
}

void GRP2diagrm6::OnOK() 
{
	                                                 CRect coord;
	                                        GetWindowRect(&coord); 
	
	                     CWinApp* pApp = AfxGetApp(); // ini profil schreiben 
	if(m_ch_ini)
	{
										 pApp->WriteProfileInt("Funktion","e_Farbe",e_clr);
										 pApp->WriteProfileInt("Funktion","x_Farbe",x_clr);
										 pApp->WriteProfileInt("Funktion","x0_Farbe",x0_clr);
										 pApp->WriteProfileInt("Funktion","x1_Farbe",x1_clr);
										 pApp->WriteProfileInt("Funktion","s0_Farbe", s0_clr);
										 pApp->WriteProfileInt("Funktion","s1_Farbe",s1_clr);
										 pApp->WriteProfileInt("Funktion","e_Linienbreite",m_e_gr);
										 pApp->WriteProfileInt("Funktion","x_Linienbreite",m_x_gr);
										 pApp->WriteProfileInt("Funktion","x0_Linienbreite",m_x0_gr);
										 pApp->WriteProfileInt("Funktion","x1_Linienbreite",m_x1_gr);
										 pApp->WriteProfileInt("Funktion","s0_Linienbreite",m_s0_gr);
										 pApp->WriteProfileInt("Funktion","s1_Linienbreite", m_s1_gr);
										 pApp->WriteProfileInt("Funktion","e_Theta_Darstellung",m_ch_e ); 
										 pApp->WriteProfileInt("Funktion","x_Theta_Darstellung",m_ch_x);
										 pApp->WriteProfileInt("Funktion","x0_Theta_Darstellung",m_ch_x0);
										 pApp->WriteProfileInt("Funktion","x1_Theta_Darstellung", m_ch_x1);
										 pApp->WriteProfileInt("Funktion","s0_Theta_Darstellung", m_ch_s0 );
										 pApp->WriteProfileInt("Funktion","s1_Theta_Darstellung",m_ch_s1);
	    if(m_e_art=="Linie")             pApp->WriteProfileInt("Funktion","e_Modus",1);
		if(m_e_art=="Punkt")             pApp->WriteProfileInt("Funktion","e_Modus",2);
		if(m_e_art=="Strich")            pApp->WriteProfileInt("Funktion","e_Modus",3);
		if(m_e_art=="Strichpunkt")       pApp->WriteProfileInt("Funktion","e_Modus",4);
		if(m_e_art=="Strichdoppelpkt.")  pApp->WriteProfileInt("Funktion","e_Modus",5);
		if(m_x_art=="Linie")             pApp->WriteProfileInt("Funktion","x_Modus",1);
		if(m_x_art=="Punkt")             pApp->WriteProfileInt("Funktion","x_Modus",2);
		if(m_x_art=="Strich")            pApp->WriteProfileInt("Funktion","x_Modus",3);
		if(m_x_art=="Strichpunkt")       pApp->WriteProfileInt("Funktion","x_Modus",4);
		if(m_x_art=="Strichdoppelpkt.")  pApp->WriteProfileInt("Funktion","x_Modus",5);
		if(m_x0_art=="Linie")            pApp->WriteProfileInt("Funktion","x0_Modus",1);
		if(m_x0_art=="Punkt")            pApp->WriteProfileInt("Funktion","x0_Modus",2);
		if(m_x0_art=="Strich")           pApp->WriteProfileInt("Funktion","x0_Modus",3);
		if(m_x0_art=="Strichpunkt")      pApp->WriteProfileInt("Funktion","x0_Modus",4);
		if(m_x0_art=="Strichdoppelpkt.") pApp->WriteProfileInt("Funktion","x0_Modus",5);
		if(m_s0_art=="Linie")            pApp->WriteProfileInt("Funktion","s0_Modus",1);
		if(m_s0_art=="Punkt")            pApp->WriteProfileInt("Funktion","s0_Modus",2);
		if(m_s0_art=="Strich")           pApp->WriteProfileInt("Funktion","s0_Modus",3);
		if(m_s0_art=="Strichpunkt")      pApp->WriteProfileInt("Funktion","s0_Modus",4);
		if(m_s0_art=="Strichdoppelpkt.") pApp->WriteProfileInt("Funktion","s0_Modus",5);
		if(m_x1_art=="Linie")            pApp->WriteProfileInt("Funktion","x1_Modus",1);
		if(m_x1_art=="Punkt")            pApp->WriteProfileInt("Funktion","x1_Modus",2);
		if(m_x1_art=="Strich")           pApp->WriteProfileInt("Funktion","x1_Modus",3);
		if(m_x1_art=="Strichpunkt")      pApp->WriteProfileInt("Funktion","x1_Modus",4);
		if(m_x1_art=="Strichdoppelpkt.") pApp->WriteProfileInt("Funktion","x1_Modus",5);
		if(m_s1_art=="Linie")            pApp->WriteProfileInt("Funktion","s1_Modus",1);
		if(m_s1_art=="Punkt")            pApp->WriteProfileInt("Funktion","s1_Modus",2);
		if(m_s1_art=="Strich")           pApp->WriteProfileInt("Funktion","s1_Modus",3);
		if(m_s1_art=="Strichpunkt")      pApp->WriteProfileInt("Funktion","s1_Modus",4);
		if(m_s1_art=="Strichdoppelpkt.") pApp->WriteProfileInt("Funktion","s1_Modus",5);
	}
	                                     pApp->WriteProfileInt("INI_schreiben","diagrm6",m_ch_ini);
			                             pApp->WriteProfileInt("Diagramm","Tabelle",6);
			                             pApp->WriteProfileInt("Diagramm","Position_x",coord.left);
			                             pApp->WriteProfileInt("Diagramm","Position_y",coord.top);
	CDialog::OnOK();
}


