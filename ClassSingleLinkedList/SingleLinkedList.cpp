#include "SingleLinkedList.h"

Node::Node(int _data) {
	this->data = _data;
	this->pNext = nullptr;
}

SingleLinkedList::SingleLinkedList() {
	this->pHead = nullptr;
	this->pTail = nullptr;
	this->iSize = 0;
}

bool SingleLinkedList::isEmpty() {
	if (this->pHead == nullptr) {
		return true;
	}
	return false;
}

void SingleLinkedList::addHead(int _data) {
	Node *pAdd = new Node(_data);
	if (isEmpty()) {
		this->pHead = pAdd;
		this->pTail = pAdd;
	}
	else {
		pAdd->pNext = this->pHead;
		this->pHead = pAdd;
	}
	this->iSize++;
}
