//------------------------------------------------------------------------| GRP2fn3.cpp                                  //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#include "stdafx.h"
#include "math.h"
#include "grp2.hpp"
#include "GRP2Dlg.hpp"
#include "GRP2fn1.hpp"
#include "GRP2fn2.hpp"
#include "GRP2fn3.hpp"
#include "GRP2fn4.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

GRP2fn3::GRP2fn3(CWnd* pParent ): CDialog(GRP2fn3::IDD, pParent)	
{
	//{{AFX_DATA_INIT(GRP2fn3)
	m_ch_vx = 1;
	m_ch_vy = 0;
	m_ch_a3 = 0;
	m_ch_a4 = 0;
	m_ch_ag3 = 0;
	m_ch_ag4 = 0;
	m_ch_am = 1;
	m_ch_sd = 1;
	m_ch_sdg = 0;
	m_ch_sga3 = 0;
	m_ch_sga4 = 0;
	m_ch_sgam = 0;
	m_CI = 95.0f;
	m_CI_t = 1.0f;
	m_CI_z = 1.0f;
	m_ch_p = 0;
	m_ch_p1 = 0;
	m_ch_p2 = 0;

	//}}AFX_DATA_INIT
}

void GRP2fn3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GRP2fn3)
	DDX_Control(pDX, IDC_EDIT_CI, m_CI_ctr);
	DDX_Control(pDX, IDC_EDIT_CI_z1, m_CIz_ctr);
	DDX_Control(pDX, IDC_EDIT_CI_t1, m_CIt_ctr);
	DDX_Control(pDX, IDC_TAB2, m_tab);
	DDX_Check(pDX, IDC_CHECK_ini, m_ch_ini);
	DDX_Check(pDX, IDC_CHECK_vx, m_ch_vx);
	DDX_Check(pDX, IDC_CHECK_vy, m_ch_vy);
	DDX_Check(pDX, IDC_CHECK_a3, m_ch_a3);
	DDX_Check(pDX, IDC_CHECK_a4, m_ch_a4);
	DDX_Check(pDX, IDC_CHECK_ag3, m_ch_ag3);
	DDX_Check(pDX, IDC_CHECK_ag4, m_ch_ag4);
	DDX_Check(pDX, IDC_CHECK_am, m_ch_am);
	DDX_Check(pDX, IDC_CHECK_sd, m_ch_sd);
	DDX_Check(pDX, IDC_CHECK_sdg, m_ch_sdg);
	DDX_Check(pDX, IDC_CHECK_sga3, m_ch_sga3);
	DDX_Check(pDX, IDC_CHECK_sga4, m_ch_sga4);
	DDX_Check(pDX, IDC_CHECK_sgam, m_ch_sgam);
	DDX_Text(pDX, IDC_EDIT_CI, m_CI);
	DDV_MinMaxFloat(pDX, m_CI, 0.1f, 99.9f);
	DDX_Text(pDX, IDC_EDIT_CI_t1, m_CI_t);
	DDX_Text(pDX, IDC_EDIT_CI_z1, m_CI_z);
	DDX_Check(pDX, IDC_CHECK_p, m_ch_p);
	DDX_Check(pDX, IDC_CHECK_pa1, m_ch_p1);
	DDX_Check(pDX, IDC_CHECK_pa2, m_ch_p2);

	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(GRP2fn3, CDialog)
	//{{AFX_MSG_MAP(GRP2fn3)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB2, OnSelchangeTab2)
	ON_BN_CLICKED(IDC_CHECK_ini, OnCHECKini)
	ON_BN_CLICKED(IDC_CHECK_vx, OnCHECKvx)
	ON_BN_CLICKED(IDC_CHECK_vy, OnCHECKvy)
	ON_BN_CLICKED(IDC_BUTTON_P1, OnButtonP1)
	ON_BN_CLICKED(IDC_BUTTON_SP1, OnButtonSp1)
	ON_BN_CLICKED(IDC_CHECK_a3, OnCHECKa3)
	ON_BN_CLICKED(IDC_CHECK_a4, OnCHECKa4)
	ON_BN_CLICKED(IDC_CHECK_ag3, OnCHECKag3)
	ON_BN_CLICKED(IDC_CHECK_ag4, OnCHECKag4)
	ON_BN_CLICKED(IDC_CHECK_am, OnCHECKam)
	ON_BN_CLICKED(IDC_CHECK_sd, OnCHECKsd)
	ON_BN_CLICKED(IDC_CHECK_sdg, OnCHECKsdg)
	ON_BN_CLICKED(IDC_CHECK_sga3, OnCHECKsga3)
	ON_BN_CLICKED(IDC_CHECK_sga4, OnCHECKsga4)
	ON_BN_CLICKED(IDC_CHECK_sgam, OnCHECKsgam)
	ON_EN_CHANGE(IDC_EDIT_CI, OnChangeEditCi)
	ON_EN_CHANGE(IDC_EDIT_CI_t1, OnChangeEDITCIt1)
	ON_EN_CHANGE(IDC_EDIT_CI_z1, OnChangeEDITCIz1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_CI, OnDeltaposSpinCi)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_CI_Fp_t, OnDeltaposSPINCIt1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_CI_Fp_z, OnDeltaposSPINCIz1)
	ON_BN_CLICKED(ID_Voreinstellungen, OnVoreinstellungen)
	ON_BN_CLICKED(IDC_CHECK_p, OnCHECKp)
	ON_BN_CLICKED(IDC_CHECK_pa1, OnCHECKpa1)
	ON_BN_CLICKED(IDC_CHECK_pa2, OnCHECKpa2)
	ON_BN_CLICKED(ID_FXY, OnFxy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL GRP2fn3::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	UpdateData(1);

				CWinApp* pApp = AfxGetApp(); // ini profil lesen 

				     df_=pApp->GetProfileInt("Funktion","N",1000);
				m_ch_vy= pApp->GetProfileInt("Funktion","Fp_Theta",0);
	   m_ch_vx=!m_ch_vy;
	          m_CI= atof(pApp->GetProfileString("Funktion","Fp_CI","95.0"));
			   m_ch_am=  pApp->GetProfileInt("Funktion","am_Darstellung",1);
			   m_ch_sd=  pApp->GetProfileInt("Funktion","sd_Darstellung",0);
			   m_ch_sdg= pApp->GetProfileInt("Funktion","sd'_Darstellung",1);
			   m_ch_sgam=pApp->GetProfileInt("Funktion","s'am_Darstellung",0);
			   m_ch_a3=  pApp->GetProfileInt("Funktion","a3_Darstellung",0);
			   m_ch_a4=  pApp->GetProfileInt("Funktion","a4_Darstellung",0);
			   m_ch_ag3= pApp->GetProfileInt("Funktion","a3'_Darstellung",0);
			   m_ch_ag4= pApp->GetProfileInt("Funktion","a4'_Darstellung",0);
			   m_ch_sga3=pApp->GetProfileInt("Funktion","s'a3_Darstellung",1);
			   m_ch_sga4=pApp->GetProfileInt("Funktion","s'a4_Darstellung",0);
			   	  m_p=   pApp->GetProfileInt("Funktion","p_p",0); 
			   if(m_p==0)m_ch_p=1;
			   if(m_p==1)m_ch_p1=1;
			   if(m_p==2)m_ch_p2=1;
			   
			   m_ch_ini= pApp->GetProfileInt("INI_schreiben","fn3",1);

	SetWindowPos(&wndTop,pApp->GetProfileInt("Funktion","Position_x",100),
		                 pApp->GetProfileInt("Funktion","Position_y",100), 200+8,100+27, SWP_NOSIZE);

	                          TC_ITEM o;
	                                  o.mask = TCIF_TEXT;
	/*CTabCtrl	m_tab;*/              o.pszText = "f(x)"; 
				m_tab.InsertItem( 0, &o );   
				                      o.pszText = "r(x,y)";
				m_tab.InsertItem( 1, &o );
				                      o.pszText = "F(p)";
				m_tab.InsertItem( 2, &o );
				                      o.pszText = "F(e)";
				m_tab.InsertItem( 3, &o );
				         
				m_tab.SetCurSel(  2);

	GRP2fn3::QP_() ;

				 swz1=0;
				 swz2=0;
				 swt1=0;
				 swt2=0;
				 swt3=0;
	if(m_ch_sd)  swz1=1;
	if(m_ch_sdg) swz2=1;
	if(m_ch_sgam)swt1=1;
	if(m_ch_sga3)swt2=1;
	if(m_ch_sga4)swt3=1;
	
	sw_edit();

	UpdateData(0);
	
	return 1;                
}

void GRP2fn3::OnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if(m_tab.GetCurSel() ==0){OnOK();GRP2fn1 o;o.DoModal();}
	if(m_tab.GetCurSel() ==1){OnOK();GRP2fn2 o;o.DoModal();}
	if(m_tab.GetCurSel() ==2);
	if(m_tab.GetCurSel() ==3){OnOK();GRP2fn4 o;o.DoModal();}
	
	*pResult = 0;
}

void GRP2fn3::OnCHECKp() {	  UpdateData(1);m_ch_p = 1; m_ch_p1 = 0; m_ch_p2 = 0; CGRP2Dlg o;o.sw_p_p(0);UpdateData(0); }
void GRP2fn3::OnCHECKpa1() {  UpdateData(1);m_ch_p = 0; m_ch_p1 = 1; m_ch_p2 = 0; CGRP2Dlg o;o.sw_p_p(1);UpdateData(0); }
void GRP2fn3::OnCHECKpa2() {  UpdateData(1);m_ch_p = 0; m_ch_p1 = 0; m_ch_p2 = 1; CGRP2Dlg o;o.sw_p_p(2);UpdateData(0); }

void GRP2fn3::OnCHECKvx(){        UpdateData(1); m_ch_vy=!m_ch_vx;       CGRP2Dlg o;o.p_q_sw(!m_ch_vx);        UpdateData(0); } 
void GRP2fn3::OnCHECKvy(){        UpdateData(1); m_ch_vx=!m_ch_vy;       CGRP2Dlg o;o.p_q_sw(m_ch_vy);         UpdateData(0); } 
void GRP2fn3::OnCHECKa3() {       UpdateData(1);                         CGRP2Dlg o;o.p_a3(m_ch_a3 );          UpdateData(0); }
void GRP2fn3::OnCHECKa4() {       UpdateData(1);                         CGRP2Dlg o;o.p_a4(m_ch_a4 );          UpdateData(0); }
void GRP2fn3::OnCHECKag3() {      UpdateData(1);                         CGRP2Dlg o;o.p_ag3(m_ch_ag3 );        UpdateData(0); }
void GRP2fn3::OnCHECKag4() {      UpdateData(1);                         CGRP2Dlg o;o.p_ag4(m_ch_ag4 );        UpdateData(0); }
void GRP2fn3::OnCHECKam() {       UpdateData(1);                         CGRP2Dlg o;o.p_am(m_ch_am );          UpdateData(0); }
void GRP2fn3::OnCHECKsd() {       UpdateData(1);swz1=m_ch_sd; sw_edit(); CGRP2Dlg o;o.p_sd(m_ch_sd );          UpdateData(0); }
void GRP2fn3::OnCHECKsdg() {      UpdateData(1);swz2=m_ch_sdg;sw_edit(); CGRP2Dlg o;o.p_sdg(m_ch_sdg );        UpdateData(0); }
void GRP2fn3::OnCHECKsga3() {     UpdateData(1);swt2=m_ch_sga3;sw_edit();CGRP2Dlg o;o.p_sga3(m_ch_sga3 );      UpdateData(0); }
void GRP2fn3::OnCHECKsga4() {     UpdateData(1);swt3=m_ch_sga4;sw_edit();CGRP2Dlg o;o.p_sga4(m_ch_sga4 );      UpdateData(0); }
void GRP2fn3::OnCHECKsgam() {     UpdateData(1);swt1=m_ch_sgam;sw_edit();CGRP2Dlg o;o.p_sgam(m_ch_sgam );      UpdateData(0); }
void GRP2fn3::OnChangeEditCi() {  UpdateData(1); GRP2fn3::QP_() ;        CGRP2Dlg o;o.CI_Fp(m_CI);             UpdateData(0); }
void GRP2fn3::OnChangeEDITCIt1() {UpdateData(1); GRP2fn3::QP_t();        CGRP2Dlg o;o.CI_Fp(m_CI);             UpdateData(0); }
void GRP2fn3::OnChangeEDITCIz1() {UpdateData(1); GRP2fn3::QP_z();        CGRP2Dlg o;o.CI_Fp(m_CI);             UpdateData(0); }

void GRP2fn3::sw_edit()
{
	m_CIt_ctr.SetReadOnly(!(swt1+swt2+swt3));
	m_CIz_ctr.SetReadOnly(!(swz1+swz2));
	m_CI_ctr.SetReadOnly(!(swz1+swz2+swt1+swt2+swt3));
};


void GRP2fn3::QP_() 
{
	m_CI_z=zp_funktion((100 -((100-m_CI)/2))/100);          
	m_CI_t=tp_funktion((100 -((100-m_CI)/2))/100,  df_  );  
}

void GRP2fn3::QP_z() 
{
	     m_CI =100*pz_funktion(m_CI_z);
	m_CI=m_CI-(100-m_CI);
	m_CI_t=tp_funktion((100 -((100-m_CI)/2))/100,  df_ ); 
}

void GRP2fn3::QP_t() 
{
	     m_CI =100*pt_funktion(m_CI_t,df_);
	m_CI=m_CI-(100-m_CI);
	m_CI_z=zp_funktion((100 -((100-m_CI)/2))/100); 
}

void GRP2fn3::OnDeltaposSpinCi(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(swt1+swt2+swt3+swz1+swz2)
	{
		if(pNMUpDown->iDelta < 0)if(m_CI<99.9)  m_CI=m_CI+0.1;
		if(pNMUpDown->iDelta >=0)if(m_CI>0.2)   m_CI=m_CI-0.1;
							   
		UpdateData(0); OnChangeEditCi();
	}
	
	*pResult = 0;
}

void GRP2fn3::OnDeltaposSPINCIt1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(swt1+swt2+swt3)
	{
		if(pNMUpDown->iDelta < 0)  m_CI_t=m_CI_t+0.1;
		if(pNMUpDown->iDelta >=0)  m_CI_t=m_CI_t-0.1;
							   
		UpdateData(0); OnChangeEDITCIt1();
	}
	
	*pResult = 0;
}

void GRP2fn3::OnDeltaposSPINCIz1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(swz1+swz2)
	{
		if(pNMUpDown->iDelta < 0)  m_CI_z=m_CI_z+0.1;
		if(pNMUpDown->iDelta >=0)  m_CI_z=m_CI_z-0.1;
							   
		UpdateData(0); OnChangeEDITCIz1();
	}
	
	*pResult = 0;
}



void GRP2fn3::OnButtonP1() 
{
	UpdateData(1);

	m_ch_a3 =    1 ; 
	m_ch_a4=     0 ; 
	m_ch_ag3 =   0 ; 
	m_ch_ag4 =   0 ; 
	m_ch_am =    1 ; 
	m_ch_sd =    1 ; swz1=1;
	m_ch_sdg =   0 ; swz2=0;
	m_ch_sga3 =  0 ; swt2=0;
	m_ch_sga4 =  0 ; swt3=0;
	m_ch_sgam =  0 ; swt1=0;
	m_p=         0; //
	m_ch_p=      1; //
	m_ch_p1=     0; //
	m_ch_p2=     0; //

	sw_edit();

	CGRP2Dlg o;
	         o.sw_p_p(m_p);
			 o.p_a3(m_ch_a3 );   
			 o.p_a4(m_ch_a4 );  
			 o.p_ag3(m_ch_ag3 );   
			 o.p_ag4(m_ch_ag4 );    
			 o.p_am(m_ch_am );    
			 o.p_sd(m_ch_sd );    
			 o.p_sdg(m_ch_sdg );   
			 o.p_sga3(m_ch_sga3 );    
			 o.p_sga4(m_ch_sga4 );    
			 o.p_sgam(m_ch_sgam );   

	UpdateData(0);	
}


void GRP2fn3::OnButtonSp1() 
{
	UpdateData(1);

	m_CI=     95.0; QP_() ;
	m_ch_a3 =    0 ; 
	m_ch_a4=     0 ; 
	m_ch_ag3 =   1 ; 
	m_ch_ag4 =   0 ; 
	m_ch_am =    0 ; 
	m_ch_sd =    0 ; swz1=0;
	m_ch_sdg =   1 ; swz2=1;
	m_ch_sga3 =  0 ; swt2=0;
	m_ch_sga4 =  0 ; swt3=0;
	m_ch_sgam =  1 ; swt1=1;

	sw_edit();

	CGRP2Dlg o;

			o.p_a3(m_ch_a3 );   
			o.p_a4(m_ch_a4 );  
			o.p_ag3(m_ch_ag3 );   
			o.p_ag4(m_ch_ag4 );    
			o.p_am(m_ch_am );    
			o.p_sd(m_ch_sd );    
			o.p_sdg(m_ch_sdg );   
			o.p_sga3(m_ch_sga3 );    
			o.p_sga4(m_ch_sga4 );    
			o.p_sgam(m_ch_sgam );

	UpdateData(0);
}

void GRP2fn3::OnVoreinstellungen() 
{
	UpdateData(1);

	m_CI=      95.0; QP_() ;// Fp_CI
	m_ch_vx=   1;           // Fp_Theta
	m_ch_vy=   0;           //
	m_ch_a3 =  0 ;          // a3_Darstellung
	m_ch_a4=   0 ;          // a4_Darstellung
	m_ch_ag3 = 0 ;          // a3'_Darstellung
	m_ch_ag4 = 0 ;          // a4'_Darstellung
	m_ch_am =  1 ;          // am_Darstellung
	m_ch_sd =  0 ; swz1=0;  // sd_Darstellung
	m_ch_sdg = 1 ; swz2=1;  // sd'_Darstellung
	m_ch_sga3 =1 ; swt2=1;  // s'a3_Darstellung
	m_ch_sga4 =0 ; swt3=0;  // s'a4_Darstellung
	m_ch_sgam =0 ; swt1=0;  // s'am_Darstellung

	sw_edit();

	CGRP2Dlg o;
	         o.CI_Fp(m_CI);
	         o.p_q_sw(0);
			 o.p_a3(m_ch_a3 );   
			 o.p_a4(m_ch_a4 );  
			 o.p_ag3(m_ch_ag3 );   
			 o.p_ag4(m_ch_ag4 );    
			 o.p_am(m_ch_am );    
			 o.p_sd(m_ch_sd );    
			 o.p_sdg(m_ch_sdg );   
			 o.p_sga3(m_ch_sga3 );    
			 o.p_sga4(m_ch_sga4 );    
			 o.p_sgam(m_ch_sgam );

	UpdateData(0);	
}

void GRP2fn3::OnFxy() {UpdateData(1);CGRP2Dlg o;o.fxy_sw( );UpdateData(0);}//funktionsmatrix neu setzen

void GRP2fn3::OnCHECKini() {UpdateData(1);UpdateData(0);}

void GRP2fn3::OnOK() 
{
				                                     CRect coord;
	                                        GetWindowRect(&coord); 
	
	         CWinApp* pApp = AfxGetApp(); // ini profil schreiben  

	if(m_ch_ini)
	{
		if(m_ch_p==1 )pApp->WriteProfileInt("Funktion","p_p",0);
		if(m_ch_p1==1)pApp->WriteProfileInt("Funktion","p_p",1);
		if(m_ch_p2==1)pApp->WriteProfileInt("Funktion","p_p",2);
		              pApp->WriteProfileString("Funktion","Fp_CI",ftoc(m_CI,3));
			          pApp->WriteProfileInt("Funktion","Fp_Theta",!m_ch_vx);
			          pApp->WriteProfileInt("Funktion","am_Darstellung",m_ch_am);
			          pApp->WriteProfileInt("Funktion","sd_Darstellung",m_ch_sd);
					  pApp->WriteProfileInt("Funktion","sd'_Darstellung",m_ch_sdg);
					  pApp->WriteProfileInt("Funktion","s'am_Darstellung",m_ch_sgam);
					  pApp->WriteProfileInt("Funktion","a3_Darstellung",m_ch_a3);
					  pApp->WriteProfileInt("Funktion","a4_Darstellung",m_ch_a4);
					  pApp->WriteProfileInt("Funktion","a3'_Darstellung",m_ch_ag3);
					  pApp->WriteProfileInt("Funktion","a4'_Darstellung",m_ch_ag4);
					  pApp->WriteProfileInt("Funktion","s'a3_Darstellung",m_ch_sga3);
					  pApp->WriteProfileInt("Funktion","s'a4_Darstellung",m_ch_sga4);
	}
					  pApp->WriteProfileInt("INI_schreiben","fn3",m_ch_ini);
					  pApp->WriteProfileInt("Funktion","Tabelle",3);
					  pApp->WriteProfileInt("Funktion","Position_x",coord.left);
					  pApp->WriteProfileInt("Funktion","Position_y",coord.top);
	
	CDialog::OnOK();
}

CString GRP2fn3::ftoc( double x0, int dez ) 
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

int GRP2fn3::ftoi(double x_) 
{
	int    i_;
		   i_=0;
		   i_=atoi(ftoc(x_,8 /*dezimalstellen*/));
	return i_; //int
}

double GRP2fn3::zp_funktion(double wert) // z verteilungsfunktion F(y=p) p -> z  // 
{
	long double  p_wert, z_wert, OO[10], RD[10];
	z_wert=RD[0]=RD[2]=RD[3]=RD[4]=0; OO[1]=OO[2]=RD[1]=RD[5]=1;
	
	if (wert>=1 || wert<0 ) {printf("\n\nvalue.0 '0<=p<=1'");exit(0);}
   		
	//F(x=p)
		
	p_wert = wert;//p-wert eingabe	
	
	//z-Wert Berechnung
	if(p_wert!=0.5)
	{
		if(p_wert>0.5) {OO[1]=1-p_wert;} else {OO[1]=p_wert;}
		OO[1]=-1*log(4*OO[1]*(1-OO[1]));
		OO[2]=(-3.231081277e-09*OO[1]+8.360937017e-08)*OO[1]-1.04527497e-06;
		OO[2]=(OO[2]*OO[1]+5.824238515e-06)*OO[1]+6.841218299e-06;
		OO[2]=((OO[2]*OO[1]-2.250947176e-04)*OO[1]-8.36435359e-04)*OO[1]+3.706987906e-02;
		z_wert=OO[2]*OO[1]+1.570796288;
		z_wert=sqrt(OO[1]*z_wert);
		if(p_wert<0.5) z_wert = z_wert * -1;
	}
	
	if(RD[0]==0)
	{
		RD[1]=z_wert; RD[2]=-5;

		//Kurvenglättung
		
		if(RD[1] !=0 )
		{	
			RD[3] = log10(fabs(RD[1]));
			RD[2]=RD[3]+RD[2]; 
			if (RD[3] >= 0) RD[3]= floor(RD[3]);		
			if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));
			RD[4]=RD[3]; RD[3]=RD[2]; 
			if (RD[3] >= 0) RD[3]= floor(RD[3]);	
			if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));	
			RD[2]=RD[4]-RD[3]-1;
			if (RD[2] < 19 ) 
			{
				if (RD[2] < 0 ) RD[1]=0; 
				if (RD[2] >=0 )
				{
					if (RD[4] >= 90){ RD[1] = RD[1] * 1e-20; RD[3]=RD[4]; RD[4] -= 20;}
					RD[5] = sqrt(pow(RD[1]*pow(10,(-1*RD[4])),2)); RD[5]=floor(RD[5]*pow(10,RD[2])+0.5);
					RD[5] *= pow(10,RD[4])*pow(10,(-1*RD[2]));
					if (RD[3] >= 90) RD[5] = RD[5] * 1e+20;
					if (RD[1] >= 0) RD[1] = RD[5]; 
					if (RD[1] < 0) RD[1] = -1*RD[5];
				}
			}
		}
		z_wert=RD[1]; ;
	}
	
	return z_wert;
};

double GRP2fn3::pz_funktion(double wert) // z verteilungsfunktion F(x=z) z -> p  //  
{
	long double   z_wert, p_wert, OO[10], RD[10];
	z_wert=RD[0]=RD[2]=RD[3]=RD[4]=0; OO[1]=OO[2]=RD[1]=RD[5]=1;

	//F(y=z)
	
	z_wert = wert;//z-wert eingabe

	//p-Wert Berechnung
	OO[1] = fabs(z_wert);
	if(OO[1]>7) p_wert=0; 
	if(OO[1]<=7)
	{
		p_wert=OO[1]*(3.80036e-05+OO[1]*(4.88906e-05+OO[1]*0.000005383));
		p_wert=1+OO[1]*(0.049867347+OO[1]*(2.11410061e-02+OO[1]*(3.2776263e-03+p_wert)));
		p_wert=0.5*pow(p_wert,-16);
	}
	if (z_wert>0) p_wert=1-p_wert;
	
	if(RD[0]==0)
	{
		RD[1]=p_wert; RD[2]=-5;

		//Kurvenglättung
		
		if(RD[1] !=0 )
		{
			RD[3] = log10(fabs(RD[1]));
			RD[2]=RD[3]+RD[2]; 
			if (RD[3] >= 0) RD[3]= floor(RD[3]);		
			if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));
			RD[4]=RD[3]; RD[3]=RD[2]; 
			if (RD[3] >= 0) RD[3]= floor(RD[3]);	
			if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));	
			RD[2]=RD[4]-RD[3]-1;
			if (RD[2] < 19 ) 
			{
				if (RD[2] < 0 ) RD[1]=0; 
				if (RD[2] >=0 )
				{
					if (RD[4] >= 90){ RD[1] = RD[1] * 1e-20; RD[3]=RD[4]; RD[4] -= 20;}
					RD[5] = sqrt(pow(RD[1]*pow(10,(-1*RD[4])),2)); RD[5]=floor(RD[5]*pow(10,RD[2])+0.5);
					RD[5] *= pow(10,RD[4])*pow(10,(-1*RD[2]));
					if (RD[3] >= 90) RD[5] = RD[5] * 1e+20;
					if (RD[1] >= 0) RD[1] = RD[5]; 
					if (RD[1] < 0) RD[1] = -1*RD[5];
				}
			}
		}
		p_wert=RD[1]; 
	}

	return p_wert;
};

double GRP2fn3::tp_funktion(long double p_wert, double n_) // t verteilungsfunktion F(y=p) p -> t  //  
{
	long double  t_wert, OO[10], RD[10];
   
	t_wert=RD[0]=RD[2]=RD[3]=RD[4]=0; OO[1]=OO[2]=OO[3]=OO[4]=OO[5]=OO[6]=OO[7]=RD[1]=RD[5]=1;

	if (p_wert>=1 || p_wert<=0 ) {printf("value.0 '0<=p<=1'");exit(0);}
	
	//t-Wert Berechnung
	if(p_wert!=0.5)
	{
		if(p_wert>0.5) {OO[1]=1-p_wert;} else {OO[1]=p_wert;}

		OO[1]=-1*log(4*OO[1]*(1-OO[1]));
		OO[2]=(-3.231081277e-09*OO[1]+8.360937017e-08)*OO[1]-1.04527497e-06;
		OO[2]=(OO[2]*OO[1]+5.824238515e-06)*OO[1]+6.841218299e-06;
		OO[2]=((OO[2]*OO[1]-2.250947176e-04)*OO[1]-8.36435359e-04)*OO[1]+3.706987906e-02;
		t_wert=OO[2]*OO[1]+1.570796288;
		t_wert=sqrt(OO[1]*t_wert);
		if(p_wert>0.5) t_wert=t_wert*-1;
	}

	if(p_wert==0.5) t_wert=0; 

	if(RD[0] ==0)
	{
		OO[3]=pow(t_wert,2);
		OO[1]=t_wert+(1+OO[3])*t_wert/(4*n_)+((5*OO[3]+16)*OO[3]+3)*t_wert/(96*pow(n_,2));
		OO[1]=OO[1]+(((3*OO[3]+19)*OO[3]+17)*OO[3]-15)*t_wert/(384*pow(n_,3));
		OO[1]=OO[1]+((((79*OO[3]+776)*OO[3]+1482)*OO[3]-1920)*OO[3]-945)*t_wert/(92160*pow(n_,4));
		t_wert=OO[1]+(((((27*OO[3]+339)*OO[3]+930)*OO[3]-1782)*OO[3]-765)*OO[3]+17955)*t_wert/(368640*pow(n_,5));
	}

	if(RD[0]==0)
	{
		RD[1]=t_wert; RD[2]=-5;

		//Kurvenglättung
		if(RD[1] !=0 )
		{	
			RD[3] = log10(fabs(RD[1]));
			RD[2]=RD[3]+RD[2]; 
			if (RD[3] >= 0) RD[3]= floor(RD[3]);		
			if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));
			RD[4]=RD[3]; RD[3]=RD[2]; 
			if (RD[3] >= 0) RD[3]= floor(RD[3]);	
			if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));	
			RD[2]=RD[4]-RD[3]-1;
			if (RD[2] < 19 ) 
			{
				if (RD[2] < 0 ) RD[1]=0; 
				if (RD[2] >=0 )
				{
					if (RD[4] >= 90){ RD[1] = RD[1] * 1e-20; RD[3]=RD[4]; RD[4] -= 20;}
					RD[5] = sqrt(pow(RD[1]*pow(10,(-1*RD[4])),2)); RD[5]=floor(RD[5]*pow(10,RD[2])+0.5);
					RD[5] *= pow(10,RD[4])*pow(10,(-1*RD[2]));
					if (RD[3] >= 90) RD[5] = RD[5] * 1e+20;
					if (RD[1] >= 0) RD[1] = RD[5]; 
					if (RD[1] < 0) RD[1] = -1*RD[5];
				}
			}
		}
		t_wert=RD[1]; 
	}
	return -t_wert;
}


double GRP2fn3::pt_funktion(long double t_wert, double n_) // t verteilungsfunktion F(x=t) t -> p  //  
{
	int sw=0;
	long double  p_wert/*P6*/, n_O/*p5*/, OO[10], RD[10], iLauf, iLauf_1, n_Z, n_N;

	RD[0]=RD[2]=RD[3]=RD[4]=iLauf_1=0; OO[1]=OO[2]=OO[3]=OO[4]=OO[5]=OO[6]=OO[7]=RD[1]=RD[5]=1;

	if (t_wert<0){t_wert=-t_wert;sw=1;} //berechnung über positive t-werte,  z bei df=100000

	//Prozentrangberechnung
	if(n_ != floor(n_))
	{
		OO[6]=n_; n_=floor(OO[6]); n_O = n_; n_=1; OO[5]=t_wert; t_wert=pow(t_wert,2);

		OO[1]=n_O/(n_O+n_*t_wert); OO[3]=sqrt(1-OO[1]);	n_Z=2*floor(n_/2)-n_+2;	n_N=2*floor(n_O/2)-n_O+2;

		if(n_Z*2-n_N == 1 )	{ p_wert=1-2/3.1417*atan(OO[3]/sqrt(OO[1])); OO[4]=OO[3]*sqrt(OO[1])/3.1417; } 
		if(n_Z*2-n_N == 2 )	{ p_wert=OO[1]; OO[4]=(1-OO[1])*p_wert;}
		if(n_Z*2-n_N == 3 ) { p_wert=sqrt(OO[1]); OO[4]=(1-OO[1])*p_wert/2; }
		if(n_Z*2-n_N != 1 && n_Z*2-n_N != 2 && n_Z*2-n_N != 3 )	{ p_wert=1-OO[3]; OO[4]=OO[1]*OO[3]/2;	}

		for(iLauf=n_N; iLauf <= n_O-2; iLauf +=2) 
		{
			if(n_O > iLauf || fabs(2/iLauf*OO[4]) >= (0.00001*p_wert) )
			{ 			
				iLauf_1=iLauf; p_wert=p_wert-2/iLauf*OO[4];
				OO[4]=OO[4]*OO[1]*(n_Z/iLauf+1);
			}
		}
		if(iLauf_1!=iLauf) iLauf_1=iLauf_1+2;
	
		for(iLauf=n_Z; iLauf <= n_-2; iLauf +=2) 
		{
			if(n_ > iLauf || fabs(2/iLauf*OO[4]) >= (0.00001*p_wert) )
			{ 
				p_wert=p_wert+2/iLauf*OO[4];
				OO[4]=OO[4]*(1-OO[1])*(iLauf_1/iLauf+1);
			}
		}
	
		if(RD[0] == 0)
		{
			p_wert=p_wert/2; n_=n_O;t_wert=OO[5];
			if(t_wert < 0) p_wert=1-p_wert;
	
			OO[7]=p_wert;
			n_=floor(OO[6])+1;
			n_O = n_; n_=1; OO[5]=t_wert; t_wert=pow(t_wert,2);
	
			OO[1]=n_O/(n_O+n_*t_wert); OO[3]=sqrt(1-OO[1]);
			n_Z=2*floor(n_/2)-n_+2;	n_N=2*floor(n_O/2)-n_O+2;

			if(n_Z*2-n_N == 1 )	{ p_wert=1-2/3.1417*atan(OO[3]/sqrt(OO[1])); OO[4]=OO[3]*sqrt(OO[1])/3.1417; } 
			if(n_Z*2-n_N == 2 )	{ p_wert=OO[1]; OO[4]=(1-OO[1])*p_wert;}
			if(n_Z*2-n_N == 3 ) { p_wert=sqrt(OO[1]); OO[4]=(1-OO[1])*p_wert/2; }
			if(n_Z*2-n_N != 1 && n_Z*2-n_N != 2 && n_Z*2-n_N != 3 )	{ p_wert=1-OO[3]; OO[4]=OO[1]*OO[3]/2;	}

		
			for(iLauf=n_N; iLauf <= n_O-2; iLauf +=2) 
			{
				if(n_O > iLauf || fabs(2/iLauf*OO[4]) >= (0.00001*p_wert) )
				{ 			
					iLauf_1=iLauf; p_wert=p_wert-2/iLauf*OO[4];
					OO[4]=OO[4]*OO[1]*(n_Z/iLauf+1);
				}
			}
			if(iLauf_1!=iLauf) iLauf_1=iLauf_1+2;
	
			for(iLauf=n_Z; iLauf <= n_-2; iLauf +=2) 
			{
				if(n_ > iLauf || fabs(2/iLauf*OO[4]) >= (0.00001*p_wert) )
				{ 
					p_wert=p_wert+2/iLauf*OO[4];
					OO[4]=OO[4]*(1-OO[1])*(iLauf_1/iLauf+1);
				}
			}

			if(RD[0] == 0)
			{
				p_wert=p_wert/2; n_=n_O; t_wert=OO[5];
				if(t_wert < 0) p_wert=1-p_wert;
			
				if(RD[0] == 0) 
				{
					p_wert=(p_wert-OO[7])*(OO[6]-floor(OO[6]))+OO[7]; n_=OO[6];
				}
			}
		}
	}

	if(n_ == floor(n_))
	{
		n_O = n_; n_=1; OO[5]=t_wert; t_wert=pow(t_wert,2);
		
		OO[1]=n_O/(n_O+n_*t_wert); OO[3]=sqrt(1-OO[1]);
		n_Z=2*floor(n_/2)-n_+2;	n_N=2*floor(n_O/2)-n_O+2;

		if(n_Z*2-n_N == 1 )	{ p_wert=1-2/3.1417*atan(OO[3]/sqrt(OO[1])); OO[4]=OO[3]*sqrt(OO[1])/3.1417; } //n=1
		if(n_Z*2-n_N == 2 )	{ p_wert=OO[1]; OO[4]=(1-OO[1])*p_wert;}//n={}
		if(n_Z*2-n_N == 3 ) { p_wert=sqrt(OO[1]); OO[4]=(1-OO[1])*p_wert/2; }//n={}
		if(n_Z*2-n_N != 1 && n_Z*2-n_N != 2 && n_Z*2-n_N != 3 )	{ p_wert=1-OO[3]; OO[4]=OO[1]*OO[3]/2;	}//n>1

	
		for(iLauf=n_N; iLauf <= n_O-2; iLauf +=2) 
		{
			if(n_O > iLauf || fabs(2/iLauf*OO[4]) >= (0.00001*p_wert) )
			{ 			
				iLauf_1=iLauf; p_wert=p_wert-2/iLauf*OO[4];
				OO[4]=OO[4]*OO[1]*(n_Z/iLauf+1);
			}
		}
		if(iLauf_1!=iLauf) iLauf_1=iLauf_1+2;
	
		for(iLauf=n_Z; iLauf <= n_-2; iLauf +=2) 
		{
			if(n_ > iLauf || fabs(2/iLauf*OO[4]) >= (0.00001*p_wert) )
			{ 
				p_wert=p_wert+2/iLauf*OO[4];
				OO[4]=OO[4]*(1-OO[1])*(iLauf_1/iLauf+1);
			}
		}

		if(RD[0] == 0)
		{
			p_wert=p_wert/2; n_=n_O; t_wert=OO[5];
			if(t_wert < 0) p_wert=1-p_wert;
		}
	}

	if(RD[0]==0)
	{
		RD[1]=p_wert; RD[2]=-5;

		//Kurvenglättung
		if(RD[1] !=0 )
		{
			RD[3] = log10(fabs(RD[1]));
			RD[2]=RD[3]+RD[2]; 
			if (RD[3] >= 0) RD[3]= floor(RD[3]);		
			if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));
			RD[4]=RD[3]; RD[3]=RD[2]; 
			if (RD[3] >= 0) RD[3]= floor(RD[3]);	
			if (RD[3] < 0)  RD[3]= -1*(floor(fabs(RD[3])));	
			RD[2]=RD[4]-RD[3]-1;
			if (RD[2] < 19 ) 
			{
				if (RD[2] < 0 ) RD[1]=0; 
				if (RD[2] >=0 )
				{
					if (RD[4] >= 90){ RD[1] = RD[1] * 1e-20; RD[3]=RD[4]; RD[4] -= 20;}
					RD[5] = sqrt(pow(RD[1]*pow(10,(-1*RD[4])),2)); RD[5]=floor(RD[5]*pow(10,RD[2])+0.5);
					RD[5] *= pow(10,RD[4])*pow(10,(-1*RD[2]));
					if (RD[3] >= 90) RD[5] = RD[5] * 1e+20;
					if (RD[1] >= 0) RD[1] = RD[5]; 
					if (RD[1] < 0) RD[1] = -1*RD[5];
				}
			}
		}
		p_wert=RD[1]; p_wert=1-p_wert;
	}
	
	if(sw==1) p_wert=1-p_wert;
	
	return p_wert;

};



