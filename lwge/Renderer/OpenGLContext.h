#ifndef __OPENGLCONTEXT_H__
#define __OPENGLCONTEXT_H__

#include "IRenderContext.h"

#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32

#include <gl\GL.h>
#include "glext.h"

#ifdef _WIN32
#include "wglext.h"  
#endif // _WIN32


class OpenGLContext :
	public IRenderContext
{
public:
#ifdef _WIN32
	OpenGLContext(HWND hwnd);
#endif // _WIN32

	~OpenGLContext();

	bool IsValid() override;
	void Render() override;

private:
	void LoadCoreFunctions();

#ifdef _WIN32
	HDC m_hdc;
	HGLRC m_hrc;
#endif // _WIN32
};

#endif // !__COPENGLCONTEXT_H__
