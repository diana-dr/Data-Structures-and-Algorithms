#include "heap.h"
#include <iostream>

Heap::Heap()
{
    this->capacity = 20;
    this->size = 0;
    this->array = new TElem[this->capacity];
}

void Heap::resize()
{
    this->capacity *= 200;

    TElem *aux = new TElem[this->capacity];
    for (int i = 0; i < this->size; i++) {
        aux[i] = this->array[i];
    }

    delete[] this->array;
    array = aux;
}

// O(log2n)
void Heap::bubble_up(Relation r,int pos)
{
    TElem elem = this->array[pos];
    int parent;
    if (pos % 2 == 0)
        parent = pos / 2 - 1;
    else
        parent = pos / 2;
    while (pos > 0 && (r(elem, this->array[parent])))
    {
        this->array[pos] = this->array[parent];
        pos = parent;
        if (parent % 2 == 0)
            parent = pos / 2 - 1;
        else
            parent = pos / 2;
    }
    this->array[pos] = elem;
}

// O(log2n)
void Heap::add(Relation r,TElem e)
{
    if (this->size == this->capacity)
    {
        resize();
    }

    this->array[this->size] = e;
    bubble_up(r, this->size);
    this->size = this->size + 1;

}

// O(log2n)
void Heap::bubble_down(Relation r, int pos)
{
    TElem elem = this->array[pos];
    while (pos < this->size - 1)
    {
        int maxChild = -1;
        if (pos * 2 + 1  <= this->size - 1)
            maxChild = pos * 2 + 1;
        if (pos * 2 +2 <= this->size -1 && (r(this->array[2 * pos +2], this->array[2 * pos + 1])))
            maxChild = pos * 2+2;
        if (maxChild != -1 && r(this->array[maxChild], elem))
        {
            TElem tmp = this->array[pos];
            this->array[pos] = this->array[maxChild];
            this->array[maxChild] = tmp;
            pos = maxChild;
        }
        else
            pos = this->size + 1;

    }
}

// O(log2n)
TElem Heap::remove(Relation r)
{
    if (this->array == 0)
    {
        throw ("");
    }

    TElem deletedElem = this->array[0];
    this->array[0] = this->array[this->size - 1];
    //this->size = this->size - 1;
    bubble_down(r, 0);
    return deletedElem;
}

// theta(1)
int Heap::getSize()
{
    return this->size;
}

//void Heap::getAll()
//{
//    for (int i = 0; i < this->size; i++)
//    {
//        std::cout << this->array[i] << " ";
//    }
//}
