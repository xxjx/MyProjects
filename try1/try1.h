// try1.h : main header file for the TRY1 application
//

#if !defined(AFX_TRY1_H__6FEDD5BA_6679_4EB7_9FD5_9079A03A9C8A__INCLUDED_)
#define AFX_TRY1_H__6FEDD5BA_6679_4EB7_9FD5_9079A03A9C8A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTry1App:
// See try1.cpp for the implementation of this class
//

class CTry1App : public CWinApp
{
public:
	CTry1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTry1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTry1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRY1_H__6FEDD5BA_6679_4EB7_9FD5_9079A03A9C8A__INCLUDED_)
