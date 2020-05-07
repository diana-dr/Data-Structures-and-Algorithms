//
// Created by d3nis on 5/22/2019.
//

#include <iostream>
#include "SortedMap.h"
#include "SMIterator.h"

SortedMap::SortedMap(Relation r) {
    //complexity is thetha(m)

    relation = r;
    m = 13;
    array_size = 0;
    array = new TElem[m];
    for(int i=0;i<m;i++)array[i] = TElem(EMPTY,EMPTY);

}

TValue SortedMap::add(TKey c, TValue v) {

//pre: ht is a HashTable, e is a TKey
//post: e was added in ht
//complexity is O(m)
    int i = 0;
    TValue oldValue;
    int pos = main_hash(c, i);
    while (i < m and array[pos].first != EMPTY and array[pos].first != DELETED)
    {
        if(array[pos].first==c)
        {
            oldValue = array[pos].second;
            array[pos].second=v;
            return oldValue;
        }
        ++i;
        pos = main_hash(c, i);
    }
    if (i == m or (array_size+1.0)/m>loadFactor) {
       // @resize and rehash
       resize();
       add(c,v);


    }
    else {
        array[pos].first = c;
        array[pos].second = v;
        array_size++;
    }
    return NULL_TVALUE;
}

TValue SortedMap::search(TKey c) const {
    //complexity is O(m)
    int i=0;
    int pos=0;
    while(i < m ){
        pos = main_hash(c,i);
        if(array[pos].first == EMPTY) return NULL_TVALUE;
        if(array[pos].first == c)return array[pos].second;
        ++i;
    }
    return NULL_TVALUE;
}

TValue SortedMap::remove(TKey c) {
    //complexity is O(m)
    int i=0;
    int pos=0;
    TValue oldValue;
    while(i < m ){
        pos = main_hash(c,i);
        if(array[pos].first == EMPTY) return NULL_TVALUE;
        if(array[pos].first == c){
            oldValue=array[pos].second;
            array[pos].second = DELETED;
            array[pos].first = DELETED;
            array_size--;
            return oldValue;
        }

        ++i;
    }
    return NULL_TVALUE;
}

int SortedMap::size() const {
    //complexity is thetha(1)
    return array_size;
}

bool SortedMap::isEmpty() const {
    //complexity is thetha(1)
    return array_size==0;
}

int SortedMap::updateValues(SortedMap& sm){
    //complexity is O(m*searchComplexity) = O(m*m)
    int count=0;
    TValue new_value;
    for(int i =0; i<m;i++){
        if(array[i].first==DELETED or array[i].first == EMPTY) continue;
        new_value = sm.search(array[i].first);
        if(new_value!= NULL_TVALUE and new_value!=array[i].second){
            ++count;
            array[i].second = new_value;
        }
    }
    return count;
}

SMIterator SortedMap::iterator() const {
    //complexity is thetha(1)
    return SMIterator(*this);
}

SortedMap::~SortedMap() {
    //complexity is thetha(1)
    delete[] array;
}

int SortedMap::hash1(TKey key) const {
    //complexity is thetha(1)
    return key%m;
}

int SortedMap::hash2(TKey key) const {
    //complexity is thetha(1)
    return 1+key%(m-1);
}


int SortedMap::main_hash(TKey key, int i) const {
    //complexity is thetha(1)
    int key_2;
    if (key>0) key_2 = key;
    else key_2 = key*(-27);
    key_2 = (hash1(key_2)+i*hash2(key_2))%m;
    return key_2;
}

void SortedMap::resize() {
    //complexity is O(m*m)
    // more precisely O(size*m)
TElem* old_array = new TElem[m];

for(int i=0;i<m;i++)old_array[i] = TElem(array[i].first,array[i].second);
delete[] array;
int old_m = m;
m = m*2;
bool found =false;
int copy_m ;
while(!found){
    copy_m = m/2;
    int count = 0;
    while(copy_m>1){
        if(m%copy_m==0)++count;
        --copy_m;
    }
    if(count!=0)m++;
    else found = true;
}

array = new TElem[m];
for(int i=0;i<m;i++)array[i]= TElem(EMPTY, EMPTY);
array_size=0;
for(int i=0;i<old_m;i++){
    if(old_array[i].first!=EMPTY and old_array[i].first!=DELETED)add(old_array[i].first, old_array[i].second);}

delete[] old_array;

}
