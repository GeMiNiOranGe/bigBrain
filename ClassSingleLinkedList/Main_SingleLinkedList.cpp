#include <ctime>
#include "SingleLinkedList.h"

using namespace std;

int random(int minN, int maxN);

int main() {
	srand((int)time(0));
	SingleLinkedList<int> list;
	const int length = 15;
	const int minData = 1;
	const int maxData = 10;
	int numRemove = random(minData, maxData);
	for (int i = 0; i < length; i++) {
		list.addTail(random(minData, maxData));
	}
	//list.selectionSort();
	list.showList();
	cout << endl;
	cout << "Number will be removed: " << numRemove << endl;
	list.removeAll(numRemove);
	list.showList();
	cout << endl << "---------------------------------------------------" << endl;
	return 0;
}

int random(int minN, int maxN) {
	return minN + rand() % (maxN + 1 - minN);
}