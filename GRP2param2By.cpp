//------------------------------------------------------------------------| GRP2param2Bx.cpp                             //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#include "stdafx.h"
#include "grp2.hpp"
#include "GRP2Dlg.hpp"
#include "GRP2param2.hpp"
#include "GRP2param2By.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


GRP2param2By::GRP2param2By(CWnd* pParent /*=NULL*/)
	: CDialog(GRP2param2By::IDD, pParent)
{
	//{{AFX_DATA_INIT(GRP2param2By)
	m_By = "y";
	//}}AFX_DATA_INIT
}


void GRP2param2By::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GRP2param2By)
	DDX_Text(pDX, IDC_EDIT_Bx, m_By);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(GRP2param2By, CDialog)
	//{{AFX_MSG_MAP(GRP2param2By)
	ON_BN_CLICKED(IDC_BUTTON_tlgx_reset, OnBUTTONtlgxreset)
	ON_EN_CHANGE(IDC_EDIT_Bx, OnChangeEDITBx)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL GRP2param2By::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	             CWinApp*  pApp = AfxGetApp(); // ini profil lesen 
	
				   m_By =  pApp->GetProfileString("Achsen","y_Bezeichnung_","y");
			
	            m_ch_ini=  pApp->GetProfileInt("INI_schreiben","param2",1);
	
	 SetWindowPos(&wndTop, pApp->GetProfileInt("Parameter","Position_x",100)+145,
		                   pApp->GetProfileInt("Parameter","Position_y",100)+80, 200+8,100+27, SWP_NOSIZE);

	UpdateData(0);

	sw=1;

	return 1;  
}

void GRP2param2By::OnChangeEDITBx() {   UpdateData(1);           sw=1;CGRP2Dlg o;o.AyBez_(sw, m_By);UpdateData(0);}
void GRP2param2By::OnBUTTONtlgxreset(){ UpdateData(1);m_By = "y";sw=0;CGRP2Dlg o;o.AyBez_(sw, "");  UpdateData(0);}

void GRP2param2By::OnOK() 
{
	CGRP2Dlg o;o.AyBez_(sw, m_By);

	CWinApp* pApp = AfxGetApp(); // ini profil schreiben  

	if(m_ch_ini)
	{
		pApp->WriteProfileString("Achsen","y_Bezeichnung_",m_By);
	}

	CDialog::OnOK();
}

	             
