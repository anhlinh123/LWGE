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

	size_t Read(void * buffer, u32 sizeToRead) override;
	size_t Write(const void * buffer, u32 sizeToWrite) override;
	bool Seek(s32 offset, bool isFromCurPos = false) override;
	size_t GetSize() const override;
	size_t GetPos() const override;
	const Path& GetFileName() const override;

private:
	Path m_fileName;
	FILE* m_file;
};

#endif // !__FILE_H__
