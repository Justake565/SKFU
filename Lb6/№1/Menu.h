#pragma once
#include <vector>
#include "Function.h"

class Menu
{
private:
	int Select_Item(int) const;
	std::vector<Function*> pObj;
public:
	Menu(std::vector<Function*>);
	Function* Select_Object() const;
};
