#pragma once
#include "MultiMapIterator.h"
#include<vector>

#include<utility>



using namespace std;


typedef int TKey;

typedef int TValue;



typedef std::pair<TKey, TValue> TElem;

class MultiMapIterator;

class MultiMap

{
	friend class MultiMapIterator;


private:

	/* representation of the MultiMap */
	TElem* hashTable;
	int* next;
	int hashTableCapacity;
	int numberOfElements;
	int firstFreePosition;

	int hashFunction(TKey c);
	void updateFirstFreePosition();
	bool needsResize();
	void resize();
	double computeLoadFactor();
	const TElem NULL_TELEM = TElem(-1000000000, -1000000000);
	const int NULL_NEXT = -1;

public:

	//constructor

	MultiMap();



	//adds a key value pair to the multimap

	void add(TKey c, TValue v);



	//removes a key value pair from the multimap

	//returns true if the pair was removed (if it was in the multimap) and false otherwise

	bool remove(TKey c, TValue v);



	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty

	vector<TValue> search(TKey c) ;



	//returns the number of pairs from the multimap

	int size() const;



	//checks whether the multimap is empty

	bool isEmpty() const;



	//returns an iterator for the multimap

	MultiMapIterator iterator() const;



	// copies elements from current hash table

	TElem* copyElements();

	void rehash(TElem* lst);


	int addIfNotPresent(MultiMap& m);

	//descturctor

	~MultiMap();





};
