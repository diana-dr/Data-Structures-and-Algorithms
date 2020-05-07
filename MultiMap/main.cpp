#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"
#include "MultiMap.h"

int main() {

	testAll();
	testAllExtended();
	MultiMap m;

	assert(m.maxKey() == NULL_TKEY);

	m.add(1, 100);
	m.add(2, 200);
	m.add(3, 300);
	m.add(1, 500);
	m.add(2, 600);
	m.add(4, 800);

	assert(m.maxKey() == 4);

	m.remove(4, 800);
	assert(m.maxKey() == 3);
	m.remove(3, 300);
	assert(m.maxKey() == 2);

	return 0;
}