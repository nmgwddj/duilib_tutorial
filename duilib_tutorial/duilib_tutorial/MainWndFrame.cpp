#include "stdafx.h"
#include "MainWndFrame.h"
#include "resource.h"

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
	m_pMinBtn = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("btn_wnd_min")));
	m_pMaxBtn = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("btn_wnd_max")));
	m_pRestoreBtn = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("btn_wnd_restore")));
	m_pCloseBtn = dynamic_cast<CButtonUI*>(m_PaintManager.FindControl(_T("btn_wnd_close")));
}

const LPCTSTR MainWndFrame::kClassName = _T("main_wnd_frame");
const LPCTSTR MainWndFrame::kMainWndFrame = _T("main_wnd_frame.xml");
