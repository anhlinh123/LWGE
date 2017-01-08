#ifndef __OPENGLCONTEXT_H__
#define __OPENGLCONTEXT_H__

#include "../IRenderContext.h"
#include "OpenGL.h"

#include <unordered_map>

struct SMesh;
struct SOpenGLMeshBuffer;

class OpenGLContext :
	public IRenderContext
{
public:
#ifdef _WIN32
	OpenGLContext(HWND hwnd);
#endif // _WIN32

	~OpenGLContext();

	bool IsValid() override;
	void UploadMesh(SMesh * mesh) override;

private:
	void LoadCoreFunctions();

#ifdef _WIN32
	HDC m_hdc;
	HGLRC m_hrc;
#endif // _WIN32

	std::unordered_map<SMesh*, SOpenGLMeshBuffer*> m_meshBuffers;
};

#endif // !__COPENGLCONTEXT_H__
