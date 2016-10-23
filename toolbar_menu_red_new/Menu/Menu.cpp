// Menu.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "resource.h"

class CMyFrameWnd : public CFrameWnd
{
	DECLARE_MESSAGE_MAP()
public:
	CToolBar toolbar;
public:
	afx_msg int OnCreate(LPCREATESTRUCT pCreateStruct);
	afx_msg void OnNew();
};
BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_NEW, OnNew)
END_MESSAGE_MAP()

void CMyFrameWnd::OnNew()
{
	AfxMessageBox("新建被点击");
}

int CMyFrameWnd::OnCreate(LPCREATESTRUCT pCreateStruct)
{
	toolbar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD|WS_VISIBLE|CBRS_ALIGN_TOP);
	toolbar.LoadToolBar(IDR_TOOLBAR);
	return CFrameWnd::OnCreate(pCreateStruct);
}

class CMyWinApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

CMyWinApp theApp;
BOOL CMyWinApp::InitInstance()
{
	CMyFrameWnd *pFrame = new CMyFrameWnd;
	pFrame->Create(NULL, "Toolbar", WS_OVERLAPPEDWINDOW, CFrameWnd::rectDefault, NULL, MAKEINTRESOURCE(IDR_MENU));
	m_pMainWnd = pFrame;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}