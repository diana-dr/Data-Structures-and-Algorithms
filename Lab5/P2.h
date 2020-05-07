#pragma once
#include <vector>
#include "heap.h"

using namespace std;

typedef int TElem;
typedef bool (*Relation) (TElem e1, TElem e2);

//merges k sorted vectors into one single vector.
//the input vectors are sorted considering the relation and the results should be sorted in the same way.
vector<TElem> mergeVectors(vector<vector<TElem>> inputVectors, Relation rel);
