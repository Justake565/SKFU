#include "Exp.h"
#include <iostream>
#include <math.h>
using namespace std;

void Exp::Calculate() {
	cout << "Расчет для функции y = " << name << endl;
	cout << "Выход x = "; cin >> x;
	cin.get();
	cout << "y = " << exp(x) << endl;
	cin.get();
}


Exp f_exp;
