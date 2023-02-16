//------------------------------------------------------------------------| GRP2.cpp                                     //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#include "stdafx.h"
#include "GRP2.hpp"
#include "GRP2Dlg.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CGRP2App, CWinApp)
	//{{AFX_MSG_MAP(CGRP2App)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

CGRP2App::CGRP2App(){}
CGRP2App theApp;


BOOL CGRP2App::InitInstance()
{
	AfxEnableControlContainer();

	#ifdef _AFXDLL
	Enable3dControls();			
	#else
	Enable3dControlsStatic();
	#endif

	if (m_lpCmdLine[0] != '\0'){ CGRP2Dlg o;o.cmdline(m_lpCmdLine); } // command line parser

	       CGRP2Dlg dlg;
	  m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();

	if (nResponse == IDOK){	}
	else if (nResponse == IDCANCEL)	{}

	return 0;
}

int CGRP2App::ExitInstance() 
{
	unlink("~tmp_sort");
	unlink("~~tmp_p.asc");
	unlink("~~tmp_z.asc");
	unlink("~~tmp_in");
	unlink("~~tmp_out");
	
	return CWinApp::ExitInstance();
}
