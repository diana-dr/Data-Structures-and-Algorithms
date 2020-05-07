#include "MapIterator.h"

//theta(1)
MapIterator::MapIterator(const Map& m) : map(m) {
	this->current = 0;
}
//theta(1)
void MapIterator::first()
{
	this->current = 0;
}
//theta(1)
void MapIterator::next()
{
	if (this->valid() == false)
		throw std::exception("");
	this->current += 1;

}
//theta1(1)
bool MapIterator::valid() const
{
	if (this->current < this->map.size())
		return true;
	return false;
}
//theta(1)
TElem MapIterator::getCurrent() const
{
	if (this->valid() == false)
		throw std::exception("");

	else return this->map.getElement(this->current);
}

