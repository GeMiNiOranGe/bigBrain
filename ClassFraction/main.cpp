#include <iostream>
#include "Fraction.h"

using namespace std;

int main() {
	Fraction FOne, FTwo, FThree(1, 2), FFour(3, 4);
	cout << "Moi ban nhap phan so: ";
	cin >> FOne;
	cout << "Moi ban nhap phan so: ";
	cin >> FTwo;
	cout << endl;
	if (FOne.getDenominator() == 0 || FTwo.getDenominator() == 0) {
		cout << "Loi phep tinh..." << endl;
	}
	else {
		cout << "Tong cua 2 PSo duoc nhap vao: " << FOne + FTwo << endl;
		cout << "Hieu cua 2 PSo duoc nhap vao: " << FOne - FTwo << endl;
		cout << "Tich cua 2 PSo duoc nhap vao: " << FOne * FTwo << endl;
		Fraction phanSoThuongTam = FOne / FTwo;
		if (phanSoThuongTam.getDenominator() == 0) {
			cout << "Thuong cua 2 PSo duoc nhap vao: Loi phep tinh..." << endl;
		}
		else {
			cout << "Thuong cua 2 PSo duoc nhap vao: " << FOne / FTwo << endl;
		}
	}
	cout << endl;
	cout << "Khoi tao PSo3(1, 2), PSo4(3, 4)" << endl;
	FThree += FFour;
	cout << "Thuc hien: PSo3 += PSo4 | Ket qua PSo3 la: " << FThree;
	cout << endl;
	return 0;
}