#include "SLL.h"

SLL::SLL() {
	this->head = NULL;
}
//O(n)
SLLNode* SLL::searchElement(TElem elem) const {

	SLLNode* current = this->head;
	while (current != NULL && current->data.first != elem.first) {
		current = current->next;
	}
	return current;
}
//theta(1)
void SLL::insertFirst(TElem elem) {
	SLLNode* newNode;
	newNode = new SLLNode;
	newNode->data = elem;
	newNode->next = this->head;
	this->head = newNode;

}
//theta(1)
void SLL::insertAfter(SLLNode* currentNode, TElem elem) {
	SLLNode* newNode;
	newNode = new SLLNode;
	newNode->data = elem;
	newNode->next = currentNode->next;
	currentNode->next = newNode;

}
//O(n)
void SLL::insertPosition(TElem elem, int position) {
	if (position < 1)
		throw std::exception("");
	else if (position == 1)
		this->insertFirst(elem);
	else {
		SLLNode* currentNode = this->head;
		int currentPosition = 1;
		while (currentPosition < position - 1 && currentNode != NULL) {
			currentNode = currentNode->next;
			currentPosition += 1;
		}
		if (currentNode != NULL)
			this->insertAfter(currentNode, elem);
		else throw std::exception("");
	}
}
//O(n)
TElem SLL::deleteElement(TElem elem) {
	SLLNode* currentNode;
	SLLNode* prevNode;
	currentNode = this->head;
	prevNode = NULL;
	while (currentNode != NULL && currentNode->data.first != elem.first) {
		prevNode = currentNode;
		currentNode = currentNode->next;
	}
	if (currentNode != NULL && prevNode == NULL)
		this->head = this->head->next;
	else if (currentNode != NULL) {
		prevNode->next = currentNode->next;
		currentNode->next = NULL;
	}
	TElem nodeInfo = currentNode->data;
	delete currentNode;
	return nodeInfo;
}
//theta(1)
SLLIterator SLL::iterator() {
	return SLLIterator(*this);
}
//theta(1)
void SLL::setElement(SLLNode* node, TElem newData)
{
	node->data = newData;
}
//theta(1)
int SLL::SLLsize() const
{
	SLLNode* currentNode = this->head;
	int s = 0;
	while (currentNode != NULL)
	{
		s += 1;
		currentNode = currentNode->next;
	}
	return s;
}

//O(n)
SLLNode* SLL::searchByPosition(int pos) const
{
	SLLNode* currentNode = this->head;
	int i = 0;
	while (i != pos && currentNode != NULL)
	{
		i += 1;
		currentNode = currentNode->next;
	}
	return currentNode;

}
//theta(n)
SLL::~SLL()
{
	SLLNode* currentNode = this->head;
	while (currentNode != NULL) {
		SLLNode* next = currentNode->next;
		delete currentNode;
		currentNode = next;
	}
	
}