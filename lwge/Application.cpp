#include "Application.h"
#include "ServiceLocator.h"
#include "Debugger/ConsoleLogger.h"
#include "Debugger/StandardAsserter.h"

Application::Application(IPlatform* platform) :
	m_platform(platform),
	m_window(-1)
{
}

Application::~Application()
{
}

void Application::Start()
{
	InitServices();

	OnStart();

	m_window = m_platform->CreateNewWindow(100, 100, 640, 840);
	if (m_window < 0)
	{
		Destroy();
		return;
	}

	m_renderContext = m_platform->CreateRenderContext(ECT_OPENGL_3_0, m_window);
	if (!m_renderContext)
	{
		Destroy();
		return;
	}

	SSystemMessage msg = {};
	while (msg.type != SM_QUIT)
	{
		while (m_platform->PopMessage(&msg))
		{
			OnSystemMessage(msg);
		}
		Update();
	}
	Destroy();
}

void Application::Update()
{
	OnUpdate();
	m_renderContext->Render();
}

void Application::Destroy()
{
	OnDestroy();
	m_platform->CloseWindow(m_window);
	ServiceLocator::Deinit();
}

void Application::InitServices()
{
	ServiceLocator::Init();
	ServiceLocator::SetLogger(new ConsoleLogger());
	ServiceLocator::SetAsserter(new StandardAsserter());
	LOG_I("Done initializing services");
}

void Application::OnSystemMessage(const SSystemMessage& message)
{
}
