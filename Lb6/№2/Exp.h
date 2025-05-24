#pragma once
#include "Function.h"
#include <math.h>

//y = e ^ x
class Exp : public Function
{
protected:
	std::string name;
public:
	Exp() : name("e ^ x") {}
	const std::string& Get_Name() const { return name; }
	void Set_Coeff() {}
	double Get_Val() const { return exp(x); }
};


extern Exp f_exp;
