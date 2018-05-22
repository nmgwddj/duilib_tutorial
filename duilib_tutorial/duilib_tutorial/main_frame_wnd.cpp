#include "stdafx.h"
#include "main_frame_wnd.h"
#include "resource.h"

DUI_BEGIN_MESSAGE_MAP(MainFrameWnd, CNotifyPump)
	DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_END_MESSAGE_MAP()

CDuiString MainFrameWnd::GetSkinFolder()
{
#if _DEBUG
	return _T("theme");
#else
	return m_PaintManager.GetInstancePath();
#endif
}

CDuiString MainFrameWnd::GetSkinFile()
{
	// 成员变量定义的皮肤文件名
	return kMainWndFrame;
}

LPCTSTR MainFrameWnd::GetWindowClassName(void) const
{
	// 成员变量定义的窗口 class name
	return kClassName;
}

DuiLib::UILIB_RESOURCETYPE MainFrameWnd::GetResourceType() const
{
#if _DEBUG
	return UILIB_FILE;
#else
	return UILIB_ZIPRESOURCE;
#endif
}

LPCTSTR MainFrameWnd::GetResourceID() const
{
	return MAKEINTRESOURCE(IDR_ZIPRES1);
}

void MainFrameWnd::InitWindow()
{
	m_pMinBtn = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("minbtn")));
	m_pMaxBtn = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("maxbtn")));
	m_pRestoreBtn = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("restorebtn")));
	m_pCloseBtn = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("closebtn")));

	m_pMainWndList = dynamic_cast<CListUI*>(m_PaintManager.FindControl(_T("main_wnd_list")));

#if 0
	// 使用代码方式创建
	CButtonUI* btn = new CButtonUI;
	btn->SetText(_T("动态添加的按钮"));
	btn->SetBkColor(0xFFFFFFFF);
	btn->SetFixedHeight(60);
	btn->SetFixedWidth(100);

	m_pMainWndContent->Add(btn);
#endif

	CControlUI* pControl = nullptr;
	if (m_pBuilder.GetMarkup()->IsValid())
	{
		pControl = m_pBuilder.Create(this, &m_PaintManager);
	}
	else
	{
		pControl = m_pBuilder.Create(_T("list_item.xml"), (UINT)0, this, &m_PaintManager);
	}
	m_pMainWndList->Add(pControl);
}

void MainFrameWnd::Notify(TNotifyUI& msg)
{
#if 0
	if (msg.sType == DUI_MSGTYPE_CLICK)
	{
		CDuiString strName = msg.pSender->GetName();
		if (strName == _T("btn_wnd_min"))
		{
			SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
		}
	}
#endif

	__super::Notify(msg);
}

void MainFrameWnd::OnClick(TNotifyUI& msg)
{
	CDuiString strName = msg.pSender->GetName();
	if (strName == _T("aboutbtn"))
	{
		if (m_pAboutWndFrame == nullptr)
		{
			m_pAboutWndFrame = new AboutFrameWnd();
			m_pAboutWndFrame->Create(this->GetHWND(), AboutFrameWnd::kClassName, UI_WNDSTYLE_DIALOG, 0);
		}
		m_pAboutWndFrame->CenterWindow();
		m_pAboutWndFrame->ShowWindow();
	}

	__super::OnClick(msg);
}

LRESULT MainFrameWnd::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if (uMsg == WM_CLOSE)
	{
		PostQuitMessage(0L);
	}

	return __super::OnClose(uMsg, wParam, lParam, bHandled);
}

const LPCTSTR MainFrameWnd::kClassName = _T("main_wnd_frame");
const LPCTSTR MainFrameWnd::kMainWndFrame = _T("main_wnd_frame.xml");
