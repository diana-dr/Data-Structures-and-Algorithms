#include "SLLAIterator.h"
#include "SLLA.h"

//theta(1)
SLLAIterator::SLLAIterator(const SLLA& s) : slla(s) {}

//theta(1)
void SLLAIterator::first() {
	this->current = this->slla.head;
}

//theta(1)
TElem SLLAIterator::getCurrent() const {
	if (this->current > this->slla.cap)
		throw std::exception();
	TElem e = this->slla.elems[this->current];
	return e;
}

//theta(1)
bool SLLAIterator::valid() const {
	return this->current < this->slla.cap;
}

//O(n)
void SLLAIterator::next() {
	if (this->current > this->slla.cap)
		throw std::exception();

	else this->current = this->slla.next[this->current]++;
}

