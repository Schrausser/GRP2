//------------------------------------------------------------------------| GRP2param5.cpp                               //
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

GRP2param5::GRP2param5(CWnd* pParent )
	: CDialog(GRP2param5::IDD, pParent)
{
	//{{AFX_DATA_INIT(GRP2param5)
	m_emfx = "25";
	m_emfy = "30";
	m_ch_ini = 1;
	m_file = "";
	//}}AFX_DATA_INIT
}

void GRP2param5::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GRP2param5)
	DDX_Control(pDX, IDC_TAB, m_tab);
	DDX_CBString(pDX, IDC_COMBO_emfx, m_emfx);
	DDX_CBString(pDX, IDC_COMBO_emfy, m_emfy);
	DDX_Check(pDX, IDC_CHECK_ini, m_ch_ini);
	DDX_Text(pDX, IDC_EDIT_emf_file, m_file);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(GRP2param5, CDialog)
	//{{AFX_MSG_MAP(GRP2param5)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, OnSelchangeTab)
	ON_BN_CLICKED(IDC_CHECK_ini, OnCHECKini)
	ON_BN_CLICKED(ID_Voreinstellungen, OnVoreinstellungen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL GRP2param5::OnInitDialog() 
{
	CDialog::OnInitDialog();

	UpdateData(1);

	            CWinApp*  pApp = AfxGetApp(); // ini profil lesen 
	
	            m_emfx=   pApp->GetProfileString("Dialog","Emf_Skalierung_x","25");
	            m_emfy=   pApp->GetProfileString("Dialog","Emf_Skalierung_y","30");
	            m_file=   pApp->GetProfileString("EMF","Dateiname","GRP_Diagramm_");
		
	           m_ch_ini=  pApp->GetProfileInt("INI_schreiben","param5",1);
	
	SetWindowPos(&wndTop, pApp->GetProfileInt("Parameter","Position_x",100),
		                  pApp->GetProfileInt("Parameter","Position_y",100), 200+8,100+27, SWP_NOSIZE);

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

				m_tab.SetCurSel(  4);

	UpdateData(0);
	
	return 1;  
}

void GRP2param5::OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if(m_tab.GetCurSel() ==0){OnOK();GRP2param1 o;o.DoModal();}
	if(m_tab.GetCurSel() ==1){OnOK();GRP2param2 o;o.DoModal();}
	if(m_tab.GetCurSel() ==2){OnOK();GRP2param3 o;o.DoModal();}
	if(m_tab.GetCurSel() ==3){OnOK();GRP2param4 o;o.DoModal();}
	if(m_tab.GetCurSel() ==4);
	
	*pResult = 0;
}

void GRP2param5::OnCHECKini() {UpdateData(1);UpdateData(0);}

void GRP2param5::OnVoreinstellungen() 
{
	UpdateData(1);

	m_emfx=   "25"; //Emf_Skalierung_x
	m_emfy=   "30"; //Emf_Skalierung_y
	m_file= "GRP_Diagramm_"; //Emf Dateiname

	UpdateData(0);	
}


void GRP2param5::OnOK() 
{
	UpdateData(1);

	CGRP2Dlg o; o.x_emf(m_emfx);
	            o.y_emf(m_emfy);
				 
	UpdateData(1);
	                                                  CRect coord;
	                                         GetWindowRect(&coord); 
	
	CWinApp* pApp = AfxGetApp(); // ini profil schreiben  

	if(m_ch_ini)
	{
			 pApp->WriteProfileString("Dialog","Emf_Skalierung_x",m_emfx);
			 pApp->WriteProfileString("Dialog","Emf_Skalierung_y",m_emfy);
	}
			 pApp->WriteProfileString("EMF","Dateiname",m_file);
			 pApp->WriteProfileInt("INI_schreiben","param5",m_ch_ini);
			 pApp->WriteProfileInt("Parameter","Tabelle",5);
	         pApp->WriteProfileInt("Parameter","Position_x",coord.left);
			 pApp->WriteProfileInt("Parameter","Position_y",coord.top);
	
	CDialog::OnOK();
}





