#pragma once
#include <iostream>
using namespace std;

// #include "MultiMap.h"

//unidirectional iterator for a container
typedef int TKey;
typedef int TValue;
typedef std::pair <TKey, TValue> TElem;

class MultiMap;

class MultiMapIterator {

	friend class MultiMap;
private:

	//Constructor receives a reference of the container.
	//after creation the iterator will refer to the first element of the container, or it will be invalid if the container is empty

	MultiMapIterator(const MultiMap& c);

	//contains a reference of the container it iterates over
	const MultiMap& c;
	int current = 0;

	/* representation specific for the iterator*/

public:

	//sets the iterator to the first element of the container
	void first();

	//moves the iterator to the next element
	//throws exception if the iterator is not valid
	void next();

	//checks if the iterator is valid
	bool valid() const;

	//returns the value of the current element from the iterator
	// throws exception if the iterator is not valid
	TElem getCurrent() const;
};


