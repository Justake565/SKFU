#pragma once
#include "Action.h"
class Any_Action : public Action
{
private:
	std::string name;
public:
	Any_Action() : name("Любое действие") {}
	const std::string& Get_Name() const { return name; };
	void Operate(Function*);
};

extern Any_Action any_action;
