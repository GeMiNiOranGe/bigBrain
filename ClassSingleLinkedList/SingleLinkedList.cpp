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

int SingleLinkedList::getSize() {
	return this->iSize;
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
void SingleLinkedList::addTail(int _data) {
	Node *pAdd = new Node(_data);
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

void SingleLinkedList::insertAt(int _data, int index) {
	if (isEmpty()) {
		addHead(_data);
	}
	else {
		Node *pTemp = this->pHead;
		for (int i = 0; i < index - 1; i++) {
			pTemp = pTemp->pNext;
		}
		Node *pAdd = new Node(_data);
		pAdd->pNext = pTemp->pNext;
		pTemp->pNext = pAdd;
	}
	this->iSize++;
}

void SingleLinkedList::showList() {
	Node *pWalker = this->pHead;
	for (; pWalker != nullptr; pWalker = pWalker->pNext) {
		cout << pWalker->data << " ";
	}
	cout << endl;
}

/*void SingleLinkedList::handle_DSLK1() {
	Node *pWalker = this->pHead;
	char cTemp = pWalker->data;
	cout << cTemp << " ";
	for (; pWalker != nullptr; pWalker = pWalker->pNext) {
		if (pWalker->data > cTemp) {
			cout << pWalker->data << " ";
			cTemp = pWalker->data;
		}
	}
}*/

void SingleLinkedList::handle_DSLK2() {
	Node *pFirst = this->pHead;
	Node *pSecond = this->pHead->pNext;
	for (; pFirst->pNext != nullptr; pFirst = pFirst->pNext) {
		if (pFirst->data + 1 != pSecond->data) {
			Node *pNewNode = new Node(pFirst->data + 1);
			pNewNode->pNext = pSecond;
			pFirst->pNext = pNewNode;
			if (pSecond->pNext != nullptr) {
				pSecond = pSecond->pNext;
			}
		}
	}
}
