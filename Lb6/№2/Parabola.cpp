#include "Parabola.h"
#include <iostream>

using namespace std;

void Parabola::Set_Coeff() {
	cout << "Введите a = "; cin >> a;
	cout << "Введите b = "; cin >> b;
	cout << "Введите c = "; cin >> c;
	cin.get();
}

Parabola f_parabola;
