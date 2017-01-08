#ifndef __SMESH_H__
#define __SMESH_H__

#include "SVertex.h"

struct SMesh
{
	SVertex* vertices;
	u32 verticesCount;
	u16* indices;
	u32 indicesCount;
};

#endif // !__SMESH_H__
