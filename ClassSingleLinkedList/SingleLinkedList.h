#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H
#pragma once

#include <iostream>
using std::cout;

bool checkSum(int a, int b, int c);

template<class dataType> class SingleLinkedList;
template<class dataType> class Node {
public:
	friend class SingleLinkedList<dataType>;
	Node(dataType);
private:
	Node* pNext;
	dataType data;
};
template<class dataType> class SingleLinkedList {
public:
	SingleLinkedList();
	int getSize();
	bool isEmpty();
	void addHead(dataType);
	void addTail(dataType);
	void addAfter(Node<dataType>*, dataType);
	Node<dataType>* search(dataType);
	Node<dataType>* searchPre(Node<dataType>*);
	void removeHead();
	void removeTail();
	void removeAfter(Node<dataType>*);
	void remove(dataType);
	void insertAt(dataType, int);
	void showList();
	bool hasSum2Equal3rdNum();
private:
	Node<dataType>* pHead;
	Node<dataType>* pTail;
	int iSize;
};
#endif 

template<class dataType> inline Node<dataType>::Node(dataType _data) {
	this->data = _data;
	this->pNext = nullptr;
}
template<class dataType> inline SingleLinkedList<dataType>::SingleLinkedList() {
	this->pHead = nullptr;
	this->pTail = nullptr;
	this->iSize = 0;
}

template<class dataType> inline int SingleLinkedList<dataType>::getSize() {
	return this->iSize;
}
template<class dataType> inline bool SingleLinkedList<dataType>::isEmpty() {
	if (this->pHead == nullptr) {
		return true;
	}
	return false;
}

template<class dataType> inline void SingleLinkedList<dataType>::addHead(dataType _data) {
	Node<dataType>* pAdd = new Node<dataType>(_data);
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
template<class dataType> inline void SingleLinkedList<dataType>::addTail(dataType _data) {
	Node<dataType>* pAdd = new Node<dataType>(_data);
	if (isEmpty()) {
		this->pHead = pAdd;
		this->pTail = pAdd;
	}
	else {
		this->pTail->pNext = pAdd;
		this->pTail = pAdd;
	}
	this->iSize++;
}
template<class dataType> inline void SingleLinkedList<dataType>::addAfter(Node<dataType>* node, dataType _data) {
	Node<dataType>* pAdd = new Node<dataType>(_data);
	if (node != nullptr) {
		pAdd->pNext = node->pNext;
		node->pNext = pAdd;
		if (node == this->pTail)
			this->pTail = pAdd;
	}
	else
		addHead(pAdd);
	this->iSize++;
}

template<class dataType> inline Node<dataType>* SingleLinkedList<dataType>::search(dataType _data) {
	Node<dataType>* pSearch = this->pHead;
	for (; pSearch != nullptr && pSearch->data != _data; pSearch = pSearch->pNext);
	return pSearch;
}
template<class dataType> inline Node<dataType>* SingleLinkedList<dataType>::searchPre(Node<dataType>* node) {
	Node<dataType>* pSearchPre = this->pHead;
	if (pSearchPre == node)
		return nullptr;
	for (; pSearchPre != nullptr && pSearchPre->pNext != node; pSearchPre = pSearchPre->pNext);
	return pSearchPre;
}

template<class dataType> inline void SingleLinkedList<dataType>::removeHead() {
	if (this->pHead != nullptr) {
		Node<dataType>* pRemove = this->pHead;
		this->pHead = this->pHead->pNext;
		delete pRemove;
		if (this->pHead == nullptr)
			this->pTail = nullptr;
		this->iSize--;
	}
}
template<class dataType> inline void SingleLinkedList<dataType>::removeTail() {
	if (this->pHead == nullptr)
		return;
	Node<dataType>* pRemove = this->pTail;
	this->pTail = searchPre(this->pTail);
	delete pRemove;
	if (this->pTail != nullptr)
		this->pTail->pNext = nullptr;
	else
		this->pHead = nullptr;
	this->iSize--;
}
template<class dataType> inline void SingleLinkedList<dataType>::removeAfter(Node<dataType>* node) {
	Node<dataType>* pRemove;
	if (node != nullptr) {
		pRemove = node->pNext;
		if (pRemove != nullptr) {
			if (pRemove == this->pTail)
				this->pTail = node;
			node->pNext = pRemove->pNext;
			delete pRemove;
		}
	}
	else
		removeHead();
	this->iSize--;
}
template<class dataType> inline void SingleLinkedList<dataType>::remove(dataType _data) {
	Node<dataType>* pWalker = this->pHead, *pTemp = nullptr;
	for (; pWalker != nullptr && pWalker->data != _data; pWalker = pWalker->pNext) {
		pTemp = pWalker;
	}
	if (pWalker == nullptr)
		return;
	if (pTemp != nullptr) {
		if (pWalker == this->pTail) {
			this->pTail = pTemp;
			this->pTail->pNext = nullptr;
		}
		pTemp->pNext = pWalker->pNext;
		delete pWalker;
		this->iSize--;
	}
}

template<class dataType> inline void SingleLinkedList<dataType>::insertAt(dataType _data, int index) {
	if (isEmpty() || index == 0)
		addHead(_data);
	else if (index > getSize())
		addTail(_data);
	else {
		Node<dataType> *pTemp = this->pHead;
		for (int i = 0; i < index - 1; i++) {
			pTemp = pTemp->pNext;
		}
		Node<dataType> *pAdd = new Node<dataType>(_data);
		pAdd->pNext = pTemp->pNext;
		pTemp->pNext = pAdd;
		this->iSize++;
	}
}
template<class dataType> inline void SingleLinkedList<dataType>::showList() {
	Node<dataType> *pWalker = this->pHead;
	for (; pWalker != nullptr; pWalker = pWalker->pNext) {
		cout << pWalker->data << " ";
	}
}

//There exists the sum of 2 of 3 numbers equal to the 3rd number
template<class dataType> inline bool SingleLinkedList<dataType>::hasSum2Equal3rdNum() {
	for (Node<dataType>* pFirst = this->pHead; pFirst->pNext->pNext != nullptr; pFirst = pFirst->pNext) {
		for (Node<dataType>* pSecond = pFirst->pNext; pSecond->pNext != nullptr; pSecond = pSecond->pNext) {
			for (Node<dataType>* pThird = pSecond->pNext; pThird != nullptr; pThird = pThird->pNext) {
				if (checkSum(pFirst->data, pSecond->data,pThird->data)) {
					return true;
				}
			}
		}
	}
	return false;
}

