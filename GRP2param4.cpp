//------------------------------------------------------------------------| GRP2param4.cpp                               //
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


GRP2param4::GRP2param4(CWnd* pParent )
	: CDialog(GRP2param4::IDD, pParent)
{
	//{{AFX_DATA_INIT(GRP2param4)
	m_sc = "1.2";
	m_scy = "30";
	m_sc_d = "0.1";
	m_scy_d = "0.5";
	m_ch_ini = 1;
	m_shift_y = 0;
	m_shift_x = 0;
	m_shift_x2 = 1.0f;
	m_shift_y2 = 1.0f;
	//}}AFX_DATA_INIT
}

void GRP2param4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GRP2param4)
	DDX_Control(pDX, IDC_TAB, m_tab);
	DDX_Text(pDX, IDC_EDIT_sc, m_sc);
	DDX_Text(pDX, IDC_EDIT_scy, m_scy);
	DDX_Text(pDX, IDC_EDIT_sc_d, m_sc_d);
	DDX_Text(pDX, IDC_EDIT_scy_d, m_scy_d);
	DDX_Check(pDX, IDC_CHECK_ini, m_ch_ini);
	DDX_Text(pDX, IDC_EDIT_shift_y, m_shift_y);
	DDX_Text(pDX, IDC_EDIT_shift_x, m_shift_x);
	DDX_Text(pDX, IDC_EDIT_shift_x2, m_shift_x2);
	DDX_Text(pDX, IDC_EDIT_shift_y2, m_shift_y2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(GRP2param4, CDialog)
	//{{AFX_MSG_MAP(GRP2param4)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, OnSelchangeTab)
	ON_EN_CHANGE(IDC_EDIT_sc, OnChangeEDITsc)
	ON_EN_CHANGE(IDC_EDIT_scy, OnChangeEDITscy)
	ON_BN_CLICKED(IDC_BUTTON_sc_d_reset, OnBUTTONscdreset)
	ON_BN_CLICKED(IDC_BUTTON_sc_reset, OnBUTTONscreset)
	ON_BN_CLICKED(IDC_BUTTON_scy_d_reset, OnBUTTONscydreset)
	ON_BN_CLICKED(IDC_BUTTON_scy_reset, OnBUTTONscyreset)
	ON_EN_CHANGE(IDC_EDIT_sc_d, OnChangeEDITscd)
	ON_EN_CHANGE(IDC_EDIT_scy_d, OnChangeEDITscyd)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_sc, OnDeltaposSPINsc)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_scy, OnDeltaposSPINscy)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_sc_d, OnDeltaposSPINscd)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_scy_d, OnDeltaposSPINscyd)
	ON_BN_CLICKED(ID_Voreinstellungen, OnVoreinstellungen)
	ON_BN_CLICKED(IDC_CHECK_ini, OnCHECKini)
	ON_EN_CHANGE(IDC_EDIT_shift_x, OnChangeEDITshiftx)
	ON_EN_CHANGE(IDC_EDIT_shift_y, OnChangeEDITshifty)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_shift_x, OnDeltaposSPINshiftx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_shift_y, OnDeltaposSPINshifty)
	ON_BN_CLICKED(IDC_BUTTON_shift_x_reset, OnBUTTONshiftxreset)
	ON_BN_CLICKED(IDC_BUTTON_shift_y_reset, OnBUTTONshiftyreset)
	ON_BN_CLICKED(IDC_BUTTON_shift_x_reset2, OnBUTTONshiftxreset2)
	ON_BN_CLICKED(IDC_BUTTON_shift_y_reset2, OnBUTTONshiftyreset2)
	ON_EN_CHANGE(IDC_EDIT_shift_x2, OnChangeEDITshiftx2)
	ON_EN_CHANGE(IDC_EDIT_shift_y2, OnChangeEDITshifty2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_shift_x2, OnDeltaposSPINshiftx2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_shift_y2, OnDeltaposSPINshifty2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL GRP2param4::OnInitDialog() 
{
	CDialog::OnInitDialog();

	UpdateData(1);

	            CWinApp*  pApp = AfxGetApp(); // ini profil lesen 

	            m_sc=     pApp->GetProfileString("Dialog","Diagramm_Skalierung_1","1.2");
	            m_scy=    pApp->GetProfileString("Dialog","Diagramm_Skalierung_2","30");
	            m_sc_d=   pApp->GetProfileString("Dialog","Diagramm_Skalierung_1_d","0.1");
	            m_scy_d=  pApp->GetProfileString("Dialog","Diagramm_Skalierung_2_d","1");
				m_shift_x=pApp->GetProfileInt("Dialog","Diagramm_X_Position",0);
	            m_shift_y=pApp->GetProfileInt("Dialog","Diagramm_Y_Position",0);
		  m_shift_x2=atof(pApp->GetProfileString("Dialog","Diagramm_X_Form","1"));
		  m_shift_y2=atof(pApp->GetProfileString("Dialog","Diagramm_Y_Form","1"));

		       m_ch_ini=  pApp->GetProfileInt("INI_schreiben","param4",1);
	
	SetWindowPos(&wndTop, pApp->GetProfileInt("Parameter","Position_x",100),
		                  pApp->GetProfileInt("Parameter","Position_y",100), 200+8,100+27, SWP_NOSIZE);

	sc_d=atof(m_sc_d);
	scy_d=atof(m_scy_d);
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

				m_tab.SetCurSel(  3);

	UpdateData(0);
	
	return 1;  
}

void GRP2param4::OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if(m_tab.GetCurSel() ==0){OnOK();GRP2param1 o;o.DoModal();}
	if(m_tab.GetCurSel() ==1){OnOK();GRP2param2 o;o.DoModal();}
	if(m_tab.GetCurSel() ==2){OnOK();GRP2param3 o;o.DoModal();}
	if(m_tab.GetCurSel() ==3);
	if(m_tab.GetCurSel() ==4){OnOK();GRP2param5 o;o.DoModal();}
	
	*pResult = 0;
}

void GRP2param4::OnDeltaposSPINsc(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	UpdateData(1);

	if(pNMUpDown->iDelta < 0) 
	{
			  float v_=atof(m_sc);
					v_-=sc_d;
		 m_sc =ftoc(v_, 2); 
	}
	if(pNMUpDown->iDelta >=0) 
	{
			  float v_=atof(m_sc);
					v_+=sc_d;
		 m_sc =ftoc(v_, 2); 
	}

	UpdateData(0);	CGRP2Dlg o; o.sc_(m_sc); 
	
	*pResult = 0;
}

void GRP2param4::OnDeltaposSPINscy(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	UpdateData(1);

	if(pNMUpDown->iDelta < 0) 
	{
			   float v_=atof(m_scy);
					 v_-=scy_d;
		 m_scy =ftoc(v_, 2); 
	}
	if(pNMUpDown->iDelta >=0) 
	{
			   float v_=atof(m_scy);
					 v_+=scy_d;
		 m_scy =ftoc(v_, 2); 
	}

	UpdateData(0);	CGRP2Dlg o; o.sc_y(m_scy); 

	*pResult = 0;
}

void GRP2param4::OnDeltaposSPINscd(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)            sc_d+=0.1;
	if(pNMUpDown->iDelta >=0)if(sc_d>0)  sc_d-=0.1;
	
	UpdateData(1); m_sc_d= ftoc(sc_d,1); UpdateData(0);
	
	*pResult = 0;
}

void GRP2param4::OnDeltaposSPINscyd(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)            scy_d+=1;
	if(pNMUpDown->iDelta >=0)if(scy_d>0)  scy_d-=1;
	
	UpdateData(1); m_scy_d= ftoc(scy_d,0); UpdateData(0);
	
	*pResult = 0;
}

void GRP2param4::OnDeltaposSPINshiftx(NMHDR* pNMHDR, LRESULT* pResult) 
{

	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)            m_shift_x+=5; //
	if(pNMUpDown->iDelta >=0)            m_shift_x-=5;
	
	UpdateData(0); OnChangeEDITshiftx(); 
	
	*pResult = 0;
}

void GRP2param4::OnDeltaposSPINshifty(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)            m_shift_y-=5; //
	if(pNMUpDown->iDelta >=0)            m_shift_y+=5;
	
	UpdateData(0); OnChangeEDITshifty(); 
	
	*pResult = 0;
}

void GRP2param4::OnDeltaposSPINshiftx2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)            m_shift_x2+=0.1;
	if(pNMUpDown->iDelta >=0)            m_shift_x2-=0.1;
	
	UpdateData(0); OnChangeEDITshiftx2(); 
	
	*pResult = 0;
}

void GRP2param4::OnDeltaposSPINshifty2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)            m_shift_y2+=0.1;
	if(pNMUpDown->iDelta >=0)            m_shift_y2-=0.1;
	
	UpdateData(0); OnChangeEDITshifty2(); 
	
	*pResult = 0;
}

// Diagrammskalierung sc
void GRP2param4::OnChangeEDITsc() {      UpdateData(1);                       CGRP2Dlg o; o.sc_(m_sc);          UpdateData(0);}
void GRP2param4::OnChangeEDITscy() {     UpdateData(1);                       CGRP2Dlg o; o.sc_y(m_scy);        UpdateData(0);}
void GRP2param4::OnChangeEDITshiftx(){   UpdateData(1);                       CGRP2Dlg o; o.pos_Dx_(m_shift_x); UpdateData(0);}
void GRP2param4::OnChangeEDITshifty(){   UpdateData(1);                       CGRP2Dlg o; o.pos_Dy_(m_shift_y); UpdateData(0);}
void GRP2param4::OnChangeEDITshiftx2(){  UpdateData(1);                       CGRP2Dlg o; o.frm_Dx_(m_shift_x2);UpdateData(0);}
void GRP2param4::OnChangeEDITshifty2() { UpdateData(1);                       CGRP2Dlg o; o.frm_Dy_(m_shift_y2);UpdateData(0);}
void GRP2param4::OnChangeEDITscyd() {    UpdateData(1); scy_d = atof(m_scy_d);                                  UpdateData(0);}
void GRP2param4::OnChangeEDITscd() {     UpdateData(1); sc_d = atof(m_sc_d);                                    UpdateData(0);}

void GRP2param4::OnBUTTONscyreset() {    UpdateData(1); m_scy="30";           CGRP2Dlg o; o.sc_y(m_scy);        UpdateData(0);}
void GRP2param4::OnBUTTONscreset() {     UpdateData(1); m_sc="1.2";           CGRP2Dlg o; o.sc_(m_sc);          UpdateData(0);}
void GRP2param4::OnBUTTONscdreset() {    UpdateData(1); m_sc_d="0.1"; sc_d=0.1;                                 UpdateData(0);} 
void GRP2param4::OnBUTTONscydreset(){    UpdateData(1); m_scy_d="1"; scy_d=1;                                   UpdateData(0);}
void GRP2param4::OnBUTTONshiftxreset(){  UpdateData(1); CWinApp*  pApp = AfxGetApp();m_shift_x=      pApp->GetProfileInt("Dialog","Diagramm_X_Position",0); OnChangeEDITshiftx(); UpdateData(0);}
void GRP2param4::OnBUTTONshiftyreset(){  UpdateData(1); CWinApp*  pApp = AfxGetApp();m_shift_y=      pApp->GetProfileInt("Dialog","Diagramm_Y_Position",0); OnChangeEDITshifty(); UpdateData(0);}
void GRP2param4::OnBUTTONshiftxreset2(){ UpdateData(1); CWinApp*  pApp = AfxGetApp();m_shift_x2=itof(pApp->GetProfileInt("Dialog","Diagramm_X_Form",1)); OnChangeEDITshiftx2();   UpdateData(0);}
void GRP2param4::OnBUTTONshiftyreset2(){ UpdateData(1); CWinApp*  pApp = AfxGetApp();m_shift_y2=itof(pApp->GetProfileInt("Dialog","Diagramm_Y_Form",1)); OnChangeEDITshifty2();   UpdateData(0);} 


void GRP2param4::OnCHECKini() {      UpdateData(1);                                                   UpdateData(0);}

void GRP2param4::OnVoreinstellungen() 
{
	UpdateData(1);

	m_sc=     "1.2"; //Diagramm_Skalierung_1
	m_scy=     "30"; //Diagramm_Skalierung_2
	m_sc_d=   "0.1"; //Diagramm_Skalierung_1_d
	m_scy_d=    "1"; //Diagramm_Skalierung_2_d
	m_shift_x=   0;  //Diagramm_X_Position
	m_shift_y=   0;  //Diagramm_Y_Position
	m_shift_x2=  1;  //Diagramm_X_Form
	m_shift_y2=  1;  //Diagramm_Y_Form

	CGRP2Dlg o; o.sc_(m_sc);
	            o.sc_y(m_scy);
				o.pos_Dx_(m_shift_x);
				o.pos_Dy_(m_shift_y);
				o.frm_Dx_(m_shift_x2);
				o.frm_Dy_(m_shift_y2);
   
	UpdateData(0);
}

void GRP2param4::OnOK() 
{
	                                                  CRect coord;
	                                         GetWindowRect(&coord); 
	
	CWinApp* pApp = AfxGetApp(); // ini profil schreiben  

	if(m_ch_ini)
	{
			 pApp->WriteProfileString("Dialog","Diagramm_Skalierung_1",m_sc);
		     pApp->WriteProfileString("Dialog","Diagramm_Skalierung_2",m_scy);
			 pApp->WriteProfileString("Dialog","Diagramm_Skalierung_1_d",m_sc_d);
		     pApp->WriteProfileString("Dialog","Diagramm_Skalierung_2_d",m_scy_d);		 
	}
		     pApp->WriteProfileInt("Dialog","Diagramm_X_Position",m_shift_x);
	         pApp->WriteProfileInt("Dialog","Diagramm_Y_Position",m_shift_y);
			 pApp->WriteProfileString("Dialog","Diagramm_X_Form",ftoc(m_shift_x2,3));
			 pApp->WriteProfileString("Dialog","Diagramm_Y_Form",ftoc(m_shift_y2,3));
			 pApp->WriteProfileInt("INI_schreiben","param4",m_ch_ini);
			 pApp->WriteProfileInt("Parameter","Tabelle",4);
	         pApp->WriteProfileInt("Parameter","Position_x",coord.left);
			 pApp->WriteProfileInt("Parameter","Position_y",coord.top);
	
	CDialog::OnOK();
}

CString GRP2param4::ftoc( double x0, int dez ) 
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

CString GRP2param4::itoc(int x_) 
{
	          char ccc[100];
           itoa(x_,ccc,10);
	const char* cc=ccc;																	 
	CString c_=cc;		                    
	 
	 return c_; //CString
}

double GRP2param4::itof(int x_){return atoi(itoc(x_));};

int GRP2param4::ftoi(double x_) 
{
	int    i_;
		   i_=0;
		   i_=atoi(ftoc(x_,8 /*dezimalstellen*/));
	return i_; //int
}






