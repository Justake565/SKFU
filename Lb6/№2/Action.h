#pragma once
#include "Function.h"
class Action
{
public:
	virtual ~Action() {}
	virtual void Operate(Function*) = 0;
	virtual const std::string& Get_Name() const = 0;
};
