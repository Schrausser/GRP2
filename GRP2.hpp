//------------------------------------------------------------------------| GRP2.hpp                                     //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#if !defined(AFX_GRP2_H__C3C3E02E_A033_412B_B7B7_D3D3C4331F0D__INCLUDED_)
#define AFX_GRP2_H__C3C3E02E_A033_412B_B7B7_D3D3C4331F0D__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

#ifndef __AFXWIN_H__
#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		


class CGRP2App : public CWinApp
{
	public:
	CGRP2App();

	//{{AFX_VIRTUAL(CGRP2App)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CGRP2App)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


//{{AFX_INSERT_LOCATION}}

#endif 
