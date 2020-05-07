#include "SLLA.h"
#define INIT_CAPACITY 400000

// theta(n) complexity - n initial capacity
SLLA::SLLA() {

	this->cap = INIT_CAPACITY;
	this->elems = new TElem[this->cap];
	this->next = new int[this->cap];
	this->head = -1;
	this->size = 0;

	for (int i = 0; i < this->cap - 1; i++)
		this->next[i] = i + 1;

	this->next[this->cap - 1] = -1;
	this->firstEmpty = 0;
}

SLLA::~SLLA() {
	delete[] this->elems;
	delete[] this->next;
}

// O(n) complexity
bool SLLA::search(TElem elem) const {
	int current = this->head;

	while (current != -1 && this->elems[current].first != elem.first)
		current = this->next[current];

	if (current != -1)
		return true;

	return false;
}

// O(n) complexity
void SLLA::insertPosition(TElem elem, int position) {
	if (position < 0)
		throw std::exception();

	//if (this->next[position] == -1)
	//	resize();

	if (this->firstEmpty == -1)
	{
		TElem* newElems;
		newElems = new TElem[this->cap * 2];

		int* newNext;
		newNext = new int[this->cap * 2];

		for (int i = 1; i < this->cap; i++)
		{
			newElems[i] = this->elems[i];
			newNext[i] = this->next[i];
		}
		for (int i = this->cap; i < this->cap * 2 - 1; i++)
			newNext[i] = i + 1;

		newNext[this->cap * 2 - 1] = -1;
		this->elems = newElems;
		this->next = newNext;
		this->firstEmpty = this->cap + 1;
		this->cap = this->cap * 2;

		this->size++;
	}
	if (position == 0) {
		int newPosition = this->firstEmpty;
		this->elems[newPosition] = elem;
		this->firstEmpty = this->next[this->firstEmpty];
		this->next[newPosition] = this->head;
		this->head = newPosition;

		this->size++;
	}
	else {
		int pozCurrent = 0;
		int nodCurrent = this->head;

		while (nodCurrent != -1 && pozCurrent < position - 1)
		{
			pozCurrent = pozCurrent + 1;
			nodCurrent = this->next[nodCurrent];
		}

		if (nodCurrent != -1)
		{
			int newElem = this->firstEmpty;
			this->firstEmpty = this->next[firstEmpty];
			this->elems[newElem] = elem;
			this->next[newElem] = this->next[nodCurrent];
			this->next[nodCurrent] = newElem;
			this->size++;
		}
		else
			throw std::exception();
	}
}

// O(n)
void SLLA::deleteElement(TElem elem) {
	int nodC = this->head;
	int prevNode = -1;

	while (nodC != -1 && this->elems[nodC] != elem)
	{
		prevNode = nodC;
		nodC = this->next[nodC];
	}
	if (nodC != -1) {
		if (nodC == this->head)
			this->head = this->next[this->head];
		else
			this->next[prevNode] = this->next[nodC];
		this->next[nodC] = this->firstEmpty;
		this->firstEmpty = nodC;
		this->size--;
	}
//	else
//		throw std::exception();
}

// O(n)
TElem SLLA::getElement(int position) const {
	int currentPos = 0;
	int currentNode = head;
	while (currentNode != -1 && currentPos < position)
	{
		currentNode = next[currentNode];
		currentPos++;
	}
	if (currentNode != -1)
		return this->elems[currentNode];
}

// theta(1)
int SLLA::SLLAsize() const {
	return this->size;
}

// O(n)
void SLLA::resize() {
	int newCap = this->cap * 2;
	TElem *aux = new TElem[newCap];

	for (int i = 0; i < this->size; i++) {
		aux[i] = this->elems[i];
	}

	delete[] this->elems;
	this->elems = aux;

	for (int i = this->cap; i < newCap - 1; i++)
		this->next[i] = i + 1;

	this->next[newCap - 1] = -1;
}