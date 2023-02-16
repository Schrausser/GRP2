//------------------------------------------------------------------------| GRP2diagrm2.cpp                              //
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

GRP2diagrm2::GRP2diagrm2(CWnd* pParent ): CDialog(GRP2diagrm2::IDD, pParent)	
{
	//{{AFX_DATA_INIT(GRP2diagrm2)
	m_X_art = "";
	m_Y_art = "";
	m_X_gr = 1;
	m_Y_gr = 1;
	m_Xgrid_art = "";
	m_Ygrid_art = "";
	m_Xgrid_gr = 0;
	m_Ygrid_gr = 0;
	m_ch_x = 1;
	m_ch_y = 1;
	//}}AFX_DATA_INIT
}

void GRP2diagrm2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GRP2diagrm2)
	DDX_Control(pDX, IDC_TAB2, m_tab);
	DDX_Check(pDX, IDC_CHECK_ini, m_ch_ini);
	DDX_CBString(pDX, IDC_COMBO_X_art, m_X_art);
	DDX_CBString(pDX, IDC_COMBO_Y_art, m_Y_art);
	DDX_Text(pDX, IDC_EDIT_X_gr, m_X_gr);
	DDX_Text(pDX, IDC_EDIT_Y_gr, m_Y_gr);
	DDX_CBString(pDX, IDC_COMBO_Xgrid_art, m_Xgrid_art);
	DDX_CBString(pDX, IDC_COMBO_Ygrid_art, m_Ygrid_art);
	DDX_Text(pDX, IDC_EDIT_Xgrid_gr, m_Xgrid_gr);
	DDX_Text(pDX, IDC_EDIT_Ygrid_gr, m_Ygrid_gr);
	DDX_Check(pDX, IDC_CHECK_x, m_ch_x);
	DDX_Check(pDX, IDC_CHECK_y, m_ch_y);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(GRP2diagrm2, CDialog)
	//{{AFX_MSG_MAP(GRP2diagrm2)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB2, OnSelchangeTab2)
	ON_BN_CLICKED(IDC_CHECK_ini, OnCHECKini)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_X_fb, OnBUTTONXfb)
	ON_BN_CLICKED(IDC_BUTTON_Y_fb, OnBUTTONYfb)
	ON_CBN_SELCHANGE(IDC_COMBO_X_art, OnSelchangeCOMBOXart)
	ON_CBN_SELCHANGE(IDC_COMBO_Y_art, OnSelchangeCOMBOYart)
	ON_EN_CHANGE(IDC_EDIT_X_gr, OnChangeEDITXgr)
	ON_EN_CHANGE(IDC_EDIT_Y_gr, OnChangeEDITYgr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_X_gr, OnDeltaposSPINXgr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_Y_gr, OnDeltaposSPINYgr)
	ON_BN_CLICKED(IDC_BUTTON_schr_x, OnBUTTONschrx)
	ON_BN_CLICKED(IDC_BUTTON_schr_y, OnBUTTONschry)
	ON_BN_CLICKED(ID_Voreinstellungen, OnVoreinstellungen)
	ON_CBN_SELCHANGE(IDC_COMBO_Xgrid_art, OnSelchangeCOMBOXgridart)
	ON_CBN_SELCHANGE(IDC_COMBO_Ygrid_art, OnSelchangeCOMBOYgridart)
	ON_BN_CLICKED(IDC_BUTTON_Xgrid_fb, OnBUTTONXgridfb)
	ON_BN_CLICKED(IDC_BUTTON_Ygrid_fb, OnBUTTONYgridfb)
	ON_EN_CHANGE(IDC_EDIT_Ygrid_gr, OnChangeEDITYgridgr)
	ON_EN_CHANGE(IDC_EDIT_Xgrid_gr, OnChangeEDITXgridgr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_Xgrid_gr, OnDeltaposSPINXgridgr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_Ygrid_gr, OnDeltaposSPINYgridgr)
	ON_BN_CLICKED(IDC_CHECK_x, OnCHECKx)
	ON_BN_CLICKED(IDC_CHECK_y, OnCHECKy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL GRP2diagrm2::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	UpdateData(1);

	               CWinApp* pApp = AfxGetApp(); // ini profil lesen 
								
				X_clr=      pApp->GetProfileInt("Achsen","X_Farbe",8421504);
				Y_clr=      pApp->GetProfileInt("Achsen","Y_Farbe",8421504);
			    Xgrid_clr=  pApp->GetProfileInt("Achsen","X_Grid_Farbe",65793*190);
	            Ygrid_clr=  pApp->GetProfileInt("Achsen","Y_Grid_Farbe",65793*190);
				m_X_gr=     pApp->GetProfileInt("Achsen","X_Linienbreite",1);
				m_Y_gr=     pApp->GetProfileInt("Achsen","Y_Linienbreite",1);
				m_Xgrid_gr= pApp->GetProfileInt("Achsen","X_Grid_Linienbreite",0);
	            m_Ygrid_gr= pApp->GetProfileInt("Achsen","Y_Grid_Linienbreite",0);
				m_ch_x=     pApp->GetProfileInt("Achsen","X_Bezeichnung",1);
	            m_ch_y=     pApp->GetProfileInt("Achsen","Y_Bezeichnung",1);
				schr_x_fn=  pApp->GetProfileString("Schriftart","Achsen_x","Arial");
	            schr_y_fn=  pApp->GetProfileString("Schriftart","Achsen_y","Arial");
	            schr_x_clr= pApp->GetProfileInt("Schriftart","Farbe_Achsen_x",8421504);
	            schr_y_clr= pApp->GetProfileInt("Schriftart","Farbe_Achsen_y",8421504);
	            schr_x_H=   pApp->GetProfileInt("Schriftart","Höhe_Achsen_x",13);
	            schr_y_H=   pApp->GetProfileInt("Schriftart","Höhe_Achsen_y",13);
	            schr_x_W=   pApp->GetProfileInt("Schriftart","Breite_Achsen_x",4);
	            schr_y_W=   pApp->GetProfileInt("Schriftart","Breite_Achsen_y",4);
				mod_X=      pApp->GetProfileInt("Achsen","X_Modus",1);
             if(mod_X==1)m_X_art="Linie";
			 if(mod_X==2)m_X_art="Punkt";
			 if(mod_X==3)m_X_art="Strich";
			 if(mod_X==4)m_X_art="Strichpunkt";
			 if(mod_X==5)m_X_art="Strichdoppelpkt.";
			    mod_Y=      pApp->GetProfileInt("Achsen","Y_Modus",1);
             if(mod_Y==1)m_Y_art="Linie";
			 if(mod_Y==2)m_Y_art="Punkt";
			 if(mod_Y==3)m_Y_art="Strich";
			 if(mod_Y==4)m_Y_art="Strichpunkt";
			 if(mod_Y==5)m_Y_art="Strichdoppelpkt.";
			    mod_Xgrd=   pApp->GetProfileInt("Achsen","X_Grid_Modus",2);
			 if(mod_Xgrd==1)m_Xgrid_art="Linie";
			 if(mod_Xgrd==2)m_Xgrid_art="Punkt";
			 if(mod_Xgrd==3)m_Xgrid_art="Strich";
			 if(mod_Xgrd==4)m_Xgrid_art="Strichpunkt";
			 if(mod_Xgrd==5)m_Xgrid_art="Strichdoppelpkt.";
				mod_Ygrd=   pApp->GetProfileInt("Achsen","Y_Grid_Modus",2);
			 if(mod_Ygrd==1)m_Ygrid_art="Linie";
			 if(mod_Ygrd==2)m_Ygrid_art="Punkt";
			 if(mod_Ygrd==3)m_Ygrid_art="Strich";
			 if(mod_Ygrd==4)m_Ygrid_art="Strichpunkt";
			 if(mod_Ygrd==5)m_Ygrid_art="Strichdoppelpkt.";

	             m_ch_ini=  pApp->GetProfileInt("INI_schreiben","diagrm2",1);

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
				         
				m_tab.SetCurSel(  1);

		 //LOGFONT lfx; 
	strncpy((char*)lfx.lfFaceName,    schr_x_fn,  sizeof lfx.lfFaceName);
		           lfx.lfFaceName[ sizeof lfx.lfFaceName-1] = 0;
	
		 //LOGFONT lfy; 
	strncpy((char*)lfy.lfFaceName,    schr_y_fn,  sizeof lfy.lfFaceName);
		           lfy.lfFaceName[ sizeof lfy.lfFaceName-1] = 0;

	UpdateData(0);

	return 1;  	              
}

void GRP2diagrm2::OnPaint() 
{
	CPaintDC ooo(this); 

	                     CRect o2(197, 55, 211, 68);
			 ooo.FillSolidRect(o2,   X_clr );        //X_Linienfarbe
			
			             CRect o3(197, 83, 211, 96);
			 ooo.FillSolidRect(o3,   Y_clr );        //Y_Linienfarbe

			                      UINT pos=222;
			             CRect o4(197, pos, 211, pos+13);
			 ooo.FillSolidRect(o4,   Xgrid_clr );     //X_grid Linienfarbe
			
			             CRect o5(197, pos+28, 211, pos+41);
			 ooo.FillSolidRect(o5,   Ygrid_clr );     //Y_grid Linienfarbe

		                  CFont f1; 
	                            f1.CreateFont(12,5,0,0,400,0,0,0,0,OUT_DEFAULT_PRECIS, 
								                                   CLIP_DEFAULT_PRECIS, 
										                           DEFAULT_QUALITY, 
										                           DEFAULT_PITCH,
										                           schr_x_fn);
			  ooo.SelectObject(&f1);
			  ooo.SetTextColor(schr_x_clr);
			  ooo.SetBkMode(TRANSPARENT);
			  ooo.TextOut(140,  140,    schr_x_fn); //schriftart x-achse
		
	                      CFont f2; 
	                            f2.CreateFont(12,5,0,0,400,0,0,0,0,OUT_DEFAULT_PRECIS, 
								                                   CLIP_DEFAULT_PRECIS, 
										                           DEFAULT_QUALITY, 
										                           DEFAULT_PITCH,
										                           schr_y_fn);
			  ooo.SelectObject(&f2);
			  ooo.SetTextColor(schr_y_clr);
			  ooo.TextOut(140,  163,    schr_y_fn); //schriftart y-achse
}


void GRP2diagrm2::OnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if(m_tab.GetCurSel() ==0){OnOK();GRP2diagrm1 o;o.DoModal();}
	if(m_tab.GetCurSel() ==1);
	if(m_tab.GetCurSel() ==2){OnOK();GRP2diagrm3 o;o.DoModal();}
	if(m_tab.GetCurSel() ==3){OnOK();GRP2diagrm4 o;o.DoModal();}
	if(m_tab.GetCurSel() ==4){OnOK();GRP2diagrm5 o;o.DoModal();}
	if(m_tab.GetCurSel() ==5){OnOK();GRP2diagrm6 o;o.DoModal();}

	*pResult = 0;
}

void GRP2diagrm2::OnChangeEDITXgr() {          UpdateData(1); CGRP2Dlg o;o.X_gr(m_X_gr);           UpdateData(0);}
void GRP2diagrm2::OnChangeEDITYgr() {          UpdateData(1); CGRP2Dlg o;o.Y_gr(m_Y_gr);           UpdateData(0);} 
void GRP2diagrm2::OnChangeEDITXgridgr() {      UpdateData(1); CGRP2Dlg o;o.Xgrd_gr(m_Xgrid_gr);    UpdateData(0);}
void GRP2diagrm2::OnChangeEDITYgridgr(){       UpdateData(1); CGRP2Dlg o;o.Ygrd_gr(m_Ygrid_gr);    UpdateData(0);}  
void GRP2diagrm2::OnSelchangeCOMBOXart() {     UpdateData(1); CGRP2Dlg o;o.X_art(m_X_art);         UpdateData(0);}
void GRP2diagrm2::OnSelchangeCOMBOYart() {     UpdateData(1); CGRP2Dlg o;o.Y_art(m_Y_art);         UpdateData(0);}
void GRP2diagrm2::OnSelchangeCOMBOXgridart() { UpdateData(1); CGRP2Dlg o;o.X_gridart(m_Xgrid_art); UpdateData(0);}
void GRP2diagrm2::OnSelchangeCOMBOYgridart() { UpdateData(1); CGRP2Dlg o;o.Y_gridart(m_Ygrid_art); UpdateData(0);}

void GRP2diagrm2::OnDeltaposSPINXgr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)             m_X_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_X_gr>0) m_X_gr-=1;
		                   
	UpdateData(0); OnChangeEDITXgr();
	
	*pResult = 0;
}

void GRP2diagrm2::OnDeltaposSPINYgr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)             m_Y_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_Y_gr>0) m_Y_gr-=1;
		                   
	UpdateData(0); OnChangeEDITYgr();
	
	*pResult = 0;
}

void GRP2diagrm2::OnDeltaposSPINXgridgr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)                 m_Xgrid_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_Xgrid_gr>0) m_Xgrid_gr-=1;
		                   
	UpdateData(0); OnChangeEDITXgridgr();
	
	*pResult = 0;
}

void GRP2diagrm2::OnDeltaposSPINYgridgr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)                 m_Ygrid_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_Ygrid_gr>0) m_Ygrid_gr-=1;
		                   
	UpdateData(0); OnChangeEDITYgridgr();
	
	*pResult = 0;
}

void GRP2diagrm2::OnBUTTONXfb()     {CColorDialog cl(X_clr,0,0);cl.DoModal();X_clr=cl.GetColor();    RedrawWindow();CGRP2Dlg o;o.clr_X(X_clr)       ;}//x achsenfarbe
void GRP2diagrm2::OnBUTTONYfb()     {CColorDialog cl(Y_clr,0,0);cl.DoModal();Y_clr=cl.GetColor();    RedrawWindow();CGRP2Dlg o;o.clr_Y(Y_clr)       ;}//y achsenfarbe
void GRP2diagrm2::OnBUTTONXgridfb() {CColorDialog cl(X_clr,0,0);cl.DoModal();Xgrid_clr=cl.GetColor();RedrawWindow();CGRP2Dlg o;o.clr_Xgrd(Xgrid_clr);}//x gridfarbe
void GRP2diagrm2::OnBUTTONYgridfb() {CColorDialog cl(X_clr,0,0);cl.DoModal();Ygrid_clr=cl.GetColor();RedrawWindow();CGRP2Dlg o;o.clr_Ygrd(Ygrid_clr);}//y gridfarbe

void GRP2diagrm2::OnBUTTONschrx() //x achsenschriftart  
{
	UpdateData(1);
	                     //LOGFONT lfx;
	 CFontDialog f(               &lfx, CF_EFFECTS | CF_SCREENFONTS ,0,0);
				 f.DoModal();
	   schr_x_fn=f.GetFaceName();
	   schr_x_sz=f.GetSize();
	  schr_x_clr=f.GetColor();
				 f.GetCurrentFont(&lfx);
						  schr_x_H=lfx.lfHeight;
						  schr_x_W=lfx.lfWidth;					 
	UpdateData(0);

	CGRP2Dlg o;
	         o.font_Ax(schr_x_fn,
				       schr_x_H,
					   schr_x_W,
					   schr_x_clr
						  );
	RedrawWindow(); 
}

void GRP2diagrm2::OnBUTTONschry() //y achsenschriftart 
{
	UpdateData(1);
	                     //LOGFONT lfy;
	 CFontDialog f(               &lfy, CF_EFFECTS | CF_SCREENFONTS ,0,0);
				 f.DoModal();
	   schr_y_fn=f.GetFaceName();
	   schr_y_sz=f.GetSize();
	  schr_y_clr=f.GetColor();
				 f.GetCurrentFont(&lfy);
						  schr_y_H=lfy.lfHeight;
						  schr_y_W=lfy.lfWidth;					 
	UpdateData(0);

	CGRP2Dlg o;
	         o.font_Ay(schr_y_fn,
				       schr_y_H,
					   schr_y_W,
					   schr_y_clr
						  );
	RedrawWindow(); 	
}

void GRP2diagrm2::OnCHECKx() {UpdateData(1);CGRP2Dlg o;o.X_bez(m_ch_x);UpdateData(0);} //x achsenbezeichnung
void GRP2diagrm2::OnCHECKy() {UpdateData(1);CGRP2Dlg o;o.Y_bez(m_ch_y);UpdateData(0);} //y achsenbezeichnung

void GRP2diagrm2::OnVoreinstellungen() 
{
	UpdateData(1);

	X_clr=       8421504;       //x achsenfarbe
	Y_clr=       8421504;       //y achsenfarbe
	m_X_gr=      1;             //x achsengrösse
	m_Y_gr=      1;             //y achsengrösse
	m_ch_x=      1;             //x achsenbezeichnung(sw)
	m_ch_y=      1;             //y achsenbezeichnung(sw)
	m_Xgrid_gr=  0;             //x grid(sw)
	m_Ygrid_gr=  0;             //y grid(sw)
	schr_x_fn=  "Arial";        //schriftart achsenwerte x
	schr_x_H=    13;            //schriftgrösse H achsenwerte x
	schr_x_W=    4;             //schriftgrösse W achsenwerte x
	schr_x_clr=  8421504;       //schriftfarbe achsenwerte x
	schr_y_fn=  "Arial";        //schriftart achsenwerte y
	schr_y_H=    13;            //schriftgrösse H achsenwerte y
	schr_y_W=    4;             //schriftgrösse W achsenwerte y
	schr_y_clr=  8421504;       //schriftfarbe achsenwerte y
	mod_X=       1;             //x achsenmodus 
	m_X_art=    "Linie";        //x achsenmodus art
	mod_Y=       1;             //y achsenmodus 
	m_Y_art=    "Linie";        //y achsenmodus art
	mod_Xgrd=    2;             //x gridmodus 
	m_Xgrid_art="Punkt";        //x gridmodus art
	mod_Ygrd=    2;             //y gridmodus 
	m_Ygrid_art="Punkt";        //y gridmodus art
	Xgrid_clr=   65793*190;     //x gridfarbe
	Ygrid_clr=   65793*190;     //y gridfarbe

	CGRP2Dlg o;
			 o.clr_X(X_clr);
			 o.clr_Y(Y_clr);
			 o.X_gr(m_X_gr);
			 o.Y_gr(m_Y_gr);
	         o.X_bez(m_ch_x);
			 o.Y_bez(m_ch_y);
             o.Xgrd_gr(m_Xgrid_gr);
             o.Ygrd_gr(m_Ygrid_gr);
	         o.font_Ax(schr_x_fn,
					   schr_x_H,
					   schr_x_W,
					   schr_x_clr
								 );
			 o.font_Ay(schr_y_fn,
					   schr_y_H,
					   schr_y_W,
					   schr_y_clr
								 );
			 o.X_art(m_X_art);
			 o.Y_art(m_Y_art);
			 o.X_gridart(m_Xgrid_art);
			 o.Y_gridart(m_Ygrid_art);
			 o.clr_Xgrd(Xgrid_clr);
		     o.clr_Ygrd(Ygrid_clr);		 
	    
	RedrawWindow();

	UpdateData(0);
	
}

void GRP2diagrm2::OnCHECKini() {UpdateData(1);UpdateData(0);}

void GRP2diagrm2::OnOK() 
{
		                                             CRect coord;
	                                        GetWindowRect(&coord); 
	
	                              CWinApp* pApp = AfxGetApp(); // ini profil schreiben  
	if(m_ch_ini)
	{
										   pApp->WriteProfileInt("Achsen","X_Farbe",X_clr);
										   pApp->WriteProfileInt("Achsen","Y_Farbe",Y_clr);
										   pApp->WriteProfileInt("Achsen","X_Grid_Farbe",Xgrid_clr);
										   pApp->WriteProfileInt("Achsen","Y_Grid_Farbe",Ygrid_clr);
										   pApp->WriteProfileInt("Achsen","X_Linienbreite",m_X_gr);
										   pApp->WriteProfileInt("Achsen","Y_Linienbreite",m_Y_gr);
										   pApp->WriteProfileInt("Achsen","X_Grid_Linienbreite",m_Xgrid_gr);
										   pApp->WriteProfileInt("Achsen","Y_Grid_Linienbreite",m_Ygrid_gr);
										   pApp->WriteProfileInt("Achsen","X_Bezeichnung",m_ch_x);
										   pApp->WriteProfileInt("Achsen","Y_Bezeichnung",m_ch_y);
			                               pApp->WriteProfileString("Schriftart","Achsen_x",schr_x_fn);
									       pApp->WriteProfileString("Schriftart","Achsen_y",schr_y_fn);
									       pApp->WriteProfileInt("Schriftart","Farbe_Achsen_x",schr_x_clr);
									       pApp->WriteProfileInt("Schriftart","Farbe_Achsen_y",schr_y_clr);
									       pApp->WriteProfileInt("Schriftart","Höhe_Achsen_x",schr_x_H);
									       pApp->WriteProfileInt("Schriftart","Höhe_Achsen_y",schr_y_H);
									       pApp->WriteProfileInt("Schriftart","Breite_Achsen_x",schr_x_W);
									       pApp->WriteProfileInt("Schriftart","Breite_Achsen_y",schr_y_W);
		if(m_X_art=="Linie")               pApp->WriteProfileInt("Achsen","X_Modus",1);
		if(m_X_art=="Punkt")               pApp->WriteProfileInt("Achsen","X_Modus",2);
		if(m_X_art=="Strich")              pApp->WriteProfileInt("Achsen","X_Modus",3);
		if(m_X_art=="Strichpunkt")         pApp->WriteProfileInt("Achsen","X_Modus",4);
		if(m_X_art=="Strichdoppelpkt.")    pApp->WriteProfileInt("Achsen","X_Modus",5);
		if(m_Y_art=="Linie")               pApp->WriteProfileInt("Achsen","Y_Modus",1);
		if(m_Y_art=="Punkt")               pApp->WriteProfileInt("Achsen","Y_Modus",2);
		if(m_Y_art=="Strich")              pApp->WriteProfileInt("Achsen","Y_Modus",3);
		if(m_Y_art=="Strichpunkt")         pApp->WriteProfileInt("Achsen","Y_Modus",4);
		if(m_Y_art=="Strichdoppelpkt.")    pApp->WriteProfileInt("Achsen","Y_Modus",5);
		if(m_Xgrid_art=="Linie")           pApp->WriteProfileInt("Achsen","X_Grid_Modus",1);
		if(m_Xgrid_art=="Punkt")           pApp->WriteProfileInt("Achsen","X_Grid_Modus",2);
		if(m_Xgrid_art=="Strich")          pApp->WriteProfileInt("Achsen","X_Grid_Modus",3);
		if(m_Xgrid_art=="Strichpunkt")     pApp->WriteProfileInt("Achsen","X_Grid_Modus",4);
		if(m_Xgrid_art=="Strichdoppelpkt.")pApp->WriteProfileInt("Achsen","X_Grid_Modus",5);
		if(m_Ygrid_art=="Linie")           pApp->WriteProfileInt("Achsen","Y_Grid_Modus",1);
		if(m_Ygrid_art=="Punkt")           pApp->WriteProfileInt("Achsen","Y_Grid_Modus",2);
		if(m_Ygrid_art=="Strich")          pApp->WriteProfileInt("Achsen","Y_Grid_Modus",3);
		if(m_Ygrid_art=="Strichpunkt")     pApp->WriteProfileInt("Achsen","Y_Grid_Modus",4);
		if(m_Ygrid_art=="Strichdoppelpkt.")pApp->WriteProfileInt("Achsen","Y_Grid_Modus",5);
	} 
                                           pApp->WriteProfileInt("INI_schreiben","diagrm2",m_ch_ini);
			                               pApp->WriteProfileInt("Diagramm","Tabelle",2);
			                               pApp->WriteProfileInt("Diagramm","Position_x",coord.left);
			                               pApp->WriteProfileInt("Diagramm","Position_y",coord.top);
	CDialog::OnOK();
}
















