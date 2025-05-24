#include "Parabola.h"
#include <iostream>
using namespace std;

void Parabola::Calculate() {
	cout << "Расчет функции y = " << name << endl;
	cout << "Enter a = "; cin >> a;
	cout << "Enter b = "; cin >> b;
	cout << "Enter c = "; cin >> c;
	cout << "Enter x = "; cin >> x;
	cin.get();
	cout << "y = " << a * x + b * x + c << endl;
	cin.get();
}
