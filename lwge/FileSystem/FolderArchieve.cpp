#include "FolderArchieve.h"
#include <stdio.h>
#include <string>

FolderArchieve::FolderArchieve(const c8 * folderName)
{
	m_folderName = folderName;
}

FolderArchieve::~FolderArchieve()
{
}

bool FolderArchieve::IsValid()
{
	return true;
}

IFile * FolderArchieve::OpenFile(const Path& fileName, EAccessMode mode)
{
	File* file = new File(m_folderName + fileName, mode);
	if (!file->IsValid())
	{
		delete file;
		file = nullptr;
	}
	return file;
}

IFile * FolderArchieve::OpenFile(u32 index, EAccessMode mode)
{
	return nullptr;
}