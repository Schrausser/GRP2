//------------------------------------------------------------------------| GRP2param3.cpp                               //
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

GRP2param3::GRP2param3(CWnd* pParent )
	: CDialog(GRP2param3::IDD, pParent)
{
	//{{AFX_DATA_INIT(GRP2param3)
	m_ch_xV = 1;
	m_ch_yV = 1;
	m_ch_xK = 1;
	m_ch_yK = 1;
	m_dez_K_x = 2;
	m_dez_K_y = 2;
	m_kjy = "0";
	m_kjx = "0";
	m_kjx_d = "1";
	m_kjy_d = "1";
	m_ch_ini = 1;
	//}}AFX_DATA_INIT
}

void GRP2param3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GRP2param3)
	DDX_Control(pDX, IDC_TAB, m_tab);
	DDX_Check(pDX, IDC_CHECK_xV, m_ch_xV);
	DDX_Check(pDX, IDC_CHECK_yV, m_ch_yV);
	DDX_Check(pDX, IDC_CHECK_xK, m_ch_xK);
	DDX_Check(pDX, IDC_CHECK_yK, m_ch_yK);
	DDX_Text(pDX, IDC_EDIT_dez_K_x, m_dez_K_x);
	DDX_Text(pDX, IDC_EDIT_dez_K_y, m_dez_K_y);
	DDX_Text(pDX, IDC_EDIT_kjy, m_kjy);
	DDX_Text(pDX, IDC_EDIT_kjx, m_kjx);
	DDX_Text(pDX, IDC_EDIT_kjx_d, m_kjx_d);
	DDX_Text(pDX, IDC_EDIT_kjy_d, m_kjy_d);
	DDX_Check(pDX, IDC_CHECK_ini, m_ch_ini);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(GRP2param3, CDialog)
	//{{AFX_MSG_MAP(GRP2param3)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, OnSelchangeTab)
	ON_BN_CLICKED(IDC_CHECK_xV, OnCHECKxV)
	ON_BN_CLICKED(IDC_CHECK_yV, OnCHECKyV)
	ON_BN_CLICKED(IDC_CHECK_xK, OnCHECKxK)
	ON_BN_CLICKED(IDC_CHECK_yK, OnCHECKyK)
	ON_EN_CHANGE(IDC_EDIT_dez_K_x, OnChangeEDITdezKx)
	ON_EN_CHANGE(IDC_EDIT_dez_K_y, OnChangeEDITdezKy)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_dez_K_x, OnDeltaposSPINdezKx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_dez_K_y, OnDeltaposSPINdezKy)
	ON_EN_CHANGE(IDC_EDIT_kjx, OnChangeEDITkjx)
	ON_EN_CHANGE(IDC_EDIT_kjy, OnChangeEDITkjy)
	ON_BN_CLICKED(IDC_BUTTON_kjx_reset, OnBUTTONkjxreset)
	ON_EN_CHANGE(IDC_EDIT_kjx_d, OnChangeEDITkjxd)
	ON_BN_CLICKED(IDC_BUTTON_kjy_reset, OnBUTTONkjyreset)
	ON_EN_CHANGE(IDC_EDIT_kjy_d, OnChangeEDITkjyd)
	ON_BN_CLICKED(IDC_BUTTON_kjx_d_reset, OnBUTTONkjxdreset)
	ON_BN_CLICKED(IDC_BUTTON_kjy_d_reset, OnBUTTONkjydreset)
	ON_WM_MOUSEWHEEL()
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_kjx, OnDeltaposSPINkjx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_kjy, OnDeltaposSPINkjy)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_kjx_d, OnDeltaposSPINkjxd)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_kjy_d, OnDeltaposSPINkjyd)
	ON_BN_CLICKED(IDC_CHECK_ini, OnCHECKini)
	ON_BN_CLICKED(ID_Voreinstellungen, OnVoreinstellungen)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_kw_x, OnDeltaposSPINkwx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_kw_y, OnDeltaposSPINkwy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL GRP2param3::OnInitDialog() 
{
	CDialog::OnInitDialog();

	UpdateData(1);

	             CWinApp*  pApp = AfxGetApp(); // ini profil lesen 

			    m_ch_xV =  pApp->GetProfileInt("Achsen","x_Vektor",1);
                m_ch_yV =  pApp->GetProfileInt("Achsen","y_Vektor",1);
				m_ch_xK =  pApp->GetProfileInt("Achsen","x_Koordinate",1);
	            m_ch_yK =  pApp->GetProfileInt("Achsen","y_Koordinate",1);
				m_dez_K_x= pApp->GetProfileInt("Achsen","x_Koordinaten_Dezimalstellen",2);
	            m_dez_K_y= pApp->GetProfileInt("Achsen","y_Koordinaten_Dezimalstellen",2);
				m_kjx=     pApp->GetProfileString("Achsen","x_Justierung","0");
				m_kjy=     pApp->GetProfileString("Achsen","y_Justierung","0");
				m_kjx_d =  pApp->GetProfileString("Achsen","x_Justierungs_d","1");
				m_kjy_d =  pApp->GetProfileString("Achsen","y_Justierungs_d","1");
				kwx_d=     pApp->GetProfileInt("Achsen","X_Vektor_Koordinaten_Position",3);
	            kwy_d=     pApp->GetProfileInt("Achsen","Y_Vektor_Koordinaten_Position",-11);

				m_ch_ini=  pApp->GetProfileInt("INI_schreiben","param3",1);

	 SetWindowPos(&wndTop, pApp->GetProfileInt("Parameter","Position_x",100),
		                   pApp->GetProfileInt("Parameter","Position_y",100), 200+8,100+27, SWP_NOSIZE);

	kjx_d=atof(m_kjx_d);
	kjy_d=atof(m_kjy_d);
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

				m_tab.SetCurSel(  2);

	UpdateData(0);
	return 1;  
}

void GRP2param3::OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if(m_tab.GetCurSel() ==0){OnOK();GRP2param1 o;o.DoModal();}
	if(m_tab.GetCurSel() ==1){OnOK();GRP2param2 o;o.DoModal();}
	if(m_tab.GetCurSel() ==2);
	if(m_tab.GetCurSel() ==3){OnOK();GRP2param4 o;o.DoModal();}
	if(m_tab.GetCurSel() ==4){OnOK();GRP2param5 o;o.DoModal();}
	
	*pResult = 0;
}

void GRP2param3::OnCHECKxV() { UpdateData(1); CGRP2Dlg o; o.x_Vektor(m_ch_xV);UpdateData(0);}
void GRP2param3::OnCHECKyV() { UpdateData(1); CGRP2Dlg o; o.y_Vektor(m_ch_yV);UpdateData(0);}
void GRP2param3::OnCHECKxK() { UpdateData(1); CGRP2Dlg o; o.x_Koor(m_ch_xK);  UpdateData(0);}
void GRP2param3::OnCHECKyK() { UpdateData(1); CGRP2Dlg o; o.y_Koor(m_ch_yK);  UpdateData(0);}

//dezimalstellen 
void GRP2param3::OnDeltaposSPINdezKx(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown =   (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)                m_dez_K_x+=1;
	if(pNMUpDown->iDelta >=0)if(m_dez_K_x>0) m_dez_K_x-=1;
		                   
	UpdateData(0); OnChangeEDITdezKx();
		
	*pResult = 0;
}

void GRP2param3::OnDeltaposSPINdezKy(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown =   (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)                m_dez_K_y+=1;
	if(pNMUpDown->iDelta >=0)if(m_dez_K_y>0) m_dez_K_y-=1;
		                   
	UpdateData(0); OnChangeEDITdezKy();
		
	*pResult = 0;
}

void GRP2param3::OnChangeEDITdezKx(){UpdateData(1);                        CGRP2Dlg o; o.xK_ds(m_dez_K_x); UpdateData(0);}
void GRP2param3::OnChangeEDITdezKy(){UpdateData(1);                        CGRP2Dlg o; o.yK_ds(m_dez_K_y); UpdateData(0);}
void GRP2param3::OnChangeEDITkjxd() {UpdateData(1); kjx_d = atof(m_kjx_d);                                 UpdateData(0);}
void GRP2param3::OnBUTTONkjxreset() {UpdateData(1); m_kjx="0";             CGRP2Dlg o; o.x_kj(m_kjx);      UpdateData(0);}
void GRP2param3::OnBUTTONkjxdreset(){UpdateData(1); m_kjx_d="1"; kjx_d=1;                                  UpdateData(0);} 
void GRP2param3::OnChangeEDITkjyd() {UpdateData(1); kjy_d = atof(m_kjy_d);                                 UpdateData(0);}
void GRP2param3::OnBUTTONkjyreset() {UpdateData(1); m_kjy="0";             CGRP2Dlg o; o.y_kj(m_kjy);      UpdateData(0);}
void GRP2param3::OnBUTTONkjydreset(){UpdateData(1); m_kjy_d="1"; kjy_d=1;                                  UpdateData(0);} 
void GRP2param3::OnChangeEDITkjx() { UpdateData(1);                        CGRP2Dlg o; o.x_kj(m_kjx);	   UpdateData(0);}
void GRP2param3::OnChangeEDITkjy() { UpdateData(1);                        CGRP2Dlg o; o.y_kj(m_kjy);	   UpdateData(0);}


// Koordinaten Justierung
void GRP2param3::OnDeltaposSPINkjx(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	UpdateData(1);
	if(pNMUpDown->iDelta < 0)
	{
			  float v_=atof(m_kjx);
					v_+=kjx_d;
		m_kjx =ftoc(v_, 3);  
	}
	if(pNMUpDown->iDelta >=0)
	{
			  float v_=atof(m_kjx);
					v_-=kjx_d;
		m_kjx =ftoc(v_, 3); 	
	}
		                   
	UpdateData(0); OnChangeEDITkjx();
	
	*pResult = 0;
}

void GRP2param3::OnDeltaposSPINkjy(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	UpdateData(1);
	if(pNMUpDown->iDelta < 0)
	{
			  float v_=atof(m_kjy);
					v_+=kjy_d;
		m_kjy =ftoc(v_, 3);  
	}
	if(pNMUpDown->iDelta >=0)
	{
			  float v_=atof(m_kjy);
					v_-=kjy_d;
		m_kjy =ftoc(v_, 3); 	
	}
		                   
	UpdateData(0); OnChangeEDITkjy();
	
	*pResult = 0;
}

void GRP2param3::OnDeltaposSPINkjxd(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)             kjx_d+=1;
	if(pNMUpDown->iDelta >=0)if(kjx_d>0)  kjx_d-=1;
	
	UpdateData(1); m_kjx_d= ftoc(kjx_d,0); UpdateData(0);
	
	*pResult = 0;
}

void GRP2param3::OnDeltaposSPINkjyd(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)             kjy_d+=1;
	if(pNMUpDown->iDelta >=0)if(kjy_d>0)  kjy_d-=1;
	
	UpdateData(1); m_kjy_d= ftoc(kjy_d,0); UpdateData(0);
	
	*pResult = 0;
}

void GRP2param3::OnDeltaposSPINkwx(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(pNMUpDown->iDelta < 0)             kwx_d+=1;
	if(pNMUpDown->iDelta >=0)             kwx_d-=1;
	
	UpdateData(1); CGRP2Dlg o; o.posVx_(kwx_d);  UpdateData(0);

	*pResult = 0;
}

void GRP2param3::OnDeltaposSPINkwy(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)             kwy_d-=1;
	if(pNMUpDown->iDelta >=0)             kwy_d+=1;
	
	UpdateData(1); CGRP2Dlg o; o.posVy_(kwy_d);  UpdateData(0);
	
	*pResult = 0;
}


BOOL GRP2param3::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
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

void GRP2param3::OnCHECKini() {UpdateData(1);UpdateData(0);}

void GRP2param3::OnVoreinstellungen() 
{
	UpdateData(1);

	m_ch_xV =  1; //x_Vektor
    m_ch_yV =  1; //y_Vektor
	m_ch_xK =  1; //x_Koordinate
	m_ch_yK =  1; //y_Koordinate
	m_dez_K_x= 2; //x_Koordinaten_Dezimalstellen
	m_dez_K_y= 2; //y_Koordinaten_Dezimalstellen
	m_kjx=    "0";//x_Justierung
	m_kjy=    "0";//y_Justierung
	m_kjx_d = "1";//x_Justierungs_d
	m_kjy_d = "1";//y_Justierungs_d
	kwx_d=     3; //X_Vektor_Koordinaten_Position
	kwy_d=   -11; //Y_Vektor_Koordinaten_Position

	CGRP2Dlg o; o.x_Vektor(m_ch_xV);
	            o.y_Vektor(m_ch_yV);
	            o.x_Koor(m_ch_xK);
	            o.y_Koor(m_ch_yK);
	            o.xK_ds(m_dez_K_x);//o.xK_ds(m_dez_K_x);
				o.yK_ds(m_dez_K_y);//o.yK_ds(m_dez_K_y);
				o.x_kj(m_kjx);
				o.y_kj(m_kjy);
				o.posVx_(kwx_d);
				o.posVy_(kwy_d);

	UpdateData(0);	
}

void GRP2param3::OnOK() 
{
	                                                  CRect coord;
	                                         GetWindowRect(&coord); 
	
	CWinApp* pApp = AfxGetApp(); // ini profil schreiben  

	if(m_ch_ini)
	{
	         pApp->WriteProfileInt("Achsen","x_Vektor",m_ch_xV);
	         pApp->WriteProfileInt("Achsen","y_Vektor",m_ch_yV);
			 pApp->WriteProfileInt("Achsen","x_Koordinate",m_ch_xK);
	         pApp->WriteProfileInt("Achsen","y_Koordinate",m_ch_yK);
			 pApp->WriteProfileInt("Achsen","x_Koordinaten_Dezimalstellen",m_dez_K_x);
	         pApp->WriteProfileInt("Achsen","y_Koordinaten_Dezimalstellen",m_dez_K_y);
			 pApp->WriteProfileString("Achsen","x_Justierung",m_kjx);
	         pApp->WriteProfileString("Achsen","y_Justierung",m_kjy);
			 pApp->WriteProfileString("Achsen","x_Justierungs_d",m_kjx_d);
			 pApp->WriteProfileString("Achsen","y_Justierungs_d",m_kjy_d);
			 pApp->WriteProfileInt("Achsen","X_Vektor_Koordinaten_Position",kwx_d);
	         pApp->WriteProfileInt("Achsen","Y_Vektor_Koordinaten_Position",kwy_d);
	}
			 pApp->WriteProfileInt("INI_schreiben","param3",m_ch_ini);
			 pApp->WriteProfileInt("Parameter","Tabelle",3);
	         pApp->WriteProfileInt("Parameter","Position_x",coord.left);
			 pApp->WriteProfileInt("Parameter","Position_y",coord.top);
	
	CDialog::OnOK();
}

CString GRP2param3::ftoc( double x0, int dez ) 
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








