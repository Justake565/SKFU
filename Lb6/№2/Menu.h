#pragma once
#include <vector>
#include "Function.h"
#include "Action.h"

class Menu
{
private:
	int Select_Item(int) const;
	std::vector<Function*> pObj;
	std::vector<Action*> pAct;
public:
	Menu(std::vector<Function*>, std::vector<Action*>);
	Function* Select_Object() const;
	Action* Select_Action(Function*) const;
};
