#pragma once

#include <utility>


#include <vector>

typedef int TKey;

typedef int TValue;

typedef std::pair<TKey, TValue> TElem;

#define NULL_TVALUE -10010
#define DELETED -10001
#define EMPTY -10000

class SMIterator;

typedef bool(*Relation)(TKey, TKey);

class SortedMap {

private:
    friend SMIterator;
    //representation of SortedMap
    int m;
    double loadFactor = 0.7;
    int array_size;

    Relation relation;

    //int capacity;

    TElem* array;



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

    int hash1(TKey) const;

    int hash2(TKey) const;

    int main_hash(TKey, int) const;


    void resize();


};



