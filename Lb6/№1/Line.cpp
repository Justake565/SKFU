#include "Line.h"
#include <iostream>

using namespace std;

void Line::Calculate() {
	cout << "Расчет функции y = " << name << endl;
	cout << "Enter a = "; cin >> a;
	cout << "Enter b = "; cin >> b;
	cout << "Enter x = "; cin >> x;
	cin.get();
	cout << "y = " << a * x + b << endl;
	cin.get();
}

Line f_line;
