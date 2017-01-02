#ifndef __PLATFORMWIN32_H__
#define __PLATFORMWIN32_H__

#include <Windows.h>
#include "IPlatform.h"

class PlatformWin32 :
	public IPlatform
{
public:
	PlatformWin32();
	~PlatformWin32();

	u32 CreateNewWindow(s32 x, s32 y, u32 width, u32 height) override;
	u32 CreateFullScreenWindow() override;
	void CloseWindow(u32 window) override;

	IRenderContext * CreateRenderContext(EContextType type, u32 windowID) override;
	void DestroyRenderContext(IRenderContext * context) override;

	bool PopMessage(SSystemMessage* outMessage) override;
	bool EnqueueMessage(SSystemMessage message) override;

private:
	HWND m_windows[1];		//Currently support 1 window only
};

#endif // !__CPLATFORMWIN32_H__
