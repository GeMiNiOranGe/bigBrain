#include "SingleLinkedList.h"

//void SingleLinkedList::insertAt(int _data, int index) {
//	if (isEmpty()) {
//		addHead(_data);
//	}
//	else {
//		Node *pTemp = this->pHead;
//		for (int i = 0; i < index - 1; i++) {
//			pTemp = pTemp->pNext;
//		}
//		Node *pAdd = new Node(_data);
//		pAdd->pNext = pTemp->pNext;
//		pTemp->pNext = pAdd;
//	}
//	this->iSize++;
//}
//
//

//void SingleLinkedList::removeAt(int index) {
//	Node *pPre = this->pHead;
//	for (int i = 0; i < index - 1; i++) {
//		pPre = pPre->pNext;
//	}
//	Node *pRemove = pPre->pNext;
//	pPre->pNext = pRemove->pNext;
//	delete pRemove;
//	this->iSize--;
//
//	//Node *pFirst = this->pHead;
//	//Node *pSecond = this->pHead->pNext;
//	//for (; pFirst != nullptr; pFirst = pFirst->pNext) {
//	//	if (pSecond->data == _data) {
//
//	//	}
//	//	if (pSecond->pNext != nullptr) {
//	//		pSecond = pSecond->pNext;
//	//	}
//	//}
//}

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
}
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
void SingleLinkedList::handle_CONTRO2(int dataRemove) {
	Node * pWalker = this->pHead;
	for (; pWalker != nullptr; pWalker = pWalker->pNext) {
		if (dataRemove == pWalker->data) {
			if (pWalker == this->pHead) {
				pWalker = pWalker->pNext;
				removeHead();
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
}*/

