#pragma once
#include "Function.h"

//y = a * x + b
class Line : public Function
{
protected:
	std::string name;
	double a;
	double b;
public:
	Line() : name("a * x + b") {}
	const std::string& Get_Name() const { return name; }
	void Calculate();
};

extern Line f_line;
