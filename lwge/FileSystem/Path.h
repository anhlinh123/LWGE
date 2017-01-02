#ifndef __PATH_H__
#define __PATH_H__

#include "../types.h"

class Path
{
public:
	Path();
	Path(const c8* name);
	Path(const Path& other);
	~Path();

	bool IsAbsolute() const;

	Path operator + (const Path& other);
	Path& operator = (const Path& other);
	Path& operator += (const Path& other);

	Path operator + (const c8* other);
	Path& operator = (const c8* other);
	Path& operator += (const c8* other);

	const c8* c_str() const;

private:
	c8 m_buffer[256];
};


#endif // !__PATH_H__
