//------------------------------------------------------------------------| GRP2diagrm3.cpp                              //
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

GRP2diagrm3::GRP2diagrm3(CWnd* pParent ): CDialog(GRP2diagrm3::IDD, pParent)
{
	//{{AFX_DATA_INIT(GRP2diagrm3)
	m_X_art = "";
	m_Y_art = "";
	m_X_gr = 1;
	m_Y_gr = 1;
	//}}AFX_DATA_INIT
}

void GRP2diagrm3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GRP2diagrm3)
	DDX_Control(pDX, IDC_TAB2, m_tab);
	DDX_Check(pDX, IDC_CHECK_ini, m_ch_ini);
	DDX_CBString(pDX, IDC_COMBO_X_art, m_X_art);
	DDX_CBString(pDX, IDC_COMBO_Y_art, m_Y_art);
	DDX_Text(pDX, IDC_EDIT_X_gr, m_X_gr);
	DDX_Text(pDX, IDC_EDIT_Y_gr, m_Y_gr);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(GRP2diagrm3, CDialog)
	//{{AFX_MSG_MAP(GRP2diagrm3)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB2, OnSelchangeTab2)
	ON_BN_CLICKED(IDC_CHECK_ini, OnCHECKini)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_X_fb, OnBUTTONXfb)
	ON_BN_CLICKED(IDC_BUTTON_Y_fb, OnBUTTONYfb)
	ON_CBN_SELCHANGE(IDC_COMBO_X_art, OnSelchangeCOMBOXart)
	ON_CBN_SELCHANGE(IDC_COMBO_Y_art, OnSelchangeCOMBOYart)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_X_gr, OnDeltaposSPINXgr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_Y_gr, OnDeltaposSPINYgr)
	ON_EN_CHANGE(IDC_EDIT_X_gr, OnChangeEDITXgr)
	ON_EN_CHANGE(IDC_EDIT_Y_gr, OnChangeEDITYgr)
	ON_BN_CLICKED(IDC_BUTTON_schr_x, OnBUTTONschrx)
	ON_BN_CLICKED(ID_Voreinstellungen, OnVoreinstellungen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL GRP2diagrm3::OnInitDialog() 
{
	CDialog::OnInitDialog();

	UpdateData(1);

	              CWinApp*  pApp = AfxGetApp(); // ini profil lesen 

				Xv_clr=     pApp->GetProfileInt("Achsen","X_Vektor_Farbe",8421504);
				Yv_clr=     pApp->GetProfileInt("Achsen","Y_Vektor_Farbe",8421504);
				m_X_gr=     pApp->GetProfileInt("Achsen","X_Vektor_Linienbreite",1);
			    m_Y_gr=     pApp->GetProfileInt("Achsen","Y_Vektor_Linienbreite",1);
				schr_x_fn=  pApp->GetProfileString("Schriftart","Vektor","Arial");
	            schr_x_clr= pApp->GetProfileInt("Schriftart","Farbe_Vektor",8421504);
	            schr_x_H=   pApp->GetProfileInt("Schriftart","Höhe_Vektor",13);
	            schr_x_W=   pApp->GetProfileInt("Schriftart","Breite_Vektor",4);
				mod_Xv=     pApp->GetProfileInt("Achsen","X_Vektor_Modus",2);
			 if(mod_Xv==1)m_X_art="Linie";
			 if(mod_Xv==2)m_X_art="Punkt";
			 if(mod_Xv==3)m_X_art="Strich";
			 if(mod_Xv==4)m_X_art="Strichpunkt";
			 if(mod_Xv==5)m_X_art="Strichdoppelpkt.";
			    mod_Yv=     pApp->GetProfileInt("Achsen","Y_Vektor_Modus",2);
             if(mod_Yv==1)m_Y_art="Linie";
			 if(mod_Yv==2)m_Y_art="Punkt";
			 if(mod_Yv==3)m_Y_art="Strich";
			 if(mod_Yv==4)m_Y_art="Strichpunkt";
			 if(mod_Yv==5)m_Y_art="Strichdoppelpkt.";

                 m_ch_ini=  pApp->GetProfileInt("INI_schreiben","diagrm3",1);

	  SetWindowPos(&wndTop, pApp->GetProfileInt("Diagramm","Position_x",100),
		                    pApp->GetProfileInt("Diagramm","Position_y",100), 200+8,100+27, SWP_NOSIZE);
	
	                          TC_ITEM o;
	                                  o.mask = TCIF_TEXT;
	 /*CTabCtrl m_tab; */             o.pszText = "Funktion"; 
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
				         
				m_tab.SetCurSel(  2);


		 //LOGFONT lfx; 
	strncpy((char*)lfx.lfFaceName,    schr_x_fn,  sizeof lfx.lfFaceName);
		           lfx.lfFaceName[ sizeof lfx.lfFaceName-1] = 0;
	
	UpdateData(0);
	
	return 1;  	              
}

void GRP2diagrm3::OnPaint() 
{
	CPaintDC ooo(this); 
	                     CRect o2(197, 55, 211, 68);
			 ooo.FillSolidRect(o2,   Xv_clr );       //X_Vektor_Linienfarbe
			
			             CRect o3(197, 83, 211, 96);
			 ooo.FillSolidRect(o3,   Yv_clr );       //Y_Vektor_Linienfarbe

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
}


void GRP2diagrm3::OnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if(m_tab.GetCurSel() ==0){OnOK();GRP2diagrm1 o;o.DoModal();}
	if(m_tab.GetCurSel() ==1){OnOK();GRP2diagrm2 o;o.DoModal();}
	if(m_tab.GetCurSel() ==2);
	if(m_tab.GetCurSel() ==3){OnOK();GRP2diagrm4 o;o.DoModal();}
	if(m_tab.GetCurSel() ==4){OnOK();GRP2diagrm5 o;o.DoModal();}
	if(m_tab.GetCurSel() ==5){OnOK();GRP2diagrm6 o;o.DoModal();}

	*pResult = 0;
}

void GRP2diagrm3::OnChangeEDITXgr() {      UpdateData(1); CGRP2Dlg o;o.Xv_gr(m_X_gr);  UpdateData(0);}
void GRP2diagrm3::OnChangeEDITYgr() {      UpdateData(1); CGRP2Dlg o;o.Yv_gr(m_Y_gr);  UpdateData(0);} 
void GRP2diagrm3::OnSelchangeCOMBOXart() { UpdateData(1); CGRP2Dlg o;o.Xv_art(m_X_art);UpdateData(0);}
void GRP2diagrm3::OnSelchangeCOMBOYart() { UpdateData(1); CGRP2Dlg o;o.Yv_art(m_Y_art);UpdateData(0);}

void GRP2diagrm3::OnDeltaposSPINXgr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)             m_X_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_X_gr>0) m_X_gr-=1;
		                   
	UpdateData(0); OnChangeEDITXgr();
	
	*pResult = 0;
}

void GRP2diagrm3::OnDeltaposSPINYgr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)             m_Y_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_Y_gr>0) m_Y_gr-=1;
		                   
	UpdateData(0); OnChangeEDITYgr();
	
	*pResult = 0;
}

void GRP2diagrm3::OnBUTTONXfb(){CColorDialog cl(Xv_clr,0,0);cl.DoModal();Xv_clr=cl.GetColor();RedrawWindow();CGRP2Dlg o; o.clr_Xv(Xv_clr);}//x vektorfarbe
void GRP2diagrm3::OnBUTTONYfb(){CColorDialog cl(Yv_clr,0,0);cl.DoModal();Yv_clr=cl.GetColor();RedrawWindow();CGRP2Dlg o; o.clr_Yv(Yv_clr);}//y vektorfarbe

void GRP2diagrm3::OnBUTTONschrx() 
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
	         o.font_V(schr_x_fn,
				      schr_x_H,
				      schr_x_W,
					  schr_x_clr
						  );
	RedrawWindow(); 
}

void GRP2diagrm3::OnVoreinstellungen() 
{
	UpdateData(1);

	Xv_clr=     8421504; //x vektorfarbe
	Yv_clr=     8421504; //y vektorfarbe
	m_X_gr=     1;       //x vektorgrösse
	m_Y_gr=     1;       //y vektorgrösse
	schr_x_fn= "Arial";  //koordinatenschriftart
	schr_x_H=   13;      //koordinatenschriftgrösse H
	schr_x_W=   4;       //koordinatenschriftgrösse W
	schr_x_clr= 8421504; //koordinatenschriftfarbe
	mod_Xv=     2;       //x vektormodus
	m_X_art=   "Punkt";  //x vektormodus art
	mod_Yv=     2;       //y vektormodus
	m_Y_art=   "Punkt";  //y vektormodus art

	CGRP2Dlg o;
			 o.clr_Xv(Xv_clr);
			 o.clr_Yv(Yv_clr);
	         o.Xv_gr(m_X_gr);
			 o.Yv_gr(m_Y_gr);
	         o.font_V(schr_x_fn,
					  schr_x_H,
					  schr_x_W,
					  schr_x_clr
					            );
			 o.Xv_art(m_X_art);
			 o.Yv_art(m_Y_art);
	    
	RedrawWindow();

	UpdateData(0);	
}

void GRP2diagrm3::OnCHECKini() {UpdateData(1);UpdateData(0);}

void GRP2diagrm3::OnOK() 
{
		                                             CRect coord;
	                                        GetWindowRect(&coord); 
	
	                          CWinApp* pApp = AfxGetApp(); // ini profil schreiben  
	if(m_ch_ini)
	{
			                           pApp->WriteProfileInt("Achsen","X_Vektor_Farbe",Xv_clr);
			                           pApp->WriteProfileInt("Achsen","Y_Vektor_Farbe",Yv_clr);
			                           pApp->WriteProfileInt("Achsen","X_Vektor_Linienbreite",m_X_gr);
			                           pApp->WriteProfileInt("Achsen","Y_Vektor_Linienbreite",m_Y_gr);
			                           pApp->WriteProfileString("Schriftart","Vektor",schr_x_fn);
									   pApp->WriteProfileInt("Schriftart","Farbe_Vektor",schr_x_clr);
									   pApp->WriteProfileInt("Schriftart","Höhe_Vektor",schr_x_H);
									   pApp->WriteProfileInt("Schriftart","Breite_Vektor",schr_x_W);
		if(m_X_art=="Linie")           pApp->WriteProfileInt("Achsen","X_Vektor_Modus",1);
		if(m_X_art=="Punkt")           pApp->WriteProfileInt("Achsen","X_Vektor_Modus",2);
		if(m_X_art=="Strich")          pApp->WriteProfileInt("Achsen","X_Vektor_Modus",3);
		if(m_X_art=="Strichpunkt")     pApp->WriteProfileInt("Achsen","X_Vektor_Modus",4);
		if(m_X_art=="Strichdoppelpkt.")pApp->WriteProfileInt("Achsen","X_Vektor_Modus",5);
		if(m_Y_art=="Linie")           pApp->WriteProfileInt("Achsen","Y_Vektor_Modus",1);
		if(m_Y_art=="Punkt")           pApp->WriteProfileInt("Achsen","Y_Vektor_Modus",2);
		if(m_Y_art=="Strich")          pApp->WriteProfileInt("Achsen","Y_Vektor_Modus",3);
		if(m_Y_art=="Strichpunkt")     pApp->WriteProfileInt("Achsen","Y_Vektor_Modus",4);
		if(m_Y_art=="Strichdoppelpkt.")pApp->WriteProfileInt("Achsen","Y_Vektor_Modus",5);
	}
	                                   pApp->WriteProfileInt("INI_schreiben","diagrm3",m_ch_ini);
			                           pApp->WriteProfileInt("Diagramm","Tabelle",3);
			                           pApp->WriteProfileInt("Diagramm","Position_x",coord.left);
			                           pApp->WriteProfileInt("Diagramm","Position_y",coord.top);
	CDialog::OnOK();
}





