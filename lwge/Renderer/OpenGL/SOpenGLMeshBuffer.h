#ifndef __SOPENGLMESHBUFFER_H__
#define __SOPENGLMESHBUFFER_H__

#include "OpenGL.h"

struct SMesh;

struct SOpenGLMeshBuffer
{
public:
	SOpenGLMeshBuffer(SMesh* mesh);
	~SOpenGLMeshBuffer();

	void Reload(SMesh* mesh);

	GLuint verticesId;
	GLuint verticesCount;
	GLuint indicesId;
	GLuint indicesCount;
};

#endif // !__SOPENGLMESHBUFFER_H__