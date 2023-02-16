//------------------------------------------------------------------------| GRP2Dlg.cpp                                  //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//


#if !defined(AFX_GRP2DLG_H__7C293CF5_09EC_4BCD_95EE_78D6E62BB11D__INCLUDED_)
#define AFX_GRP2DLG_H__7C293CF5_09EC_4BCD_95EE_78D6E62BB11D__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class CAboutDlg : public CDialog
{
	public:
	CAboutDlg();

	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


class CGRP2Dlg : public CDialog
{
	public:
	CGRP2Dlg(CWnd* pParent = NULL);	

	POINT dlg;

	CString filename;
	CString emfname;

	float x_, y_;
	float min_x,max_x, min_y, max_y;
	int swli;

	void CGRP2Dlg::MINMAX(); 
	void CGRP2Dlg::GRP_Diagramm();


	void CGRP2Dlg::x_scala(int x);
	void CGRP2Dlg::y_scala(int y);
	void CGRP2Dlg::x_minmax(int x);
	void CGRP2Dlg::y_minmax(int y);
	void CGRP2Dlg::x_Achse(int x);
	void CGRP2Dlg::y_Achse(int y);
	void CGRP2Dlg::x_Vektor(int x);
	void CGRP2Dlg::y_Vektor(int y);
	void CGRP2Dlg::x_Skala(int x);
	void CGRP2Dlg::y_Skala(int y);
	void CGRP2Dlg::x_Koor(int x);
	void CGRP2Dlg::y_Koor(int y);
	void CGRP2Dlg:: _FnKu(int x);
	void CGRP2Dlg:: _xyPkt(int y);


	//{{AFX_DATA(CGRP2Dlg)
	enum { IDD = IDD_GRP2_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CGRP2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	//}}AFX_VIRTUAL

	protected:
	HICON m_hIcon;

	//{{AFX_MSG(CGRP2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnEinstellungenAnsicht();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnFunktionsmatrixFfnen();
	afx_msg void OnFunktionEmfspeichern();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
