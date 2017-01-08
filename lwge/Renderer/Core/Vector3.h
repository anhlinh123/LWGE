#ifndef __VECTOR3_H__
#define __VECTOR3_H__

#include "maths.h"

class Vector3
{
public:
	Vector3() : x(0), y(0), z(0) {}
	Vector3(f32 nx, f32 ny, f32 nz) : x(nx), y(ny), z(nz) {}
	explicit Vector3(f32 n) : x(n), y(n), z(n) {}
	Vector3(const Vector3& other) : x(other.x), y(other.y), z(other.z) {}

	Vector3	operator-	() const { return Vector3(-x, -y, -z); }
	Vector3	operator+	(const Vector3& other) const { return Vector3(x + other.x, y + other.y, z + other.z); }
	Vector3	operator-	(const Vector3& other) const { return Vector3(x - other.x, y - other.y, z - other.z); }
	Vector3	operator*	(const Vector3& other) const { return Vector3(x * other.x, y * other.y, z * other.z); }
	Vector3	operator/	(const Vector3& other) const { return Vector3(x / other.x, y / other.y, z / other.z); }

	Vector3& operator=	(const Vector3& other) { x = other.x; y = other.y; z = other.z; return *this; }
	Vector3& operator+=	(const Vector3& other) { x += other.x; y += other.y; z += other.z; return *this; }
	Vector3& operator-=	(const Vector3& other) { x -= other.x; y -= other.y; z -= other.z; return *this; }
	Vector3& operator*=	(const Vector3& other) { x *= other.x; y *= other.y; z *= other.z; return *this; }
	Vector3& operator/=	(const Vector3& other) { x /= other.x; y /= other.y; z /= other.z; return *this; }

	Vector3	operator+	(const f32 v) const { return Vector3(x + v, y + v, z + v); }
	Vector3	operator-	(const f32 v) const { return Vector3(x - v, y - v, z - v); }
	Vector3	operator*	(const f32 v) const { return Vector3(x * v, y * v, z * v); }
	Vector3	operator/	(const f32 v) const { f32 i = (f32)1.0 / v; return Vector3(x * i, y * i, z * i); }

	Vector3& operator+=	(const f32 v) { x += v; y += v; z += v; return *this; }
	Vector3& operator-=	(const f32 v) { x -= v; y -= v; z -= v; return *this; }
	Vector3& operator*=	(const f32 v) { x *= v; y *= v; z *= v; return *this; }
	Vector3& operator/=	(const f32 v) { f32 i = (f32)1.0 / v; x *= i; y *= i; z *= i; return *this; }

	bool	operator==	(const Vector3& other) const { return equals(x, other.x) && equals(y, other.y) && equals(z, other.z); }
	bool	operator!=	(const Vector3& other) const { return !equals(x, other.x) || !equals(y, other.y) || !equals(z, other.z); }

	Vector3& Set(const f32 nx, const f32 ny, const f32 nz) { x = nx; y = ny; z = nz; return *this; }

	f32 GetLength() const { return sqrt(x*x + y*y + z*z); }

	f32 GetSquareLength() const { return x*x + y*y + z*z; }

	f32 Dot(const Vector3& other) const { return x*other.x + y*other.y + z*other.z; }

	Vector3 Cross(const Vector3& p) const { return Vector3(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x); }

	Vector3& Normalize()
	{
		f64 length = x*x + y*y + z*z;
		if (length == 0) // this check isn't an optimization but prevents getting NAN in the sqrt.
			return *this;
		length = 1.0f / length;

		x = (f32)(x * length);
		y = (f32)(y * length);
		z = (f32)(z * length);
		return *this;
	}

	f32 x, y, z;
};

#endif // !__VECTOR3_H__
