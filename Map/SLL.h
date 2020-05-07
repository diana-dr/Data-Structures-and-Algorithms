#pragma once
#include "SLLIterator.h"
#include <iostream>
#include <exception>
#define NULL_TVALUE -1

typedef int TKey;

typedef int TValue;
typedef std::pair <TKey, TValue>  TElem;

class SLLNode {

public:

	TElem data;

	SLLNode *next;

	SLLNode() {};

	~SLLNode() {};


};

class SLL {

	friend class SLLIterator;
	friend class SLLNode;

public:

	SLLNode *head;       //Node pointers to head 



	SLL();               // constructor


	SLLNode* searchElement(TElem elem) const;
	void insertFirst(TElem elem);
	void insertAfter(SLLNode* currentNode, TElem elem);
	void insertPosition(TElem ielemtem, int position);
	TElem deleteElement(TElem elem);
	SLLIterator iterator();
	void setElement(SLLNode* node, TElem newData);
	SLLNode* searchByPosition(int pos) const;
	int SLLsize() const;
	~SLL();
};
