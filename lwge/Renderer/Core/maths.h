#ifndef __MATHS_H__
#define __MATHS_H__

#include "../../types.h"
#include <math.h>
#include <float.h>

inline bool equals(const f32 a, const f32 b, const f32 tolerance = FLT_EPSILON)
{
	return (a + tolerance >= b) && (a - tolerance <= b);
}

inline bool equals(const f64 a, const f64 b, const f64 tolerance = LDBL_EPSILON)
{
	return (a + tolerance >= b) && (a - tolerance <= b);
}

#endif // !__MATHS_H__
