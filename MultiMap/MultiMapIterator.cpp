#include <stdexcept>
#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <iostream>

// theta(1)
MultiMapIterator::MultiMapIterator(const MultiMap& c) : c(c) {
	this->current = 0;
}

// theta(1)
void MultiMapIterator::first()
{
	this->current = 0;
}

// theta(1)
void MultiMapIterator::next()
{
	if (valid())
		this->current += 1;
	else
		throw std::exception();
}

// theta(1)
bool MultiMapIterator::valid() const
{
	return this->current < this->c.size();
}

// theta(1)
TElem MultiMapIterator::getCurrent() const
{
	if (valid()) {
		return this->c.getElement(this->current);
	}
	else
		throw std::exception();
}