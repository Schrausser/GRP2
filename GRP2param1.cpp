//------------------------------------------------------------------------| GRP2param1.cpp                               //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#include "stdafx.h"
#include "GRP2.hpp"
#include "GRP2Dlg.hpp"
#include "GRP2param1.hpp"
#include "GRP2param2.hpp"
#include "GRP2param3.hpp"
#include "GRP2param4.hpp"
#include "GRP2param5.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

GRP2param1::GRP2param1(CWnd* pParent )
	: CDialog(GRP2param1::IDD, pParent)
{
	//{{AFX_DATA_INIT(GRP2param1)
		m_ch_Fk = 1;
		m_ch_xy = 0;
		m_dez_W_x = 2;
		m_dez_W_y = 2;
		m_ch_x = 0;
		m_ch_y = 0;
		m_ch_xm = 1;
		m_ch_ym = 1;
		m_ch_y_ = 0;
		m_ch_x_ = 0;
	    m_ch_ini = 1;
	//}}AFX_DATA_INIT
}


void GRP2param1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GRP2param1)
	DDX_Control(pDX, IDC_TAB2, m_tab);
	DDX_Check(pDX, IDC_CHECK_Fk, m_ch_Fk);
	DDX_Check(pDX, IDC_CHECK_xy, m_ch_xy);
	DDX_Text(pDX, IDC_EDIT_dez_W_x, m_dez_W_x);
	DDX_Text(pDX, IDC_EDIT_dez_W_y, m_dez_W_y);
	DDX_Check(pDX, IDC_CHECK_x, m_ch_x);
	DDX_Check(pDX, IDC_CHECK_y, m_ch_y);
	DDX_Check(pDX, IDC_CHECK_xm, m_ch_xm);
	DDX_Check(pDX, IDC_CHECK_ym, m_ch_ym);
	DDX_Check(pDX, IDC_CHECK_y_, m_ch_y_);
	DDX_Check(pDX, IDC_CHECK_x_, m_ch_x_);
	DDX_Check(pDX, IDC_CHECK_ini, m_ch_ini);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(GRP2param1, CDialog)
	//{{AFX_MSG_MAP(GRP2param1)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB2, OnSelchangeTab)
	ON_BN_CLICKED(IDC_CHECK_Fk, OnCHECKFk)
	ON_BN_CLICKED(IDC_CHECK_xy, OnCHECKxy)
	ON_EN_CHANGE(IDC_EDIT_dez_W_x, OnChangeEDITdezWx)
	ON_EN_CHANGE(IDC_EDIT_dez_W_y, OnChangeEDITdezWy)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_dez_W_x, OnDeltaposSPINdezWx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_dez_W_y, OnDeltaposSPINdezWy)
	ON_BN_CLICKED(IDC_CHECK_x, OnCHECKx)
	ON_BN_CLICKED(IDC_CHECK_y, OnCHECKy)
	ON_BN_CLICKED(IDC_CHECK_xm, OnCHECKxm)
	ON_BN_CLICKED(IDC_CHECK_ym, OnCHECKym)
	ON_BN_CLICKED(IDC_CHECK_x_, OnCHECKx_)
	ON_BN_CLICKED(IDC_CHECK_y_, OnCHECKy_)
	ON_BN_CLICKED(IDC_CHECK_ini, OnCHECKini)
	ON_BN_CLICKED(ID_Voreinstellungen, OnVoreinstellungen)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_fw_xX, OnDeltaposSPINfwxX)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_fw_xY, OnDeltaposSPINfwxY)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_fw_yX, OnDeltaposSPINfwyX)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_fw_yY, OnDeltaposSPINfwyY)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL GRP2param1::OnInitDialog() 
{
	CDialog::OnInitDialog();

	UpdateData(1);

	            CWinApp*  pApp = AfxGetApp(); // ini profil lesen  
	
				m_ch_Fk=  pApp->GetProfileInt("Funktion","Kurve",1);
				m_ch_xy = pApp->GetProfileInt("Funktion","Punkte",0);
				m_dez_W_x=pApp->GetProfileInt("Achsen","x_Werte_Dezimalstellen",3);
				m_dez_W_y=pApp->GetProfileInt("Achsen","y_Werte_Dezimalstellen",3);
				m_ch_x  = pApp->GetProfileInt("Achsen","x_Beschriftung_Werte",0);
				m_ch_y  = pApp->GetProfileInt("Achsen","y_Beschriftung_Werte",0);
				m_ch_xm = pApp->GetProfileInt("Achsen","x_Beschriftung_MinMax",1);
				m_ch_ym = pApp->GetProfileInt("Achsen","y_Beschriftung_MinMax",1);
				fwxXd=    pApp->GetProfileInt("Achsen","X_Beschriftung_Werte_Position_x",0);
				fwyXd=    pApp->GetProfileInt("Achsen","X_Beschriftung_Werte_Position_y",-12);
				fwxYd=    pApp->GetProfileInt("Achsen","Y_Beschriftung_Werte_Position_x",6);
				fwyYd=    pApp->GetProfileInt("Achsen","Y_Beschriftung_Werte_Position_y",-8);

	           m_ch_ini=  pApp->GetProfileInt("INI_schreiben","param1",1);
	
	SetWindowPos(&wndTop, pApp->GetProfileInt("Parameter","Position_x",100),
		                  pApp->GetProfileInt("Parameter","Position_y",100), 200+8,100+27, SWP_NOSIZE);
	
	if(m_ch_x==0&&m_ch_xm==0) m_ch_x_=1;
	if(m_ch_y==0&&m_ch_ym==0) m_ch_y_=1;

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

				m_tab.SetCurSel(  0);

	UpdateData(0);
	
	return 1;  
}

void GRP2param1::OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if(m_tab.GetCurSel() ==0);
	if(m_tab.GetCurSel() ==1){OnOK();GRP2param2 o;o.DoModal();}
	if(m_tab.GetCurSel() ==2){OnOK();GRP2param3 o;o.DoModal();}
	if(m_tab.GetCurSel() ==3){OnOK();GRP2param4 o;o.DoModal();}
	if(m_tab.GetCurSel() ==4){OnOK();GRP2param5 o;o.DoModal();}
	
	*pResult = 0;
}

void GRP2param1::OnCHECKx() {UpdateData(1); m_ch_xm=!m_ch_x; m_ch_x_=0; CGRP2Dlg o; o.x_scala(m_ch_x);
                                                                                    o.x_minmax(m_ch_xm); UpdateData(0);}
void GRP2param1::OnCHECKy() {UpdateData(1); m_ch_ym=!m_ch_y; m_ch_y_=0; CGRP2Dlg o; o.y_scala(m_ch_y);
                                                                                    o.y_minmax(m_ch_ym); UpdateData(0);}
void GRP2param1::OnCHECKxm(){UpdateData(1); m_ch_x=!m_ch_xm; m_ch_x_=0; CGRP2Dlg o; o.x_scala(m_ch_x);
                                                                                    o.x_minmax(m_ch_xm); UpdateData(0);}
void GRP2param1::OnCHECKym(){UpdateData(1); m_ch_y=!m_ch_ym; m_ch_y_=0; CGRP2Dlg o; o.y_scala(m_ch_y);
                                                                                    o.y_minmax(m_ch_ym); UpdateData(0);}
void GRP2param1::OnCHECKx_(){UpdateData(1); m_ch_xm=0;       m_ch_x=0;  CGRP2Dlg o; o.x_scala(m_ch_x);
                                                                                    o.x_minmax(m_ch_xm); UpdateData(0);}
void GRP2param1::OnCHECKy_(){UpdateData(1); m_ch_ym=0;       m_ch_y=0;  CGRP2Dlg o; o.y_scala(m_ch_y);
                                                                                    o.y_minmax(m_ch_ym); UpdateData(0);}

void GRP2param1::OnCHECKFk() {            UpdateData(1);                CGRP2Dlg o; o._FnKu(m_ch_Fk);    UpdateData(0);}
void GRP2param1::OnCHECKxy() {            UpdateData(1);                CGRP2Dlg o; o._xyPkt(m_ch_xy);   UpdateData(0);}
void GRP2param1::OnChangeEDITdezWx() {    UpdateData(1);                CGRP2Dlg o; o.xW_ds(m_dez_W_x);  UpdateData(0);}
void GRP2param1::OnChangeEDITdezWy() {    UpdateData(1);                CGRP2Dlg o; o.yW_ds(m_dez_W_y);  UpdateData(0);}


void GRP2param1::OnDeltaposSPINdezWx(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown =   (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)                m_dez_W_x+=1;
	if(pNMUpDown->iDelta >=0)if(m_dez_W_x>0) m_dez_W_x-=1;
		                   
	UpdateData(0); OnChangeEDITdezWx();
		
	*pResult = 0;
}

void GRP2param1::OnDeltaposSPINdezWy(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown =   (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)                m_dez_W_y+=1;
	if(pNMUpDown->iDelta >=0)if(m_dez_W_y>0) m_dez_W_y-=1;
		                   
	UpdateData(0); OnChangeEDITdezWy();
		
	*pResult = 0;
}

void GRP2param1::OnDeltaposSPINfwxX(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)             fwxXd+=1;
	if(pNMUpDown->iDelta >=0)             fwxXd-=1;
	
	UpdateData(1); CGRP2Dlg o; o.posFXx_(fwxXd);  UpdateData(0);
	
	*pResult = 0;
}

void GRP2param1::OnDeltaposSPINfwyX(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)             fwyXd-=1;
	if(pNMUpDown->iDelta >=0)             fwyXd+=1;
	
	UpdateData(1); CGRP2Dlg o; o.posFXy_(fwyXd);  UpdateData(0);
	
	*pResult = 0;
}

void GRP2param1::OnDeltaposSPINfwxY(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)             fwxYd+=1;
	if(pNMUpDown->iDelta >=0)             fwxYd-=1;
	
	UpdateData(1); CGRP2Dlg o; o.posFYx_(fwxYd);  UpdateData(0);
	
	*pResult = 0;
}

void GRP2param1::OnDeltaposSPINfwyY(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)             fwyYd-=1;
	if(pNMUpDown->iDelta >=0)             fwyYd+=1;
	
	UpdateData(1); CGRP2Dlg o; o.posFYy_(fwyYd);  UpdateData(0);
	
	*pResult = 0;
}

void GRP2param1::OnVoreinstellungen() //reset
{
	UpdateData(1);

	m_ch_Fk   = 0; //Kurve
	m_ch_xy   = 1; //Punkte
	m_dez_W_x = 3; //x_Werte_Dezimalstellen
	m_dez_W_y = 3; //y_Werte_Dezimalstellen
	m_ch_x    = 0; //x_Beschriftung_Werte
	m_ch_x_   = 1; //x_Beschriftung_keine
	m_ch_y    = 0; //y_Beschriftung_Werte
	m_ch_y_   = 1; //y_Beschriftung_keine
	m_ch_xm   = 0; //x_Beschriftung_MinMax
	m_ch_ym   = 0; //y_Beschriftung_MinMax
	fwxXd=      0; //X_Beschriftung_Werte_Position_x
	fwyXd=    -12; //X_Beschriftung_Werte_Position_y
	fwxYd=      6; //Y_Beschriftung_Werte_Position_x
	fwyYd=     -8; //Y_Beschriftung_Werte_Position_y

	CGRP2Dlg o; 
	         o._FnKu(m_ch_Fk);  
             o._xyPkt(m_ch_xy); 
             o.xW_ds(m_dez_W_x); 
             o.yW_ds(m_dez_W_y); 
			 o.x_scala(m_ch_x);
			 o.y_scala(m_ch_y);
			 o.x_minmax(m_ch_xm);
			 o.y_minmax(m_ch_ym);
			 o.posFXx_(fwxXd);
			 o.posFXy_(fwyXd);
			 o.posFYx_(fwxYd);
			 o.posFYy_(fwyYd);

	UpdateData(0);
}

void GRP2param1::OnCHECKini() {UpdateData(1);UpdateData(0);}

void GRP2param1::OnOK() 
{
	                                                  CRect coord;
	                                         GetWindowRect(&coord); 
	
	CWinApp* pApp = AfxGetApp(); // ini profil schreiben  
	
	if(m_ch_ini)
	{
	         pApp->WriteProfileInt("Funktion","Kurve",m_ch_Fk);
			 pApp->WriteProfileInt("Funktion","Punkte",m_ch_xy);
			 pApp->WriteProfileInt("Achsen","x_Werte_Dezimalstellen",m_dez_W_x);
	         pApp->WriteProfileInt("Achsen","y_Werte_Dezimalstellen",m_dez_W_y);
			 pApp->WriteProfileInt("Achsen","x_Beschriftung_Werte",m_ch_x);
	         pApp->WriteProfileInt("Achsen","y_Beschriftung_Werte",m_ch_y);
			 pApp->WriteProfileInt("Achsen","x_Beschriftung_MinMax",m_ch_xm);
	         pApp->WriteProfileInt("Achsen","y_Beschriftung_MinMax",m_ch_ym);
			 pApp->WriteProfileInt("Achsen","X_Beschriftung_Werte_Position_x",fwxXd);
	         pApp->WriteProfileInt("Achsen","X_Beschriftung_Werte_Position_y",fwyXd);
	         pApp->WriteProfileInt("Achsen","Y_Beschriftung_Werte_Position_x",fwxYd);
	         pApp->WriteProfileInt("Achsen","Y_Beschriftung_Werte_Position_y",fwyYd);
	}
			 pApp->WriteProfileInt("INI_schreiben","param1",m_ch_ini);
			 pApp->WriteProfileInt("Parameter","Tabelle",1);
	         pApp->WriteProfileInt("Parameter","Position_x",coord.left);
			 pApp->WriteProfileInt("Parameter","Position_y",coord.top);
	
	CDialog::OnOK();
}







	




