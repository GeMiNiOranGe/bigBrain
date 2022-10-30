#include <iostream>
#include "SingleLinkedList.h"

using namespace std;

int main() {
	SingleLinkedList listTemp;
	int length, tempNum;
	cin >> length;
	for (int i = 0; i < length; i++) {
		cin >> tempNum;
		listTemp.addHead(tempNum);
	}

	return 0;
}
