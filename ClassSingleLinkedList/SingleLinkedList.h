#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H
#pragma once

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

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
	int getSize();
	bool isEmpty();
	void addHead(int);
	void addTail(int);
	void insertAt(int, int);
	void handle_DSLK2();
	//void removeHead();
	//void removeTail();
	void showList();
private:
	Node *pHead;
	Node *pTail;
	int iSize;
};

#endif 
