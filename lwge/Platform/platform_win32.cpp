#include "PlatformWin32.h"
#include "../Application.h"

#define TEST 0

int main()
{
#if defined(TEST) && TEST == 1
	int test();
	return test();
#endif
	PlatformWin32* platformW32 = new PlatformWin32();
	Application* application = new Application(platformW32);
	application->Start();
	application->Destroy();
	delete application;
	delete platformW32;

	return 0;
}