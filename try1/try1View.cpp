// try1View.cpp : implementation of the CTry1View class
//

#include "stdafx.h"
#include "try1.h"

#include "try1Doc.h"
#include "try1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTry1View

IMPLEMENT_DYNCREATE(CTry1View, CView)

BEGIN_MESSAGE_MAP(CTry1View, CView)
	//{{AFX_MSG_MAP(CTry1View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTry1View construction/destruction

	int x1,x2,x;
	float k,y;
CTry1View::CTry1View()
{
	x1=100;
	x2=400;
	y=100;
	k=0.4;
	// TODO: add construction code here

}

CTry1View::~CTry1View()
{
}

BOOL CTry1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTry1View drawing

void CTry1View::OnDraw(CDC* pDC)
{
	CTry1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	for (x=x1;x¡Üx2;x++)
	{ 
			drawpixel(x,int(y+0.5),color);
			pDC->SetPixel(x,int(y+0.5),RGB(0,0,255));
  	          	y=y+k;
	} 

}

/////////////////////////////////////////////////////////////////////////////
// CTry1View printing

BOOL CTry1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTry1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTry1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTry1View diagnostics

#ifdef _DEBUG
void CTry1View::AssertValid() const
{
	CView::AssertValid();
}

void CTry1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTry1Doc* CTry1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTry1Doc)));
	return (CTry1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTry1View message handlers
