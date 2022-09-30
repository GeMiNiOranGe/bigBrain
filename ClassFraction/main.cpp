#include <iostream>
#include "Fraction.h"

using namespace std;

int main() {
	Fraction FOne, FTwo;
	cin >> FOne >> FTwo;
	if (FOne.getDenominator() == 0 || FTwo.getDenominator() == 0) {
		cout << "Loi phep tinh..." << endl;
	}
	else {
		cout << "Ket qua tinh tong: " << FOne + FTwo << endl;
		cout << "Ket qua tinh hieu: " << FOne - FTwo << endl;
		cout << "Ket qua tinh tich: " << FOne * FTwo << endl;
		Fraction phanSoThuongTam = FOne / FTwo;
		if (phanSoThuongTam.getDenominator() == 0) {
			cout << "Ket qua tinh thuong: Loi phep tinh..." << endl;
		}
		else {
			cout << "Ket qua tinh thuong: " << FOne / FTwo << endl;
		}
	}
	return 0;
}
