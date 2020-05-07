//
//  SMIterator.cpp
//  ADTSortedMap
//
//  Created by Diana Dragos on 19/05/2019.
//  Copyright © 2019 Diana Dragos. All rights reserved.
//

#include "SMIterator.hpp"
#include <stdexcept>

// O(n*n)
SMIterator::SMIterator(const SortedMap &m):map(m) {
    this->size = map.numberOfElements;
    this->sortedArray = new TElem[map.numberOfElements];
    this->current = 0;
    int s = 0;
    
    for (int i = 0; i < map.capacity; ++i)
    {
        auto elem = map.hashTable[i];
        if(elem.first == NULL_TKEY)
            continue;
        int j = 0;
        if(s == 0)
        {
            sortedArray[s] = elem;
            ++s;
            continue;
        }
        j = s - 1;
        while(j >= 0 and !map.relation(sortedArray[j].first, elem.first)){
            --j;
        }
        ++j;
        for(int k = s; k > j; --k){
            sortedArray[k]= TElem(sortedArray[k - 1].first, sortedArray[k - 1].second);
        }
        sortedArray[j] = elem;
        ++s;
    }
}

// theta (1)
void SMIterator::next(){
    
    if (this->valid())this->current += 1;
    else
        throw std::exception();
    
};

// theta (1)
TElem SMIterator::getCurrent(){
    if (this->valid())return this->sortedArray[this->current];
    else throw std::exception();
};

// theta (1)
bool SMIterator::valid(){
    return this->current<size;
    
};

// theta (1)
void SMIterator::first(){
    this->current = 0;
    
}

// thetha(1)
SMIterator::~SMIterator() {
    delete[] sortedArray;
}
