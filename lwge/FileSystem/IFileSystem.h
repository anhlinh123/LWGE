#ifndef __IFILESYSTEM_H__
#define __IFILESYSTEM_H__

#include "IFile.h"
#include "IFileArchieve.h"

class IFileSystem
{
public:
	virtual ~IFileSystem() {};

	virtual IFile* OpenFile(const Path& fileName, EAccessMode mode) = 0;
	virtual bool AddFileArchive(IFileArchieve* fileArchive) = 0;
};

#endif // !__IFILESYSTEM_H__
