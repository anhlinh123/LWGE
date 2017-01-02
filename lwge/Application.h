#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Platform/IPlatform.h"
#include "Renderer/IRenderContext.h"

class Application
{
public:
	Application(IPlatform* platform);
	~Application();

	void Start();
	void Update();
	void Destroy();

protected:
	virtual void OnStart() {};
	virtual void OnUpdate() {};
	virtual void OnDestroy() {};

private:
	void InitServices();
	void OnSystemMessage(const SSystemMessage& message);

	u32 m_window;
	IPlatform* m_platform;
	IRenderContext* m_renderContext;
};

#endif // !__CAPPLICATION_H__
