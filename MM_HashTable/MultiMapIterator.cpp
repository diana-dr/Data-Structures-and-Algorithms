#include "MultiMapIterator.h"


//O(n)
MultiMapIterator::MultiMapIterator(const MultiMap& c): c { c }, currentIndex{ 0 }
{
	while (currentIndex < c.hashTableCapacity && c.hashTable[currentIndex] == NULL_TELEM) {
		++currentIndex;
	}
}

//O(n)
void MultiMapIterator::first()
{
	currentIndex = 0;
	while (currentIndex < c.hashTableCapacity && c.hashTable[currentIndex] == NULL_TELEM) {
		++currentIndex;
	}
}

//O(n)
void MultiMapIterator::next()
{
	if (!valid())
		throw std::runtime_error("");
	++currentIndex;
	while (currentIndex < c.hashTableCapacity && c.hashTable[currentIndex] == NULL_TELEM) {
		++currentIndex;
	}
}

//theta(1)
bool MultiMapIterator::valid() const
{
	return currentIndex < c.hashTableCapacity;
}

//theta(1)
TElem MultiMapIterator::getCurrent() const
{
	if (!valid())
		throw std::runtime_error("");
	return c.hashTable[currentIndex];
}

//theta(1)
MultiMapIterator::~MultiMapIterator()
{
}
