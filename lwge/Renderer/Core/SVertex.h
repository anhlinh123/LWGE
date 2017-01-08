#ifndef __SVERTEX_H__
#define __SVERTEX_H__

#include "Vector2.h"
#include "Vector3.h"

struct SVertex
{
	SVertex() {}

	Vector3 position;
	Vector3 normal;
	Vector3 binormal;
	Vector3 tangent;
	Vector2 uv1;
	Vector2 uv2;
	Vector3 color;
};

#endif // !__SVERTEX_H__
