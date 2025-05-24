#pragma once
#include "Function.h"

class Parabola : public Function
{
protected:
	std::string name;
	double a, b, c;
public:
	Parabola() : name("a * x ^ 2 + b * x + c") {}
	const std::string& Get_Name() const { return name; }
	void Set_Coeff();
	double Get_Val() const { return a * x * x + b * x + c; }
};

extern Parabola f_parabola;
