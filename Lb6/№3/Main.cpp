#include <iostream>
#include <vector>
#include "AString.h"
#include "SymbString.h"
#include "HexString.h"
#include "Action.h"
#include "ShowStr.h"
#include "ShowDec.h"
#include "ShowBin.h"
#include "Factory.h"
#include "Menu.h"

using namespace std;

Action* pActs[] = { new ShowStr(), new ShowDec(), new ShowBin() };
vector<Action*> actionList(pActs, pActs + sizeof(pActs) / sizeof(Action*));

int main() {
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    Factory factory;
    Menu menu(actionList);
    JobMode jobMode;

    while ((jobMode = menu.SelectJob()) != Exit) {
        switch (jobMode) {
        case AddObj:
            factory.AddObject();
            break;
        case DelObj:
            factory.DeleteObject();
            break;
        case WorkWithObj: {
            AString* pObj = menu.SelectObject(factory);
            Action* pAct = menu.SelectAction(pObj);
            if (pAct) pAct->Operate(pObj);
            break;
        }
        }
        cin.get();
    }

    cout << "Пока!\n";
    return 0;
}

