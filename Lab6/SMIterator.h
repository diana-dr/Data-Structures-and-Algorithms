//
// Created by d3nis on 5/22/2019.
//

#pragma once


#include "SortedMap.h"

class SMIterator {

private:
    const SortedMap& map;
    int current;
    TElem* sorted_array;
    int sorted_size;
public:
    explicit SMIterator(const SortedMap& m);
    ~SMIterator();

    void next();

    TElem getCurrent();

    bool valid();

    void first();
};

