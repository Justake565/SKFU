#pragma once
#include "Function.h"

// y = a * x ^ 2 + b * x + c
class Parabola : public Function
{
protected:
	std::string name;
	double a, b, c;
public:
	Parabola() : name("a * x ^ 2 + b * x + c") {}
	const std::string& Get_Name() const { return name; }
	void Calculate();
};

extern Parabola f_parabola;
