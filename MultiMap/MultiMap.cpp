#include "MultiMap.h"
#include <vector>
#include <iostream>

MultiMap::MultiMap() {}

// O(n)
void MultiMap::add(TKey c, TValue v)
{
	if (isEmpty())
		this->slla.insertPosition(std::make_pair(c, v), 0);
	else
		this->slla.insertPosition(std::make_pair(c, v), this->size());
}

// O(n)
TKey  MultiMap::maxKey() const
{
    TKey max = this->getElement(0).first;
	int current = this->slla.head;

	if (this->isEmpty())
        return NULL_TKEY;
	else
    {
		while (current != -1) {
			if (this->getElement(current).first > max)
				max = this->getElement(current).first;
			current = this->slla.next[current];
		}
    }
    return max;
}

// O(n)
bool MultiMap::remove(TKey c, TValue v)
{
	TElem elem = std::make_pair(c, v);
	bool ok = false;

	if (searchPair(c, v))
		ok = true;

	this->slla.deleteElement(elem);
	return ok;
}

// O(n)
vector<TValue> MultiMap::search(TKey c) const
{
	vector<TValue> empty;
	int current = this->slla.head;

	std::vector<TValue> result;
	if (this->slla.search(std::make_pair(c, 0))) {
		while (current != -1) {
			if (this->slla.getElement(current).first == c)
				result.push_back(this->slla.getElement(current).second);
			current = this->slla.next[current];
		}
		return result;
	}
	return empty;
}

// O(n)
bool MultiMap::searchPair(TKey c, TValue v)
{
	int currentNode = this->slla.head;
	int currentPos = 0;

	while (currentNode != -1) {
		if (this->getElement(currentPos) == std::make_pair(c, v))
			return true;
		currentPos++;
		currentNode = this->slla.next[currentPos];
	}

	return false;
}

// theta(1)
int MultiMap::size() const
{
	int s = this->slla.SLLAsize();
	return s;
}

// theta(1)
bool MultiMap::isEmpty() const
{
	return this->size() == 0;
}

// theta(1)
MultiMapIterator MultiMap::iterator() const
{
	return MultiMapIterator(*this);
}

// O(n)
TElem MultiMap::getElement(int position) const
{
	return this->slla.getElement(position);
}

MultiMap::~MultiMap() {}