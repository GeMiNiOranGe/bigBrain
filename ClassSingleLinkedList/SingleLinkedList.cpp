#include "SingleLinkedList.h"

/*template<class T>
void List<T>::RemoveAt(int pos) {
	if (count == 0) {
		throw exception("List is empty");
		return;
	}
	if (pos<0 || pos >count - 1) {
		throw exception("Index is out of range");
	}
	else {
		Node<T>* previous, *following;
		if (pos > 0) {
			previous = SetPosition(pos - 1);
			following = previous->next;
			previous->next = following->next;
		}
		else {
			following = head; head = following->next;
		}
		delete following;
		count--;
	}
}
template<typename T>
void List<T>::removeAt(unsigned index) {
	if (!index) {
		this->pop_front ();
	}
	else {
		Node<T>*previous = this->head;
		for (unsigned i = 0; i != index - 1; i++)
			previous = previous->next;

		Node<T> *removable = previous->next;
		previous->next = removable->next;
		delete removable;
		this->size--;
	}
}
void SingleLinkedList::handle_DSLK1() {
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
				for (int i = 0; i < 20 && pWalker != nullptr; i++) {
					if (dataRemove == pWalker->data) {
						pWalker = pWalker->pNext;
						removeHead();
					}
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
}*/
bool checkSum(int a, int b, int c) {
	return (a == b + c || b == a + c || c == a + b);
}