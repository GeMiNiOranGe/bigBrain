#include <iostream>
#include "SingleLinkedList.h"

using namespace std;

int main() {
	SingleLinkedList<int> listTemp;
	int length, data, temp, index;
	cin >> length >> data >> index;
	for (int i = 0; i < length; i++) {
		cin >> temp;
		listTemp.addTail(temp);
	}
	listTemp.selectionSort();
	listTemp.showList();
	return 0;
}