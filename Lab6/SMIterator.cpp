//
// Created by d3nis on 5/22/2019.
//

#include "SMIterator.h"


void SMIterator::next(){

// the complexity is theta (1)
    if (this->valid())this->current += 1;
    else
        throw std::exception();

};

TElem SMIterator::getCurrent(){
// the complexity is theta (1)
    if (this->valid())return this->sorted_array[this->current];
    else throw std::exception();
};

bool SMIterator::valid(){
// the complexity is theta (1)
    return this->current<sorted_size;

};

void SMIterator::first(){
// the complexity is theta (1)
    this->current = 0;

}

SMIterator::SMIterator(const SortedMap &m):map(m) {
// complexity is O(m*m)
sorted_size = map.array_size;
this->sorted_array = new TElem[map.array_size];
current = 0;
int s =0;
    for (int i = 0; i < map.m; ++i) {
        auto elem = map.array[i];
        if(elem.first == DELETED) continue;
        if(elem.first == EMPTY) continue;
        int j=0;
        if(s==0){
            sorted_array[s] = elem;
            ++s;
            continue;
        }

//        while(j<s and map.relation(sorted_array[j].first,elem.first)){
//            ++j;
//        }
        j=s-1;
        while(j>=0 and !map.relation(sorted_array[j].first,elem.first)){
            --j;
        }
        ++j;
        for(int k = s; k > j; --k){
            sorted_array[k]= TElem(sorted_array[k-1].first,sorted_array[k-1].second);
        }
        sorted_array[j] = elem;
//        if(j<s) for(int k = s; k > j; --k){
//            sorted_array[k]= TElem(sorted_array[k-1].first,sorted_array[k-1].second);
//        }
//        sorted_array[j] = elem;
        ++s;
    }
}

SMIterator::~SMIterator() {
    //complexity is thetha(1)
    delete[] sorted_array;
}
