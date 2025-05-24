#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(vector<Function*> _pObj, vector<Action*> _pAct) : pObj(_pObj), pAct(_pAct) {
	pObj.push_back(0); 
}

Function* Menu::Select_Object() const {
	int n_item = pObj.size();
	cout << "=============================================\n";
	cout << "Выберите одну из следующих функцийn\n";

	for (int i = 0; i < n_item; ++i) {
		cout << i + 1 << ". ";


		if (pObj[i])
			cout << pObj[i]->Get_Name() << endl;
		else
			cout << "Выход" << endl;
	}
	int item = Select_Item(n_item);
	return pObj[item - 1];
}

Action* Menu::Select_Action(Function* pObj) const {
	int n_item = pAct.size();
	cout << "=============================================\n";
	cout << "Выберите одно из следующих действий :\n";

	for (int i = 0; i < n_item; ++i) {
		cout << i + 1 << ". ";
		cout << pAct[i]->Get_Name() << endl;
	}
	int item = Select_Item(n_item);
	return pAct[item - 1];
}

int Menu::Select_Item(int n_item) const {
	cout << "=============================================\n";
	int item;
	while (true) {
		cin >> item;
		if ((item > 0) && (item <= n_item) && (cin.peek() == '\n')) {
			cin.get(); break;
		}
		else {
			cout << "Ошибка(должно быть число от 1 до " << n_item
				<< "):" << endl;
			cin.clear();
			while (cin.get() != '\n') {};
		}
	}
	return item;
}
