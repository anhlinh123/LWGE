#include "File.h"
#include <string>

File::File(const Path& fileName, EAccessMode mode)
{
	m_fileName = fileName;
	static const char* smode[] = { "r", "w", "a" };
	m_file = fopen(fileName.c_str(), smode[mode]);
}

File::~File()
{
	if (m_file)
		fclose(m_file);
	m_file = nullptr;
}

bool File::IsValid()
{
	return m_file != nullptr;
}

size_t File::Read(void * buffer, u32 sizeToRead)
{
	return fread(buffer, sizeof(c8), sizeToRead, m_file);
}

size_t File::Write(const void * buffer, u32 sizeToWrite)
{
	return fwrite(buffer, sizeof(c8), sizeToWrite, m_file);
}

bool File::Seek(s32 offset, bool isFromCurPos)
{
	return !fseek(m_file, offset, isFromCurPos);
}

size_t File::GetSize() const
{
	s32 curPos = ftell(m_file);
	fseek(m_file, 0, SEEK_END);
	s32 size = ftell(m_file);
	fseek(m_file, curPos, SEEK_SET);
	return size;
}

size_t File::GetPos() const
{
	return ftell(m_file);
}

const Path& File::GetFileName() const
{
	return m_fileName;
}
