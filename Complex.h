#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
private:
	double re;
	double img;

public:
	// Constructors / destructor
	Complex(double r = 0.0, double i = 0.0);
	Complex(const Complex& c);
	~Complex();

	// Addition
	Complex operator+(const Complex& c) const;
	Complex operator+(double a) const;

	// Subtraction
	Complex operator-(const Complex& c) const;
	Complex operator-(double a) const;

	// Multiplication
	Complex operator*(const Complex& c) const;
	Complex operator*(double a) const;

	// Division
	Complex operator/(const Complex& c) const;
	Complex operator/(double a) const;

	// Comparisons
	bool operator>(const Complex& c) const;
	bool operator==(const Complex& c) const;
	bool operator!=(const Complex& c) const;

	// Display
	void afficher() const;

	// double (op) Complex
	friend Complex operator+(double a, const Complex& c);
	friend Complex operator-(double a, const Complex& c);
	friend Complex operator*(double a, const Complex& c);
	friend Complex operator/(double a, const Complex& c);
};

#endif