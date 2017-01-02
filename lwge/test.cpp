#include "ServiceLocator.h"
#include "Debugger/ILogger.h"
#include "Debugger/StandardAsserter.h"
#include "Debugger/ConsoleLogger.h"
#include <stdio.h>
#include "FileSystem/Path.h"

int test()
{
	ServiceLocator::Init();
	ServiceLocator::SetLogger(new ConsoleLogger());

	Path p1 = "LINH";
	Path p2("THAO");
	Path p3 = p1;
	Path p4 = p1 + "/adg";
	p3 += "agegi";
	Path p5 = "/abc";
	Path p6 = "\\abc";

	LOG_I(p1.c_str());
	LOG_I(p2.c_str());
	LOG_I(p3.c_str());
	LOG_I(p4.c_str());
	LOG_I("p1 = %d, p5 = %d, p6 = %d", p1.IsAbsolute(), p5.IsAbsolute(), p6.IsAbsolute());

	getchar();

	return 1;
}