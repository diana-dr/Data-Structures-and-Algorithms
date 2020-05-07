#include "Map.h"

Map::Map()
{
}
//O(n)
TValue Map::add(TKey c, TValue v)
{
	SLLNode* foundElement = this->sll.searchElement(std::make_pair(c, v));

	//if the key is in the map, increase the value
	if (foundElement != NULL) {
		TValue oldValue = foundElement->data.second;
		this->sll.setElement(foundElement, std::make_pair(c, v));
		return oldValue;
	}
	//add the element (key, value) to the map
	else {
		this->sll.insertFirst(std::make_pair(c, v));
		return NULL_TVALUE;
	}

}
//O(n)
TValue Map::search(TKey c) const
{
	SLLNode* foundElement = this->sll.searchElement(std::make_pair(c, 0));
	if (foundElement != NULL)
		return foundElement->data.second;
	return NULL_TVALUE;
}
//O(n)
TValue Map::remove(TKey c)
{
	SLLNode* foundElement = this->sll.searchElement(std::make_pair(c, 0));
	if (foundElement == NULL)
		return NULL_TVALUE;
	else return this->sll.deleteElement(std::make_pair(c, 0)).second;


}
//theta(1)
int Map::size() const
{
	int s = sll.SLLsize();
	return s;
}
//theta(1)
bool Map::isEmpty() const
{
	if (sll.SLLsize() == 0)
		return true;
	return false;
}
//theta(1)
MapIterator Map::iterator() const
{
	return MapIterator(*this);
}
//O(n)
TElem Map::getElement(int position) const
{
	return this->sll.searchByPosition(position)->data;

}


