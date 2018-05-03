#include "stdafx.h"
#include "MainWndFrame.h"
#include "resource.h"

DUI_BEGIN_MESSAGE_MAP(MainWndFrame, CNotifyPump)
	DUI_ON_MSGTYPE(DUI_MSGTYPE_CLICK, OnClick)
DUI_END_MESSAGE_MAP()

DuiLib::CDuiString MainWndFrame::GetSkinFolder()
{
#if _DEBUG
	return _T("theme");
#else
	return m_PaintManager.GetInstancePath();
#endif
}

DuiLib::CDuiString MainWndFrame::GetSkinFile()
{
	// 成员变量定义的皮肤文件名
	return kMainWndFrame;
}

LPCTSTR MainWndFrame::GetWindowClassName(void) const
{
	// 成员变量定义的窗口 class name
	return kClassName;
}

DuiLib::UILIB_RESOURCETYPE MainWndFrame::GetResourceType() const
{
#if _DEBUG
	return UILIB_FILE;
#else
	return UILIB_ZIPRESOURCE;
#endif
}

LPCTSTR MainWndFrame::GetResourceID() const
{
	return MAKEINTRESOURCE(IDR_ZIPRES1);
}

void MainWndFrame::InitWindow()
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

void MainWndFrame::Notify(TNotifyUI& msg)
{
	if (msg.sType == DUI_MSGTYPE_CLICK)
	{
		CDuiString strName = msg.pSender->GetName();
		if (strName == _T("btn_wnd_min"))
		{
			SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
		}
	}

	__super::Notify(msg);
}

LRESULT MainWndFrame::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if (uMsg == WM_CLOSE)
	{
		PostQuitMessage(0L);
	}

	return __super::OnClose(uMsg, wParam, lParam, bHandled);
}

const LPCTSTR MainWndFrame::kClassName = _T("main_wnd_frame");
const LPCTSTR MainWndFrame::kMainWndFrame = _T("main_wnd_frame.xml");
