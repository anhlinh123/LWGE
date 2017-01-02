#include "Path.h"
#include "../Debugger/IAsserter.h"
#include <string>

Path::Path()
{
	memset(m_buffer, 0, sizeof(m_buffer));
}

Path::Path(const c8 * name)
{
	strncpy(m_buffer, name, sizeof(m_buffer) - 1);
}

Path::Path(const Path & other)
{
	strncpy(m_buffer, other.m_buffer, sizeof(m_buffer) - 1);
}

Path::~Path()
{
}

bool Path::IsAbsolute() const
{
	return m_buffer[0] == '/' || m_buffer[0] == '\\';
}

Path Path::operator+(const Path & other)
{
	Path p = *this;
	p += other;
	return p;
}

Path & Path::operator=(const Path & other)
{
	strncpy(m_buffer, other.m_buffer, sizeof(m_buffer) - 1);
	return *this;
}

Path & Path::operator+=(const Path & other)
{
	return *this += other.m_buffer;
}

Path Path::operator+(const c8 * other)
{
	ASSERT(other != nullptr, "Cannot concatenate a null string");

	Path p = *this;
	p += other;
	return p;
}

Path & Path::operator=(const c8 * other)
{
	ASSERT(other != nullptr, "Cannot assign with a null string");

	strncpy(m_buffer, other, sizeof(m_buffer) - 1);
	return *this;
}

Path & Path::operator+=(const c8 * other)
{
	ASSERT(other != nullptr, "Cannot concatenate a null string");

	//The other cannot be absolute
	if (other[0] == '/' || other[0] == '\\')
		return *this;

	//Remove almost trailing slashes, leave out just one
	size_t len = strlen(m_buffer) - 1;
	for (; len >= 0; len--)
	{
		if (m_buffer[len] == '\\' || m_buffer[len] == '/')
		{
			m_buffer[len] = '\0';
			continue;
		}
		else if (len + 2 < sizeof(m_buffer))
		{
			len++;
			m_buffer[len] = '/';
		}
		break;
	}

	strncat(m_buffer, other, sizeof(m_buffer) - 1 - len);
	return *this;
}

const c8 * Path::c_str() const
{
	return m_buffer;
}
