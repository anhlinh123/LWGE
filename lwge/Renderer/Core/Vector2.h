#ifndef __VECTOR2_H__
#define __VECTOR2_H__

#include "maths.h"

class Vector2
{
public:
	Vector2() : x(0), y(0) {}
	Vector2(f32 nx, f32 ny) : x(nx), y(ny) {}
	explicit Vector2(f32 n) : x(n), y(n) {}
	Vector2(const Vector2& other) : x(other.x), y(other.y) {}

	Vector2	operator-	() const { return Vector2(-x, -y); }

	Vector2	operator+	(const Vector2& other) const { return Vector2(x + other.x, y + other.y); }
	Vector2	operator-	(const Vector2& other) const { return Vector2(x - other.x, y - other.y); }
	Vector2	operator*	(const Vector2& other) const { return Vector2(x * other.x, y * other.y); }
	Vector2	operator/	(const Vector2& other) const { return Vector2(x / other.x, y / other.y); }

	Vector2	operator+	(const f32 v) const { return Vector2(x + v, y + v); }
	Vector2	operator-	(const f32 v) const { return Vector2(x - v, y - v); }
	Vector2	operator*	(const f32 v) const { return Vector2(x * v, y * v); }
	Vector2	operator/	(const f32 v) const { return Vector2(x / v, y / v); }

	Vector2& operator=	(const Vector2& other) { x = other.x; y = other.y; return *this; }
	Vector2& operator+=	(const Vector2& other) { x += other.x; y += other.y; return *this; }
	Vector2& operator-=	(const Vector2& other) { x -= other.x; y -= other.y; return *this; }
	Vector2& operator*=	(const Vector2& other) { x *= other.x; y *= other.y; return *this; }
	Vector2& operator/=	(const Vector2& other) { x /= other.x; y /= other.y; return *this; }

	Vector2& operator+=	(const f32 v) { x += v; y += v; return *this; }
	Vector2& operator-=	(const f32 v) { x -= v; y -= v; return *this; }
	Vector2& operator*=	(const f32 v) { x *= v; y *= v; return *this; }
	Vector2& operator/=	(const f32 v) { x /= v; y /= v; return *this; }

	bool	operator==	(const Vector2& other) const { return equals(x, other.x) && equals(y, other.y); }
	bool	operator!=	(const Vector2& other) const { return !equals(x, other.x) || !equals(y, other.y); }

	Vector2& Set(f32 nx, f32 ny) { x = nx; y = ny; return *this; }

	f32 GetLength() const { return sqrt(x*x + y*y); }

	f32 GetSquareLength() const { return x*x + y*y; }

	f32 Dot(const Vector2& other) const { return x*other.x + y*other.y; }

	Vector2& Normalize()
	{
		f32 length = x*x + y*y;
		if (length == 0)
			return *this;
		length = 1.0f / length;
		x = x * length;
		y = y * length;
		return *this;
	}

	f32 x, y;
};

#endif // !__VECTOR2_H__
