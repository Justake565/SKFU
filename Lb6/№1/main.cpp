#include <iostream>
#include "Function.h"
#include "Exp.h"
#include "Line.h"
#include "Parabola.h" 
#include "Menu.h"

using namespace std;

// Создаем глобальные объекты
Exp f_exp;
Line f_line;
Parabola f_parabola; 
vector<Function*> func_list = { &f_exp, &f_line, &f_parabola };

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    Menu menu(func_list);
    while (Function* pObj = menu.Select_Object()) {
        pObj->Calculate();
    }
    cout << "Пока\n";
    return 0;
}

