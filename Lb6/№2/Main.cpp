#include <iostream>
#include <vector> 
#include "Function.h"
#include "Action.h"
#include "Calculation.h"
#include "Tabulation.h"
#include "Any_Action.h"
#include "Parabola.h"
#include "Exp.h"
#include "Line.h"
#include "Menu.h"

using namespace std;

vector<Function*> func_list = { &f_exp, &f_line, &f_parabola };
vector<Action*> act_list = { &calculation, &tabulation, &any_action };

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251"); 

    Menu menu(func_list, act_list);
    while (Function* pObj = menu.Select_Object()) {
        Action* pAct = menu.Select_Action(pObj);
        if (pAct) {
            pAct->Operate(pObj);
        }
        else {
            cout << "Ошибка: действие не выбрано." << endl;
        }
    }
    cout << "Пока\n";
    return 0;
}
