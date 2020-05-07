//
//  SMIterator.cpp
//  SortedMap_BST
//
//  Created by Diana Dragos on 04/06/2019.
//  Copyright © 2019 Diana Dragos. All rights reserved.
//

#include "SMIterator.hpp"

SMIterator::SMIterator(const SortedMap &c) : c{ c }
{
    if (c.size() > 0)
        traverse();
        }

void SMIterator::traverse()
{
    int current = c.root;
    
    stack<int> stack;
    
    while (current!=-1 || !stack.empty())
    {
        while (current!=-1)
        {
            stack.push(current);
            current = c.elements[current].left;
        }
        
        current = stack.top();
        stack.pop();
        
        this->tree.push_back(this->c.elements[current].info);
        
        current = c.elements[current].right;
        
    }
    
}

void SMIterator::first()
{
    this->current_idx = 0;
}

void SMIterator::next()
{
    if (!valid())
        throw exception();
    this->current_idx++;
}

bool SMIterator::valid() const
{
    return (this->current_idx < this->tree.size());
}

TElem SMIterator::getCurrent() const
{
    if (!valid())
        throw exception();
    return this->tree[current_idx];
}
