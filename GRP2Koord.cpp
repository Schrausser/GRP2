//------------------------------------------------------------------------| GRP2koord.cpp                                //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//


#include "stdafx.h"
#include "grp2.hpp"
#include "GRP2Dlg.hpp"
#include "GRP2koord.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



GRP2Koord::GRP2Koord(CWnd* pParent )
	: CDialog(GRP2Koord::IDD, pParent)
{
	//{{AFX_DATA_INIT(GRP2Koord)
	m_ch_ini = 1;
	m_Ax = 0.0f;
	m_Ay = 0.0f;
	m_Vx = 0.0f;
	m_Vy = 0.0f;
	m_Ax_d = 0.0f;
	m_Ay_d = 0.0f;
	m_Vx_d = 0.0f;
	m_Vy_d = 0.0f;
	//}}AFX_DATA_INIT
}

void GRP2Koord::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GRP2Koord)
	DDX_Control(pDX, ID_BUTTON_Vx_min, m_Vx_min_ctr);
	DDX_Control(pDX, ID_BUTTON_Vx_max, m_Vx_max_ctr);
	DDX_Control(pDX, ID_BUTTON_Ax_min, m_Ax_min_ctr);
	DDX_Control(pDX, ID_BUTTON_Ax_max, m_Ax_max_ctr);
	DDX_Control(pDX, ID_BUTTON_Vy_min, m_Vy_min_ctr);
	DDX_Control(pDX, ID_BUTTON_Vy_max, m_Vy_max_ctr);
	DDX_Control(pDX, ID_BUTTON_Ay_min, m_AY_min_ctr);
	DDX_Control(pDX, ID_BUTTON_Ay_max, m_Ay_max_ctr);
	DDX_Control(pDX, ID_BUTTON_Vx_0, m_Vx_0_ctr);
	DDX_Control(pDX, ID_BUTTON_Ax_0, m_Ax_0_ctr);
	DDX_Check(pDX, IDC_CHECK_ini, m_ch_ini);
	DDX_Text(pDX, IDC_EDIT_Ax, m_Ax);
	DDX_Text(pDX, IDC_EDIT_Ay, m_Ay);
	DDX_Text(pDX, IDC_EDIT_Vx, m_Vx);
	DDX_Text(pDX, IDC_EDIT_Vy, m_Vy);
	DDX_Text(pDX, IDC_EDIT_Ax_d, m_Ax_d);
	DDX_Text(pDX, IDC_EDIT_Ay_d, m_Ay_d);
	DDX_Text(pDX, IDC_EDIT_Vx_d, m_Vx_d);
	DDX_Text(pDX, IDC_EDIT_Vy_d, m_Vy_d);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(GRP2Koord, CDialog)
	//{{AFX_MSG_MAP(GRP2Koord)
	ON_BN_CLICKED(IDC_CHECK_ini, OnCHECKini)
	ON_BN_CLICKED(ID_Voreinstellungen, OnVoreinstellungen)
	ON_EN_CHANGE(IDC_EDIT_Ax, OnChangeEDITAx)
	ON_EN_CHANGE(IDC_EDIT_Ay, OnChangeEDITAy)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_Ax, OnDeltaposSPINAx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_Ay, OnDeltaposSPINAy)
	ON_EN_CHANGE(IDC_EDIT_Vx, OnChangeEDITVx)
	ON_EN_CHANGE(IDC_EDIT_Vy, OnChangeEDITVy)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_Vx, OnDeltaposSPINVx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_Vy, OnDeltaposSPINVy)
	ON_EN_CHANGE(IDC_EDIT_Ax_d, OnChangeEDITAxd)
	ON_EN_CHANGE(IDC_EDIT_Ay_d, OnChangeEDITAyd)
	ON_BN_CLICKED(ID_BUTTON_Ax_0, OnBUTTONAx0)
	ON_BN_CLICKED(ID_BUTTON_Vx_0, OnBUTTONVx0)
	ON_BN_CLICKED(ID_BUTTON_Ax_max, OnBUTTONAxmax)
	ON_BN_CLICKED(ID_BUTTON_Ax_min, OnBUTTONAxmin)
	ON_BN_CLICKED(ID_BUTTON_Ay_min, OnBUTTONAymin)
	ON_BN_CLICKED(ID_BUTTON_Ay_max, OnBUTTONAymax)
	ON_BN_CLICKED(ID_BUTTON_Vx_max, OnBUTTONVxmax)
	ON_BN_CLICKED(ID_BUTTON_Vx_min, OnBUTTONVxmin)
	ON_BN_CLICKED(ID_BUTTON_Vy_max, OnBUTTONVymax)
	ON_BN_CLICKED(ID_BUTTON_Vy_min, OnBUTTONVymin)
	ON_EN_CHANGE(IDC_EDIT_Vx_d, OnChangeEDITVxd)
	ON_EN_CHANGE(IDC_EDIT_Vy_d, OnChangeEDITVyd)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_Ax_d, OnDeltaposSPINAxd)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_Ay_d, OnDeltaposSPINAyd)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_Vx_d, OnDeltaposSPINVxd)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_Vy_d, OnDeltaposSPINVyd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void GRP2Koord::Koord_(float Ax,float Ay,float Vx,float Vy, float tx,float ty)//koordinatenwertübernahme
{
	                     Ax_=Ax;  Ay_=Ay;  Vx_=Vx;  Vy_=Vy;   tx_=tx;  ty_=ty;
};

void GRP2Koord::MinMax_(float xmin, float xmax, float ymin, float ymax)//kennwertübernahme
{
	                    xmin_=xmin; xmax_=xmax; ymin_=ymin; ymax_=ymax;  
};

BOOL GRP2Koord::OnInitDialog() 
{
	CDialog::OnInitDialog();

	UpdateData(1);

	            CWinApp*  pApp = AfxGetApp(); // ini profil lesen 
				m_Ax_d =  pApp->GetProfileInt("Koordinaten","x_Achsen_delta",0);
				m_Ay_d =  pApp->GetProfileInt("Koordinaten","y_Achsen_delta",0);
				m_Vx_d =  pApp->GetProfileInt("Koordinaten","x_Vektoren_delta",0);
				m_Vy_d =  pApp->GetProfileInt("Koordinaten","y_Vektoren_delta",0);

	           m_ch_ini=  pApp->GetProfileInt("INI_schreiben","Koordinaten",1);
	
	SetWindowPos(&wndTop, pApp->GetProfileInt("Koordinaten","Position_x",100),
		                  pApp->GetProfileInt("Koordinaten","Position_y",100), 200+8,100+27, SWP_NOSIZE);

	m_Ax=Ax_; Ax_0=Ax_;
	m_Ay=Ay_; Ay_0=Ay_;
	m_Vx=Vx_; Vx_0=Vx_;
	m_Vy=Vy_; Vy_0=Vy_;

	if(m_Ax_d==0)m_Ax_d = tx_; tx_0=tx_;
	if(m_Ay_d==0)m_Ay_d = ty_; ty_0=ty_;

	if(m_Vx_d==0)m_Vx_d = tx_; 
	if(m_Vy_d==0)m_Vy_d = ty_; 

	  m_Ax_0_ctr.SetIcon(AfxGetApp()->LoadIcon(IDI_ICON_Ax));
	  m_Vx_0_ctr.SetIcon(AfxGetApp()->LoadIcon(IDI_ICON_Ax));
	m_AY_min_ctr.SetIcon(AfxGetApp()->LoadIcon(IDI_ICON_Ax_mn1));
	m_Vy_min_ctr.SetIcon(AfxGetApp()->LoadIcon(IDI_ICON_Ax_mn1));
	m_Ay_max_ctr.SetIcon(AfxGetApp()->LoadIcon(IDI_ICON_Ax_mx1));
	m_Vy_max_ctr.SetIcon(AfxGetApp()->LoadIcon(IDI_ICON_Ax_mx1));
	m_Ax_min_ctr.SetIcon(AfxGetApp()->LoadIcon(IDI_ICON_Ax_mn0));
	m_Vx_min_ctr.SetIcon(AfxGetApp()->LoadIcon(IDI_ICON_Ax_mn0));
	m_Ax_max_ctr.SetIcon(AfxGetApp()->LoadIcon(IDI_ICON_Ax_mx0));
	m_Vx_max_ctr.SetIcon(AfxGetApp()->LoadIcon(IDI_ICON_Ax_mx0));
	
	UpdateData(0);
	
	return 1; 	              
}

void GRP2Koord::OnChangeEDITAx() {       UpdateData(1); CGRP2Dlg o;o.m_AX_(m_Ax );     UpdateData(0); }
void GRP2Koord::OnChangeEDITAy() {       UpdateData(1); CGRP2Dlg o;o.m_AY_(m_Ay );     UpdateData(0); }
void GRP2Koord::OnChangeEDITAxd() {      UpdateData(1);                                UpdateData(0); }
void GRP2Koord::OnChangeEDITAyd() {      UpdateData(1);                                UpdateData(0); }
void GRP2Koord::OnChangeEDITVxd() {      UpdateData(1);                                UpdateData(0); } 
void GRP2Koord::OnChangeEDITVyd() {      UpdateData(1);                                UpdateData(0); } 
void GRP2Koord::OnChangeEDITVx() {       UpdateData(1); CGRP2Dlg o;o.m_VX_(m_Vx );     UpdateData(0); } 
void GRP2Koord::OnChangeEDITVy() {       UpdateData(1); CGRP2Dlg o;o.m_VY_(m_Vy );     UpdateData(0); } 

void GRP2Koord::OnDeltaposSPINAx(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)                m_Ax+=m_Ax_d;
	if(pNMUpDown->iDelta >=0)                m_Ax-=m_Ax_d;
		                   
	UpdateData(0); OnChangeEDITAx();
	
	*pResult = 0;
}

void GRP2Koord::OnDeltaposSPINAy(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)                m_Ay+=m_Ay_d;
	if(pNMUpDown->iDelta >=0)                m_Ay-=m_Ay_d;
		                   
	UpdateData(0); OnChangeEDITAy();
	
	*pResult = 0;
}

void GRP2Koord::OnDeltaposSPINVx(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)                m_Vx+=m_Vx_d;
	if(pNMUpDown->iDelta >=0)                m_Vx-=m_Vx_d;
		                   
	UpdateData(0); OnChangeEDITVx();
	
	*pResult = 0;
}

void GRP2Koord::OnDeltaposSPINVy(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)                m_Vy+=m_Vy_d;
	if(pNMUpDown->iDelta >=0)                m_Vy-=m_Vy_d;
		                   
	UpdateData(0); OnChangeEDITVy();
	
	*pResult = 0;
}

void GRP2Koord::OnDeltaposSPINAxd(NMHDR* pNMHDR, LRESULT* pResult) 
{
	
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
		
	if(pNMUpDown->iDelta < 0)                m_Ax_d*=10;
	if(pNMUpDown->iDelta >=0)                m_Ax_d/=10;
		     
	UpdateData(0);OnChangeEDITAxd(); 
	
	*pResult = 0;
}

void GRP2Koord::OnDeltaposSPINAyd(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)                m_Ay_d*=10;
	if(pNMUpDown->iDelta >=0)                m_Ay_d/=10;
		     
	UpdateData(0);OnChangeEDITAyd(); 
	
	*pResult = 0;
}

void GRP2Koord::OnDeltaposSPINVxd(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)                m_Vx_d*=10;
	if(pNMUpDown->iDelta >=0)                m_Vx_d/=10;
		     
	UpdateData(0);OnChangeEDITVxd(); 

	*pResult = 0;
}

void GRP2Koord::OnDeltaposSPINVyd(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)                m_Vy_d*=10;
	if(pNMUpDown->iDelta >=0)                m_Vy_d/=10;
		     
	UpdateData(0);OnChangeEDITVyd(); 
	
	*pResult = 0;
}

void GRP2Koord::OnBUTTONAx0() //achsen mittelpunkt
{
	UpdateData(1);
	
	m_Ax=(xmin_+xmax_)/2;
	m_Ay=(ymin_+ymax_)/2;

	UpdateData(0);
	
	OnChangeEDITAx();
	OnChangeEDITAy();
}

void GRP2Koord::OnBUTTONAxmin() {UpdateData(1); m_Ax=xmin_; UpdateData(0); OnChangeEDITAx();}//y achse zu x minimalwert
void GRP2Koord::OnBUTTONAxmax() {UpdateData(1); m_Ax=xmax_; UpdateData(0); OnChangeEDITAx();}//y achse zu x maximalwert	
void GRP2Koord::OnBUTTONAymin() {UpdateData(1); m_Ay=ymin_; UpdateData(0); OnChangeEDITAy();}//x achse zu y minimalwert
void GRP2Koord::OnBUTTONAymax() {UpdateData(1); m_Ay=ymax_; UpdateData(0); OnChangeEDITAy();}//x achse zu y maximalwert
void GRP2Koord::OnBUTTONVxmin() {UpdateData(1); m_Vx=xmin_; UpdateData(0); OnChangeEDITVx();}//x vektor zu x minimalwert
void GRP2Koord::OnBUTTONVxmax() {UpdateData(1); m_Vx=xmax_; UpdateData(0); OnChangeEDITVx();}//x vektor zu x maximalwert	
void GRP2Koord::OnBUTTONVymin() {UpdateData(1); m_Vy=ymin_; UpdateData(0); OnChangeEDITVy();}//y vektor zu y minimalwert
void GRP2Koord::OnBUTTONVymax() {UpdateData(1); m_Vy=ymax_; UpdateData(0); OnChangeEDITVy();}//y vektor zu y maximalwert


void GRP2Koord::OnBUTTONVx0() //vektoren mittelpunkt
{
	UpdateData(1);
	
	m_Vx=(xmin_+xmax_)/2;
	m_Vy=(ymin_+ymax_)/2;

	UpdateData(0);
	
	OnChangeEDITVx();
	OnChangeEDITVy();
}


void GRP2Koord::OnVoreinstellungen() 
{
	UpdateData(1);

	m_Ax=Ax_0;
	m_Ay=Ay_0;
	m_Vx=Vx_0;
	m_Vy=Vy_0;
	m_Ax_d = tx_0;
	m_Ay_d = ty_0;
	m_Vx_d = tx_0;
	m_Vy_d = ty_0;

	CGRP2Dlg o;
	         o.m_AX_(m_Ax );
	         o.m_AY_(m_Ay );
			 o.m_VX_(m_Vx );
	         o.m_VY_(m_Vy ); 
	
	UpdateData(0);
}


void GRP2Koord::OnCHECKini() {UpdateData(1);UpdateData(0);}

void GRP2Koord::OnOK() 
{
	                                                  CRect coord;
	                                         GetWindowRect(&coord); 
	
	CWinApp* pApp = AfxGetApp(); // ini profil schreiben  
	
	if(!m_ch_ini)
	{
		     pApp->WriteProfileInt("Koordinaten","x_Achsen_delta",0);
			 pApp->WriteProfileInt("Koordinaten","y_Achsen_delta",0);
			 pApp->WriteProfileInt("Koordinaten","x_Vektoren_delta",0);
			 pApp->WriteProfileInt("Koordinaten","y_Vektoren_delta",0);	 
	}
	
	if(m_ch_ini)
	{
		     pApp->WriteProfileInt("Koordinaten","x_Achsen_delta",m_Ax_d);
			 pApp->WriteProfileInt("Koordinaten","y_Achsen_delta",m_Ay_d);
			 pApp->WriteProfileInt("Koordinaten","x_Vektoren_delta",m_Vx_d);
			 pApp->WriteProfileInt("Koordinaten","y_Vektoren_delta",m_Vy_d);	 
	}
			 pApp->WriteProfileInt("INI_schreiben","Koordinaten",m_ch_ini);
	         pApp->WriteProfileInt("Koordinaten","Position_x",coord.left);
			 pApp->WriteProfileInt("Koordinaten","Position_y",coord.top);
	
	CDialog::OnOK();
}







 




 






 



