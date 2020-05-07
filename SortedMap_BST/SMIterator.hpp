//
//  SMIterator.hpp
//  SortedMap_BST
//
//  Created by Diana Dragos on 04/06/2019.
//  Copyright © 2019 Diana Dragos. All rights reserved.
//
#pragma once
#include "SortedMap.hpp"
#include <iostream>
#include <stack>

//unidirectional iterator for a container

class SMIterator {
    
private:
    
    //Constructor receives a reference of the container.
    
    //after creation the iterator will refer to the first element of the container, or it will be invalid if the container is empty
    
    friend class SortedMap;
    
    SMIterator(const SortedMap& c);
    
    
    
    //contains a reference of the container it iterates over
    
    const SortedMap& c;
    
    /* representation specific for the iterator*/
    
    vector <TElem> tree;
    int current_idx;
    void traverse();
    
public:
    
    
    
    //sets the iterator to the first element of the container
    
    void first();
    
    
    
    //moves the iterator to the next element
    
    //throws exception if the iterator is not valid
    
    void next();
    
    
    
    //checks if the iterator is valid
    
    bool valid() const;
    
    
    
    //returns the value of the current element from the iterator
    
    // throws exception if the iterator is not valid
    
    TElem getCurrent() const;
    
    
    
};


