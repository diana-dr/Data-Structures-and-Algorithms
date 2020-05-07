#include "SLLIterator.h"


//theta(1)
SLLIterator::SLLIterator(const SLL& s) : sll(s) {

}
//theta(1)
void SLLIterator::first() {
	this->currentElement = this->sll.head;
}
//theta(1)
TElem SLLIterator::getCurrent() const {
	if (this->currentElement == NULL)
		throw std::exception("");
	TElem e = this->currentElement->data;
	return e;

}
//theta(1)
bool SLLIterator::valid() const {
	if (this->currentElement == NULL)
		return false;
	else return true;
}
//O(n)
void SLLIterator::next() {
	if (this->currentElement == NULL)
		throw std::exception("");
	else this->currentElement = this->currentElement->next;
}

