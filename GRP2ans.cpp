//------------------------------------------------------------------------| GRP2ans.cpp                                  //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#include "stdafx.h"
#include "GRP2.hpp"
#include "GRP2ans.hpp"
#include "GRP2Dlg.hpp"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


GRP2ans::GRP2ans(CWnd* pParent )
	: CDialog(GRP2ans::IDD, pParent)
{
	//{{AFX_DATA_INIT(GRP2ans)
	m_ch_x = 0;
	m_ch_y = 0;
	m_ch_xm = 1;
	m_ch_ym = 1;
	m_ch_xA = 1;
	m_ch_xS = 1;
	m_ch_xV = 1;
	m_ch_yA = 1;
	m_ch_yS = 1;
	m_ch_yV = 1;
	m_ch_Fk = 1;
	m_ch_xK = 1;
	m_ch_xy = 0;
	m_ch_yK = 1;
	m_kjy = "0";
	m_kjx = "0";
	m_emfx = "25";
	m_emfy = "30";
	m_ch_y_ = 0;
	m_sc = "1.2";
	m_scy = "30";
	m_ch_x_ = 0;
	m_ch_xSw = 0;
	m_ch_ySw = 0;
	m_kjx_d = "1";
	m_kjy_d = "1";
	m_sc_d = "0.1";
	m_scy_d = "0.5";
	m_tlgx = "2";
	m_tlgx_d = "1";
	m_tlgy = "2";
	m_tlgy_d = "1";
	m_dez_K_x = 2;
	m_dez_K_y = 2;
	m_dez_S_x = 2;
	m_dez_S_y = 2;
	m_dez_W_x = 2;
	m_dez_W_y = 2;
	m_ch_inv = 1;
	//}}AFX_DATA_INIT
}


void GRP2ans::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GRP2ans)
	DDX_Check(pDX, IDC_CHECK_x, m_ch_x);
	DDX_Check(pDX, IDC_CHECK_y, m_ch_y);
	DDX_Check(pDX, IDC_CHECK_xm, m_ch_xm);
	DDX_Check(pDX, IDC_CHECK_ym, m_ch_ym);
	DDX_Check(pDX, IDC_CHECK_xA, m_ch_xA);
	DDX_Check(pDX, IDC_CHECK_xS, m_ch_xS);
	DDX_Check(pDX, IDC_CHECK_xV, m_ch_xV);
	DDX_Check(pDX, IDC_CHECK_yA, m_ch_yA);
	DDX_Check(pDX, IDC_CHECK_yS, m_ch_yS);
	DDX_Check(pDX, IDC_CHECK_yV, m_ch_yV);
	DDX_Check(pDX, IDC_CHECK_Fk, m_ch_Fk);
	DDX_Check(pDX, IDC_CHECK_xK, m_ch_xK);
	DDX_Check(pDX, IDC_CHECK_xy, m_ch_xy);
	DDX_Check(pDX, IDC_CHECK_yK, m_ch_yK);
	DDX_Text(pDX, IDC_EDIT_kjy, m_kjy);
	DDX_Text(pDX, IDC_EDIT_kjx, m_kjx);
	DDX_CBString(pDX, IDC_COMBO_emfx, m_emfx);
	DDX_CBString(pDX, IDC_COMBO_emfy, m_emfy);
	DDX_Check(pDX, IDC_CHECK_y_, m_ch_y_);
	DDX_Text(pDX, IDC_EDIT_sc, m_sc);
	DDX_Text(pDX, IDC_EDIT_scy, m_scy);
	DDX_Check(pDX, IDC_CHECK_x_, m_ch_x_);
	DDX_Check(pDX, IDC_CHECK_xSw, m_ch_xSw);
	DDX_Check(pDX, IDC_CHECK_ySw, m_ch_ySw);
	DDX_Text(pDX, IDC_EDIT_kjx_d, m_kjx_d);
	DDX_Text(pDX, IDC_EDIT_kjy_d, m_kjy_d);
	DDX_Text(pDX, IDC_EDIT_sc_d, m_sc_d);
	DDX_Text(pDX, IDC_EDIT_scy_d, m_scy_d);
	DDX_Text(pDX, IDC_EDIT_tlgx, m_tlgx);
	DDX_Text(pDX, IDC_EDIT_tlgx_d, m_tlgx_d);
	DDX_Text(pDX, IDC_EDIT_tlgy, m_tlgy);
	DDX_Text(pDX, IDC_EDIT_tlgy_d, m_tlgy_d);
	DDX_Text(pDX, IDC_EDIT_dez_K_x, m_dez_K_x);
	DDX_Text(pDX, IDC_EDIT_dez_K_y, m_dez_K_y);
	DDX_Text(pDX, IDC_EDIT_dez_S_x, m_dez_S_x);
	DDX_Text(pDX, IDC_EDIT_dez_S_y, m_dez_S_y);
	DDX_Text(pDX, IDC_EDIT_dez_W_x, m_dez_W_x);
	DDX_Text(pDX, IDC_EDIT_dez_W_y, m_dez_W_y);
	DDX_Check(pDX, IDC_CHECK_inv, m_ch_inv);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(GRP2ans, CDialog)
	//{{AFX_MSG_MAP(GRP2ans)
	ON_BN_CLICKED(IDC_CHECK_x, OnCHECKx)
	ON_BN_CLICKED(IDC_CHECK_y, OnCHECKy)
	ON_BN_CLICKED(IDC_CHECK_xm, OnCHECKxm)
	ON_BN_CLICKED(IDC_CHECK_ym, OnCHECKym)
	ON_BN_CLICKED(IDC_CHECK_xA, OnCHECKxA)
	ON_BN_CLICKED(IDC_CHECK_xS, OnCHECKxS)
	ON_BN_CLICKED(IDC_CHECK_yA, OnCHECKyA)
	ON_BN_CLICKED(IDC_CHECK_yS, OnCHECKyS)
	ON_BN_CLICKED(IDC_CHECK_xV, OnCHECKxV)
	ON_BN_CLICKED(IDC_CHECK_yV, OnCHECKyV)
	ON_BN_CLICKED(IDC_CHECK_Fk, OnCHECKFk)
	ON_BN_CLICKED(IDC_CHECK_xK, OnCHECKxK)
	ON_BN_CLICKED(IDC_CHECK_yK, OnCHECKyK)
	ON_BN_CLICKED(IDC_CHECK_xy, OnCHECKxy)
	ON_CBN_SELCHANGE(IDC_COMBO_emfy, OnSelchangeCOMBOemfy)
	ON_CBN_SELCHANGE(IDC_COMBO_emfx, OnSelchangeCOMBOemfx)
	ON_EN_CHANGE(IDC_EDIT_kjx, OnChangeEDITkjx)
	ON_EN_CHANGE(IDC_EDIT_kjy, OnChangeEDITkjy)
	ON_EN_CHANGE(IDC_EDIT_sc, OnChangeEDITsc)
	ON_EN_CHANGE(IDC_EDIT_scy, OnChangeEDITscy)
	ON_WM_MOUSEWHEEL()
	ON_BN_CLICKED(IDC_CHECK_x_, OnCHECKx_)
	ON_BN_CLICKED(IDC_CHECK_y_, OnCHECKy_)
	ON_BN_CLICKED(IDC_CHECK_xSw, OnCHECKxSw)
	ON_BN_CLICKED(IDC_CHECK_ySw, OnCHECKySw)
	ON_BN_CLICKED(IDC_BUTTON_kjx_dwn, OnBUTTONkjxdwn)
	ON_BN_CLICKED(IDC_BUTTON_kjx_reset, OnBUTTONkjxreset)
	ON_BN_CLICKED(IDC_BUTTON_kjx_up, OnBUTTONkjxup)
	ON_EN_CHANGE(IDC_EDIT_kjx_d, OnChangeEDITkjxd)
	ON_BN_CLICKED(IDC_BUTTON_kjy_dwn, OnBUTTONkjydwn)
	ON_BN_CLICKED(IDC_BUTTON_kjy_reset, OnBUTTONkjyreset)
	ON_BN_CLICKED(IDC_BUTTON_kjy_up, OnBUTTONkjyup)
	ON_EN_CHANGE(IDC_EDIT_kjy_d, OnChangeEDITkjyd)
	ON_BN_CLICKED(IDC_BUTTON_kjx_d_reset, OnBUTTONkjxdreset)
	ON_BN_CLICKED(IDC_BUTTON_kjy_d_reset, OnBUTTONkjydreset)
	ON_BN_CLICKED(IDC_BUTTON_sc_d_reset, OnBUTTONscdreset)
	ON_BN_CLICKED(IDC_BUTTON_sc_dwn, OnBUTTONscdwn)
	ON_BN_CLICKED(IDC_BUTTON_sc_reset, OnBUTTONscreset)
	ON_BN_CLICKED(IDC_BUTTON_sc_up, OnBUTTONscup)
	ON_BN_CLICKED(IDC_BUTTON_scy_d_reset, OnBUTTONscydreset)
	ON_BN_CLICKED(IDC_BUTTON_scy_dwn, OnBUTTONscydwn)
	ON_BN_CLICKED(IDC_BUTTON_scy_reset, OnBUTTONscyreset)
	ON_BN_CLICKED(IDC_BUTTON_scy_up, OnBUTTONscyup)
	ON_EN_CHANGE(IDC_EDIT_sc_d, OnChangeEDITscd)
	ON_EN_CHANGE(IDC_EDIT_scy_d, OnChangeEDITscyd)
	ON_EN_CHANGE(IDC_EDIT_tlgx, OnChangeEDITtlgx)
	ON_EN_CHANGE(IDC_EDIT_tlgx_d, OnChangeEDITtlgxd)
	ON_EN_CHANGE(IDC_EDIT_tlgy, OnChangeEDITtlgy)
	ON_EN_CHANGE(IDC_EDIT_tlgy_d, OnChangeEDITtlgyd)
	ON_BN_CLICKED(IDC_BUTTON_tlgx_d_reset, OnBUTTONtlgxdreset)
	ON_BN_CLICKED(IDC_BUTTON_tlgx_dwn, OnBUTTONtlgxdwn)
	ON_BN_CLICKED(IDC_BUTTON_tlgx_reset, OnBUTTONtlgxreset)
	ON_BN_CLICKED(IDC_BUTTON_tlgx_up, OnBUTTONtlgxup)
	ON_BN_CLICKED(IDC_BUTTON_tlgy_d_reset, OnBUTTONtlgydreset)
	ON_BN_CLICKED(IDC_BUTTON_tlgy_dwn, OnBUTTONtlgydwn)
	ON_BN_CLICKED(IDC_BUTTON_tlgy_reset, OnBUTTONtlgyreset)
	ON_BN_CLICKED(IDC_BUTTON_tlgy_up, OnBUTTONtlgyup)
	ON_EN_CHANGE(IDC_EDIT_dez_K_x, OnChangeEDITdezKx)
	ON_EN_CHANGE(IDC_EDIT_dez_K_y, OnChangeEDITdezKy)
	ON_EN_CHANGE(IDC_EDIT_dez_S_x, OnChangeEDITdezSx)
	ON_EN_CHANGE(IDC_EDIT_dez_S_y, OnChangeEDITdezSy)
	ON_EN_CHANGE(IDC_EDIT_dez_W_x, OnChangeEDITdezWx)
	ON_EN_CHANGE(IDC_EDIT_dez_W_y, OnChangeEDITdezWy)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_dez_K_x, OnDeltaposSPINdezKx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_dez_K_y, OnDeltaposSPINdezKy)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_dez_S_x, OnDeltaposSPINdezSx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_dez_S_y, OnDeltaposSPINdezSy)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_dez_W_x, OnDeltaposSPINdezWx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_dez_W_y, OnDeltaposSPINdezWy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL GRP2ans::OnInitDialog() 
{
	CDialog::OnInitDialog();

	UpdateData(1);
	
	CWinApp*  pApp = AfxGetApp(); // ini profil lesen    
	
	m_ch_x  = pApp->GetProfileInt("Achsen","x_Beschriftung_Werte",0);
	m_ch_y  = pApp->GetProfileInt("Achsen","y_Beschriftung_Werte",0);
	m_ch_xm = pApp->GetProfileInt("Achsen","x_Beschriftung_MinMax",1);
	m_ch_ym = pApp->GetProfileInt("Achsen","y_Beschriftung_MinMax",1);
	m_ch_xA = pApp->GetProfileInt("Achsen","x_",1);
	m_ch_yA = pApp->GetProfileInt("Achsen","y_",1);
	m_ch_xV = pApp->GetProfileInt("Achsen","x_Vektor",1);
	m_ch_yV = pApp->GetProfileInt("Achsen","y_Vektor",1);
	m_ch_xS = pApp->GetProfileInt("Achsen","x_Skala",1);
	m_ch_yS = pApp->GetProfileInt("Achsen","y_Skala",1);
	m_ch_xSw= pApp->GetProfileInt("Achsen","x_Skalenwerte",0);
	m_ch_ySw= pApp->GetProfileInt("Achsen","y_Skalenwerte",0);
	m_ch_xK = pApp->GetProfileInt("Achsen","x_Koordinate",1);
	m_ch_yK = pApp->GetProfileInt("Achsen","y_Koordinate",1);
	m_ch_Fk=  pApp->GetProfileInt("Funktion","Kurve",1);
	m_ch_xy = pApp->GetProfileInt("Funktion","Punkte",0);

	m_ch_inv= pApp->GetProfileInt("Funktion","invers",0);
	m_kjx=    pApp->GetProfileString("Achsen","x_Justierung","0");
	m_kjy=    pApp->GetProfileString("Achsen","y_Justierung","0");
	m_kjx_d = pApp->GetProfileString("Achsen","x_Justierungs_d","1");
	m_kjy_d = pApp->GetProfileString("Achsen","y_Justierungs_d","1");
	m_tlgx=    pApp->GetProfileString("Achsen","x_Skala_Teilung","2");
	m_tlgy=    pApp->GetProfileString("Achsen","y_Skala_Teilung","2");
	m_tlgx_d = pApp->GetProfileString("Achsen","x_Skala_Teilungs_d","1");
	m_tlgy_d = pApp->GetProfileString("Achsen","y_Skala_Teilungs_d","1");

	m_dez_W_x= pApp->GetProfileInt("Achsen","x_Werte_Dezimalstellen",3);
	m_dez_W_y= pApp->GetProfileInt("Achsen","y_Werte_Dezimalstellen",3);
	m_dez_S_x= pApp->GetProfileInt("Achsen","x_Skalenwerte_Dezimalstellen",1);
	m_dez_S_y= pApp->GetProfileInt("Achsen","y_Skalenwerte_Dezimalstellen",1);
	m_dez_K_x= pApp->GetProfileInt("Achsen","x_Koordinaten_Dezimalstellen",2);
	m_dez_K_y= pApp->GetProfileInt("Achsen","y_Koordinaten_Dezimalstellen",2);


	m_sc=     pApp->GetProfileString("Dialog","Diagramm_Skalierung_1","1.2");
	m_scy=    pApp->GetProfileString("Dialog","Diagramm_Skalierung_2","30");
	m_sc_d=   pApp->GetProfileString("Dialog","Diagramm_Skalierung_1_d","0.1");
	m_scy_d=  pApp->GetProfileString("Dialog","Diagramm_Skalierung_2_d","1");
	m_emfx=   pApp->GetProfileString("Dialog","Emf_Skalierung_x","25");
	m_emfy=   pApp->GetProfileString("Dialog","Emf_Skalierung_y","30");

	if(m_ch_x==0&&m_ch_xm==0) m_ch_x_=1;
	if(m_ch_y==0&&m_ch_ym==0) m_ch_y_=1;

	kjx_d=atof(m_kjx_d);
	kjy_d=atof(m_kjy_d);

	tlgx_d=atof(m_tlgx_d);
	tlgy_d=atof(m_tlgy_d);

	sc_d=atof(m_sc_d);
	scy_d=atof(m_scy_d);

	UpdateData(0);
	
	return 1;  	              
}


void GRP2ans::OnCHECKx() 
{
	UpdateData(1);

	m_ch_xm=!m_ch_x;
	m_ch_x_=0;
	
	CGRP2Dlg o; o.x_scala(m_ch_x);
	            o.x_minmax(m_ch_xm);
	
	UpdateData(0);	
}

void GRP2ans::OnCHECKy() 
{
	UpdateData(1);

	m_ch_ym=!m_ch_y;
	m_ch_y_=0;
	
	CGRP2Dlg o; o.y_scala(m_ch_y);
	            o.y_minmax(m_ch_ym);

	UpdateData(0);
}

void GRP2ans::OnCHECKxm() 
{
	UpdateData(1);

	m_ch_x=!m_ch_xm;
	m_ch_x_=0;
	
	CGRP2Dlg o;	o.x_scala(m_ch_x);
                o.x_minmax(m_ch_xm);

	UpdateData(0);
}

void GRP2ans::OnCHECKym() 
{
	UpdateData(1);

	m_ch_y=!m_ch_ym;
	m_ch_y_=0;
	
	CGRP2Dlg o; o.y_scala(m_ch_y);
	            o.y_minmax(m_ch_ym);

	UpdateData(0);
}

void GRP2ans::OnCHECKx_() 
{
	UpdateData(1);

	m_ch_xm=0;
	m_ch_x=0;
	
	CGRP2Dlg o; o.x_scala(m_ch_x);
	            o.x_minmax(m_ch_xm);
	
	UpdateData(0);
}

void GRP2ans::OnCHECKy_() 
{
	UpdateData(1);

	m_ch_ym=0;
	m_ch_y=0;
	
	CGRP2Dlg o; o.y_scala(m_ch_y);
	            o.y_minmax(m_ch_ym);
	
	UpdateData(0);	
}


void GRP2ans::OnCHECKxS()
{           
	UpdateData(1); 
	
	if(m_ch_xS==0)m_ch_xSw=0;
	
	CGRP2Dlg o; o.x_Skala(m_ch_xS);
	            o.x_Sw(m_ch_xSw);
	
	
	UpdateData(0);
}


void GRP2ans::OnCHECKyS()
{            
	UpdateData(1); 

	if(m_ch_yS==0)m_ch_ySw=0;

	CGRP2Dlg o; o.y_Skala(m_ch_yS); 
	            o.y_Sw(m_ch_ySw);
	
	
	UpdateData(0);
}

// Koordinaten Justierung x
void GRP2ans::OnBUTTONkjxdwn() 
{
	UpdateData(1);
	
	      float v_=atof(m_kjx);
	            v_-=kjx_d;
	m_kjx =ftoc(v_, 3); 
	
	CGRP2Dlg o; o.x_kj(m_kjx); 
	
	UpdateData(0);
	
}

void GRP2ans::OnBUTTONkjxup() 
{
	UpdateData(1);
	
	      float v_=atof(m_kjx);
	            v_+=kjx_d;
	m_kjx =ftoc(v_, 3); 
	
	CGRP2Dlg o; o.x_kj(m_kjx); 
	
	UpdateData(0);	
}

void GRP2ans::OnChangeEDITkjxd() {UpdateData(1); kjx_d = atof(m_kjx_d);                UpdateData(0);}
void GRP2ans::OnBUTTONkjxreset() {UpdateData(1); m_kjx="0"; CGRP2Dlg o; o.x_kj(m_kjx); UpdateData(0);}
void GRP2ans::OnBUTTONkjxdreset(){UpdateData(1); m_kjx_d="1"; kjx_d=1;                 UpdateData(0);} 


// Koordinaten Justierung y
void GRP2ans::OnBUTTONkjydwn() 
{
	UpdateData(1);
	
	      float v_=atof(m_kjy);
	            v_-=kjy_d;
	m_kjy =ftoc(v_, 3); 
	
	CGRP2Dlg o; o.y_kj(m_kjy); 
	
	UpdateData(0);
}

void GRP2ans::OnBUTTONkjyup() 
{
	UpdateData(1);
	
	      float v_=atof(m_kjy);
	            v_+=kjy_d;
	m_kjy =ftoc(v_, 3); 
	
	CGRP2Dlg o; o.y_kj(m_kjy); 
	
	UpdateData(0);	
}

void GRP2ans::OnChangeEDITkjyd() {UpdateData(1); kjy_d = atof(m_kjy_d);                UpdateData(0);}
void GRP2ans::OnBUTTONkjyreset() {UpdateData(1); m_kjy="0"; CGRP2Dlg o; o.y_kj(m_kjy); UpdateData(0);}
void GRP2ans::OnBUTTONkjydreset(){UpdateData(1); m_kjy_d="1"; kjy_d=1;                 UpdateData(0);} 

// Diagrammskalierung sc
void GRP2ans::OnBUTTONscdwn()
{
	UpdateData(1);
	
	      float v_=atof(m_sc);
	            v_-=sc_d;
	 m_sc =ftoc(v_, 3); 
	
	CGRP2Dlg o; o.sc_(m_sc); 
	
	UpdateData(0);	
}

void GRP2ans::OnBUTTONscup() 
{
	UpdateData(1);
	
	      float v_=atof(m_sc);
	            v_+=sc_d;
	 m_sc =ftoc(v_, 3); 
	
	CGRP2Dlg o; o.sc_(m_sc); 
	
	UpdateData(0);
}

void GRP2ans::OnChangeEDITscd() {UpdateData(1); sc_d = atof(m_sc_d);                UpdateData(0);}
void GRP2ans::OnBUTTONscdreset() {UpdateData(1); m_sc_d="0.1"; sc_d=0.1;  UpdateData(0);} 
void GRP2ans::OnBUTTONscreset() {UpdateData(1); m_sc="1.2"; CGRP2Dlg o; o.sc_(m_sc); UpdateData(0);}



// Diagrammskalierung scy
void GRP2ans::OnBUTTONscydwn() 
{
	UpdateData(1);
	
	      float v_=atof(m_scy);
	            v_-=scy_d;
	m_scy =ftoc(v_, 3); 
	
	CGRP2Dlg o; o.sc_y(m_scy); 
	
	UpdateData(0);
	
}

void GRP2ans::OnBUTTONscyup() 
{
	UpdateData(1);
	
	      float v_=atof(m_scy);
	            v_+=scy_d;
	 m_scy =ftoc(v_, 3); 
	
	CGRP2Dlg o; o.sc_y(m_scy); 
	
	UpdateData(0);
}

void GRP2ans::OnBUTTONscydreset(){UpdateData(1); m_scy_d="1"; scy_d=1;                  UpdateData(0);}
void GRP2ans::OnBUTTONscyreset() {UpdateData(1); m_scy="30"; CGRP2Dlg o; o.sc_y(m_scy); UpdateData(0);}
void GRP2ans::OnChangeEDITscyd() {UpdateData(1); scy_d = atof(m_scy_d);                 UpdateData(0);}

//skalen teilung
void GRP2ans::OnBUTTONtlgxdwn() 
{
	UpdateData(1);
	                          float v_=atof(m_tlgx);
	                                v_-=tlgx_d;
	                   m_tlgx =ftoc(v_, 3); 
	CGRP2Dlg o; o.x_tlg(m_tlgx); 
	
	UpdateData(0);
}


void GRP2ans::OnBUTTONtlgxup() 
{
	UpdateData(1);
	                          float v_=atof(m_tlgx);
	                                v_+=tlgx_d;
	                   m_tlgx =ftoc(v_, 3); 
	CGRP2Dlg o; o.x_tlg(m_tlgx); 
	
	UpdateData(0);	
}



void GRP2ans::OnBUTTONtlgydwn() 
{
	UpdateData(1);
	                          float v_=atof(m_tlgy);
	                                v_-=tlgy_d;
	                   m_tlgy =ftoc(v_, 3); 
	CGRP2Dlg o; o.y_tlg(m_tlgy); 
	
	UpdateData(0);	
}

void GRP2ans::OnBUTTONtlgyup() 
{
	UpdateData(1);
	                          float v_=atof(m_tlgy);
	                                v_+=tlgy_d;
	                   m_tlgy =ftoc(v_, 3); 
	CGRP2Dlg o; o.y_tlg(m_tlgy); 
	
	UpdateData(0);		
}

void GRP2ans::OnBUTTONtlgxdreset() { UpdateData(1); m_tlgx_d="1"; tlgx_d=1;                  UpdateData(0);}
void GRP2ans::OnBUTTONtlgydreset() { UpdateData(1); m_tlgy_d="1"; tlgy_d=1;                  UpdateData(0);}

void GRP2ans::OnBUTTONtlgxreset() { UpdateData(1); m_tlgx="2"; CGRP2Dlg o; o.x_tlg(m_tlgx); UpdateData(0);}  
void GRP2ans::OnBUTTONtlgyreset() { UpdateData(1); m_tlgy="2"; CGRP2Dlg o; o.y_tlg(m_tlgy); UpdateData(0);} 

void GRP2ans::OnChangeEDITtlgx() { UpdateData(1); CGRP2Dlg o; o.x_tlg(m_tlgx);	  UpdateData(0);}  
void GRP2ans::OnChangeEDITtlgy() { UpdateData(1); CGRP2Dlg o; o.y_tlg(m_tlgy);	  UpdateData(0);} 

void GRP2ans::OnChangeEDITtlgxd() { UpdateData(1); tlgx_d = atof(m_tlgx_d);                 UpdateData(0);} 
void GRP2ans::OnChangeEDITtlgyd() { UpdateData(1); tlgy_d = atof(m_tlgy_d);                 UpdateData(0);}

//dezimalstellen spinschalter
void GRP2ans::OnDeltaposSPINdezKx(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown =   (NM_UPDOWN*)pNMHDR;

	        if(pNMUpDown->iDelta < 0)                m_dez_K_x+=1;
	        if(pNMUpDown->iDelta >=0)if(m_dez_K_x>0) m_dez_K_x-=1;
		                   
		UpdateData(0); OnChangeEDITdezKx();
		
	*pResult = 0;
}

void GRP2ans::OnDeltaposSPINdezKy(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown =   (NM_UPDOWN*)pNMHDR;

	        if(pNMUpDown->iDelta < 0)                m_dez_K_y+=1;
	        if(pNMUpDown->iDelta >=0)if(m_dez_K_y>0) m_dez_K_y-=1;
		                   
		UpdateData(0); OnChangeEDITdezKy();
		
	*pResult = 0;
}

void GRP2ans::OnDeltaposSPINdezSx(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown =   (NM_UPDOWN*)pNMHDR;

	        if(pNMUpDown->iDelta < 0)                m_dez_S_x+=1;
	        if(pNMUpDown->iDelta >=0)if(m_dez_S_x>0) m_dez_S_x-=1;
		                   
		UpdateData(0); OnChangeEDITdezSx();
		
	*pResult = 0;
}

void GRP2ans::OnDeltaposSPINdezSy(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown =   (NM_UPDOWN*)pNMHDR;

	    if(pNMUpDown->iDelta < 0)                m_dez_S_y+=1;
	    if(pNMUpDown->iDelta >=0)if(m_dez_S_y>0) m_dez_S_y-=1;
		               
	UpdateData(0); OnChangeEDITdezSy();
		
	*pResult = 0;
}

void GRP2ans::OnDeltaposSPINdezWx(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown =   (NM_UPDOWN*)pNMHDR;

	        if(pNMUpDown->iDelta < 0)                m_dez_W_x+=1;
	        if(pNMUpDown->iDelta >=0)if(m_dez_W_x>0) m_dez_W_x-=1;
		                   
	UpdateData(0); OnChangeEDITdezWx();
		
	*pResult = 0;
}

void GRP2ans::OnDeltaposSPINdezWy(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown =   (NM_UPDOWN*)pNMHDR;

	        if(pNMUpDown->iDelta < 0)                m_dez_W_y+=1;
	        if(pNMUpDown->iDelta >=0)if(m_dez_W_y>0) m_dez_W_y-=1;
		                   
	UpdateData(0); OnChangeEDITdezWy();
		
	*pResult = 0;
}

void GRP2ans::OnChangeEDITdezKx() {    UpdateData(1); CGRP2Dlg o; o.xK_ds(m_dez_K_x); UpdateData(0);}
void GRP2ans::OnChangeEDITdezKy() {    UpdateData(1); CGRP2Dlg o; o.yK_ds(m_dez_K_y); UpdateData(0);}
void GRP2ans::OnChangeEDITdezSx() {    UpdateData(1); CGRP2Dlg o; o.xS_ds(m_dez_S_x); UpdateData(0);}
void GRP2ans::OnChangeEDITdezSy() {    UpdateData(1); CGRP2Dlg o; o.yS_ds(m_dez_S_y); UpdateData(0);}
void GRP2ans::OnChangeEDITdezWx() {    UpdateData(1); CGRP2Dlg o; o.xW_ds(m_dez_W_x); UpdateData(0);}
void GRP2ans::OnChangeEDITdezWy() {    UpdateData(1); CGRP2Dlg o; o.yW_ds(m_dez_W_y); UpdateData(0);}

void GRP2ans::OnCHECKxA() {            UpdateData(1); CGRP2Dlg o; o.x_Achse(m_ch_xA); UpdateData(0);}
void GRP2ans::OnCHECKyA() {	           UpdateData(1); CGRP2Dlg o; o.y_Achse(m_ch_yA); UpdateData(0);}
void GRP2ans::OnCHECKxV() {            UpdateData(1); CGRP2Dlg o; o.x_Vektor(m_ch_xV);UpdateData(0);}
void GRP2ans::OnCHECKyV() {            UpdateData(1); CGRP2Dlg o; o.y_Vektor(m_ch_yV);UpdateData(0);}
void GRP2ans::OnCHECKFk() {            UpdateData(1); CGRP2Dlg o; o. _FnKu(m_ch_Fk);  UpdateData(0);}
void GRP2ans::OnCHECKxK() {            UpdateData(1); CGRP2Dlg o; o.x_Koor(m_ch_xK);  UpdateData(0);}
void GRP2ans::OnCHECKyK() {            UpdateData(1); CGRP2Dlg o; o.y_Koor(m_ch_yK);  UpdateData(0);}
void GRP2ans::OnCHECKxy() {            UpdateData(1); CGRP2Dlg o; o. _xyPkt(m_ch_xy); UpdateData(0);}
void GRP2ans::OnCHECKxSw(){            UpdateData(1); CGRP2Dlg o; o.x_Sw(m_ch_xSw);   UpdateData(0);}
void GRP2ans::OnCHECKySw(){            UpdateData(1); CGRP2Dlg o; o.y_Sw(m_ch_ySw);   UpdateData(0);}
void GRP2ans::OnSelchangeCOMBOemfy() { UpdateData(1);                                 UpdateData(0);}
void GRP2ans::OnSelchangeCOMBOemfx() { UpdateData(1);                                 UpdateData(0);}
void GRP2ans::OnChangeEDITkjx() {      UpdateData(1); CGRP2Dlg o; o.x_kj(m_kjx);	  UpdateData(0);}
void GRP2ans::OnChangeEDITkjy() {      UpdateData(1); CGRP2Dlg o; o.y_kj(m_kjy);	  UpdateData(0);}
void GRP2ans::OnChangeEDITsc() {       UpdateData(1); CGRP2Dlg o; o.sc_(m_sc);        UpdateData(0);}
void GRP2ans::OnChangeEDITscy() {      UpdateData(1); CGRP2Dlg o; o.sc_y(m_scy);      UpdateData(0);}


BOOL GRP2ans::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	UpdateData(1);
	                    int x;
	
	if(nFlags!=MK_RBUTTON ) x=atoi(m_kjx);
	if(nFlags==MK_RBUTTON ) x=atoi(m_kjy);
		
	if(zDelta< 0) x+=1;
	if(zDelta>=0 )x-=1;

	       char ccc[100];
           itoa(x,ccc,10);
	const char* cc=ccc;																	 
	CString c_=cc;

	if(nFlags!=MK_RBUTTON ) {m_kjx=c_; CGRP2Dlg o; o.x_kj(m_kjx);}
	if(nFlags==MK_RBUTTON ) {m_kjy=c_; CGRP2Dlg o; o.y_kj(m_kjy);}

	UpdateData(0);

	return CDialog::OnMouseWheel(nFlags, zDelta, pt);
}

void GRP2ans::OnOK() 
{
	UpdateData(1);

	CGRP2Dlg o; o.x_emf(m_emfx);
	            o.y_emf(m_emfy);
				 
	          
	UpdateData(1);
	
	CWinApp*  pApp = AfxGetApp(); // ini profil lesen    
	
	          pApp->WriteProfileInt("Achsen","x_Beschriftung_Werte",m_ch_x);
	          pApp->WriteProfileInt("Achsen","y_Beschriftung_Werte",m_ch_y);
			  pApp->WriteProfileInt("Achsen","x_Beschriftung_MinMax",m_ch_xm);
	          pApp->WriteProfileInt("Achsen","y_Beschriftung_MinMax",m_ch_ym);
			  pApp->WriteProfileInt("Achsen","x_",m_ch_xA);
	          pApp->WriteProfileInt("Achsen","y_",m_ch_yA);
	          pApp->WriteProfileInt("Achsen","x_Vektor",m_ch_xV);
	          pApp->WriteProfileInt("Achsen","y_Vektor",m_ch_yV);
	          pApp->WriteProfileInt("Achsen","x_Skala",m_ch_xS);
	          pApp->WriteProfileInt("Achsen","y_Skala",m_ch_yS);
			  pApp->WriteProfileInt("Achsen","x_Skalenwerte",m_ch_xSw);
	          pApp->WriteProfileInt("Achsen","y_Skalenwerte",m_ch_ySw);
			  pApp->WriteProfileInt("Achsen","x_Koordinate",m_ch_xK);
	          pApp->WriteProfileInt("Achsen","y_Koordinate",m_ch_yK);
              pApp->WriteProfileInt("Funktion","Kurve",m_ch_Fk);
	          pApp->WriteProfileInt("Funktion","Punkte",m_ch_xy);
			  pApp->WriteProfileInt("Funktion","invers",m_ch_inv);
			  pApp->WriteProfileString("Achsen","x_Justierung",m_kjx);
	          pApp->WriteProfileString("Achsen","y_Justierung",m_kjy);
			  pApp->WriteProfileString("Achsen","x_Justierungs_d",m_kjx_d);
			  pApp->WriteProfileString("Achsen","y_Justierungs_d",m_kjy_d);
			  pApp->WriteProfileString("Achsen","x_Skala_Teilung",m_tlgx);
	          pApp->WriteProfileString("Achsen","y_Skala_Teilung",m_tlgy);
	          pApp->WriteProfileString("Achsen","x_Skala_Teilungs_d",m_tlgx_d);
	          pApp->WriteProfileString("Achsen","y_Skala_Teilungs_d",m_tlgy_d);
			  
			  pApp->WriteProfileInt("Achsen","x_Werte_Dezimalstellen",m_dez_W_x);
	          pApp->WriteProfileInt("Achsen","y_Werte_Dezimalstellen",m_dez_W_y);
	          pApp->WriteProfileInt("Achsen","x_Skalenwerte_Dezimalstellen",m_dez_S_x);
	          pApp->WriteProfileInt("Achsen","y_Skalenwerte_Dezimalstellen",m_dez_S_y);
			  pApp->WriteProfileInt("Achsen","x_Koordinaten_Dezimalstellen",m_dez_K_x);
	          pApp->WriteProfileInt("Achsen","y_Koordinaten_Dezimalstellen",m_dez_K_y);

			  pApp->WriteProfileString("Dialog","Diagramm_Skalierung_1",m_sc);
		      pApp->WriteProfileString("Dialog","Diagramm_Skalierung_2",m_scy);
			  pApp->WriteProfileString("Dialog","Diagramm_Skalierung_1_d",m_sc_d);
		      pApp->WriteProfileString("Dialog","Diagramm_Skalierung_2_d",m_scy_d);
			  pApp->WriteProfileString("Dialog","Emf_Skalierung_x",m_emfx);
			  pApp->WriteProfileString("Dialog","Emf_Skalierung_y",m_emfy);

			  

	CDialog::OnOK();
}

	




//--------------------------------------------------------------------------------------| ftoc(), fliesskomma zu CString
//                                                                                      | bsp. cvar= ftoc(fvar, 8);
CString GRP2ans::ftoc( double x0, int dez ) 
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





