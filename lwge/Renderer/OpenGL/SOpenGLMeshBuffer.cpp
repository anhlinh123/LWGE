#include "SOpenGLMeshBuffer.h"
#include "../Core/SMesh.h"

SOpenGLMeshBuffer::SOpenGLMeshBuffer(SMesh * mesh)
	: verticesCount(mesh->verticesCount)
	, indicesCount(mesh->indicesCount)
{
	glGenBuffers(1, &verticesId);
	glGenBuffers(1, &indicesId);
	Reload(mesh);
}

SOpenGLMeshBuffer::~SOpenGLMeshBuffer()
{
	glDeleteBuffers(1, &verticesId);
	glDeleteBuffers(1, &indicesId);
}

void SOpenGLMeshBuffer::Reload(SMesh * mesh)
{
	glBindBuffer(GL_ARRAY_BUFFER, verticesId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(SVertex) * verticesCount, mesh->vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(u16) * indicesCount, mesh->indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
