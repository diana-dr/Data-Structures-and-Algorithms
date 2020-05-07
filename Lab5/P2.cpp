#include "P2.h"
#include <iostream>


vector<TElem> mergeVectors(vector<vector<TElem>> inputVectors, Relation rel)
{
    Heap heap;
    vector<TElem> resultVector;
    int noOfVectors = inputVectors.size();
    for (int i = 0; i < noOfVectors; i++)
    {
        vector<TElem> vector = inputVectors.at(i);
        for (int j = 0; j < vector.size(); j++)
        {
            heap.add(rel, vector.at(j));
        }
    }
    /*heap.getAll();
    std::cout << "\n hep size:" << heap.getsize();*/

    for (int i = 0; i < heap.getSize(); i++)
    {
        TElem deletedElem = heap.remove(rel);
        resultVector.push_back(deletedElem);

    }

    /*std::cout << "\n";
    for (int i = 0; i < resultVector.size(); i++)
        std::cout << resultVector.at(i) << " ";

    std::cout << "\nvecot size:" << resultVector.size();*/

    return resultVector;
}

