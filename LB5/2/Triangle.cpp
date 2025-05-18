#define _CRT_SECURE_NO_WARNINGS

#include "Triangle.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;


Triangle::Triangle(Point _v1, Point _v2, Point _v3, const char* ident) : v1(_v1), v2(_v2), v3(_v3) {
	char buf[16];

	objID = new char[strlen(ident) + 1];
	strcpy(objID, ident);
	count++;

	sprintf(buf, "Треугольник %d", count);

	name = new char[strlen(buf) + 1];
	strcpy(name, buf);

	a = sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
	b = sqrt((v2.x - v3.x) * (v2.x - v3.x) + (v2.y - v3.y) * (v2.y - v3.y));
	c = sqrt((v1.x - v3.x) * (v1.x - v3.x) + (v1.y - v3.y) * (v1.y - v3.y));

	cout << "Constructor_l for: " << objID
		<< " (" << name << " ) " << endl; 
}

Triangle::Triangle(const char* ident) {
	char buf[16];
	objID = new char[strlen(ident) + 1];
	strcpy(objID, ident);

	count++;
	sprintf(buf, "Треугольник %d", count);
	name = new char[strlen(buf) + 1];

	strcpy(name, buf);
	a = b = c = 0;

	cout << "Constructor_2 for: " << objID << " (" << name << ")" << endl;
}

Triangle::~Triangle() {
	cout << "Destructor for: " << objID << endl;
	delete[] objID;
	delete[] name;
}


void Triangle::Show() const {
	cout << name << ":";
	v1.Show(); v2.Show(); v3.Show();
	cout << endl;
}

void Triangle::ShowSideAndArea() const {
	double p = (a + b + c) / 2;
	double s = sqrt(p * (p - a) * (p - b) * (p - c));
	cout << " • " << endl;
	cout << name << ":";
	cout.precision(4);
	cout << " a= " << setw(5) << a;
	cout << ". b= " << setw(5) << b;
	cout << ". c= " << setw(5) << c;
	cout << ";\ts= " << s << endl;
}
