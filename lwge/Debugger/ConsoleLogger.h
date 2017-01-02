#ifndef __CONSOLELOGGER_H__
#define __CONSOLELOGGER_H__

#include "ILogger.h"

class ConsoleLogger : public ILogger
{
public:
	ConsoleLogger();
	~ConsoleLogger();

	ELOG_LEVEL GetLogLevel() const override;
	void SetLogLevel(ELOG_LEVEL ll) override;
	void Log(ELOG_LEVEL ll, const c8* tag, const c8 * text...) override;

private:
	ELOG_LEVEL m_logLevel;
};

#endif // !__ILOGGER_H__
