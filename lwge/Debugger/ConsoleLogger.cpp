#include "ConsoleLogger.h"
#include <stdio.h>
#include <stdarg.h>
#include <time.h>

#ifdef _WIN32
#include <Windows.h>
#endif

ConsoleLogger::ConsoleLogger() : m_logLevel(ELL_DEBUG)
{
}

ConsoleLogger::~ConsoleLogger()
{
}

ELOG_LEVEL ConsoleLogger::GetLogLevel() const
{
	return m_logLevel;
}

void ConsoleLogger::SetLogLevel(ELOG_LEVEL ll)
{
	m_logLevel = ll;
}

void ConsoleLogger::Log(ELOG_LEVEL ll, const c8 * tag, const c8 *text ...)
{
	if (m_logLevel <= ll)
	{
		char logLevelName[] = { 'D', 'I', 'W', 'E', 'N' };
		char buffer[256];
		va_list args;
		va_start(args, text);
		vsprintf(buffer, text, args);
		va_end(args);
		time_t t = time(0);
		struct tm* now = localtime(&t);

#ifdef _WIN32
		WORD logLevelColors[] = {
			FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
			FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
			FOREGROUND_RED | FOREGROUND_GREEN,
			FOREGROUND_RED,
			FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
		};
		HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
		WORD   index = 0;

		SetConsoleTextAttribute(hstdout, logLevelColors[ll]);
		printf("%c\\ %.2d:%.2d:%.2d [%s] %s\n", logLevelName[ll], now->tm_hour, now->tm_min, now->tm_sec, tag, buffer);
		SetConsoleTextAttribute(hstdout, logLevelColors[ELL_NONE]);
#else
		printf("%c\\ %.2d:%.2d:%.2d [%s] %s\n", logLevelName[ll], now->tm_hour, now->tm_min, now->tm_sec, tag, buffer);
#endif
	}
}
