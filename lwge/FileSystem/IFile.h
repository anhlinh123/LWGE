#ifndef __IFILE_H__
#define __IFILE_H__

#include "../types.h"
#include "Path.h"

enum EAccessMode
{
	EAM_READ,
	EAM_WRITE,
	EAM_APPEND
};

class IFile
{
public:
	virtual ~IFile() {};

	virtual s32 Read(void* buffer, u32 sizeToRead) = 0;
	virtual s32 Write(const void* buffer, u32 sizeToWrite) = 0;
	virtual bool Seek(s32 offset, bool isFromCurPos = false) = 0;
	virtual s32 GetSize() const = 0;
	virtual s32 GetPos() const = 0;
	virtual const Path& GetFileName() const = 0;
};

#endif // !__IFILE_H__