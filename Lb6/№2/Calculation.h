#pragma once
#include "Action.h"
class Calculation : public Action
{
private:
	std::string name;
public:
	Calculation() : name("Расчет") {}
	const std::string& Get_Name() const { return name; };
	void Operate(Function*);
};

extern Calculation calculation;
