#include "stdafx.h"
#include "AboutWndFrame.h"
#include "Resource.h"

DuiLib::CDuiString AboutWndFrame::GetSkinFolder()
{
#if _DEBUG
	return _T("theme");
#else
	return m_PaintManager.GetInstancePath();
#endif
}

DuiLib::CDuiString AboutWndFrame::GetSkinFile()
{
	return kAboutWndFrame;
}

LPCTSTR AboutWndFrame::GetWindowClassName(void) const
{
	return kClassName;
}

DuiLib::UILIB_RESOURCETYPE AboutWndFrame::GetResourceType() const
{
#if _DEBUG
	return UILIB_FILE;
#else
	return UILIB_ZIPRESOURCE;
#endif
}

LPCTSTR AboutWndFrame::GetResourceID() const
{
	return MAKEINTRESOURCE(IDR_ZIPRES1);
}

void AboutWndFrame::InitWindow()
{
	m_pCloseBtn = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("btn_close")));
}

void AboutWndFrame::Notify(TNotifyUI& msg)
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

const LPCTSTR AboutWndFrame::kClassName = _T("about_wnd_frame");
const LPCTSTR AboutWndFrame::kAboutWndFrame = _T("about_wnd_frame.xml");
