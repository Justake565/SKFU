#include "Any_Action.h"
#include <iostream>
using namespace std;

void Any_Action::Operate(Function* func) {
	cout << "Здесь может быть ваша реклама!\n";
	cin.get();
}


Any_Action any_action;
