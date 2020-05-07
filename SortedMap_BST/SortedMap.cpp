//
//  SortedMap.cpp
//  SortedMap_BST
//
//  Created by Diana Dragos on 04/06/2019.
//  Copyright © 2019 Diana Dragos. All rights reserved.
//

#include <assert.h>
#include "SortedMap.hpp"
#include "SMIterator.hpp"

int SortedMap::allocate_node()
{
    if (first_empty == -1)
        resize();
    int new_position = this->first_empty;
    this->first_empty = this->elements[first_empty].left;
    this->numberOfElements++;
    return new_position;
}

void SortedMap::free_node(int position)
{
    elements[position].left = first_empty;
    first_empty = position;
    this->numberOfElements--;
}

bool SortedMap::compare_keys(int pos1, int pos2)
{
    return (relation(elements[pos1].info.first, elements[pos2].info.first) || elements[pos1].info.first == elements[pos2].info.first);
}

void SortedMap::resize()
{
    int new_capacity = this->capacity * 2;
    Node *new_elements = new Node[new_capacity];
    for (int i = 0; i < this->capacity; i++)
        new_elements[i] = this->elements[i];
    
    for (int i = capacity; i < capacity * 2 - 1; i++)
        new_elements[i].left = i + 1;
    new_elements[capacity * 2 - 1].left = -1;
    
    first_empty = capacity;
    this->capacity = new_capacity;
    delete[] this->elements;
    this->elements = new_elements;
}

SortedMap::SortedMap(Relation r) : relation{r}
{
    this->root = -1;
    this->capacity = 10;
    this->elements = new Node[this->capacity];
    this->first_empty = 0;
    
    for (int i = 0; i < capacity - 1; i++)
        elements[i].left = i + 1;
        
        elements[capacity - 1].left = -1;
        }

TValue SortedMap::add(TKey c, TValue v)
{
    int current_node = this->root;
    while (current_node != -1)
        if (elements[current_node].info.first == c)
        {
            TValue old_value = elements[current_node].info.second;
            elements[current_node].info.second = v;
            return old_value;
        }
        else if (this->relation(c, this->elements[current_node].info.first))
            current_node = elements[current_node].left;
        else
            current_node = elements[current_node].right;
    
    int position = allocate_node();
    elements[position].info.first = c;
    elements[position].info.second = v;
    elements[position].left = -1;
    elements[position].right = -1;
    
    if (this->root == -1)
    {
        root = position;
        return NULL_TVALUE;
    }
    
    current_node = this->root;
    while (current_node != -1)
    {
        if (this->relation(elements[position].info.first, elements[current_node].info.first))
        {
            if (elements[current_node].left == -1)
            {
                elements[current_node].left = position;
                current_node = -1;
            }
            else
                current_node = elements[current_node].left;
        }
        else
        {
            if (elements[current_node].right == -1)
            {
                elements[current_node].right = position;
                current_node = -1;
            }
            else
            {
                current_node = elements[current_node].right;
            }
        }
    }
    return NULL_TVALUE;
}

TValue SortedMap::search(TKey c) const
{
    int current_node = this->root;
    while (current_node != -1)
    {
        if (elements[current_node].info.first == c)
            return this->elements[current_node].info.second;
        if (this->relation(c, this->elements[current_node].info.first))
            current_node = elements[current_node].left;
        else
            current_node = elements[current_node].right;
    }
    return NULL_TVALUE;
}

TValue SortedMap::remove(TKey c)
{
    if (root == -1)
        return NULL_TVALUE;
    
    int parent = -1;
    int current_node = this->root;
    while (current_node != -1 && elements[current_node].info.first != c)
    {
        parent = current_node;
        if (this->relation(c, this->elements[current_node].info.first) || c == elements[current_node].info.first)
            current_node = elements[current_node].left;
        else
            current_node = elements[current_node].right;
    }
    if (current_node == -1)
        return NULL_TVALUE;
    
    if (elements[current_node].left == -1)
    {
        if (parent == -1)
        {
            root = elements[current_node].right;
            TValue old_value = this->elements[current_node].info.second;
            free_node(current_node);
            return old_value;
        }
        if (compare_keys(current_node, parent))
            elements[parent].left = elements[current_node].right;
        else
            elements[parent].right = elements[current_node].right;
        TValue old_value = elements[current_node].info.second;
        free_node(current_node);
        return old_value;
    }
    else if (elements[current_node].right == -1)
    {
        if (parent == -1)
        {
            root = elements[current_node].left;
            TValue old_value = this->elements[current_node].info.second;
            free_node(current_node);
            return old_value;
        }
        if (compare_keys(current_node, parent))
            elements[parent].left = elements[current_node].left;
        else
            elements[parent].right = elements[current_node].left;
        TValue old_value = this->elements[current_node].info.second;
        free_node(current_node);
        return old_value;
    }
    
    int max_parent = current_node;
    int max = elements[current_node].left;
    while (elements[max].right != -1)
    {
        max_parent = max;
        max = elements[max].right;
    }
    if (compare_keys(max, max_parent))
        elements[max_parent].left = elements[max].left;
    else
        elements[max_parent].right = elements[max].left;
    elements[max].left = elements[current_node].left;
    elements[max].right = elements[current_node].right;
    
    if (parent == -1)
        root = max;
    else
    {
        if (compare_keys(current_node, parent))
            elements[parent].left = max;
        else
            elements[parent].right = max;
    }
    TValue old_value = this->elements[current_node].info.second;
    free_node(current_node);
    return old_value;
}

int SortedMap::size() const
{
    return this->numberOfElements;
}

bool SortedMap::isEmpty() const
{
    return (this->numberOfElements == 0);
}

SMIterator SortedMap::iterator() const
{
    return SMIterator{ *this };
}

SortedMap::~SortedMap()
{
    delete[] this->elements;
}
