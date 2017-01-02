#ifndef __FILESYSTEM_H__
#define __FILESYSTEM_H__

#include "IFileSystem.h"
#include <vector>

class FileSystem :
	public IFileSystem
{
public:
	FileSystem();
	~FileSystem();

	IFile * OpenFile(const Path& fileName, EAccessMode mode) override;
	bool AddFileArchive(IFileArchieve * fileArchive) override;

private:
	std::vector<IFileArchieve*> m_fileArchives;
};

#endif // !__FILESYSTEM_H__
