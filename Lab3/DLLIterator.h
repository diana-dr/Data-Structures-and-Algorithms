#pragma once
#include <exception>
#include <iostream>
#include "DLL.h"

typedef int TElem;

class DLLIterator
{
    // friend class DLLNode;
    friend class DLL;


private:
    DLLIterator(const DLL& d);
    //the iterator stores a reference to the container
    const DLL& dll;
    DLLNode* currentElement;


public:
    TElem getCurrent() const;
    bool valid() const;
    void next();
    void first();
};

