#include "MultiMap.h"
#include <stdio.h>
#include <iostream>

//theta(n)
MultiMap::MultiMap() : hashTableCapacity{ 500 }, numberOfElements{0}, firstFreePosition{0}
{
	hashTable = new TElem[500];
	next = new int[500];
	for (int i = 0; i < hashTableCapacity; ++i)
	{
		this->hashTable[i] = NULL_TELEM;
		this->next[i] = NULL_NEXT;
	}
}

//O(n)
void MultiMap::add(TKey c, TValue v)
{
	int insertPosition = this->hashFunction(c);
	if (needsResize())
		resize();


	if (hashTable[insertPosition] == NULL_TELEM)
	{
		hashTable[insertPosition] = TElem(c,v);
		next[insertPosition] = NULL_NEXT;

		if (firstFreePosition == insertPosition)
			updateFirstFreePosition();
	}
	else
	{
		int current = insertPosition;
		bool foundElem = false;
		while (next[current] != NULL_NEXT ) {
			if (hashTable[current] == TElem(c, v))
				foundElem = true;
			current = next[current];
		}
		hashTable[firstFreePosition] = TElem(c,v);
		next[firstFreePosition] = NULL_NEXT;
		next[current] = firstFreePosition;
		
		updateFirstFreePosition();

	}
	++numberOfElements;
	return;


}

//O(n)
bool MultiMap::remove(TKey c, TValue v)
{
	int actualNode = hashFunction(c);
	int previoudNode = NULL_NEXT;
	int index = 0;
	int counter = 0;

	while (counter < hashTableCapacity && next[counter] != actualNode)
		counter += 1;
	if (counter < hashTableCapacity)
		previoudNode = counter;
	

	while (actualNode != NULL_NEXT && hashTable[actualNode] != TElem(c,v))
	{
		previoudNode = actualNode;
		actualNode = next[actualNode];
	}

	if (actualNode == NULL_NEXT) // we didn't find the element 
		return false;
	else
	{
		bool over = false;
		do
		{
			int currentPosition = next[actualNode];
			int previousposition = actualNode;

			while (currentPosition != NULL_NEXT && hashFunction(hashTable[currentPosition].first) != actualNode)
			{
				previousposition = currentPosition;
				currentPosition = next[currentPosition];
			}
			if (currentPosition == NULL_NEXT)
				over = true;
			else {
				hashTable[actualNode] = hashTable[currentPosition];
				actualNode = currentPosition;
				previoudNode = previousposition;
			}
		} while (over == false);

		if (previoudNode != NULL_NEXT)
		{
			next[previoudNode] = next[actualNode];
		}
		hashTable[actualNode] = NULL_TELEM;
		next[actualNode] = NULL_NEXT;


		if (actualNode < firstFreePosition)
			firstFreePosition = actualNode;
	}

	--numberOfElements;
	return true;
}

// O(n)
vector<TValue> MultiMap::search(TKey c) 
{
	vector<TValue> elems;
	int currentNode = hashFunction(c);
	while (currentNode != NULL_NEXT) {
		if (hashTable[currentNode].first == c)
			elems.push_back(hashTable[currentNode].second);
		currentNode = next[currentNode];
	}

	return elems;
}

//theta(1)
int MultiMap::size() const
{
	return this->numberOfElements;
}
//theta(1)
bool MultiMap::isEmpty() const
{
	return this->numberOfElements == 0;
}

//theta(1)
MultiMapIterator MultiMap::iterator() const
{
	return MultiMapIterator{*this};
}

//O(n)
void MultiMap::resize()
{
	TElem *oldElements = new TElem[numberOfElements];
	oldElements = copyElements();

	hashTableCapacity *= 2;
	TElem *newHashTable = new TElem[hashTableCapacity];
	int *newNextNode = new int[hashTableCapacity];
	for (int i = 0; i < hashTableCapacity; ++i) {
		newHashTable[i] = NULL_TELEM;
		newNextNode[i] = NULL_NEXT;
	}
	

	delete[] hashTable;
	delete[] next;
	
	hashTable = newHashTable;
	next = newNextNode;

	firstFreePosition = 0;
	int oldNumberOfElements = numberOfElements;
	numberOfElements = 0;
	for (int i = 0; i < oldNumberOfElements; ++i) {
		add(oldElements[i].first, oldElements[i].second);
	}
	delete[] oldElements;
}

//O(n)
TElem * MultiMap::copyElements()
{
	TElem *oldElements = new TElem[numberOfElements];
	for (int i = 0; i < numberOfElements; ++i) {
		oldElements[i] = NULL_TELEM;
	}
	int currentAppendIndex = 0;
	for (int i = 0; i < hashTableCapacity; ++i) {
		if (hashTable[i] != NULL_TELEM) {
			oldElements[currentAppendIndex++] = hashTable[i];
		}
	}
	return oldElements;
}

//theta(n)
void MultiMap::rehash(TElem * lst)
{
	for (int i = 0; i < hashTableCapacity / 2; i++)
		add(lst[i].first, lst[i].second);
}


//theta(1)
int MultiMap::hashFunction(TKey c)
{
	if (c < 0)
		c *= -1;
	return c % hashTableCapacity;
}

//O(n)
void MultiMap::updateFirstFreePosition()
{
	++firstFreePosition;
	while (firstFreePosition < hashTableCapacity && hashTable[firstFreePosition] != NULL_TELEM)
		++firstFreePosition;
}

bool MultiMap::needsResize()
{
	return computeLoadFactor() >= 0.75;
}

double MultiMap::computeLoadFactor()
{
	return (1.0 * numberOfElements) / (1.0 * hashTableCapacity);
}



MultiMap::~MultiMap()
{
	delete[] hashTable;
	delete[] next;
}



int MultiMap::addIfNotPresent(MultiMap & m)
{
	int insertPosition,prevNode,currentNode,noOfElemsAdded = 0;
	TElem elementFromM;
	bool found;

	for (int i = 0; i < m.hashTableCapacity; i++)
	{
		if (m.hashTable[i] != NULL_TELEM)
		{
			found = false;
			elementFromM = m.hashTable[i];
			insertPosition = hashFunction(elementFromM.first);
			currentNode = insertPosition;
			prevNode = NULL_NEXT;
			while (currentNode != NULL_NEXT) {
				if (hashTable[currentNode].first == elementFromM.first && hashTable[currentNode].second == elementFromM.second)
					found = true;
				prevNode = currentNode;
				currentNode = next[currentNode];
			}
			if (found == false)
			{
				if (prevNode != NULL_NEXT)
				{
					hashTable[firstFreePosition] = TElem(elementFromM.first, elementFromM.second);
					next[firstFreePosition] = NULL_NEXT;
					next[prevNode] = firstFreePosition;
					updateFirstFreePosition();
				}
				else
				{
					hashTable[insertPosition] = TElem(elementFromM.first, elementFromM.second);
					next[insertPosition] = NULL_NEXT;
					if (firstFreePosition == insertPosition)
						updateFirstFreePosition();
				}
				++noOfElemsAdded;
			}
		}
	}
	return noOfElemsAdded;
}