//------------------------------------------------------------------------| GRP2fn4.cpp                                  //
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

GRP2fn4::GRP2fn4(CWnd* pParent )
	: CDialog(GRP2fn4::IDD, pParent)
{
	//{{AFX_DATA_INIT(GRP2fn4)
	m_ch_ini = 1;
	m_ch_p = 0;
	m_ch_p1 = 0;
	m_ch_p2 = 0;
	m_ch_s0 = 0;
	m_ch_s1 = 0;
	m_ch_x0 = 0;
	m_ch_x1 = 0;
	m_ch_x = 0;
	m_ch_e = 0;
	m_CI = 95.0f;
	m_CI_t = 1.0f;
	m_CI_z = 1.0f;
	m_ch_t = 0;
	m_ch_z = 1;
	m_df = 10;
	//}}AFX_DATA_INIT
}


void GRP2fn4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GRP2fn4)
	DDX_Control(pDX, IDC_EDIT_CI, m_CI_ctr);
	DDX_Control(pDX, IDC_CHECK_t, m_cht_ctr);
	DDX_Control(pDX, IDC_CHECK_z, m_chz_ctr);
	DDX_Control(pDX, IDC_EDIT_CI_z, m_z_ctr);
	DDX_Control(pDX, IDC_EDIT_CI_t, m_t_ctr);
	DDX_Control(pDX, IDC_EDIT_df, m_df_ctr);
	DDX_Control(pDX, IDC_TAB2, m_tab);
	DDX_Check(pDX, IDC_CHECK_ini, m_ch_ini);
	DDX_Check(pDX, IDC_CHECK_p, m_ch_p);
	DDX_Check(pDX, IDC_CHECK_pa1, m_ch_p1);
	DDX_Check(pDX, IDC_CHECK_pa2, m_ch_p2);
	DDX_Check(pDX, IDC_CHECK_s0, m_ch_s0);
	DDX_Check(pDX, IDC_CHECK_s1, m_ch_s1);
	DDX_Check(pDX, IDC_CHECK_x0, m_ch_x0);
	DDX_Check(pDX, IDC_CHECK_x1, m_ch_x1);
	DDX_Check(pDX, IDC_CHECK_xcrit, m_ch_x);
	DDX_Check(pDX, IDC_CHECK_e, m_ch_e);
	DDX_Text(pDX, IDC_EDIT_CI, m_CI);
	DDV_MinMaxFloat(pDX, m_CI, 0.1f, 99.9f);
	DDX_Text(pDX, IDC_EDIT_CI_t, m_CI_t);
	DDX_Text(pDX, IDC_EDIT_CI_z, m_CI_z);
	DDX_Check(pDX, IDC_CHECK_t, m_ch_t);
	DDX_Check(pDX, IDC_CHECK_z, m_ch_z);
	DDX_Text(pDX, IDC_EDIT_df, m_df);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(GRP2fn4, CDialog)
	//{{AFX_MSG_MAP(GRP2fn4)
	ON_BN_CLICKED(IDC_CHECK_ini, OnCHECKini)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB2, OnSelchangeTab2)
	ON_BN_CLICKED(ID_Voreinstellungen, OnVoreinstellungen)
	ON_BN_CLICKED(IDC_CHECK_p, OnCHECKp)
	ON_BN_CLICKED(IDC_CHECK_pa1, OnCHECKpa1)
	ON_BN_CLICKED(IDC_CHECK_pa2, OnCHECKpa2)
	ON_BN_CLICKED(IDC_CHECK_e, OnCHECKe)
	ON_BN_CLICKED(IDC_CHECK_s0, OnCHECKs0)
	ON_BN_CLICKED(IDC_CHECK_s1, OnCHECKs1)
	ON_BN_CLICKED(IDC_CHECK_x0, OnCHECKx0)
	ON_BN_CLICKED(IDC_CHECK_x1, OnCHECKx1)
	ON_BN_CLICKED(IDC_CHECK_xcrit, OnCHECKxcrit)
	ON_EN_CHANGE(IDC_EDIT_CI_z, OnChangeEDITCIz)
	ON_EN_CHANGE(IDC_EDIT_CI_t, OnChangeEDITCIt)
	ON_EN_CHANGE(IDC_EDIT_CI, OnChangeEditCi)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_CI, OnDeltaposSpinCi)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_CI_Fe_t, OnDeltaposSPINCIFet)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_CI_Fe_z, OnDeltaposSPINCIFez)
	ON_BN_CLICKED(IDC_CHECK_t, OnCHECKt)
	ON_BN_CLICKED(IDC_CHECK_z, OnCHECKz)
	ON_EN_CHANGE(IDC_EDIT_df, OnChangeEDITdf)
	ON_BN_CLICKED(ID_FXY, OnFxy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL GRP2fn4::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	UpdateData(1);

				CWinApp* pApp = AfxGetApp(); // ini profil lesen 

				     //df_=pApp->GetProfileInt("Funktion","N",1000);
			  m_CI= atof(pApp->GetProfileString("Funktion","Fe_CI","95.0"));
		       m_ch_e=   pApp->GetProfileInt("Funktion","e_Darstellung",1);
		      m_ch_x=    pApp->GetProfileInt("Funktion","x_Darstellung",0);
			  m_ch_x0=   pApp->GetProfileInt("Funktion","x0_Darstellung",1);
			  m_ch_x1=   pApp->GetProfileInt("Funktion","x1_Darstellung",1);
			  m_ch_s0=   pApp->GetProfileInt("Funktion","s0_Darstellung",0);
			  m_ch_s1=   pApp->GetProfileInt("Funktion","s1_Darstellung",0);
			      m_p=   pApp->GetProfileInt("Funktion","Epsilon_p",0); 	
			   if(m_p==0)m_ch_p=1;
			   if(m_p==1)m_ch_p1=1;
			   if(m_p==2)m_ch_p2=1;
			   
			   m_ch_ini= pApp->GetProfileInt("INI_schreiben","fn4",1);

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
				         
				m_tab.SetCurSel(  3);

	sw=0;
	GRP2fn4::QP_() ;                  
	                            
	SetCh01();
	                              
	UpdateData(0);

	return 1;  	              
}

void GRP2fn4::OnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if(m_tab.GetCurSel() ==0){OnOK();GRP2fn1 o;o.DoModal();}
	if(m_tab.GetCurSel() ==1){OnOK();GRP2fn2 o;o.DoModal();}
	if(m_tab.GetCurSel() ==2){OnOK();GRP2fn3 o;o.DoModal();}
	if(m_tab.GetCurSel() ==3);
	
	*pResult = 0;
}

void GRP2fn4::OnCHECKp() {	     UpdateData(1);m_ch_p = 1; m_ch_p1 = 0; m_ch_p2 = 0;                CGRP2Dlg o;o.sw_p_e(0);           UpdateData(0); }
void GRP2fn4::OnCHECKpa1() {     UpdateData(1);m_ch_p = 0; m_ch_p1 = 1; m_ch_p2 = 0;                CGRP2Dlg o;o.sw_p_e(1);           UpdateData(0); }
void GRP2fn4::OnCHECKpa2() {     UpdateData(1);m_ch_p = 0; m_ch_p1 = 0; m_ch_p2 = 1;                CGRP2Dlg o;o.sw_p_e(2);           UpdateData(0); }
void GRP2fn4::OnCHECKe() {       UpdateData(1);                                                     CGRP2Dlg o;o.p_e(m_ch_e );        UpdateData(0); }
void GRP2fn4::OnCHECKs0() {      UpdateData(1); if(!m_ch_t)m_ch_z=1;if(m_ch_t)m_ch_z=0;SetCh01();                                          CGRP2Dlg o;o.p_s0(m_ch_s0 );      UpdateData(0); }
void GRP2fn4::OnCHECKs1() {      UpdateData(1); if(!m_ch_t)m_ch_z=1;if(m_ch_t)m_ch_z=0;SetCh01();                                        CGRP2Dlg o;o.p_s1(m_ch_s1 );      UpdateData(0); }
void GRP2fn4::OnCHECKx0() {      UpdateData(1);                                                     CGRP2Dlg o;o.p_x0(m_ch_x0 );      UpdateData(0); }
void GRP2fn4::OnCHECKx1() {      UpdateData(1);                                                     CGRP2Dlg o;o.p_x1(m_ch_x1 );      UpdateData(0); }
void GRP2fn4::OnCHECKxcrit(){    UpdateData(1);                                                     CGRP2Dlg o;o.p_x(m_ch_x );        UpdateData(0); }
void GRP2fn4::OnChangeEDITCIz(){ UpdateData(1);GRP2fn4::QP_z() ;                                    CGRP2Dlg o;o.CI_Fe(sw,m_CI,m_df); UpdateData(0); }
void GRP2fn4::OnChangeEDITCIt(){ UpdateData(1);GRP2fn4::QP_t();                                     CGRP2Dlg o;o.CI_Fe(sw,m_CI,m_df); UpdateData(0); }
void GRP2fn4::OnChangeEditCi(){  UpdateData(1);GRP2fn4::QP_();                                      CGRP2Dlg o;o.CI_Fe(sw,m_CI,m_df); UpdateData(0); }
void GRP2fn4::OnCHECKz() 
{ 
	if(m_ch_s0||m_ch_s1){        UpdateData(1);m_ch_t=!m_ch_z; sw=m_ch_t; SetCh01(); GRP2fn4::QP_();CGRP2Dlg o;o.CI_Fe(sw,m_CI,m_df); UpdateData(0); }
	if(!m_ch_s0&&!m_ch_s1){      UpdateData(1);        m_ch_z=0; m_chz_ctr.SetState(1);                                               UpdateData(0); }
}																		  	             
void GRP2fn4::OnCHECKt() 
{
	if(m_ch_s0||m_ch_s1){        UpdateData(1);m_ch_z=!m_ch_t; sw=m_ch_t; SetCh01(); GRP2fn4::QP_();CGRP2Dlg o;o.CI_Fe(sw,m_CI,m_df); UpdateData(0); }
	if(!m_ch_s0&&!m_ch_s1){      UpdateData(1);        m_ch_t=0; m_cht_ctr.SetState(1);                                               UpdateData(0); }

}														  	            
void GRP2fn4::OnChangeEDITdf(){  UpdateData(1);                                      GRP2fn4::QP_();CGRP2Dlg o;o.CI_Fe(sw,m_CI,m_df); UpdateData(0); } 

void GRP2fn4::SetCh01()
{
	if(m_ch_s0||m_ch_s1)
	{
                          //CButton m_chz_ctr;//
    //DDX_Control(pDX, IDC_CHECK_z, m_chz_ctr);
									m_chz_ctr.SetState(0);
									m_cht_ctr.SetState(0);
				
									 m_df_ctr.SetReadOnly(!m_ch_t); 
									  m_t_ctr.SetReadOnly(!m_ch_t); 
								 	  m_z_ctr.SetReadOnly( m_ch_t); 
									 m_CI_ctr.SetReadOnly(0);
	}

	if(!m_ch_s0&&!m_ch_s1)
	{
		                            m_chz_ctr.SetState(1); m_ch_z=0;
		                            m_cht_ctr.SetState(1); m_ch_t=0;
		                           
									 m_df_ctr.SetReadOnly(1); 
									  m_t_ctr.SetReadOnly(1);
									  m_z_ctr.SetReadOnly(1);
									 m_CI_ctr.SetReadOnly(1);
	}
}

void GRP2fn4::QP_() 
{
	m_CI_z=zp_funktion((100 -((100-m_CI)/2))/100);          
	m_CI_t=tp_funktion((100 -((100-m_CI)/2))/100,  m_df  ); 
}

void GRP2fn4::QP_z() 
{
	     m_CI =100*pz_funktion(m_CI_z);
	m_CI=m_CI-(100-m_CI);
	m_CI_t=tp_funktion((100 -((100-m_CI)/2))/100,  m_df );  
}

void GRP2fn4::QP_t() 
{
	     m_CI =100*pt_funktion(m_CI_t,m_df);
	m_CI=m_CI-(100-m_CI);
	m_CI_z=zp_funktion((100 -((100-m_CI)/2))/100); 
}


void GRP2fn4::OnDeltaposSpinCi(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(m_ch_s0||m_ch_s1)
	{
		if(pNMUpDown->iDelta < 0)if(m_CI<99.9)  m_CI=m_CI+0.1;
		if(pNMUpDown->iDelta >=0)if(m_CI>0.2)   m_CI=m_CI-0.1;
							   
		UpdateData(0); OnChangeEditCi();
	}
	
	*pResult = 0;
}


void GRP2fn4::OnDeltaposSPINCIFet(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(sw)if(m_ch_s0||m_ch_s1)
	{
		if(pNMUpDown->iDelta < 0)  m_CI_t=m_CI_t+0.1;
		if(pNMUpDown->iDelta >=0)  m_CI_t=m_CI_t-0.1;
							   
		UpdateData(0); OnChangeEDITCIt();
	}

	*pResult = 0;
}

void GRP2fn4::OnDeltaposSPINCIFez(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(!sw)if(m_ch_s0||m_ch_s1)
	{
		if(pNMUpDown->iDelta < 0)  m_CI_z=m_CI_z+0.1;
		if(pNMUpDown->iDelta >=0)  m_CI_z=m_CI_z-0.1;
							   
		UpdateData(0); OnChangeEDITCIz();
	}
	
	*pResult = 0;
}

void GRP2fn4::OnFxy() {UpdateData(1);CGRP2Dlg o;o.fxy_sw( );UpdateData(0);}//funktionsmatrix neu setzen

void GRP2fn4::OnCHECKini() {  UpdateData(1);                                                                   UpdateData(0); }

void GRP2fn4::OnVoreinstellungen() 
{
	UpdateData(1);

	m_CI=     95.0; QP_() ;// Fe_CI
	m_ch_e=   1; //e_Darstellung
	m_ch_x=   0; //x_Darstellung
	m_ch_x0=  1; //x0_Darstellung
	m_ch_x1=  1; //x1_Darstellung
	m_ch_s0=  0; //s0_Darstellung
	m_ch_s1=  0; //s1_Darstellung
	m_p=      0; //Epsilon_p
	m_ch_p=   1; //
	m_ch_p1=  0; //
	m_ch_p2=  0; //

	SetCh01();

	CGRP2Dlg o;
	         o.CI_Fe(sw,m_CI,m_df);
			 o.sw_p_e(m_p); 
			 o.p_e(m_ch_e );  
			 o.p_s0(m_ch_s0 );  
			 o.p_s1(m_ch_s1 );  
			 o.p_x0(m_ch_x0 );  
			 o.p_x1(m_ch_x1 );  
			 o.p_x(m_ch_x );  
	         
	UpdateData(0);		
}

void GRP2fn4::OnOK() 
{
				                                     CRect coord;
	                                        GetWindowRect(&coord); 
	
	         CWinApp* pApp = AfxGetApp(); // ini profil schreiben  
	if(m_ch_ini)
	{
		              pApp->WriteProfileString("Funktion","Fe_CI",ftoc(m_CI,3));
		if(m_ch_p==1 )pApp->WriteProfileInt("Funktion","Epsilon_p",0);
		if(m_ch_p1==1)pApp->WriteProfileInt("Funktion","Epsilon_p",1);
		if(m_ch_p2==1)pApp->WriteProfileInt("Funktion","Epsilon_p",2);
				      pApp->WriteProfileInt("Funktion","e_Darstellung",m_ch_e);
		              pApp->WriteProfileInt("Funktion","x_Darstellung",m_ch_x);
			          pApp->WriteProfileInt("Funktion","x0_Darstellung",m_ch_x0);
			          pApp->WriteProfileInt("Funktion","x1_Darstellung",m_ch_x1);
			          pApp->WriteProfileInt("Funktion","s0_Darstellung",m_ch_s0);
			          pApp->WriteProfileInt("Funktion","s1_Darstellung",m_ch_s1);
	}
                      pApp->WriteProfileInt("INI_schreiben","fn4",m_ch_ini);
			          pApp->WriteProfileInt("Funktion","Tabelle",4);
			          pApp->WriteProfileInt("Funktion","Position_x",coord.left);
			          pApp->WriteProfileInt("Funktion","Position_y",coord.top);
	
	CDialog::OnOK();
}

CString GRP2fn4::ftoc( double x0, int dez ) 
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

int GRP2fn4::ftoi(double x_) 
{
	int    i_;
		   i_=0;
		   i_=atoi(ftoc(x_,8 /*dezimalstellen*/));
	return i_; //int
}

double GRP2fn4::zp_funktion(double wert) // z verteilungsfunktion F(y=p) p -> z  // 
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

		//Kurvengl�ttung
		
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

double GRP2fn4::pz_funktion(double wert) // z verteilungsfunktion F(x=z) z -> p  //  
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

		//Kurvengl�ttung
		
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

double GRP2fn4::tp_funktion(long double p_wert, double n_) // t verteilungsfunktion F(y=p) p -> t  //  
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

		//Kurvengl�ttung
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


double GRP2fn4::pt_funktion(long double t_wert, double n_) // t verteilungsfunktion F(x=t) t -> p  //  
{
	int sw=0;
	long double  p_wert/*P6*/, n_O/*p5*/, OO[10], RD[10], iLauf, iLauf_1, n_Z, n_N;

	RD[0]=RD[2]=RD[3]=RD[4]=iLauf_1=0; OO[1]=OO[2]=OO[3]=OO[4]=OO[5]=OO[6]=OO[7]=RD[1]=RD[5]=1;

	if (t_wert<0){t_wert=-t_wert;sw=1;} //berechnung �ber positive t-werte,  z bei df=100000

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

		//Kurvengl�ttung
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




 




