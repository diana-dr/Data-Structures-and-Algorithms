#pragma once
#include <iostream>
#include <exception>
#include <algorithm>

typedef int TKey;
typedef int TValue;
typedef std::pair <TKey, TValue> TElem;

class SLLA {

private:

public:
	TElem* elems;
	int* next;
	int cap;
	int head;
	int firstEmpty;
	int size;

	SLLA();
	~SLLA();

	bool search(TElem elem) const;
	void insertPosition(TElem elem, int position);
	void deleteElement(TElem elem);
	TElem getElement(int position) const;
	int SLLAsize() const;
	void resize();
};

