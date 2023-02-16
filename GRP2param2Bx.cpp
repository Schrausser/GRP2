//------------------------------------------------------------------------| GRP2param2Bx.cpp                             //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//


#include "stdafx.h"
#include "grp2.hpp"
#include "GRP2Dlg.hpp"
#include "GRP2param2.hpp"
#include "GRP2param2Bx.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


GRP2param2Bx::GRP2param2Bx(CWnd* pParent )
	: CDialog(GRP2param2Bx::IDD, pParent)
{
	//{{AFX_DATA_INIT(GRP2param2Bx)
	m_Bx = "x";
	//}}AFX_DATA_INIT
}


void GRP2param2Bx::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GRP2param2Bx)
	DDX_Text(pDX, IDC_EDIT_Bx, m_Bx);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(GRP2param2Bx, CDialog)
	//{{AFX_MSG_MAP(GRP2param2Bx)
	ON_BN_CLICKED(IDC_BUTTON_tlgx_reset, OnBUTTONtlgxreset)
	ON_EN_CHANGE(IDC_EDIT_Bx, OnChangeEDITBx)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL GRP2param2Bx::OnInitDialog() 
{
	UpdateData(1);

	             CWinApp*  pApp = AfxGetApp(); // ini profil lesen 
	
				   m_Bx =  pApp->GetProfileString("Achsen","x_Bezeichnung_","x");

	            m_ch_ini=  pApp->GetProfileInt("INI_schreiben","param2",1);
	
	 SetWindowPos(&wndTop, pApp->GetProfileInt("Parameter","Position_x",100)+45,
		                   pApp->GetProfileInt("Parameter","Position_y",100)+80, 200+8,100+27, SWP_NOSIZE);

	UpdateData(0);

	sw=1;
	
	return 1;
}

void GRP2param2Bx::OnChangeEDITBx(){     UpdateData(1);           sw=1; CGRP2Dlg o;o.AxBez_(sw, m_Bx);UpdateData(0);}
void GRP2param2Bx::OnBUTTONtlgxreset() { UpdateData(1);m_Bx = "x";sw=0; CGRP2Dlg o;o.AxBez_(sw, "");  UpdateData(0);}

void GRP2param2Bx::OnOK() 
{
	CGRP2Dlg o;o.AxBez_(sw, m_Bx);
	
	CWinApp* pApp = AfxGetApp(); // ini profil schreiben  

	if(m_ch_ini)
	{
		pApp->WriteProfileString("Achsen","x_Bezeichnung_",m_Bx);
	}


	CDialog::OnOK();
}



