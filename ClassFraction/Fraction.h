#ifndef FRACTION_H
#define FRACTION_H
#pragma once

#include <iostream>

using namespace std;

class Fraction {
private:
	int numerator, denominator;
public:
	Fraction(int = 0, int = 1);
	int getNumerator();
	int getDenominator();
	void setNumerator(int);
	void setDenominator(int);
	friend Fraction operator+(Fraction, Fraction);
	friend Fraction operator-(Fraction, Fraction);
	friend Fraction operator*(Fraction, Fraction);
	friend Fraction operator/(Fraction, Fraction);
	//Fraction& operator+=(Fraction&);
	friend Fraction& operator+=(Fraction&, Fraction);
	friend Fraction& operator-=(Fraction&, Fraction);
	friend Fraction& operator*=(Fraction&, Fraction);
	friend Fraction& operator/=(Fraction&, Fraction);
	friend bool operator>(Fraction, Fraction);
	friend bool operator<(Fraction, Fraction);
	friend bool operator==(Fraction, Fraction);
	friend bool operator>=(Fraction, Fraction);
	friend bool operator<=(Fraction, Fraction);
	friend bool operator!=(Fraction, Fraction);
	friend istream& operator>>(istream&, Fraction&);
	friend ostream& operator<<(ostream&, Fraction);
	Fraction inverseFraction();
	Fraction simplify();
};

int GCD(int paraOne, int paraTwo);

#endif