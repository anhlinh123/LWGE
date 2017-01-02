#include "ServiceLocator.h"
#include "Debugger/ILogger.h"
#include "Debugger/IAsserter.h"
#include "FileSystem/FileSystem.h"

ILogger* ServiceLocator::m_logger;
IAsserter* ServiceLocator::m_asserter;
IFileSystem* ServiceLocator::m_fileSystem;

class NullLogger : public ILogger
{
	ELOG_LEVEL GetLogLevel() const override
	{
		return ELOG_LEVEL();
	}
	void SetLogLevel(ELOG_LEVEL ll) override
	{
	}
	void Log(ELOG_LEVEL ll, const c8 * tag, const c8 *text ...) override
	{
	}
};

class NullAsserter : public IAsserter
{
	void Assert(bool condition, const c8* file, u32 line, const c8 *message ...) override
	{
	}
};

void ServiceLocator::Init()
{
	if (!m_logger)
		m_logger = new NullLogger();

	if (!m_asserter)
		m_asserter = new NullAsserter();

	if (!m_fileSystem)
		m_fileSystem = new FileSystem();
}

void ServiceLocator::Deinit()
{
	delete m_logger;
	m_logger = nullptr;

	delete m_asserter;
	m_asserter = nullptr;
}

void ServiceLocator::SetLogger(ILogger * logger)
{
	m_logger = logger;
}

ILogger * ServiceLocator::GetLogger()
{
	return m_logger;
}

void ServiceLocator::SetAsserter(IAsserter * asserter)
{
	m_asserter = asserter;
}

IAsserter * ServiceLocator::GetAsserter()
{
	return m_asserter;
}

void ServiceLocator::SetFileSystem(IFileSystem * fileSystem)
{
	m_fileSystem = fileSystem;
}

IFileSystem * ServiceLocator::GetFileSystem()
{
	return m_fileSystem;
}
