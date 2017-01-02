#ifndef __SERVICELOCATOR_H__
#define __SERVICELOCATOR_H__

#include "types.h"

class ILogger;
class IAsserter;
class IFileSystem;

class ServiceLocator
{
public:
	ServiceLocator() = delete;
	ServiceLocator(const ServiceLocator&) = delete;
	ServiceLocator(ServiceLocator&&) = delete;
	~ServiceLocator() = delete;

	static void Init();
	static void Deinit();

	static void SetLogger(ILogger* logger);
	static ILogger* GetLogger();

	static void SetAsserter(IAsserter* asserter);
	static IAsserter* GetAsserter();

	static void SetFileSystem(IFileSystem* fileSystem);
	static IFileSystem* GetFileSystem();

private:
	static ILogger* m_logger;
	static IAsserter* m_asserter;
	static IFileSystem* m_fileSystem;
};


#endif // !__SERVICELOCATOR_H__
