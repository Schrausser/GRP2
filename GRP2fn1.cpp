//------------------------------------------------------------------------| GRP2fn1.cpp                                  //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//

#include "stdafx.h"
#include "grp2.hpp"
#include "GRP2Dlg.hpp"
#include "GRP2fn1.hpp"
#include "GRP2fn2.hpp"
#include "GRP2fn3.hpp"
#include "GRP2fn4.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

GRP2fn1::GRP2fn1(CWnd* pParent ): CDialog(GRP2fn1::IDD, pParent)
{
	//{{AFX_DATA_INIT(GRP2fn1)
	m_diff_n =  1;
	m_int_n =   1;
	m_ch_diff = 0;
	m_ch_int =  0;
	m_ch_mtlg = 0;
	m_ch_nwtn = 0;
	m_ch_qspl = 0;
	m_mtlg_i =  1;
	//}}AFX_DATA_INIT
}

void GRP2fn1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GRP2fn1)
	DDX_Control(pDX, IDC_EDIT_mtlg_i, m_mtlg_ctr);
	DDX_Control(pDX, IDC_EDIT_int_n, m_int_ctr);
	DDX_Control(pDX, IDC_EDIT_diff_n, m_diff_ctr);
	DDX_Control(pDX, IDC_TAB2, m_tab);
	DDX_Check(pDX, IDC_CHECK_ini, m_ch_ini);
	DDX_Text(pDX, IDC_EDIT_diff_n, m_diff_n);
	DDV_MinMaxInt(pDX, m_diff_n, 1, 100);
	DDX_Text(pDX, IDC_EDIT_int_n, m_int_n);
	DDV_MinMaxInt(pDX, m_int_n, 1, 100);
	DDX_Check(pDX, IDC_CHECK_diff, m_ch_diff);
	DDX_Check(pDX, IDC_CHECK_int, m_ch_int);
	DDX_Check(pDX, IDC_CHECK_mtlg, m_ch_mtlg);
	DDX_Check(pDX, IDC_CHECK_nwtn, m_ch_nwtn);
	DDX_Check(pDX, IDC_CHECK_qspl, m_ch_qspl);
	DDX_Text(pDX, IDC_EDIT_mtlg_i, m_mtlg_i);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(GRP2fn1, CDialog)
	//{{AFX_MSG_MAP(GRP2fn1)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB2, OnSelchangeTab2)
	ON_BN_CLICKED(IDC_CHECK_ini, OnCHECKini)
	ON_BN_CLICKED(ID_Voreinstellungen, OnVoreinstellungen)
	ON_BN_CLICKED(IDC_CHECK_diff, OnCHECKdiff)
	ON_BN_CLICKED(IDC_CHECK_int, OnCHECKint)
	ON_BN_CLICKED(IDC_CHECK_mtlg, OnCHECKmtlg)
	ON_BN_CLICKED(IDC_CHECK_nwtn, OnCHECKnwtn)
	ON_BN_CLICKED(IDC_CHECK_qspl, OnCHECKqspl)
	ON_EN_CHANGE(IDC_EDIT_diff_n, OnChangeEDITdiffn)
	ON_EN_CHANGE(IDC_EDIT_int_n, OnChangeEDITintn)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_diff_n, OnDeltaposSPINdiffn)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_int_n, OnDeltaposSPINintn)
	ON_EN_CHANGE(IDC_EDIT_mtlg_i, OnChangeEDITmtlgi)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_mtlg_i, OnDeltaposSPINmtlgi)
	ON_BN_CLICKED(ID_FXY, OnFxy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL GRP2fn1::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	UpdateData(1);

		        CWinApp*  pApp = AfxGetApp(); // ini profil lesen 

			   m_ch_ini=  pApp->GetProfileInt("INI_schreiben","fn1",1);

	SetWindowPos(&wndTop, pApp->GetProfileInt("Funktion","Position_x",100),
		                  pApp->GetProfileInt("Funktion","Position_y",100), 200+8,100+27, SWP_NOSIZE);

	                          TC_ITEM o;
	                                  o.mask = TCIF_TEXT;
	/*CTabCtrl	m_tab;*/              o.pszText = "f(x)"; 
				m_tab.InsertItem( 0, &o );   
				                      o.pszText = "r(x,y)";
				m_tab.InsertItem( 1, &o );
				                      o.pszText = "F(p)";
				m_tab.InsertItem( 2, &o );
				                      o.pszText = "F(e)";
				m_tab.InsertItem( 3, &o );
				         
				m_tab.SetCurSel(  0);

	UpdateData(0);
	
	return 1;              
}

void GRP2fn1::OnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if(m_tab.GetCurSel() ==0);
	if(m_tab.GetCurSel() ==1){OnOK();GRP2fn2 o;o.DoModal();}
	if(m_tab.GetCurSel() ==2){OnOK();GRP2fn3 o;o.DoModal();}
	if(m_tab.GetCurSel() ==3){OnOK();GRP2fn4 o;o.DoModal();}
	
	*pResult = 0;
}

void GRP2fn1::OnCHECKdiff(){ UpdateData(1);m_ch_int =0;m_diff_ctr.SetReadOnly(!m_ch_diff);
                                                        m_int_ctr.SetReadOnly(1);
														if(m_ch_diff ){CGRP2Dlg o;o.diff_sw(m_diff_n );}
														if(!m_ch_diff){CGRP2Dlg o;o.diff_sw(0)        ;}  UpdateData(0);}
void GRP2fn1::OnCHECKint(){  UpdateData(1);m_ch_diff=0; m_int_ctr.SetReadOnly(!m_ch_int);
                                                       m_diff_ctr.SetReadOnly(1);        
													    if(m_ch_int ){CGRP2Dlg o;o.int_sw( m_int_n  ) ;}
														if(!m_ch_int){CGRP2Dlg o;o.int_sw( 0)         ;}  UpdateData(0);}
void GRP2fn1::OnCHECKmtlg() {UpdateData(1);m_ch_nwtn=0;m_ch_qspl=0;
                                                        m_mtlg_ctr.SetReadOnly(!m_ch_mtlg);
													if(m_ch_mtlg ){CGRP2Dlg o;o.kgl_sw(m_mtlg_i )     ;}
													if(!m_ch_mtlg){CGRP2Dlg o;o.kgl_sw(0)             ;}  UpdateData(0);}

void GRP2fn1::OnCHECKnwtn() {UpdateData(1);m_ch_mtlg=0;            m_ch_qspl=0;UpdateData(0);}
void GRP2fn1::OnCHECKqspl() {UpdateData(1);m_ch_mtlg=0;m_ch_nwtn=0;            UpdateData(0);}

void GRP2fn1::OnChangeEDITdiffn() {UpdateData(1);CGRP2Dlg o;o.diff_sw(m_diff_n );UpdateData(0);}

void GRP2fn1::OnChangeEDITintn() {UpdateData(1);CGRP2Dlg o;o.int_sw( m_int_n  );UpdateData(0);}

void GRP2fn1::OnChangeEDITmtlgi(){UpdateData(1);CGRP2Dlg o;o.kgl_sw( m_mtlg_i  );UpdateData(0);} 

void GRP2fn1::OnDeltaposSPINdiffn(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	
	if(m_ch_diff)
	{
		if(pNMUpDown->iDelta < 0)if(m_diff_n<100)  m_diff_n+=1;
		if(pNMUpDown->iDelta >=0)if(m_diff_n>1)    m_diff_n-=1;
								   
		UpdateData(0); OnChangeEDITdiffn();
	}
	
	*pResult = 0;
}

void GRP2fn1::OnDeltaposSPINintn(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(m_ch_int)
	{
		if(pNMUpDown->iDelta < 0)if(m_int_n<100)  m_int_n+=1;
		if(pNMUpDown->iDelta >=0)if(m_int_n>1)    m_int_n-=1;
								   
		UpdateData(0); OnChangeEDITintn();
	}
	
	*pResult = 0;
}

void GRP2fn1::OnDeltaposSPINmtlgi(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	if(m_ch_mtlg)
	{
		if(pNMUpDown->iDelta < 0)if(m_mtlg_i<100)  m_mtlg_i+=1;
		if(pNMUpDown->iDelta >=0)if(m_mtlg_i>1)    m_mtlg_i-=1;
								   
		UpdateData(0); OnChangeEDITmtlgi();
	}
	
	*pResult = 0;
}

void GRP2fn1::OnFxy() {UpdateData(1);CGRP2Dlg o;o.fxy_sw( );UpdateData(0);}//funktionsmatrix neu setzen

void GRP2fn1::OnCHECKini() {UpdateData(1);UpdateData(0);}

void GRP2fn1::OnVoreinstellungen() 
{
	UpdateData(1);

	m_diff_n =  1;
	m_int_n =   1;
	m_ch_diff = 0;
	m_ch_int =  0;
	m_ch_mtlg = 0;
	m_ch_nwtn = 0;
	m_ch_qspl = 0;
	m_mtlg_i =  1;

	 m_int_ctr.SetReadOnly(1); 
	m_diff_ctr.SetReadOnly(1); 
	m_mtlg_ctr.SetReadOnly(1);

	CGRP2Dlg o;
	         o.int_sw( 0);
             
	UpdateData(0);	
}


void GRP2fn1::OnOK() 
{
	    CGRP2Dlg o;
	//if(m_ch_int )o.int_sw( m_int_n  );//integralfunktion
	//if(m_ch_diff)o.diff_sw(m_diff_n );//differentialfunktion

			                                         CRect coord;
	                                        GetWindowRect(&coord); 
	
	CWinApp* pApp = AfxGetApp(); // ini profil schreiben  
	
	if(m_ch_ini)
	{

	}
	         pApp->WriteProfileInt("INI_schreiben","fn1",m_ch_ini);
			 pApp->WriteProfileInt("Funktion","Tabelle",1);
			 pApp->WriteProfileInt("Funktion","Position_x",coord.left);
			 pApp->WriteProfileInt("Funktion","Position_y",coord.top);

	CDialog::OnOK();
}



