#include <iostream>
#include "SingleLinkedList.h"

using namespace std;

int main() {
	SingleLinkedList listTemp;
	int length, data, index, tempNum;
	cin >> length;
	for (int i = 0; i < length; i++) {
		cin >> tempNum;
		listTemp.addTail(tempNum);
	}
	listTemp.handle_DSLK2();
	listTemp.showList();
	return 0;
}