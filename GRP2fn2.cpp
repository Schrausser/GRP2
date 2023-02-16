//------------------------------------------------------------------------| GRP2fn2.cpp                                  //
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


GRP2fn2::GRP2fn2(CWnd* pParent ): CDialog(GRP2fn2::IDD, pParent)	
{
	//{{AFX_DATA_INIT(GRP2fn2)
	m_CI     = 95.0f;
	m_ch_D   = 0;
	m_ch_rxy = 1;
	m_ch_ryx = 1;
	m_ch_sxy = 1;
	m_ch_syx = 1;
	m_ch_s1yx = 1;
	m_ch_s1xy = 1;
	m_ch_srx = 1;
	m_ch_srxy = 1;
	m_ch_sry = 1;
	m_ch_sryx =1;
	m_CI_t = 1.0f;
	m_CI_z = 1.0f;
	//}}AFX_DATA_INIT
}


void GRP2fn2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GRP2fn2)
	DDX_Control(pDX, IDC_EDIT_CI, m_CI_ctr);
	DDX_Control(pDX, IDC_EDIT_CI_t, m_CIt_ctr);
	DDX_Control(pDX, IDC_EDIT_CI_z, m_CIz_ctr);
	DDX_Control(pDX, IDC_TAB2, m_tab);
	DDX_Check(pDX, IDC_CHECK_ini, m_ch_ini);
	DDX_Text(pDX, IDC_EDIT_CI, m_CI);
	DDV_MinMaxFloat(pDX, m_CI, 0.1f, 99.9f);
	DDX_Check(pDX, IDC_CHECK_D, m_ch_D);
	DDX_Check(pDX, IDC_CHECK_rxy, m_ch_rxy);
	DDX_Check(pDX, IDC_CHECK_ryx, m_ch_ryx);
	DDX_Check(pDX, IDC_CHECK_sxy, m_ch_sxy);
	DDX_Check(pDX, IDC_CHECK_syx, m_ch_syx);
	DDX_Check(pDX, IDC_CHECK_s1yx, m_ch_s1yx);
	DDX_Check(pDX, IDC_CHECK_s1xy, m_ch_s1xy);
	DDX_Check(pDX, IDC_CHECK_srx, m_ch_srx);
	DDX_Check(pDX, IDC_CHECK_srxy, m_ch_srxy);
	DDX_Check(pDX, IDC_CHECK_sry, m_ch_sry);
	DDX_Check(pDX, IDC_CHECK_sryx, m_ch_sryx);
	DDX_Text(pDX, IDC_EDIT_CI_t, m_CI_t);
	DDX_Text(pDX, IDC_EDIT_CI_z, m_CI_z);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(GRP2fn2, CDialog)
	//{{AFX_MSG_MAP(GRP2fn2)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB2, OnSelchangeTab2)
	ON_BN_CLICKED(IDC_CHECK_ini, OnCHECKini)
	ON_EN_CHANGE(IDC_EDIT_CI, OnChangeEditCi)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_CI, OnDeltaposSpinCi)
	ON_BN_CLICKED(ID_Voreinstellungen, OnVoreinstellungen)
	ON_BN_CLICKED(IDC_CHECK_D, OnCheckD)
	ON_BN_CLICKED(IDC_CHECK_rxy, OnCHECKrxy)
	ON_BN_CLICKED(IDC_CHECK_ryx, OnCHECKryx)
	ON_BN_CLICKED(IDC_CHECK_sxy, OnCHECKsxy)
	ON_BN_CLICKED(IDC_CHECK_syx, OnCHECKsyx)
	ON_BN_CLICKED(IDC_CHECK_s1xy, OnCHECKs1xy)
	ON_BN_CLICKED(IDC_CHECK_s1yx, OnCHECKs1yx)
	ON_BN_CLICKED(IDC_CHECK_sryx, OnCHECKsryx)
	ON_BN_CLICKED(IDC_CHECK_sry, OnCHECKsry)
	ON_BN_CLICKED(IDC_CHECK_srxy, OnCHECKsrxy)
	ON_BN_CLICKED(IDC_CHECK_srx, OnCHECKsrx)
	ON_BN_CLICKED(IDC_BUTTON_P, OnButtonP)
	ON_BN_CLICKED(IDC_BUTTON_SP, OnButtonSp)
	ON_EN_CHANGE(IDC_EDIT_CI_t, OnChangeEDITCIt)
	ON_EN_CHANGE(IDC_EDIT_CI_z, OnChangeEDITCIz)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_CI_t, OnDeltaposSPINCIt)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_CI_z, OnDeltaposSPINCIz)
	ON_WM_PAINT()
	ON_BN_CLICKED(ID_FXY, OnFxy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL GRP2fn2::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	UpdateData(1);

				CWinApp*  pApp = AfxGetApp(); // ini profil lesen 
				
				     df_= pApp->GetProfileInt("Funktion","N",1000);
				     df_-=2;

			   m_CI= atof(pApp->GetProfileString("Funktion","rxy_CI","95.0"));
			   m_ch_D=    pApp->GetProfileInt("Funktion","rxy_Darstellung_überschnitten",0);
			   m_ch_rxy=  pApp->GetProfileInt("Funktion","rxy_Darstellung",1);
			   m_ch_ryx=  pApp->GetProfileInt("Funktion","ryx_Darstellung",1);
			   m_ch_sxy=  pApp->GetProfileInt("Funktion","sxy_Darstellung",1);
			   m_ch_syx=  pApp->GetProfileInt("Funktion","syx_Darstellung",1);
			   m_ch_s1xy= pApp->GetProfileInt("Funktion","s'xy_Darstellung",0);
			   m_ch_s1yx= pApp->GetProfileInt("Funktion","s'yx_Darstellung",0);
			   m_ch_srxy= pApp->GetProfileInt("Funktion","srxy_Darstellung",0);
			   m_ch_sryx= pApp->GetProfileInt("Funktion","sryx_Darstellung",0);
			   m_ch_srx = pApp->GetProfileInt("Funktion","srx_Darstellung",1);
			   m_ch_sry = pApp->GetProfileInt("Funktion","sry_Darstellung",1);

			   m_ch_ini=  pApp->GetProfileInt("INI_schreiben","fn2",1);
			   
	SetWindowPos(&wndTop, pApp->GetProfileInt("Funktion","Position_x",100),
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
				         
				m_tab.SetCurSel(  1);

	GRP2fn2::QP_() ;

	             swz1=0;
				 swz2=0;
				 swz3=0;
				 swz4=0;
	             swt1=0;
				 swt2=0;
				 swt3=0;
				 swt4=0;
	if(m_ch_sxy) swz1=1;
	if(m_ch_syx) swz2=1;
	if(m_ch_s1xy)swz3=1;
	if(m_ch_s1yx)swz4=1;
	if(m_ch_srxy)swt1=1;
	if(m_ch_sryx)swt2=1;
	if(m_ch_srx) swt3=1;
	if(m_ch_sry) swt4=1;

	sw_edit();

	UpdateData(0);
	
	return 1;  	              
}

void GRP2fn2::OnPaint() 
{
	CPaintDC ooo(this);
	         /*
	                  UINT xpos=88,   ypos=114;
	         ooo.SetPixel( xpos,      ypos, 0); //r-1 symbol
			 ooo.SetPixel( xpos+1,    ypos, 0);
			 ooo.SetPixel( xpos+2,    ypos, 0);
			 ooo.SetPixel( xpos+4,    ypos, 0);
			 ooo.SetPixel( xpos+4,    ypos+1, 0);
			 ooo.SetPixel( xpos+4,    ypos+2, 0);
			 ooo.SetPixel( xpos+4,    ypos-1, 0);*/ //als bitmap realisiert
}

void GRP2fn2::OnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if(m_tab.GetCurSel() ==0){OnOK();GRP2fn1 o;o.DoModal();}
	if(m_tab.GetCurSel() ==1);
	if(m_tab.GetCurSel() ==2){OnOK();GRP2fn3 o;o.DoModal();}
	if(m_tab.GetCurSel() ==3){OnOK();GRP2fn4 o;o.DoModal();}
	
	*pResult = 0;
}

void GRP2fn2::OnCHECKrxy() {     UpdateData(1);                                          CGRP2Dlg o;o.r_rxy(m_ch_rxy );   UpdateData(0); }
void GRP2fn2::OnCHECKryx() {     UpdateData(1);                                          CGRP2Dlg o;o.r_ryx(m_ch_ryx );   UpdateData(0); }
void GRP2fn2::OnCHECKsxy() {     UpdateData(1);                 swz1=m_ch_sxy; sw_edit();CGRP2Dlg o;o.r_sxy(m_ch_sxy );   UpdateData(0); }
void GRP2fn2::OnCHECKsyx() {     UpdateData(1);                 swz2=m_ch_syx; sw_edit();CGRP2Dlg o;o.r_syx(m_ch_syx );   UpdateData(0); }
void GRP2fn2::OnCHECKs1xy(){     UpdateData(1);                 swz3=m_ch_s1xy;sw_edit();CGRP2Dlg o;o.r_s1xy(m_ch_s1xy ); UpdateData(0); }
void GRP2fn2::OnCHECKs1yx(){     UpdateData(1);                 swz4=m_ch_s1yx;sw_edit();CGRP2Dlg o;o.r_s1yx(m_ch_s1yx ); UpdateData(0); }
void GRP2fn2::OnCHECKsryx(){     UpdateData(1);                 swt2=m_ch_sryx;sw_edit();CGRP2Dlg o;o.r_sryx(m_ch_sryx ); UpdateData(0); }
void GRP2fn2::OnCHECKsry() {     UpdateData(1);                 swt4=m_ch_sry; sw_edit();CGRP2Dlg o;o.r_sry(m_ch_sry );   UpdateData(0); }
void GRP2fn2::OnCHECKsrxy(){     UpdateData(1);                 swt1=m_ch_srxy;sw_edit();CGRP2Dlg o;o.r_srxy(m_ch_srxy ); UpdateData(0); }
void GRP2fn2::OnCHECKsrx() {     UpdateData(1);                 swt3=m_ch_srx; sw_edit();CGRP2Dlg o;o.r_srx(m_ch_srx );   UpdateData(0); } 
void GRP2fn2::OnCheckD(){        UpdateData(1);                                          CGRP2Dlg o;o.D_rxy(m_ch_D);      UpdateData(0); }
void GRP2fn2::OnChangeEditCi() { UpdateData(1); GRP2fn2::QP_();                          CGRP2Dlg o;o.CI_rxy(m_CI);       UpdateData(0); }
void GRP2fn2::OnChangeEDITCIz() {UpdateData(1); GRP2fn2::QP_z();                         CGRP2Dlg o;o.CI_rxy(m_CI);       UpdateData(0); }
void GRP2fn2::OnChangeEDITCIt(){ UpdateData(1); GRP2fn2::QP_t();                         CGRP2Dlg o;o.CI_rxy(m_CI);       UpdateData(0); }

void GRP2fn2::sw_edit()
{
	m_CIt_ctr.SetReadOnly(!(swt1+swt2+swt3+swt4));
	m_CIz_ctr.SetReadOnly(!(swz1+swz2+swz3+swz4));
	m_CI_ctr.SetReadOnly(!(swz1+swz2+swz3+swz4+swt1+swt2+swt3+swt4));
};

void GRP2fn2::QP_() 
{
	m_CI_z=zp_funktion((100 -((100-m_CI)/2))/100);          
	m_CI_t=tp_funktion((100 -((100-m_CI)/2))/100,  df_  );  
}

void GRP2fn2::QP_z() 
{
	     m_CI =100*pz_funktion(m_CI_z);
	m_CI=m_CI-(100-m_CI);
	m_CI_t=tp_funktion((100 -((100-m_CI)/2))/100,  df_ );  
}

void GRP2fn2::QP_t() 
{
	     m_CI =100*pt_funktion(m_CI_t,df_);
	m_CI=m_CI-(100-m_CI);
	m_CI_z=zp_funktion((100 -((100-m_CI)/2))/100); 
}

void GRP2fn2::OnDeltaposSpinCi(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(swt1+swt2+swt3+swt4+swz1+swz2+swz3+swz4)
	{
		if(pNMUpDown->iDelta < 0)if(m_CI<99.9)  m_CI=m_CI+0.1;
		if(pNMUpDown->iDelta >=0)if(m_CI>0.2)   m_CI=m_CI-0.1;
							   
		UpdateData(0); OnChangeEditCi();
	}
	
	*pResult = 0;
}

void GRP2fn2::OnDeltaposSPINCIt(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(swt1+swt2+swt3+swt4)
	{
		if(pNMUpDown->iDelta < 0)  m_CI_t=m_CI_t+0.1;
		if(pNMUpDown->iDelta >=0)  m_CI_t=m_CI_t-0.1;
							   
		UpdateData(0); OnChangeEDITCIt();
	}
	
	*pResult = 0;
}

void GRP2fn2::OnDeltaposSPINCIz(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(swz1+swz2+swz3+swz4)
	{
		if(pNMUpDown->iDelta < 0)  m_CI_z=m_CI_z+0.1;
		if(pNMUpDown->iDelta >=0)  m_CI_z=m_CI_z-0.1;
							   
		UpdateData(0); OnChangeEDITCIz();
	}
	
	*pResult = 0;
}

void GRP2fn2::OnButtonP() 
{
	UpdateData(1);

	m_ch_rxy=1;
	m_ch_ryx=1;
	m_ch_sxy=1;swz1=1;
	m_ch_syx=1;swz2=1;
	m_ch_s1xy=0;swz3=0;
	m_ch_s1yx=0;swz4=0;
	m_ch_srxy=0;swt1=0;
	m_ch_sryx=0;swt2=0;
	m_ch_srx=0; swt3=0;
	m_ch_sry=0;swt4=0;
				

	sw_edit();

	CGRP2Dlg o;
			 o.r_rxy(m_ch_rxy );
			 o.r_ryx(m_ch_ryx );
			 o.r_sxy(m_ch_sxy );
			 o.r_syx(m_ch_syx );
			 o.r_s1xy(m_ch_s1xy );
			 o.r_s1yx(m_ch_s1yx );
			 o.r_srxy(m_ch_srxy );
			 o.r_sryx(m_ch_sryx );
			 o.r_srx(m_ch_srx );
			 o.r_sry(m_ch_sry );


	UpdateData(0);
}

void GRP2fn2::OnButtonSp() 
{
	UpdateData(1);

	m_CI=     95.0; QP_() ;
	m_ch_rxy=0;
	m_ch_ryx=0;
	m_ch_sxy=0;swz1=0;
	m_ch_syx=0;swz2=0;
	m_ch_s1xy=1;swz3=1;
	m_ch_s1yx=1;swz4=1;
	m_ch_srxy=0;swt1=0;
	m_ch_sryx=0;swt2=0;
	m_ch_srx=1;swt3=1;
	m_ch_sry=1;swt4=1;

	sw_edit();

	CGRP2Dlg o;
			 o.CI_rxy(m_CI);
			 o.r_rxy(m_ch_rxy );
			 o.r_ryx(m_ch_ryx );
			 o.r_sxy(m_ch_sxy );
			 o.r_syx(m_ch_syx );
			 o.r_s1xy(m_ch_s1xy );
			 o.r_s1yx(m_ch_s1yx );
			 o.r_srxy(m_ch_srxy );
			 o.r_sryx(m_ch_sryx );
			 o.r_srx(m_ch_srx );
			 o.r_sry(m_ch_sry );

	UpdateData(0);
}

void GRP2fn2::OnVoreinstellungen() 
{
	UpdateData(1);

	m_CI=     95.0;  QP_() ; //rxy_CI
	m_ch_D=   0;             //rxy_Darstellung_überschnitten
	m_ch_rxy= 1;             //rxy_Darstellung
	m_ch_ryx= 1;             //ryx_Darstellung
	m_ch_sxy= 1;swz1=1;      //sxy_Darstellung
	m_ch_syx= 1;swz2=1;      //syx_Darstellung
	m_ch_s1xy=0;swz3=0;      //s'xy_Darstellung
	m_ch_s1yx=0;swz4=0;      //s'yx_Darstellung
	m_ch_srxy=0;swt1=0;      //srxy_Darstellung
	m_ch_sryx=0;swt2=0;      //sryx_Darstellung
	m_ch_srx= 1;swt3=1;      //srx_Darstellung
	m_ch_sry= 1;swt4=1;      //sry_Darstellung

	sw_edit();

	CGRP2Dlg o;
	         o.CI_rxy(m_CI);
			 o.D_rxy(m_ch_D);
			 o.r_rxy(m_ch_rxy );
			 o.r_ryx(m_ch_ryx );
			 o.r_sxy(m_ch_sxy );
			 o.r_syx(m_ch_syx );
			 o.r_s1xy(m_ch_s1xy );
			 o.r_s1yx(m_ch_s1yx );
			 o.r_srxy(m_ch_srxy );
			 o.r_sryx(m_ch_sryx );
			 o.r_srx(m_ch_srx );
			 o.r_sry(m_ch_sry );
			 
	UpdateData(0);	
}

void GRP2fn2::OnFxy() {UpdateData(1);CGRP2Dlg o;o.fxy_sw( );UpdateData(0);}//funktionsmatrix neu setzen

void GRP2fn2::OnCHECKini() {UpdateData(1); UpdateData(0);}

void GRP2fn2::OnOK() 
{
				                                     CRect coord;
	                                        GetWindowRect(&coord); 
	
	CWinApp* pApp = AfxGetApp(); // ini profil schreiben  

	if(m_ch_ini)
	{
		     pApp->WriteProfileString("Funktion","rxy_CI",ftoc(m_CI,3));
			 pApp->WriteProfileInt("Funktion","rxy_Darstellung_überschnitten",m_ch_D);
			 pApp->WriteProfileInt("Funktion","rxy_Darstellung",m_ch_rxy);
			 pApp->WriteProfileInt("Funktion","ryx_Darstellung",m_ch_ryx);
			 pApp->WriteProfileInt("Funktion","sxy_Darstellung",m_ch_sxy);
			 pApp->WriteProfileInt("Funktion","syx_Darstellung",m_ch_syx);
			 pApp->WriteProfileInt("Funktion","s'xy_Darstellung",m_ch_s1xy);
			 pApp->WriteProfileInt("Funktion","s'yx_Darstellung",m_ch_s1yx);
			 pApp->WriteProfileInt("Funktion","srxy_Darstellung",m_ch_srxy);
			 pApp->WriteProfileInt("Funktion","sryx_Darstellung",m_ch_sryx);
			 pApp->WriteProfileInt("Funktion","srx_Darstellung",m_ch_srx);
			 pApp->WriteProfileInt("Funktion","sry_Darstellung",m_ch_sry);
	}
	         pApp->WriteProfileInt("INI_schreiben","fn2",m_ch_ini);
			 pApp->WriteProfileInt("Funktion","Tabelle",2);
			 pApp->WriteProfileInt("Funktion","Position_x",coord.left);
			 pApp->WriteProfileInt("Funktion","Position_y",coord.top);
	
	CDialog::OnOK();
}

CString GRP2fn2::ftoc( double x0, int dez ) 
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

int GRP2fn2::ftoi(double x_) 
{
	int    i_;
		   i_=0;
		   i_=atoi(ftoc(x_,8 /*dezimalstellen*/));
	return i_; //int
}

double GRP2fn2::zp_funktion(double wert) // z verteilungsfunktion F(y=p) p -> z  // 
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

double GRP2fn2::pz_funktion(double wert) // z verteilungsfunktion F(x=z) z -> p  //  
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

double GRP2fn2::tp_funktion(long double p_wert, double n_) // t verteilungsfunktion F(y=p) p -> t  //  
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


double GRP2fn2::pt_funktion(long double t_wert, double n_) // t verteilungsfunktion F(x=t) t -> p  //  
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



