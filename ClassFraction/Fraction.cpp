#include "Fraction.h"
Fraction::Fraction(int _numerator, int _denominator) {
	this->numerator = _numerator;
	this->denominator = _denominator;
}

int Fraction::getNumerator() {
	return this->numerator;
}
int Fraction::getDenominator() {
	return this->denominator;
}

void Fraction::setNumerator(int _numerator) {
	this->numerator = _numerator;
}
void Fraction::setDenominator(int _denominator) {
	this->denominator = _denominator;
}

Fraction operator+(Fraction fractionOne, Fraction fractionTwo) {
	return Fraction(fractionOne.numerator * fractionTwo.getDenominator() + fractionOne.denominator * fractionTwo.getNumerator(), fractionOne.denominator * fractionTwo.getDenominator()).simplify();
}
Fraction operator-(Fraction fractionOne, Fraction fractionTwo) {
	return Fraction(fractionOne.numerator * fractionTwo.getDenominator() - fractionOne.denominator * fractionTwo.getNumerator(), fractionOne.denominator * fractionTwo.getDenominator()).simplify();
}
Fraction operator*(Fraction fractionOne, Fraction fractionTwo) {
	return Fraction(fractionOne.numerator * fractionTwo.getNumerator(), fractionOne.denominator * fractionTwo.getDenominator()).simplify();
}
Fraction operator/(Fraction fractionOne, Fraction fractionTwo) {
	return (fractionOne * fractionTwo.inverseFraction()).simplify();
}

/*Method 1: don't use friend function
Fraction& Fraction::operator+=(Fraction& fractionOne) {
	*this = *this + fractionOne;
	return *this;
}

Method 2: use friend function*/
Fraction& operator+=(Fraction& fractionOne, Fraction fractionTwo) {
	return fractionOne = fractionOne + fractionTwo;
}
Fraction& operator-=(Fraction& fractionOne, Fraction fractionTwo) {
	return fractionOne = fractionOne - fractionTwo;
}
Fraction& operator*=(Fraction& fractionOne, Fraction fractionTwo) {
	return fractionOne = fractionOne * fractionTwo;
}
Fraction& operator/=(Fraction& fractionOne, Fraction fractionTwo) {
	return fractionOne = fractionOne / fractionTwo;
}

bool operator>(Fraction fractionOne, Fraction fractionTwo) {
	return (fractionOne.getNumerator() * fractionTwo.getDenominator()) > (fractionOne.getDenominator() * fractionTwo.getNumerator());
}
bool operator<(Fraction fractionOne, Fraction fractionTwo) {
	return (fractionOne.getNumerator() * fractionTwo.getDenominator()) < (fractionOne.getDenominator() * fractionTwo.getNumerator());
}
bool operator==(Fraction fractionOne, Fraction fractionTwo) {
	return (fractionOne.getNumerator() * fractionTwo.getDenominator()) == (fractionOne.getDenominator() * fractionTwo.getNumerator());
}
bool operator>=(Fraction fractionOne, Fraction fractionTwo) {
	return (fractionOne.getNumerator() * fractionTwo.getDenominator()) >= (fractionOne.getDenominator() * fractionTwo.getNumerator());
}
bool operator<=(Fraction fractionOne, Fraction fractionTwo) {
	return (fractionOne.getNumerator() * fractionTwo.getDenominator()) <= (fractionOne.getDenominator() * fractionTwo.getNumerator());
}
bool operator!=(Fraction fractionOne, Fraction fractionTwo) {
	return !(fractionOne == fractionTwo);
}

istream& operator>>(istream& in, Fraction& _fraction) {
	in >> _fraction.numerator >> _fraction.denominator;
	return in;
}
ostream& operator<<(ostream& out, Fraction _fraction) {
	if (_fraction.getDenominator() == 1) {
		out << _fraction.getNumerator();
	}
	else {
		out << _fraction.getNumerator() << "/" << _fraction.getDenominator();
	}
	return out;
}

Fraction Fraction::inverseFraction() {
	Fraction inverseFractionTemporary(getDenominator(), getNumerator());
	return inverseFractionTemporary;
}
Fraction Fraction::simplify() {
	int temp = GCD(numerator, denominator);
	numerator /= temp;
	denominator /= temp;
	return *this;
}

int GCD(int paraOne, int paraTwo) {
	paraOne = abs(paraOne);
	paraTwo = abs(paraTwo);
	if (paraTwo == 0) {
		return paraOne;
	}
	return GCD(paraTwo, paraOne % paraTwo);
}