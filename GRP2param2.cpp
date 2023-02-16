//------------------------------------------------------------------------| GRP2param2.cpp                               //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#include "stdafx.h"
#include "GRP2.hpp"
#include "GRP2Dlg.hpp"
#include "GRP2param1.hpp"
#include "GRP2param2.hpp"
#include "GRP2param2Bx.hpp"
#include "GRP2param2By.hpp"
#include "GRP2param3.hpp"
#include "GRP2param4.hpp"
#include "GRP2param5.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

GRP2param2::GRP2param2(CWnd* pParent )
	: CDialog(GRP2param2::IDD, pParent)
{
	//{{AFX_DATA_INIT(GRP2param2)
	m_ch_xA = 0;
	m_ch_yA = 0;
	m_ch_xS = 1;
	m_ch_yS = 1;
	m_ch_xSw = 0;
	m_ch_ySw = 0;
	m_dez_S_x = 2;
	m_dez_S_y = 2;
	m_tlgx = "2";
	m_tlgx_d = "1";
	m_tlgy = "2";
	m_tlgy_d = "1";
	m_ch_ini = 1;
	m_ch_xGrd = 0;
	m_ch_yGrd = 0;
	//}}AFX_DATA_INIT
}

void GRP2param2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GRP2param2)
	DDX_Control(pDX, IDC_TAB, m_tab);
	DDX_Check(pDX, IDC_CHECK_xA, m_ch_xA);
	DDX_Check(pDX, IDC_CHECK_yA, m_ch_yA);
	DDX_Check(pDX, IDC_CHECK_xS, m_ch_xS);
	DDX_Check(pDX, IDC_CHECK_yS, m_ch_yS);
	DDX_Check(pDX, IDC_CHECK_xSw, m_ch_xSw);
	DDX_Check(pDX, IDC_CHECK_ySw, m_ch_ySw);
	DDX_Text(pDX, IDC_EDIT_dez_S_x, m_dez_S_x);
	DDX_Text(pDX, IDC_EDIT_dez_S_y, m_dez_S_y);
	DDX_Text(pDX, IDC_EDIT_tlgx, m_tlgx);
	DDX_Text(pDX, IDC_EDIT_tlgx_d, m_tlgx_d);
	DDX_Text(pDX, IDC_EDIT_tlgy, m_tlgy);
	DDX_Text(pDX, IDC_EDIT_tlgy_d, m_tlgy_d);
	DDX_Check(pDX, IDC_CHECK_ini, m_ch_ini);
	DDX_Check(pDX, IDC_CHECK_xGrd, m_ch_xGrd);
	DDX_Check(pDX, IDC_CHECK_yGrd, m_ch_yGrd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(GRP2param2, CDialog)
	//{{AFX_MSG_MAP(GRP2param2)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, OnSelchangeTab)
	ON_BN_CLICKED(IDC_CHECK_xA, OnCHECKxA)
	ON_BN_CLICKED(IDC_CHECK_yA, OnCHECKyA)
	ON_BN_CLICKED(IDC_CHECK_xS, OnCHECKxS)
	ON_BN_CLICKED(IDC_CHECK_yS, OnCHECKyS)
	ON_BN_CLICKED(IDC_CHECK_xSw, OnCHECKxSw)
	ON_BN_CLICKED(IDC_CHECK_ySw, OnCHECKySw)
	ON_EN_CHANGE(IDC_EDIT_dez_S_x, OnChangeEDITdezSx)
	ON_EN_CHANGE(IDC_EDIT_dez_S_y, OnChangeEDITdezSy)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_dez_S_x, OnDeltaposSPINdezSx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_dez_S_y, OnDeltaposSPINdezSy)
	ON_EN_CHANGE(IDC_EDIT_tlgx, OnChangeEDITtlgx)
	ON_EN_CHANGE(IDC_EDIT_tlgx_d, OnChangeEDITtlgxd)
	ON_EN_CHANGE(IDC_EDIT_tlgy, OnChangeEDITtlgy)
	ON_EN_CHANGE(IDC_EDIT_tlgy_d, OnChangeEDITtlgyd)
	ON_BN_CLICKED(IDC_BUTTON_tlgx_d_reset, OnBUTTONtlgxdreset)
	ON_BN_CLICKED(IDC_BUTTON_tlgx_reset, OnBUTTONtlgxreset)
	ON_BN_CLICKED(IDC_BUTTON_tlgy_d_reset, OnBUTTONtlgydreset)
	ON_BN_CLICKED(IDC_BUTTON_tlgy_reset, OnBUTTONtlgyreset)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_tlgx, OnDeltaposSPINtlgx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_tlgy, OnDeltaposSPINtlgy)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_tlgx_d, OnDeltaposSPINtlgxd)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_tlgy_d, OnDeltaposSPINtlgyd)
	ON_BN_CLICKED(IDC_CHECK_ini, OnCHECKini)
	ON_BN_CLICKED(ID_Voreinstellungen, OnVoreinstellungen)
	ON_BN_CLICKED(IDC_CHECK_yGrd, OnCHECKyGrd)
	ON_BN_CLICKED(IDC_CHECK_xGrd, OnCHECKxGrd)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_sw_x, OnDeltaposSPINswx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_sw_y, OnDeltaposSPINswy)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_sw_x2, OnDeltaposSPINswx2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_sw_y2, OnDeltaposSPINswy2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_sw_scx, OnDeltaposSPINswscx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_sw_scy, OnDeltaposSPINswscy)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_sw_Axx, OnDeltaposSPINswAxx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_sw_Axy, OnDeltaposSPINswAxy)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_sw_Ayy, OnDeltaposSPINswAyy)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_sw_Ayx, OnDeltaposSPINswAyx)
	ON_BN_CLICKED(IDC_BUTTON_Bx, OnBUTTONBx)
	ON_BN_CLICKED(IDC_BUTTON_By, OnBUTTONBy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL GRP2param2::OnInitDialog() 
{
	CDialog::OnInitDialog();

	UpdateData(1);

	             CWinApp*  pApp = AfxGetApp(); // ini profil lesen 
	
				m_ch_xA =  pApp->GetProfileInt("Achsen","x_",1);
				m_ch_yA =  pApp->GetProfileInt("Achsen","y_",1);
				m_ch_xS =  pApp->GetProfileInt("Achsen","x_Skala",1);
				m_ch_yS =  pApp->GetProfileInt("Achsen","y_Skala",1);
				m_ch_xSw=  pApp->GetProfileInt("Achsen","x_Skalenwerte",1);
				m_ch_ySw=  pApp->GetProfileInt("Achsen","y_Skalenwerte",1);
				m_dez_S_x= pApp->GetProfileInt("Achsen","x_Skalenwerte_Dezimalstellen",2);
				m_dez_S_y= pApp->GetProfileInt("Achsen","y_Skalenwerte_Dezimalstellen",2);
				m_ch_xGrd= pApp->GetProfileInt("Achsen","x_Grid",0);
				m_ch_yGrd= pApp->GetProfileInt("Achsen","y_Grid",0);
				m_tlgx=    pApp->GetProfileString("Achsen","x_Skala_Teilung","4");
				m_tlgy=    pApp->GetProfileString("Achsen","y_Skala_Teilung","4");
				m_tlgx_d = pApp->GetProfileString("Achsen","x_Skala_Teilungs_d","1");
				m_tlgy_d = pApp->GetProfileString("Achsen","y_Skala_Teilungs_d","1");
				swxXd=     pApp->GetProfileInt("Achsen","X_Skalenwerte_Position_x",0);
				swyXd=     pApp->GetProfileInt("Achsen","X_Skalenwerte_Position_y",3);
				swxYd=     pApp->GetProfileInt("Achsen","Y_Skalenwerte_Position_x",-26);
				swyYd=     pApp->GetProfileInt("Achsen","Y_Skalenwerte_Position_y",-8);
				scxd=      pApp->GetProfileInt("Achsen","X_Skalierungs_Position",0);
	            scyd=      pApp->GetProfileInt("Achsen","Y_Skalierungs_Position",0);
				Axxd=      pApp->GetProfileInt("Achsen","X_Bezeichnungs_Position_x",0);
	            Axyd=      pApp->GetProfileInt("Achsen","X_Bezeichnungs_Position_y",0);
	            Ayxd=      pApp->GetProfileInt("Achsen","Y_Bezeichnungs_Position_x",0);
	            Ayyd=      pApp->GetProfileInt("Achsen","Y_Bezeichnungs_Position_y",0);

	            m_ch_ini=  pApp->GetProfileInt("INI_schreiben","param2",1);
	
	 SetWindowPos(&wndTop, pApp->GetProfileInt("Parameter","Position_x",100),
		                   pApp->GetProfileInt("Parameter","Position_y",100), 200+8,100+27, SWP_NOSIZE);

	tlgx_d=atof(m_tlgx_d);
	tlgy_d=atof(m_tlgy_d);

                              TC_ITEM o;
	                                  o.mask = TCIF_TEXT;
	/*CTabCtrl	m_tab;*/              o.pszText = "Funktion"; 
				m_tab.InsertItem( 0, &o );   
				                      o.pszText = "Achsen";
				m_tab.InsertItem( 1, &o );
				                      o.pszText = "Vektoren";
				m_tab.InsertItem( 2, &o );
				                      o.pszText = "Diagramm";
				m_tab.InsertItem( 3, &o );
				                      o.pszText = "EMF";
				m_tab.InsertItem( 4, &o );

				m_tab.SetCurSel(  1);

	UpdateData(0);
	return 1;  
}


void GRP2param2::OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if(m_tab.GetCurSel() ==0){OnOK();GRP2param1 o;o.DoModal();}
	if(m_tab.GetCurSel() ==1);
	if(m_tab.GetCurSel() ==2){OnOK();GRP2param3 o;o.DoModal();}
	if(m_tab.GetCurSel() ==3){OnOK();GRP2param4 o;o.DoModal();}
	if(m_tab.GetCurSel() ==4){OnOK();GRP2param5 o;o.DoModal();}
	
	*pResult = 0;
}

void GRP2param2::OnCHECKxS(){          UpdateData(1); if(m_ch_xS==0)m_ch_xSw=0; CGRP2Dlg o; o.x_Skala(m_ch_xS);
                                                                                            o.x_Sw(m_ch_xSw);   UpdateData(0); }      
void GRP2param2::OnCHECKyS(){          UpdateData(1); if(m_ch_yS==0)m_ch_ySw=0; CGRP2Dlg o; o.y_Skala(m_ch_yS); 
	                                                                                        o.y_Sw(m_ch_ySw);   UpdateData(0); }
void GRP2param2::OnCHECKxSw(){         UpdateData(1);                           CGRP2Dlg o; o.x_Sw(m_ch_xSw);   UpdateData(0); }
void GRP2param2::OnCHECKySw(){         UpdateData(1);                           CGRP2Dlg o; o.y_Sw(m_ch_ySw);   UpdateData(0); }	
void GRP2param2::OnCHECKxA(){          UpdateData(1);                           CGRP2Dlg o; o.x_Achse(m_ch_xA); UpdateData(0); }
void GRP2param2::OnCHECKyA(){          UpdateData(1);                           CGRP2Dlg o; o.y_Achse(m_ch_yA); UpdateData(0); }
void GRP2param2::OnChangeEDITdezSx() { UpdateData(1);                           CGRP2Dlg o; o.xS_ds(m_dez_S_x); UpdateData(0);}
void GRP2param2::OnChangeEDITdezSy() { UpdateData(1);                           CGRP2Dlg o; o.yS_ds(m_dez_S_y); UpdateData(0);}
void GRP2param2::OnCHECKxGrd() {       UpdateData(1);                           CGRP2Dlg o; o.x_Grid(m_ch_xGrd); UpdateData(0);}
void GRP2param2::OnCHECKyGrd() {       UpdateData(1);                           CGRP2Dlg o; o.y_Grid(m_ch_yGrd); UpdateData(0);}

void GRP2param2::OnBUTTONBx() {GRP2param2Bx o;o.DoModal();}
void GRP2param2::OnBUTTONBy() {GRP2param2By o;o.DoModal();}

void GRP2param2::OnDeltaposSPINdezSx(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown =   (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)                m_dez_S_x+=1;
	if(pNMUpDown->iDelta >=0)if(m_dez_S_x>0) m_dez_S_x-=1;
		                   
	UpdateData(0); OnChangeEDITdezSx();
		
	*pResult = 0;
}

void GRP2param2::OnDeltaposSPINdezSy(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown =   (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)                m_dez_S_y+=1;
	if(pNMUpDown->iDelta >=0)if(m_dez_S_y>0) m_dez_S_y-=1;
		               
	UpdateData(0); OnChangeEDITdezSy();
		
	*pResult = 0;
}

//skalen teilung
void GRP2param2::OnDeltaposSPINtlgx(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	UpdateData(1);

	if(pNMUpDown->iDelta < 0)
	{           
							   float v_=atof(m_tlgx);
									 v_+=tlgx_d;
						m_tlgx =ftoc(v_, 3); 
	}
	    
	if(atof(m_tlgx)>tlgx_d)	
	if(pNMUpDown->iDelta >=0)
	{
							  float v_=atof(m_tlgx);
									v_-=tlgx_d;
					   m_tlgx =ftoc(v_, 3); 
	}

	UpdateData(0); 
	
	CGRP2Dlg o; o.x_tlg(m_tlgx);
	
	*pResult = 0;
}

void GRP2param2::OnDeltaposSPINtlgy(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	UpdateData(1);

	if(pNMUpDown->iDelta < 0)
	{           
							   float v_=atof(m_tlgy);
									 v_+=tlgy_d;
						m_tlgy =ftoc(v_, 3); 
	}
	    
	if(atof(m_tlgy)>tlgy_d)	
	if(pNMUpDown->iDelta >=0)
	{
							  float v_=atof(m_tlgy);
									v_-=tlgy_d;
					   m_tlgy =ftoc(v_, 3); 
	}
	
	UpdateData(0); 
	
	CGRP2Dlg o; o.y_tlg(m_tlgy); 
	
	*pResult = 0;
}

void GRP2param2::OnDeltaposSPINtlgxd(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)             tlgx_d+=1;
	if(pNMUpDown->iDelta >=0)if(tlgx_d>0) tlgx_d-=1;
	
	UpdateData(1);         m_tlgx_d= ftoc(tlgx_d,0); UpdateData(0);
	*pResult = 0;
}

void GRP2param2::OnDeltaposSPINtlgyd(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)             tlgy_d+=1;
	if(pNMUpDown->iDelta >=0)if(tlgy_d>0) tlgy_d-=1;
	
	UpdateData(1);         m_tlgy_d= ftoc(tlgy_d,0); UpdateData(0);
	*pResult = 0;
}

void GRP2param2::OnDeltaposSPINswx(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)             swxXd+=1;
	if(pNMUpDown->iDelta >=0)             swxXd-=1;
	
	UpdateData(1); CGRP2Dlg o; o.posAXx_(swxXd);  UpdateData(0);

	*pResult = 0;
}

void GRP2param2::OnDeltaposSPINswy(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)             swyXd-=1;
	if(pNMUpDown->iDelta >=0)             swyXd+=1;
	
	UpdateData(1); CGRP2Dlg o; o.posAXy_(swyXd);  UpdateData(0);
	
	*pResult = 0;
}

void GRP2param2::OnDeltaposSPINswx2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)             swxYd+=1;
	if(pNMUpDown->iDelta >=0)             swxYd-=1;
	
	UpdateData(1); CGRP2Dlg o; o.posAYx_(swxYd);  UpdateData(0);
	
	*pResult = 0;
}

void GRP2param2::OnDeltaposSPINswy2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)             swyYd-=1;
	if(pNMUpDown->iDelta >=0)             swyYd+=1;
	
	UpdateData(1); CGRP2Dlg o; o.posAYy_(swyYd);  UpdateData(0);
	
	*pResult = 0;
}


void GRP2param2::OnDeltaposSPINswscx(NMHDR* pNMHDR, LRESULT* pResult) //x skalenmarkierungs position  
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)             scxd-=1;
	if(pNMUpDown->iDelta >=0)             scxd+=1;
	
	UpdateData(1); CGRP2Dlg o; o.pos_scx_(scxd);  UpdateData(0);
	
	*pResult = 0;
}

void GRP2param2::OnDeltaposSPINswscy(NMHDR* pNMHDR, LRESULT* pResult) //y skalenmarkierungs position  
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)             scyd+=1;
	if(pNMUpDown->iDelta >=0)             scyd-=1;
	
	UpdateData(1); CGRP2Dlg o; o.pos_scy_(scyd);  UpdateData(0);
	
	
	*pResult = 0;
}

void GRP2param2::OnDeltaposSPINswAxx(NMHDR* pNMHDR, LRESULT* pResult) //x achsenbezeichnungs position x  
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)             Axxd+=1;
	if(pNMUpDown->iDelta >=0)             Axxd-=1;
	
	UpdateData(1); CGRP2Dlg o; o.pos_Axx_(Axxd);  UpdateData(0);
	
	*pResult = 0;
}

void GRP2param2::OnDeltaposSPINswAxy(NMHDR* pNMHDR, LRESULT* pResult) //x achsenbezeichnungs position y  
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)             Axyd-=1;
	if(pNMUpDown->iDelta >=0)             Axyd+=1;
	
	UpdateData(1); CGRP2Dlg o; o.pos_Axy_(Axyd);  UpdateData(0);
	
	*pResult = 0;
}

void GRP2param2::OnDeltaposSPINswAyx(NMHDR* pNMHDR, LRESULT* pResult) //y achsenbezeichnungs position x   
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)             Ayxd+=1;
	if(pNMUpDown->iDelta >=0)             Ayxd-=1;
	
	UpdateData(1); CGRP2Dlg o; o.pos_Ayx_(Ayxd);  UpdateData(0);
	
	*pResult = 0;
}

void GRP2param2::OnDeltaposSPINswAyy(NMHDR* pNMHDR, LRESULT* pResult) //y achsenbezeichnungs position y  
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)             Ayyd-=1;
	if(pNMUpDown->iDelta >=0)             Ayyd+=1;
	
	UpdateData(1); CGRP2Dlg o; o.pos_Ayy_(Ayyd);  UpdateData(0);
	
	*pResult = 0;
}

void GRP2param2::OnBUTTONtlgxdreset(){ UpdateData(1); m_tlgx_d="1"; tlgx_d=1;                              UpdateData(0);}
void GRP2param2::OnBUTTONtlgydreset(){ UpdateData(1); m_tlgy_d="1"; tlgy_d=1;                              UpdateData(0);}
void GRP2param2::OnBUTTONtlgxreset() { UpdateData(1); m_tlgx="2";             CGRP2Dlg o; o.x_tlg(m_tlgx); UpdateData(0);}  
void GRP2param2::OnBUTTONtlgyreset() { UpdateData(1); m_tlgy="2";             CGRP2Dlg o; o.y_tlg(m_tlgy); UpdateData(0);} 

void GRP2param2::OnChangeEDITtlgx() {  UpdateData(1);                         CGRP2Dlg o; o.x_tlg(m_tlgx); UpdateData(0);}  
void GRP2param2::OnChangeEDITtlgy() {  UpdateData(1);                         CGRP2Dlg o; o.y_tlg(m_tlgy); UpdateData(0);} 
void GRP2param2::OnChangeEDITtlgxd() { UpdateData(1); tlgx_d = atof(m_tlgx_d);                             UpdateData(0);} 
void GRP2param2::OnChangeEDITtlgyd() { UpdateData(1); tlgy_d = atof(m_tlgy_d);                             UpdateData(0);}

void GRP2param2::OnVoreinstellungen() //reset
{
	UpdateData(1);

	m_ch_xA   =  1; //x_Achse
	m_ch_yA   =  1; //y_Achse
	m_ch_xS   =  1; //x_Skala
	m_ch_yS   =  1; //y_Skala
	m_ch_xSw  =  1; //x_Skalenwerte
	m_ch_ySw  =  1; //y_Skalenwerte
	m_dez_S_x =  2; //x_Skalenwerte_Dezimalstellen
	m_dez_S_y =  2; //y_Skalenwerte_Dezimalstellen
	m_ch_xGrd =  0; //x_Grid
	m_ch_yGrd =  0; //y_Grid
	m_tlgx    = "4";//x_Skala_Teilung
	m_tlgy    = "4";//y_Skala_Teilung
	m_tlgx_d  = "1";//x_Skala_Teilungs_d
	m_tlgy_d  = "1";//y_Skala_Teilungs_d
	swxXd=       0; //X_Skalenwerte_Position_x
	swyXd=       3; //X_Skalenwerte_Position_y
	swxYd=     -26; //Y_Skalenwerte_Position_x
	swyYd=      -8; //Y_Skalenwerte_Position_y

	scxd=        0; //X_Skalierungs_Position //neu...
	scyd=        0; //Y_Skalierungs_Position


	CGRP2Dlg o; 
			 o.x_Achse(m_ch_xA);
			  o.x_Achse(m_ch_yA);
			   o.x_Skala(m_ch_xS);
                o.y_Skala(m_ch_yS);
			     o.x_Sw(m_ch_xSw);
			    o.y_Sw(m_ch_ySw);
			   o.xS_ds(m_dez_S_x);
			 o.yS_ds(m_dez_S_y);
			o.x_Grid(m_ch_xGrd);
		    o.y_Grid(m_ch_yGrd);
			 o.x_tlg(m_tlgx);
			  o.y_tlg(m_tlgy);
			   o.posAXx_(swxXd);
			    o.posAXy_(swyXd);
			   o.posAYx_(swxYd);
			  o.posAYy_(swyYd);
			  o.pos_scx_(scxd);
			   o.pos_scy_(scyd);
	         
	UpdateData(0);	
}

void GRP2param2::OnCHECKini() {UpdateData(1);UpdateData(0);}

void GRP2param2::OnOK() 
{
	                                                  CRect coord;
	                                         GetWindowRect(&coord); 
	
	CWinApp* pApp = AfxGetApp(); // ini profil schreiben  

	if(m_ch_ini)
	{
			 pApp->WriteProfileInt("Achsen","x_",m_ch_xA);
	         pApp->WriteProfileInt("Achsen","y_",m_ch_yA);
			 pApp->WriteProfileInt("Achsen","x_Skala",m_ch_xS);
	         pApp->WriteProfileInt("Achsen","y_Skala",m_ch_yS);
			 pApp->WriteProfileInt("Achsen","x_Skalenwerte",m_ch_xSw);
	         pApp->WriteProfileInt("Achsen","y_Skalenwerte",m_ch_ySw);
			 pApp->WriteProfileInt("Achsen","x_Skalenwerte_Dezimalstellen",m_dez_S_x);
	         pApp->WriteProfileInt("Achsen","y_Skalenwerte_Dezimalstellen",m_dez_S_y);
			 pApp->WriteProfileString("Achsen","x_Skala_Teilung",m_tlgx);
	         pApp->WriteProfileString("Achsen","y_Skala_Teilung",m_tlgy);
	         pApp->WriteProfileString("Achsen","x_Skala_Teilungs_d",m_tlgx_d);
	         pApp->WriteProfileString("Achsen","y_Skala_Teilungs_d",m_tlgy_d);
			 pApp->WriteProfileInt("Achsen","x_Grid",m_ch_xGrd);
		     pApp->WriteProfileInt("Achsen","y_Grid",m_ch_yGrd);
			 pApp->WriteProfileInt("Achsen","X_Skalenwerte_Position_x",swxXd);
	         pApp->WriteProfileInt("Achsen","X_Skalenwerte_Position_y",swyXd);
			 pApp->WriteProfileInt("Achsen","Y_Skalenwerte_Position_x",swxYd);
	         pApp->WriteProfileInt("Achsen","Y_Skalenwerte_Position_y",swyYd);
			 pApp->WriteProfileInt("Achsen","X_Skalierungs_Position",scxd);
	         pApp->WriteProfileInt("Achsen","Y_Skalierungs_Position",scyd);
			 pApp->WriteProfileInt("Achsen","X_Bezeichnungs_Position_x",Axxd);
	         pApp->WriteProfileInt("Achsen","X_Bezeichnungs_Position_y",Axyd);
	         pApp->WriteProfileInt("Achsen","Y_Bezeichnungs_Position_x",Ayxd);
	         pApp->WriteProfileInt("Achsen","Y_Bezeichnungs_Position_y",Ayyd);
	}
			 pApp->WriteProfileInt("INI_schreiben","param2",m_ch_ini);
			 pApp->WriteProfileInt("Parameter","Tabelle",2);
	         pApp->WriteProfileInt("Parameter","Position_x",coord.left);
			 pApp->WriteProfileInt("Parameter","Position_y",coord.top);
	
	CDialog::OnOK();
}

CString GRP2param2::ftoc( double x0, int dez ) 
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












