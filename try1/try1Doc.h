// try1Doc.h : interface of the CTry1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRY1DOC_H__3C9ECAA9_0F03_479E_8767_0B76298D0CBE__INCLUDED_)
#define AFX_TRY1DOC_H__3C9ECAA9_0F03_479E_8767_0B76298D0CBE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTry1Doc : public CDocument
{
protected: // create from serialization only
	CTry1Doc();
	DECLARE_DYNCREATE(CTry1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTry1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTry1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTry1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRY1DOC_H__3C9ECAA9_0F03_479E_8767_0B76298D0CBE__INCLUDED_)
