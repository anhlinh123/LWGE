#include "IAsserter.h"
#include <assert.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

class StandardAsserter : public IAsserter
{
public:
	void Assert(bool condition, const c8* file, u32 line, const c8 *message ...) override
	{
		if (!condition)
		{
			char buffer[256];
			va_list args;
			va_start(args, message);
			vsprintf(buffer, message, args);
			va_end(args);

#ifdef _WIN32
			wchar_t wfile[64];
			wchar_t wbuffer[256];
			mbstowcs(wfile, file, 64);
			mbstowcs(wbuffer, buffer, 256);
			_wassert(wbuffer, wfile, line);
#endif
		}
	}
};

