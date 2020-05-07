#pragma once
#include "SLL.h"
#include <exception>
#include <iostream>

#define NULL_TVALUE -1

typedef int TKey;

typedef int TValue;
typedef std::pair <TKey, TValue>  TElem;

class SLL;

class SLLIterator
{
	friend class SLL;
	friend class SLLNode;


private:
	friend class SLL;
	SLLIterator(const SLL& s);
	//the iterator stores a reference to the container 
	const SLL& sll;
	SLLNode* currentElement;


public:
	TElem getCurrent() const;
	bool valid() const;
	void next();
	void first();
};

