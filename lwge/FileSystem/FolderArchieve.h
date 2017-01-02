#ifndef __FOLDERARCHIEVE_H__
#define __FOLDERARCHIEVE_H__

#include "IFileArchieve.h"
#include "File.h"

class FolderArchieve :
	public IFileArchieve
{
public:
	FolderArchieve(const c8* folderName);
	~FolderArchieve();

	bool Reload() override;
	bool HasLoaded() override;
	IFile * OpenFile(const Path& fileName, EAccessMode mode) override;
	IFile * OpenFile(u32 index, EAccessMode mode) override;

private:
	Path m_folderName;
	bool m_isLoaded;
};

#endif // !__FOLDERARCHIEVE_H__
