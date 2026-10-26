#include "Complex.h"
#include <iostream>
#include <cmath>
using namespace std;

// ---------- Constructors / destructor ----------
Complex::Complex(double r, double i) : re(r), img(i) {}

Complex::Complex(const Complex& c) : re(c.re), img(c.img) {}

Complex::~Complex() {}

// ---------- Addition ----------
Complex Complex::operator+(const Complex& c) const
{
	return Complex(re + c.re, img + c.img);
}

Complex Complex::operator+(double a) const
{
	return Complex(re + a, img);
}

// ---------- Subtraction ----------
Complex Complex::operator-(const Complex& c) const
{
	return Complex(re - c.re, img - c.img);
}

Complex Complex::operator-(double a) const
{
	return Complex(re - a, img);
}

// ---------- Multiplication ----------
Complex Complex::operator*(const Complex& c) const
{
	return Complex(re * c.re - img * c.img,
		re * c.img + img * c.re);
}

Complex Complex::operator*(double a) const
{
	return Complex(re * a, img * a);
}

// ---------- Division ----------
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

// ---------- Comparisons (on the modules for >) ----------
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

// ---------- Display ----------
void Complex::afficher() const
{
	cout << re << (img >= 0 ? "+" : "-") << fabs(img) << "i" << endl;
}

// ---------- double (op) Complex (friends) ----------
Complex operator+(double a, const Complex& c)
{
	return Complex(a + c.re, c.img);
}

Complex operator-(double a, const Complex& c)
{
	return Complex(a - c.re, -c.img);
}

Complex operator*(double a, const Complex& c)
{
	return Complex(a * c.re, a * c.img);
}

Complex operator/(double a, const Complex& c)
{
	return Complex(a, 0.0) / c;
}