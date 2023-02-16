//------------------------------------------------------------------------| GRP2splash.cpp                               //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#include "stdafx.h"
#include "grp2.hpp"
#include "GRP2splash.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


GRP2splash::GRP2splash(CWnd* pParent )
	: CDialog(GRP2splash::IDD, pParent)
{
	//{{AFX_DATA_INIT(GRP2splash)
	//}}AFX_DATA_INIT
}

void GRP2splash::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GRP2splash)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(GRP2splash, CDialog)
	//{{AFX_MSG_MAP(GRP2splash)
	ON_WM_TIMER()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL GRP2splash::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	SetTimer(0,2000,0);
	
	return 1; 
}

void GRP2splash::OnPaint() 
{
	CPaintDC ooo(this); 





	
}


void GRP2splash::OnTimer(UINT nIDEvent) 
{
	CDialog::OnCancel();
	CDialog::OnTimer(nIDEvent);
}

