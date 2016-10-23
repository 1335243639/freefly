// Menu.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "resource.h"

class CMyFrameWnd : public CFrameWnd
{
	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
END_MESSAGE_MAP()

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