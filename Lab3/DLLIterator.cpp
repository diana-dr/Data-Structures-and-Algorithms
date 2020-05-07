#include "DLLIterator.h"
#include "DLL.h"

//theta(1)
DLLIterator::DLLIterator(const DLL& d) : dll(d) {}

//theta(1)
void DLLIterator::first() {
    this->currentElement = this->dll.head;
}

//theta(1)
TElem DLLIterator::getCurrent() const {
    if (this->currentElement == NULL)
        throw std::exception();
    TElem e = this->currentElement->data;
    return e;
}

//theta(1)
bool DLLIterator::valid() const {
    return this->currentElement != NULL;
}

//O(n)
void DLLIterator::next() {
    if (this->currentElement == NULL)
        throw std::exception();

    else this->currentElement = this->currentElement->next;
}
