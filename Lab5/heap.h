#pragma once

#include <iostream>
using namespace std;
typedef int TElem;
typedef bool (*Relation) (TElem e1, TElem e2);


class Heap {

private:

    TElem* array;
    int capacity;
    int size;

public:
    Heap();
    void resize();
    void bubble_up(Relation r, int p);
    void add(Relation r, TElem e);
    TElem remove(Relation r);
    void bubble_down(Relation r, int p);
    int getSize();
};