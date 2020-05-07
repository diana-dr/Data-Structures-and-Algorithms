#include "IndexedList.h"
#include "ListIterator.h"

IndexedList::IndexedList() {}

int IndexedList::size() const
{
    return dll.DLLsize();
}

bool IndexedList::isEmpty() const
{
    return dll.DLLsize() == 0;
}

TElem IndexedList::getElement(int pos) const
{
    return this->dll.getElementFromPosition(pos)->data;
}

TElem IndexedList::setElement(int pos, TElem e)
{
    if (pos < 0 || pos >= this->dll.DLLsize())
        throw std::exception();

    DLLNode* currentNode = this->dll.getElementFromPosition(pos);

    TElem oldData = currentNode->data;
    currentNode->data = e;

    return oldData;
}

void IndexedList::addToEnd(TElem e)
{
    this->dll.insertLast(e);
}

void IndexedList::addToPosition(int pos, TElem e)
{
    this->dll.insertPosition(pos, e);
}

TElem IndexedList::remove(int pos)
{
    DLLNode* found = this->dll.getElementFromPosition(pos);
    if (found != NULL)
        return this->dll.deleteElement(found->data);
    return -1;
}

int IndexedList::search(TElem e)  const
{
    int found = this->dll.searchElement(e);

    if (found < this->dll.DLLsize())
        return found;
    return -1;
}

IndexedList::~IndexedList() {}

ListIterator IndexedList::iterator() const {
    return ListIterator(*this);
}