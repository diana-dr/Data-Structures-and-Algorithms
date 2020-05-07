#pragma once
#include <exception>
#include <iostream>

typedef int TElem;

class ListIterator;
class DLLIterator;

class DLLNode {
    friend class DLLIterator;
public:

    TElem data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode() {};
    ~DLLNode() {};
};

class DLL {

private:

    friend class DLLIterator;
    friend class DLLNode;

public:

    DLLNode* head; // node pointers to head
    DLLNode* tail; // node pointers to tail

    DLL();         // constructor

    int searchElement(TElem elem) const;
    void insertFirst(TElem elem);
    void insertAfter(DLLNode* current, TElem elem);
    void insertPosition(int position, TElem elem);
    void insertLast(TElem elem);
    TElem deleteElement(TElem elem);
    // void setElement(DLLNode* node, TElem newElem);
    DLLNode* getElementFromPosition(int position) const;
    DLLIterator iterator();
    int DLLsize() const;
    ~DLL();
};