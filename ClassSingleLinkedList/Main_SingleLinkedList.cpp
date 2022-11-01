#include <iostream>
#include "SingleLinkedList.h"

using namespace std;

int main() {
	SingleLinkedList<char> listTemp;
	int length, index;
	char data, tempNum;
	cin >> length;
	for (int i = 0; i < length; i++) {
		cin >> tempNum;
		listTemp.addTail(tempNum);
	}
	//listTemp.handle();
	//listTemp.getSize();
	//listTemp.showList();
	return 0;
}