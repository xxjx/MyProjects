// try1Doc.cpp : implementation of the CTry1Doc class
//

#include "stdafx.h"
#include "try1.h"

#include "try1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTry1Doc

IMPLEMENT_DYNCREATE(CTry1Doc, CDocument)

BEGIN_MESSAGE_MAP(CTry1Doc, CDocument)
	//{{AFX_MSG_MAP(CTry1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTry1Doc construction/destruction

CTry1Doc::CTry1Doc()
{
	// TODO: add one-time construction code here

}

CTry1Doc::~CTry1Doc()
{
}

BOOL CTry1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTry1Doc serialization

void CTry1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTry1Doc diagnostics

#ifdef _DEBUG
void CTry1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTry1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTry1Doc commands
