#ifndef __IFILEARCHIEVE_H__
#define __IFILEARCHIEVE_H__

#include "IFile.h"

class IFileArchieve
{
public:
	virtual ~IFileArchieve() {};

	virtual bool Reload() = 0;
	virtual bool HasLoaded() = 0;

	virtual IFile* OpenFile(const Path& fileName, EAccessMode mode) = 0;
	virtual IFile* OpenFile(u32 index, EAccessMode mode) = 0;
};

#endif // !__IFILEARCHIEVE_H__