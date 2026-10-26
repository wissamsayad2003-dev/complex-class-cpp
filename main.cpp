#include "Complex.h"
#include <iostream>
using namespace std;

int main()
{
	Complex a(1, 2), b(3, 4);

	(a + b).afficher();    // 4+6i
	(a + 2.0).afficher();  // 3+2i
	(2.0 + a).afficher();  // 3+2i

	(a - b).afficher();    // -2-2i
	(a - 2.0).afficher();  // -1+2i
	(5.0 - a).afficher();  // 4-2i

	(a * b).afficher();    // -5+10i
	(a * 2.0).afficher();  // 2+4i
	(2.0 * a).afficher();  // 2+4i

	(a / b).afficher();    // 0.44+0.08i
	(a / 2.0).afficher();  // 0.5+1i
	(2.0 / a).afficher();  // 0.4-0.8i

	cout << boolalpha;
	cout << (b > a) << endl;   // true  (|b| = 5 > |a| = 2.23)
	cout << (a == a) << endl;  // true
	cout << (a != b) << endl;  // true

	Complex c(a);              // copy constructor
	c.afficher();              // 1+2i

	return 0;
}
