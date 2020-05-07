#pragma once
#include<vector>
#include<utility>
#include "MultiMapIterator.h"
#include "SLLA.h"

#define NULL_TKEY 0

using namespace std;

typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;

// class MultiMapIterator;

class MultiMap

{
	friend class MultiMapIterator;

private:
	SLLA slla;

	/* representation of the MultiMap */

public:

	//constructor
	MultiMap();

	TKey  maxKey() const;
	//adds a key value pair to the multimap
	void add(TKey c, TValue v);

	//removes a key value pair from the multimap
	//returns true if the pair was removed (if it was in the multimap) and false otherwise
	bool remove(TKey c, TValue v);

	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty
	vector<TValue> search(TKey c) const;

	//returns the number of pairs from the multimap
	int size() const;

	//checks whether the multimap is empty
	bool isEmpty() const;

	//returns an iterator for the multimap
	MultiMapIterator iterator() const;

	TElem getElement(int position) const;
	bool searchPair(TKey c, TValue v);

	//descturctor
	~MultiMap();
};


