#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H
#pragma once

class Node {
public:
	friend class SingleLinkedList;
	Node(int);
	//void showData();
private:
	Node *pNext;
	int data;
};

class SingleLinkedList {
public:
	SingleLinkedList();
	bool isEmpty();
	void addHead(int);
	//void addTail(int);
	//void removeHead();
	//void removeTail();
private:
	Node *pHead;
	Node *pTail;
	int iSize;
};

#endif 
