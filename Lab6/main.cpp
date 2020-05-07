#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"
int main() {
    setbuf(stdout,NULL);
    std::cout << "Hello, World!" << std::endl;
    testAll();
    testAllExtended();
    return 0;
}