#ifndef __IPLATFORM_H__
#define __IPLATFORM_H__

#include "SSystemMessage.h"
#include "../Renderer/IRenderContext.h"

class IPlatform
{
public:
	IPlatform() {};
	virtual ~IPlatform() {};

	virtual u32 CreateNewWindow(s32 x, s32 y, u32 width, u32 height) = 0;
	virtual u32 CreateFullScreenWindow() = 0;
	virtual void CloseWindow(u32 window) = 0;

	virtual IRenderContext* CreateRenderContext(EContextType type, u32 windowID) = 0;
	virtual void DestroyRenderContext(IRenderContext* context) = 0;

	virtual bool PopMessage(SSystemMessage* outMessage) = 0;
	virtual bool EnqueueMessage(SSystemMessage message) = 0;
};

#endif // !__IPLATFORM_H__