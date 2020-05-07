#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"

using namespace std;

int main()
{
	testAll();
	cout << "Short passed!\n";
	testAllExtended();
	return 0;
}