//
//  SortedMap.cpp
//  ADTSortedMap
//
//  Created by Diana Dragos on 19/05/2019.
//  Copyright © 2019 Diana Dragos. All rights reserved.
//

#include <iostream>
#include <vector>
#include "SortedMap.hpp"
#include "SMIterator.hpp"

using namespace std;


vector<TKey> SortedMap::keySet() const
{
    vector<TKey> keys;
    
    for (int i = 0; i < this->capacity; ++i) {
        TKey elem = hashTable[i].first;
        if(elem == NULL_TKEY)
            continue;
        keys.push_back(elem);
    }
    
    int i, j;
    TKey key;
    for(j = 1; j < this->numberOfElements; j++)
    {
        key = keys[j];
        for(i = j - 1; (i >= 0) && this->relation(key, keys[i]); i--)
        {
            keys[i+1] = keys[i];
        }
        keys[i+1] = key;
    }
    // sort(keys.begin(), keys.begin() + this->numberOfElements, this->relation);
    return keys;
}

// thetha(n)
SortedMap::SortedMap(Relation r) {
    relation = r;
    capacity = 13;
    numberOfElements = 0;
    hashTable = new TElem[capacity];
    next = new int[capacity];
    for(int i = 0; i < capacity; i++)
    {
        hashTable[i] = TElem(NULL_TKEY, NULL_TVALUE);
        next[i] = EMPTY;
    }
}

// O(n)
TValue SortedMap::add(TKey c, TValue v) {
    TValue value;
    value = NULL_TVALUE;
    int position = this->hash(c);
    
    if (numberOfElements/capacity > 0.7)
    {
        resize();
        add(c, v);
    }
    
    if (hashTable[position] == TElem(NULL_TKEY, NULL_TVALUE))
    {
        hashTable[position] = TElem(c, v);
        next[position] = EMPTY;
        if (firstEmpty == position)
            changeFirstFree();
    }
    else
    {
        int current = position;
        bool foundKey = false;
        while (next[current] != EMPTY) {
            if (hashTable[current].first == c)
            {
                foundKey = true;
                value = hashTable[current].second;
                hashTable[current].second = v;
                --numberOfElements;
            }
            current = next[current];
        }
        if (!foundKey)
        {
            hashTable[firstEmpty] = TElem(c,v);
            next[firstEmpty] = EMPTY;
            next[current] = firstEmpty;
            
            changeFirstFree();
        }
    }
    ++numberOfElements;
    return value;
}

// O(n)
TValue SortedMap::search(TKey c) const {
    int i=0;
    int pos=0;
    while(i < capacity )
    {
        pos = hash(c);
        if(hashTable[pos].first == NULL_TKEY)
            return NULL_TVALUE;
        if(hashTable[pos].first == c)
            return hashTable[pos].second;
        ++i;
    }
    return NULL_TVALUE;
}

// O(n)
TValue SortedMap::remove(TKey c) {
    TValue v = search(c);
    int i = hash(c);
    int j = -1;
    int idx = 0;
    
    while(idx < this->numberOfElements && j == -1)
    {
        if (this->next[idx] == i)
            j = idx;
        else
            idx++;
        
    }
    while(i != -1 and this->hashTable[i].first != c)
    {
        j = i;
        i = this->next[i];
    }
    if (i == -1)
        return NULL_TVALUE;
    else
    {
        bool over = false;
        while(!over)
        {
            int p = next[i];
            int pp = i;
            while(p != -1 && hash(hashTable[p].first) != i)
            {
                pp = p;
                p = next[p];
            }
            if (p == -1)
                over = true;
            else
            {
                hashTable[i] = hashTable[p];
                j = pp;
                i = p;
            }
        }
        if (j != -1)
            next[j] = next[i];
        hashTable[i] = TElem(NULL_TKEY, NULL_TVALUE);
        next[i] = -1;
        
        if (this->firstEmpty > i)
            this->firstEmpty = i;
    }
    numberOfElements--;
    return v;
}

// thetha(1)
int SortedMap::size() const {
    return numberOfElements;
}

// thetha(1)
bool SortedMap::isEmpty() const {
    return numberOfElements==0;
}

// O(n*n)
int SortedMap::updateValues(SortedMap& sm){
    int count=0;
    TValue new_value;
    for(int i =0; i<capacity;i++){
        if(hashTable[i].first == NULL_TKEY) continue;
        new_value = sm.search(hashTable[i].first);
        if(new_value!= NULL_TVALUE and new_value!=hashTable[i].second){
            ++count;
            hashTable[i].second = new_value;
        }
    }
    return count;
}

void SortedMap::changeFirstFree()
{
    this->firstEmpty++;
    while (this->firstEmpty < this->capacity && hashTable[firstEmpty] != TElem(NULL_TKEY, NULL_TVALUE))
        this->firstEmpty++;
}

// thetha(1)
SMIterator SortedMap::iterator() const {
    return SMIterator(*this);
}

// thetha(1)
SortedMap::~SortedMap() {
    delete[] hashTable;
}

// thetha(1)
int SortedMap::hash(TKey key) const {
    return key % capacity;
}

// O(n*n)
void SortedMap::resize()
{
    TElem *oldElements = new TElem[numberOfElements];
    for (int i = 0; i < numberOfElements; ++i) {
        oldElements[i] = TElem(NULL_TKEY, NULL_TVALUE);
    }
    
    int position = 0;
    for (int i = 0; i < capacity; ++i) {
        if (hashTable[i] != TElem(NULL_TKEY, NULL_TVALUE)) {
            oldElements[position++] = hashTable[i];
        }
    }
    
    capacity *= 2;
    TElem *newHashTable = new TElem[capacity];
    int *newNext = new int[capacity];
    for (int i = 0; i < capacity; ++i) {
        newHashTable[i] = TElem(NULL_TKEY, NULL_TVALUE);
        newNext[i] = EMPTY;
    }
    
    delete[] hashTable;
    delete[] next;
    
    hashTable = newHashTable;
    next = newNext;
    
    firstEmpty = 0;
    int oldNumberOfElements = numberOfElements;
    numberOfElements = 0;
    for (int i = 0; i < oldNumberOfElements; ++i) {
        add(oldElements[i].first, oldElements[i].second);
    }
    delete[] oldElements;
}
