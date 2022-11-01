#include <iostream>
#include "SingleLinkedList.h"

using namespace std;

int main() {
	SingleLinkedList<int> listTemp;
	int length, dataRemove, temp;
	cin >> length >> dataRemove;
	for (int i = 0; i < length; i++) {
		cin >> temp;
		listTemp.addTail(temp);
	}
	listTemp.handle(dataRemove);
	cout << listTemp.getSize() << endl;
	listTemp.showList();
	return 0;
}