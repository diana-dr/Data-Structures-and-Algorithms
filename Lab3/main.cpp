#include <iostream>

#include "ExtendedTest.h"
#include "ShortTest.h"
#include "ListIterator.h"

using namespace std;

// 25. ADT List (interface with TPozition = Integer) – using a DLL

int main() {
    testAll();
    testAllExtended();

    IndexedList list = IndexedList();

    list.addToEnd(1);
    list.addToEnd(2);
    list.addToEnd(3);

    ListIterator it = list.iterator();

    it.next();

    assert(it.getCurrent() == 2);
    it.previous();
    assert(it.getCurrent() == 1);

    try {
        it.previous();
        assert(false);
    } catch (std::exception &) {
        assert(true);
    }

    return 0;
}