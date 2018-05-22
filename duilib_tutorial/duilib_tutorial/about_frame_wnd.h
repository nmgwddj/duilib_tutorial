#pragma once
class AboutFrameWnd : public WindowImplBase
{
protected:
	virtual CDuiString GetSkinFolder() override;				// 获取皮肤文件的目录，如果有多层目录这里可以设置
	virtual CDuiString GetSkinFile() override;					// 设置皮肤文件名字
	virtual LPCTSTR GetWindowClassName(void) const override;	// 设置当前窗口的 class name

	virtual UILIB_RESOURCETYPE GetResourceType() const override;// 返回资源类型
	virtual LPCTSTR GetResourceID() const override;				// 如果是ZIP资源，返回资源ID

	virtual void InitWindow() override;							// 窗口初始化函数
	virtual void Notify(TNotifyUI& msg) override;				// 通知事件处理函数

public:
	static const LPCTSTR	kClassName;
	static const LPCTSTR	kAboutWndFrame;

private:
	CButtonUI*				m_pCloseBtn = nullptr;
};

