#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <sstream>
#include "Fraction.h"
#include "Fraction.h"

int gcd(int a, int b)
{
	int t;
	if(a < b) {
		t = a;
		a = b;
		b = t;
	}
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

Fraction::Fraction() {
	numerator = 0;
	denominator = 1;
}

Fraction::Fraction(const Fraction& f)
{
	numerator = f.numerator;
	denominator = f.denominator;
}

Fraction::Fraction(int numerator, int denominator) {
	this->numerator = numerator;
	this->denominator = denominator;
	simplify();
}

void Fraction::simplify() {
	int unit = numerator / denominator, g;
	numerator -= unit * denominator;
	g = gcd(numerator, denominator);
	numerator /= g;
	denominator /= g;
	numerator += unit * denominator;
}

Fraction& Fraction::operator=(const Fraction& f) {
	if (this == &f)
		return *this;
	numerator = f.numerator;
	denominator = f.denominator;
	return *this;
}

Fraction& Fraction::operator=(const int& n)
{
	numerator = n;
	denominator = 1;
	return *this;
}

Fraction& Fraction::operator+=(const Fraction& f) {
	*this = *this + f;
	return *this;
}

Fraction& Fraction::operator-=(const Fraction& f) {
	*this = *this - f;
	return *this;
}

Fraction& Fraction::operator*=(const Fraction& f) {
	*this = *this * f;
	return *this;
}

Fraction& Fraction::operator/=(const Fraction& f) {
	*this = *this / f;
	return *this;
}

Fraction operator+(const Fraction& a, const Fraction& b) {
	int numerator = a.numerator * b.denominator + b.numerator * b.denominator;
	int denominator = a.denominator * b.denominator;
	return Fraction(numerator, denominator);
}

Fraction operator-(const Fraction& a, const Fraction& b) {
	int numerator = a.numerator * b.denominator - b.numerator * b.denominator;
	int denominator = a.denominator * b.denominator;
	return Fraction(numerator, denominator);
}

Fraction operator*(const Fraction& a, const Fraction& b) {
	int numerator = a.numerator * b.numerator;
	int denominator = a.denominator * b.denominator;
	return Fraction(numerator, denominator);
}

Fraction operator/(const Fraction& a, const Fraction& b) {
	int numerator = a.numerator * b.denominator;
	int denominator = a.denominator * b.numerator;
	return Fraction(numerator, denominator);
}

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
	std::ostringstream ss;
	ss << f.numerator << '/' << f.denominator;
	std::string s = ss.str();
	out << s;
	return out;
}