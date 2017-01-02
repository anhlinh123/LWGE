#ifndef __ILOGGER_H__
#define __ILOGGER_H__

#include "../types.h"
#include "../ServiceLocator.h"

#define LOG_D(...)	ServiceLocator::GetLogger()->Log(ELL_DEBUG, "LWGE", __VA_ARGS__);
#define LOG_I(...)	ServiceLocator::GetLogger()->Log(ELL_INFORMATION, "LWGE", __VA_ARGS__);
#define LOG_W(...)	ServiceLocator::GetLogger()->Log(ELL_WARNING, "LWGE", __VA_ARGS__);
#define LOG_E(...)	ServiceLocator::GetLogger()->Log(ELL_ERROR, "LWGE", __VA_ARGS__);

//! Possible log levels.
//! When used has filter ELL_DEBUG means => log everything and ELL_NONE means => log (nearly) nothing.
//! When used to print logging information ELL_DEBUG will have lowest priority while ELL_NONE
//! messages are never filtered and always printed.
enum ELOG_LEVEL
{
	//! Used for printing information helpful in debugging
	ELL_DEBUG,

	//! Useful information to print. For example hardware infos or something started/stopped.
	ELL_INFORMATION,

	//! Warnings that something isn't as expected and can cause oddities
	ELL_WARNING,

	//! Something did go wrong.
	ELL_ERROR,

	//! Logs with ELL_NONE will never be filtered.
	//! And used as filter it will remove all logging except ELL_NONE messages.
	ELL_NONE
};

class ILogger
{
public:
	virtual ~ILogger() {}
	virtual ELOG_LEVEL GetLogLevel() const = 0;
	virtual void SetLogLevel(ELOG_LEVEL ll) = 0;
	virtual void Log(ELOG_LEVEL ll, const c8* tag, const c8* text...) = 0;
};

#endif // !__ILOGGER_H__
