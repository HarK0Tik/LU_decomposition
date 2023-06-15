#pragma once
#include <iostream>
class Fraction
{
public:
	Fraction();
	Fraction(int, int);
	Fraction(const Fraction&);
	Fraction& operator=(const Fraction&);
	Fraction& operator=(const int&);
	Fraction& operator+=(const Fraction&);
	Fraction& operator-=(const Fraction&);
	Fraction& operator*=(const Fraction&);
	Fraction& operator/=(const Fraction&);
	friend bool operator==(const Fraction&, const Fraction&);
	friend bool operator==(const Fraction&, const int&);
	friend bool operator==(const int&, const Fraction&);
	friend Fraction operator+(const Fraction&, const Fraction&);
	friend Fraction operator-(const Fraction&, const Fraction&);
	friend Fraction operator*(const Fraction&, const Fraction&);
	friend Fraction operator/(const Fraction&, const Fraction&);
	friend std::ostream& operator<<(std::ostream&, const Fraction&);
private:
	int numerator;
	int denominator;
	void simplify();
};