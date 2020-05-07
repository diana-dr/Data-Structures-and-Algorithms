#include "ShortTest.h"
#include "ExtendedTest.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
int main()
{
	testAll();
	testAllExtended();
	_CrtDumpMemoryLeaks();
	return 0;
}