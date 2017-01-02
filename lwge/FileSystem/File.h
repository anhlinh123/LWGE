#ifndef __FILE_H__
#define __FILE_H__

#include "../types.h"
#include "IFile.h"
#include "Path.h"
#include <stdio.h>

class File :
	public IFile
{
public:
	File(const Path& fileName, EAccessMode mode);
	~File();

	bool IsValid();

	s32 Read(void * buffer, u32 sizeToRead) override;
	s32 Write(const void * buffer, u32 sizeToWrite) override;
	bool Seek(s32 offset, bool isFromCurPos = false) override;
	s32 GetSize() const override;
	s32 GetPos() const override;
	const Path& GetFileName() const override;

private:
	Path m_fileName;
	FILE* m_file;
};

#endif // !__FILE_H__
