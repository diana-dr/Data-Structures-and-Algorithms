//
//  SortedMap.hpp
//  ADTSortedMap
//
//  Created by Diana Dragos on 19/05/2019.
//  Copyright © 2019 Diana Dragos. All rights reserved.
//
#pragma once
#include <utility>
#include <vector>

typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;

#define NULL_TVALUE -10000000
#define NULL_TKEY -10000000
#define EMPTY -10000000

class SMIterator;

typedef bool(*Relation)(TKey, TKey);

class SortedMap {
private:
    friend SMIterator;
    //representation of SortedMap
    int capacity;
    int *next;
    double loadFactor = 0.7;
    int numberOfElements;
    int firstEmpty;
    Relation relation;
    //int capacity;
    TElem* hashTable;

public:
    // implicit constructor
    
    SortedMap(Relation r);
    
    
    
    // adds a pair (key,value) to the map
    
    //if the key already exists in the map, then the value associated to the key is replaced by the new value and the old value is returned
    
    //if the key does not exist, a new pair is added and the value null is returned
    
    TValue add(TKey c, TValue v);
    
    
    
    //searches for the key and returns the value associated with the key if the map contains the key or null: NULL_TVALUE otherwise
    
    TValue search(TKey c) const;
    
    
    
    
    
    //removes a key from the map and returns the value associated with the key if the key existed or null: NULL_TVALUE otherwise
    
    TValue remove(TKey c);
    
    
    
    //returns the number of pairs (key,value) from the map
    
    int size() const;
    
    
    
    //checks whether the map is empty or not
    
    bool isEmpty() const;
    
    
    
    // return the iterator for the map
    
    // the iterator will return the keys following the order given by the relation
    
    SMIterator iterator() const;
    
    
    
    // destructor
    
    ~SortedMap();
    
    int updateValues(SortedMap& sm);
    
    int hash(TKey) const;
    std::vector<TKey> keySet() const;
    void changeFirstFree();
    void resize();
    
    
};



