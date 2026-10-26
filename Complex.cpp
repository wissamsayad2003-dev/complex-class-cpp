#include "Complex.h"
#include <iostream>
#include <cmath>
using namespace std;


Complex::Complex(double r, double i) : re(r), img(i) {}

Complex::Complex(const Complex& c) : re(c.re), img(c.img) {}

Complex::~Complex() {}


Complex Complex::operator+(const Complex& c) const
{
	return Complex(re + c.re, img + c.img);
}

Complex Complex::operator+(double a) const
{
	return Complex(re + a, img);
}


Complex Complex::operator-(const Complex& c) const
{
	return Complex(re - c.re, img - c.img);
}

Complex Complex::operator-(double a) const
{
	return Complex(re - a, img);
}


Complex Complex::operator*(const Complex& c) const
{
	return Complex(re * c.re - img * c.img,
		re * c.img + img * c.re);
}

Complex Complex::operator*(double a) const
{
	return Complex(re * a, img * a);
}


Complex Complex::operator/(const Complex& c) const
{
	double d = c.re * c.re + c.img * c.img;
	if (d == 0) {
		cerr << "Division par zero" << endl;
		return Complex(0, 0);
	}
	return Complex((re * c.re + img * c.img) / d,
		(img * c.re - re * c.img) / d);
}

Complex Complex::operator/(double a) const
{
	if (a == 0) {
		cerr << "Division par zero" << endl;
		return Complex(0, 0);
	}
	return Complex(re / a, img / a);
}


bool Complex::operator>(const Complex& c) const
{
	return (re * re + img * img) > (c.re * c.re + c.img * c.img);
}

bool Complex::operator==(const Complex& c) const
{
	return re == c.re && img == c.img;
}

bool Complex::operator!=(const Complex& c) const
{
	return !(*this == c);
}


void Complex::afficher() const
{
	cout << re << (img >= 0 ? "+" : "-") << fabs(img) << "i" << endl;
}

