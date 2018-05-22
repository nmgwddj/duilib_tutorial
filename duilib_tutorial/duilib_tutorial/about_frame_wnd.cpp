#include "stdafx.h"
#include "about_frame_wnd.h"
#include "Resource.h"

DuiLib::CDuiString AboutFrameWnd::GetSkinFolder()
{
#if _DEBUG
	return _T("theme");
#else
	return m_PaintManager.GetInstancePath();
#endif
}

DuiLib::CDuiString AboutFrameWnd::GetSkinFile()
{
	return kAboutWndFrame;
}

LPCTSTR AboutFrameWnd::GetWindowClassName(void) const
{
	return kClassName;
}

DuiLib::UILIB_RESOURCETYPE AboutFrameWnd::GetResourceType() const
{
#if _DEBUG
	return UILIB_FILE;
#else
	return UILIB_ZIPRESOURCE;
#endif
}

LPCTSTR AboutFrameWnd::GetResourceID() const
{
	return MAKEINTRESOURCE(IDR_ZIPRES1);
}

void AboutFrameWnd::InitWindow()
{
	m_pCloseBtn = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("btn_close")));
}

void AboutFrameWnd::Notify(TNotifyUI& msg)
{
	if (msg.sType == DUI_MSGTYPE_CLICK)
	{
		CDuiString strName = msg.pSender->GetName();
		if (strName == _T("btn_close"))
		{
			HWND hWndParent = GetWindowOwner(m_hWnd);
			if (hWndParent)
			{
				::EnableWindow(hWndParent, TRUE);
				::SetFocus(hWndParent);
			}
			ShowWindow(false);
		}
	}
}

const LPCTSTR AboutFrameWnd::kClassName = _T("about_wnd_frame");
const LPCTSTR AboutFrameWnd::kAboutWndFrame = _T("about_wnd_frame.xml");
