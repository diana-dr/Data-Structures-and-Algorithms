#include "DLL.h"
#include "DLLIterator.h"

DLL::DLL() {
    this->head = NULL;
    this->tail = NULL;
}

DLL::~DLL() {
    DLLNode* currentNode= this->head;
    while (currentNode!= this->tail)
    {
        DLLNode* next = currentNode->next;
        delete currentNode;
       currentNode= next;
    }
}

int DLL::searchElement(TElem elem) const {

    DLLNode*currentNode= this->head;
    int i = 0;
    while (currentNode!= NULL && currentNode->data != elem) {
        currentNode = currentNode->next;
        i++;
    }
    return i;
}

DLLNode* DLL::getElementFromPosition(int position) const
{
    DLLNode* currentNode = this->head;
    int i = 0;

    if (position >= this->DLLsize())
        throw std::exception();

    while (i != position && currentNode != NULL)
    {
        i += 1;
        currentNode = currentNode->next;
    }
    return currentNode;
}

void DLL::insertFirst(TElem elem) {

    DLLNode* newNode;

    newNode = new DLLNode;
    newNode->data = elem;
    newNode->next = this->head;
    this->head = newNode;
    newNode->prev = NULL;

}

void DLL::insertAfter(DLLNode *currentNode, TElem elem) {
    DLLNode* newNode;
    newNode = new DLLNode;
    newNode->data = elem;

    newNode->next = currentNode->next;
    newNode->prev = currentNode;

    currentNode->next = newNode;
}

void DLL::insertPosition(int position, TElem elem) {
    if (position < 0)
        throw std::exception();
    else if (position == 0)
        insertFirst(elem);
    else if (position > this->DLLsize())
        throw std::exception();
    else
    {
        DLLNode* currentNode = this->head;
        int currentPosition = 0;
        while (currentNode != NULL && currentPosition < position -1)
        {
            currentNode = currentNode->next;
            currentPosition++;
        }
        if (currentNode == NULL)
            throw std::exception();
        else if (currentNode == this->tail)
            insertLast(elem);
        else
        {
            DLLNode* newNode;
            newNode = new DLLNode;
            newNode->data = elem;
            newNode->next = currentNode->next;
            newNode->prev = currentNode;
            currentNode->next->prev = newNode;
            currentNode->next = newNode;
        }
    }
}

void DLL::insertLast(TElem elem) {
    DLLNode* newNode;
    newNode = new DLLNode;

    newNode->data = elem;
    newNode->next = NULL;
    newNode->prev = this->tail;

    if (this->head == NULL)
    {
        this->head = newNode;
        this->tail = newNode;
    } else {
        this->tail->next = newNode;
        this->tail = newNode;
    }
}

TElem DLL::deleteElement(TElem elem) {
    DLLNode *currentNode = this->head;
    while (currentNode != NULL && currentNode->data != elem)
        currentNode = currentNode->next;
    DLLNode *deletedNode = currentNode;

    if (currentNode != NULL) {
        if (currentNode == this->head) {
            if (currentNode == this->tail) {
                this->head = NULL;
                this->tail = NULL;
            } else {
                this->head = this->head->next;
                this->head->prev = NULL;
            }
        } else if (currentNode == this->tail) {
            this->tail = this->tail->prev;
            this->tail->next = NULL;
        } else {
            currentNode->next->prev = currentNode->prev;
            currentNode->prev->next = currentNode->next;

            deletedNode->next = NULL;
            deletedNode->prev = NULL;
        }
    }
    return deletedNode->data;
}

DLLIterator DLL::iterator() {
    return DLLIterator(*this);
}

int DLL::DLLsize() const {
    DLLNode* currentNode = this->head;
    int size = 0;
    while (currentNode != NULL)
    {
        size ++;
        currentNode = currentNode->next;
    }
    return size;
}
