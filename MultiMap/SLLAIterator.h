#pragma once

#include <iostream>
#include "SLLA.h"
//unidirectional iterator for a container

typedef int TKey;
typedef int TValue;
typedef std::pair <TKey, TValue> TElem;

class SLLA;

class SLLAIterator {

private:
	friend class SLLA;

	//Constructor receives a reference of the container.

	//after creation the iterator will refer to the first element of the container, or it will be invalid if the container is empty

	SLLAIterator(const SLLA& s);
	const SLLA& slla;
	int current = slla.head;

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


