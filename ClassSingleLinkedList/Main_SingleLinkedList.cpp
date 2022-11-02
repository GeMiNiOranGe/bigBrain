#include <iostream>
#include "SingleLinkedList.h"

using namespace std;

int main() {
	SingleLinkedList<int> listTemp;
	int length, temp;
	cin >> length;
	for (int i = 0; i < length; i++) {
		cin >> temp;
		listTemp.addTail(temp);
	}
	if (listTemp.hasSum2Equal3rdNum()) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}