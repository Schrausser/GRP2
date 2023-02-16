//------------------------------------------------------------------------| GRP2diagrm1.cpp                              //
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

GRP2diagrm1::GRP2diagrm1(CWnd* pParent): CDialog(GRP2diagrm1::IDD, pParent)	
{
	//{{AFX_DATA_INIT(GRP2diagrm1)
	m_K_art = "Linie";
	m_P_art = "rund";
	m_K_gr = 1;
	m_P_gr = 1;
	//}}AFX_DATA_INIT
}

void GRP2diagrm1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GRP2diagrm1)
	DDX_Control(pDX, IDC_TAB2, m_tab);
	DDX_CBString(pDX, IDC_COMBO_K_art, m_K_art);
	DDX_CBString(pDX, IDC_COMBO_P_art, m_P_art);
	DDX_Text(pDX, IDC_EDIT_K_gr, m_K_gr);
	DDX_Text(pDX, IDC_EDIT_P_gr, m_P_gr);
	DDX_Check(pDX, IDC_CHECK_ini, m_ch_ini);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(GRP2diagrm1, CDialog)
	//{{AFX_MSG_MAP(GRP2diagrm1)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB2, OnSelchangeTab2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_K_gr, OnDeltaposSPINKgr)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_P_gr, OnDeltaposSPINPgr)
	ON_EN_CHANGE(IDC_EDIT_K_gr, OnChangeEDITKgr)
	ON_EN_CHANGE(IDC_EDIT_P_gr, OnChangeEDITPgr)
	ON_BN_CLICKED(IDC_BUTTON_K_fb, OnBUTTONKfb)
	ON_BN_CLICKED(IDC_BUTTON_P_fb, OnBUTTONPfb)
	ON_BN_CLICKED(IDC_BUTTON_hg_fb, OnBUTTONhgfb)
	ON_BN_CLICKED(IDC_BUTTON_schr_x, OnBUTTONschrx)
	ON_BN_CLICKED(IDC_BUTTON_schr_y, OnBUTTONschry)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_hg, OnBUTTONhg)
	ON_BN_CLICKED(IDC_CHECK_ini, OnCHECKini)
	ON_CBN_SELCHANGE(IDC_COMBO_K_art, OnSelchangeCOMBOKart)
	ON_CBN_SELCHANGE(IDC_COMBO_P_art, OnSelchangeCOMBOPart)
	ON_BN_CLICKED(ID_Voreinstellungen, OnVoreinstellungen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL GRP2diagrm1::OnInitDialog() 
{
	CDialog::OnInitDialog();

	UpdateData(1);

	              CWinApp*  pApp = AfxGetApp(); // ini profil lesen 

				hg_clr=     pApp->GetProfileInt("Diagramm","Hintergrundfarbe",13357270);
				K_clr=      pApp->GetProfileInt("Funktion","Linienfarbe",0);
				P_clr=      pApp->GetProfileInt("Funktion","Punktfarbe",0);
				m_K_gr=     pApp->GetProfileInt("Funktion","Kurvenlinienbreite",1);
				m_P_gr=     pApp->GetProfileInt("Funktion","Punktbreite",2);
				schr_x_fn=  pApp->GetProfileString("Schriftart","Funktion_x","Arial");
	            schr_y_fn=  pApp->GetProfileString("Schriftart","Funktion_y","Arial");
	            schr_x_clr= pApp->GetProfileInt("Schriftart","Farbe_Funktion_x",8421504);
	            schr_y_clr= pApp->GetProfileInt("Schriftart","Farbe_Funktion_y",8421504);
	            schr_x_H=   pApp->GetProfileInt("Schriftart","Höhe_Funktion_x",13);
	            schr_y_H=   pApp->GetProfileInt("Schriftart","Höhe_Funktion_y",13);
	            schr_x_W=   pApp->GetProfileInt("Schriftart","Breite_Funktion_x",4);
	            schr_y_W=   pApp->GetProfileInt("Schriftart","Breite_Funktion_y",4);
				mod_K=      pApp->GetProfileInt("Funktion","Kurvenmodus",1);
             if(mod_K==1)m_K_art="Linie";
			 if(mod_K==2)m_K_art="Punkt";
			 if(mod_K==3)m_K_art="Strich";
			 if(mod_K==4)m_K_art="Strichpunkt";
			 if(mod_K==5)m_K_art="Strichdoppelpkt.";
			    mod_P=      pApp->GetProfileInt("Funktion","Punktmodus",1);
             if(mod_P==1)m_P_art="rund";
			 if(mod_P==2)m_P_art="eckig";
			 if(mod_P==3)m_P_art="Kreuz";

				 m_ch_ini=  pApp->GetProfileInt("INI_schreiben","diagrm1",1);

	SetWindowPos(&wndTop,   pApp->GetProfileInt("Diagramm","Position_x",100),
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
				         
				m_tab.SetCurSel(  0);

		 //LOGFONT lfx; 
	strncpy((char*)lfx.lfFaceName,    schr_x_fn,  sizeof lfx.lfFaceName);
		           lfx.lfFaceName[ sizeof lfx.lfFaceName-1] = 0;
	
		 //LOGFONT lfy; 
	strncpy((char*)lfy.lfFaceName,    schr_y_fn,  sizeof lfy.lfFaceName);
		           lfy.lfFaceName[ sizeof lfy.lfFaceName-1] = 0;

	
	UpdateData(0);

	///////////////////////////// beispiel Struktur objekt
	
	  CGRP2Dlg o1;
	double sm= o1.qX.sum;
	           o1.qX.sum = 3;
			 
    /////////////////////////////
	
	return 1; 	              
}

void GRP2diagrm1::OnPaint() 
{
	CPaintDC ooo(this); 
  
						 CRect o1(125, 223, 183, 237);
			 ooo.FillSolidRect(o1,   hg_clr );        //hintergrundfarbe

			             CRect o2(197, 55, 211, 68);
			 ooo.FillSolidRect(o2,   K_clr );         //Kurvenfarbe

			             CRect o3(197, 83, 211, 96);
			 ooo.FillSolidRect(o3,   P_clr );         //Punktfarbe
			 
						  CFont f1; 
							    f1.CreateFont(12,5,0,0,400,0,0,0,0,OUT_DEFAULT_PRECIS, 
																   CLIP_DEFAULT_PRECIS, 
																   DEFAULT_QUALITY, 
																   DEFAULT_PITCH,
																   schr_x_fn);
			  ooo.SelectObject(&f1);
			  ooo.SetTextColor(schr_x_clr);
			  ooo.SetBkMode(TRANSPARENT);
			  ooo.TextOut(140,  140,    schr_x_fn);   //schriftart x-werte
		
						  CFont f2; 
							    f2.CreateFont(12,5,0,0,400,0,0,0,0,OUT_DEFAULT_PRECIS, 
																   CLIP_DEFAULT_PRECIS, 
																   DEFAULT_QUALITY, 
																   DEFAULT_PITCH,
																   schr_y_fn);
			  ooo.SelectObject(&f2);
			  ooo.SetTextColor(schr_y_clr);
			  ooo.TextOut(140,  163,    schr_y_fn);   //schriftart y-werte
}


void GRP2diagrm1::OnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if(m_tab.GetCurSel() ==0);
	if(m_tab.GetCurSel() ==1){OnOK();GRP2diagrm2 o;o.DoModal();}
	if(m_tab.GetCurSel() ==2){OnOK();GRP2diagrm3 o;o.DoModal();}
	if(m_tab.GetCurSel() ==3){OnOK();GRP2diagrm4 o;o.DoModal();}
	if(m_tab.GetCurSel() ==4){OnOK();GRP2diagrm5 o;o.DoModal();}
	if(m_tab.GetCurSel() ==5){OnOK();GRP2diagrm6 o;o.DoModal();}
	
	*pResult = 0;
}

void GRP2diagrm1::OnChangeEDITKgr() {      UpdateData(1); CGRP2Dlg o;o.K_gr(m_K_gr);   UpdateData(0);}
void GRP2diagrm1::OnChangeEDITPgr() {      UpdateData(1); CGRP2Dlg o;o.P_gr(m_P_gr);   UpdateData(0);} 
void GRP2diagrm1::OnSelchangeCOMBOKart() { UpdateData(1); CGRP2Dlg o;o.K_art(m_K_art); UpdateData(0);}
void GRP2diagrm1::OnSelchangeCOMBOPart() { UpdateData(1); CGRP2Dlg o;o.P_art(m_P_art); UpdateData(0);}

void GRP2diagrm1::OnDeltaposSPINKgr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
		
	if(pNMUpDown->iDelta < 0)             m_K_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_K_gr>0) m_K_gr-=1;
		                   
	UpdateData(0); OnChangeEDITKgr();
	
	*pResult = 0;
}

void GRP2diagrm1::OnDeltaposSPINPgr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(pNMUpDown->iDelta < 0)             m_P_gr+=1;
	if(pNMUpDown->iDelta >=0)if(m_P_gr>0) m_P_gr-=1;
		                   
	UpdateData(0); OnChangeEDITPgr();
	
	*pResult = 0;
}

void GRP2diagrm1::OnBUTTONKfb() {CColorDialog cl(K_clr,0,0); cl.DoModal();K_clr=cl.GetColor(); RedrawWindow();CGRP2Dlg o;o.clr_K(K_clr)  ;}//Kurvenfarbe
void GRP2diagrm1::OnBUTTONPfb() {CColorDialog cl(P_clr,0,0); cl.DoModal();P_clr=cl.GetColor(); RedrawWindow();CGRP2Dlg o;o.clr_P(P_clr)  ;}//Punktfarbe
void GRP2diagrm1::OnBUTTONhgfb(){CColorDialog cl(hg_clr,0,0);cl.DoModal();hg_clr=cl.GetColor();RedrawWindow();CGRP2Dlg o;o.clr_hg(hg_clr);}//hintergrundfarbe 
void GRP2diagrm1::OnBUTTONhg() {                 hg_clr=13357270;                              RedrawWindow();CGRP2Dlg o;o.clr_hg(hg_clr);}//keine Hintergrundfarbe (windowsgrau) 
	         
void GRP2diagrm1::OnBUTTONschrx() // schrift x
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
	         o.fn_font_x(schr_x_fn,
				         schr_x_H,
						 schr_x_W,
						 schr_x_clr
						 );
	RedrawWindow(); 
}

void GRP2diagrm1::OnBUTTONschry() //schrift y
{
	 /*      LOGFONT lf; //explizitdefinition
	                                
    strncpy((char*)lf.lfFaceName,    schr_y_fn,  sizeof lf.lfFaceName);
		           lf.lfFaceName[ sizeof lf.lfFaceName-1] = 0;

	               lf.lfUnderline = (BYTE)0;
				   lf.lfStrikeOut = (BYTE)0;

				   lf.lfHeight = 10;
				   lf.lfWeight = 0;

				   lf.lfItalic =    (BYTE)0;
	*/
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
	         o.fn_font_y(schr_y_fn,
				         schr_y_H,
						 schr_y_W,
						 schr_y_clr
						 );
	RedrawWindow();
}

void GRP2diagrm1::OnVoreinstellungen() 
{
	UpdateData(1);

	hg_clr=     13357270;  //hintergrundfarbe
	K_clr=      0;         //funktionskurvenfarbe
	P_clr=      0;         //xypunktfarbe
	m_K_gr=     1;         //funktionskurvengrösse       
	m_P_gr=     2;         //xypunktgrösse
	schr_x_fn=  "Arial";   //schriftart funktionswerte x
	schr_y_fn=  "Arial";   //schriftart funktionswerte y
	schr_x_clr= 8421504;   //schriftfarbe funktionswerte x
	schr_y_clr= 8421504;   //schriftfarbe funktionswerte y
	schr_x_H=   13;        //schriftgrösse H funktionswerte x
	schr_y_H=   4;        //schriftgrösse H funktionswerte y
	schr_x_W=   0;         //schriftgrösse W funktionswerte x
	schr_y_W=   0;         //schriftgrösse W funktionswerte y
	mod_K=      1;         //funktionskurvenmodus 
	mod_P=      1;         //xypunktmodus
	m_K_art=    "Linie";   //funktionskurvenmodus  art
	m_P_art=    "rund";   //xypunktmodus art

	CGRP2Dlg o;
			 o.clr_hg(hg_clr);
	         o.clr_K(K_clr);
			 o.clr_P(P_clr);
			 o.K_gr(m_K_gr);
			 o.P_gr(m_P_gr);
	         o.fn_font_x(schr_x_fn,
						 schr_x_H,
						 schr_x_W,
						 schr_x_clr
								 );
			 o.fn_font_y(schr_y_fn,
						 schr_y_H,
						 schr_y_W,
						 schr_y_clr
								 );
			 o.K_art(m_K_art);
			 o.P_art(m_P_art);
	    
	RedrawWindow();

	UpdateData(0);
}

void GRP2diagrm1::OnCHECKini() {UpdateData(1);UpdateData(0);}

void GRP2diagrm1::OnOK() 
{
	                                                 CRect coord;
	                                        GetWindowRect(&coord); 
	
	                         CWinApp* pApp = AfxGetApp(); // ini profil schreiben  
	if(m_ch_ini)
	{
									  pApp->WriteProfileInt("Diagramm","Hintergrundfarbe",hg_clr);
									  pApp->WriteProfileInt("Funktion","Linienfarbe",K_clr);
									  pApp->WriteProfileInt("Funktion","Punktfarbe",P_clr);
									  pApp->WriteProfileInt("Funktion","Kurvenlinienbreite",m_K_gr);
									  pApp->WriteProfileInt("Funktion","Punktbreite",m_P_gr);
									  pApp->WriteProfileString("Schriftart","Funktion_x",schr_x_fn);
									  pApp->WriteProfileString("Schriftart","Funktion_y",schr_y_fn);
									  pApp->WriteProfileInt("Schriftart","Farbe_Funktion_x",schr_x_clr);
									  pApp->WriteProfileInt("Schriftart","Farbe_Funktion_y",schr_y_clr);
									  pApp->WriteProfileInt("Schriftart","Höhe_Funktion_x",schr_x_H);
									  pApp->WriteProfileInt("Schriftart","Höhe_Funktion_y",schr_y_H);
									  pApp->WriteProfileInt("Schriftart","Breite_Funktion_x",schr_x_W);
									  pApp->WriteProfileInt("Schriftart","Breite_Funktion_y",schr_y_W);
	   if(m_K_art=="Linie")           pApp->WriteProfileInt("Funktion","Kurvenmodus",1);
	   if(m_K_art=="Punkt")           pApp->WriteProfileInt("Funktion","Kurvenmodus",2);
	   if(m_K_art=="Strich")          pApp->WriteProfileInt("Funktion","Kurvenmodus",3);
	   if(m_K_art=="Strichpunkt")     pApp->WriteProfileInt("Funktion","Kurvenmodus",4);
	   if(m_K_art=="Strichdoppelpkt.")pApp->WriteProfileInt("Funktion","Kurvenmodus",5);
	   if(m_P_art=="rund")            pApp->WriteProfileInt("Funktion","Punktmodus",1);
	   if(m_P_art=="eckig")           pApp->WriteProfileInt("Funktion","Punktmodus",2);
	   if(m_P_art=="Kreuz")           pApp->WriteProfileInt("Funktion","Punktmodus",3);
	}
									  pApp->WriteProfileInt("INI_schreiben","diagrm1",m_ch_ini);
									  pApp->WriteProfileInt("Diagramm","Tabelle",1);
									  pApp->WriteProfileInt("Diagramm","Position_x",coord.left);
									  pApp->WriteProfileInt("Diagramm","Position_y",coord.top);
	CDialog::OnOK();
}






