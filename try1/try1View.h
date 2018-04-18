// try1View.h : interface of the CTry1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRY1VIEW_H__5EC7F7B5_3F59_4FCC_9A9E_255882FF5473__INCLUDED_)
#define AFX_TRY1VIEW_H__5EC7F7B5_3F59_4FCC_9A9E_255882FF5473__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTry1View : public CView
{
protected: // create from serialization only
	CTry1View();
	DECLARE_DYNCREATE(CTry1View)

// Attributes
public:
	CTry1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTry1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTry1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTry1View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in try1View.cpp
inline CTry1Doc* CTry1View::GetDocument()
   { return (CTry1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRY1VIEW_H__5EC7F7B5_3F59_4FCC_9A9E_255882FF5473__INCLUDED_)
