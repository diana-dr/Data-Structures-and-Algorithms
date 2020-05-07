#include <stdexcept>
#include "ListIterator.h"
#include "IndexedList.h"
#include <iostream>

ListIterator::ListIterator(const IndexedList& c): c(c) {
    this->current = this->c.dll.head;
}

void ListIterator::first() {
    this->current = this->c.dll.head;
}

TElem ListIterator::getCurrent() const {
    if (this->current == NULL)
        throw std::exception();
    TElem e = this->current->data;
    return e;
}

bool ListIterator::valid() const {
    return this->current != NULL;
}

void ListIterator::next() {
    if (this->current == NULL)
        throw std::exception();

    else this->current = this->current->next;
}

void ListIterator::previous() {
    if (this->current == this->c.dll.head)
        this->current = NULL;

    if (!valid())
        throw std::exception();

    this->current = this->current->prev;
}