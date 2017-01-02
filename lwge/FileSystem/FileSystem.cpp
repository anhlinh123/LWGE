#include "FileSystem.h"
#include "../Debugger/IAsserter.h"

FileSystem::FileSystem()
{
}

FileSystem::~FileSystem()
{
}

IFile * FileSystem::OpenFile(const Path& fileName, EAccessMode mode)
{
	for (std::vector<IFileArchieve*>::const_iterator it = m_fileArchives.begin(); it != m_fileArchives.end(); it++)
	{
		IFile* file = (*it)->OpenFile(fileName, mode);
		if (file)
			return file;
	}
	return nullptr;
}

bool FileSystem::AddFileArchive(IFileArchieve * fileArchive)
{
	ASSERT(fileArchive != nullptr, "Can not add null archieve");

	if (fileArchive->IsValid())
	{
		m_fileArchives.push_back(fileArchive);
		return true;
	}

	return false;
}