#pragma once
#include "Function.h"


class Exp : public Function
{
protected:
	std::string name;
public:
	Exp() : name("e ^ x") {}
	const std::string& Get_Name() const { return name; }
	void Calculate();
};
