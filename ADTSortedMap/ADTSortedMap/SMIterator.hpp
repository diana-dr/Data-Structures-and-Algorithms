//
//  SMIterator.hpp
//  ADTSortedMap
//
//  Created by Diana Dragos on 19/05/2019.
//  Copyright © 2019 Diana Dragos. All rights reserved.
//
#pragma once
#include "SortedMap.hpp"
#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>
#include <iostream>

class SMIterator {
    
private:
    const SortedMap& map;
    int current;
    TElem* sortedArray;
    int size;
public:
    explicit SMIterator(const SortedMap& m);
    ~SMIterator();
    
    void next();
    
    TElem getCurrent();
    
    bool valid();
    
    void first();
};
