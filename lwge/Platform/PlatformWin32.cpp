#include "PlatformWin32.h"
#include "../Renderer/OpenGLContext.h"
#include "../Debugger/ILogger.h"

LRESULT CALLBACK winProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	SSystemMessage* outMessage = (SSystemMessage*)GetWindowLongPtr(hwnd, GWL_USERDATA);
	switch (msg)
	{
	case WM_QUIT:
		outMessage->type = SM_QUIT;
		break;
	case WM_DESTROY:
		outMessage->type = SM_WINDOW_DESTROY;
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wparam, lparam);
	}

	return 0;
}

PlatformWin32::PlatformWin32()
{
}

PlatformWin32::~PlatformWin32()
{
}

u32 PlatformWin32::CreateNewWindow(s32 x, s32 y, u32 width, u32 height)
{
	LPCTSTR className = TEXT("LWGE Win32 Surface");
	HINSTANCE hInstance = GetModuleHandle(0);

	// Register Class
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = winProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = NULL;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = 0;
	wcex.lpszClassName = className;
	wcex.hIconSm = 0;
	wcex.hIcon = 0;
	RegisterClassEx(&wcex);

	//Create a window
	m_windows[0] = CreateWindowEx(
		0,
		className,
		TEXT(""),
		WS_POPUP | WS_SYSMENU | WS_BORDER | WS_CAPTION | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
		100, 100, 640, 480,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!m_windows[0])
	{
		LOG_E("Cannot create window");
		UnregisterClass(className, hInstance);
		return -1;
	}

	ShowWindow(m_windows[0], SW_NORMAL);

	return 0;
}

u32 PlatformWin32::CreateFullScreenWindow()
{
	return u32();
}

IRenderContext * PlatformWin32::CreateRenderContext(EContextType type, u32 windowID)
{
	switch (type)
	{
	case ECT_OPENGL_3_0:
		return new OpenGLContext(m_windows[windowID]);
	default:
		break;
	}
	return nullptr;
}

bool PlatformWin32::PopMessage(SSystemMessage* outMessage)
{
	MSG msg = {};
	if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
	{
		SetWindowLongPtr(m_windows[0], GWL_USERDATA, (LONG_PTR)outMessage);
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		outMessage->timestamp = msg.time;
		outMessage->windowID = 0;

		return true;
	}

	return false;
}

bool PlatformWin32::EnqueueMessage(SSystemMessage message)
{
	return false;
}

void PlatformWin32::CloseWindow(u32 window)
{
	DestroyWindow(m_windows[window]);
	m_windows[window] = 0;
	UnregisterClass(TEXT("LWGE Win32 Surface"), GetModuleHandle(0));
}

void PlatformWin32::DestroyRenderContext(IRenderContext * context)
{
}
