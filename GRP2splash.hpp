//------------------------------------------------------------------------| GRP2splash.hpp                               //
//                                                                        | GRP2, Graphik Dialog 2            (deutsch)  //
//                                                                        | von Dietmar Schrausser, (C) SCHRAUSSER 2011  //              
//


#if !defined(AFX_GRP2SPLASH_HPP__32F19524_5E54_4E99_9D48_C483121C5C70__INCLUDED_)
#define AFX_GRP2SPLASH_HPP__32F19524_5E54_4E99_9D48_C483121C5C70__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class GRP2splash : public CDialog
{
	public:
	GRP2splash(CWnd* pParent = NULL);   

	//{{AFX_DATA(GRP2splash)
	enum { IDD = IDD_GRP2_Splash };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(GRP2splash)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

	protected:
	//{{AFX_MSG(GRP2splash)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
