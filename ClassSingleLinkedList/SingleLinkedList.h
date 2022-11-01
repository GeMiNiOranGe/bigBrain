#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H
#pragma once

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using namespace std;

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

	//void insertAt(dataType, int);
	void handle(int);
	void showList();
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

template<class dataType>
inline void SingleLinkedList<dataType>::handle(int dataRemove) {
	Node<dataType> * pWalker = this->pHead;
	for (; pWalker != nullptr; pWalker = pWalker->pNext) {
		if (dataRemove == pWalker->data) {
			if (pWalker == this->pHead) {
				for (int i = 0; i < 10 && dataRemove == pWalker->data; i++) {
					pWalker = pWalker->pNext;
					removeHead();
				}
				pWalker = this->pHead;
				if (pWalker == nullptr) {
					break;
				}
			}
			else if (pWalker == this->pTail) {
				pWalker = searchPre(pWalker);
				removeTail();
			}
			else {
				pWalker = searchPre(pWalker);
				remove(pWalker->pNext->data);
			}
		}
	}
}
template<class dataType> inline void SingleLinkedList<dataType>::showList() {
	Node<dataType> *pWalker = this->pHead;
	for (; pWalker != nullptr; pWalker = pWalker->pNext) {
		cout << pWalker->data << " ";
	}
}
