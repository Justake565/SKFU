#include <iostream>
#include "Factory.h"
#include "Menu.h"
#include "SymbString.h"
#include "HexString.h"

#define MAX_LEN_STR 100

void Factory::AddObject() {
    std::cout << "Выберите тип объекта:\n";
    std::cout << "1. Символическая строка" << std::endl;
    std::cout << "2. Шестнадцатеричная строка" << std::endl;

    int item = Menu::SelectItem(2);
    std::string name;
    std::cout << "Введите имя объекта: ";
    std::cin >> name;
    std::cin.ignore();

    std::cout << "Введите стоимость объекта: ";
    char buf[MAX_LEN_STR];
    std::cin.getline(buf, MAX_LEN_STR);
    std::string value = buf;
    AString* pNewObj = nullptr;

    switch (item) {
    case 1:
        pNewObj = new SymbString(name, value);
        break;
    case 2:
        if (!IsHexStrVal(value)) {
            std::cout << "Ошибка!" << std::endl;
            return;
        }
        pNewObj = new HexString(name, value);
        break;
    }

    pObj.push_back(pNewObj);
    std::cout << "Объект добавлен." << std::endl;
}

void Factory::DeleteObject() {
    int nItem = pObj.size();
    if (!nItem) {
        std::cout << "Нет объектов." << std::endl;
        std::cin.get();
        return;
    }

    std::cout << "Удалить один из следующих объектов:\n";
    for (int i = 0; i < nItem; ++i) {
        std::cout << i + 1 << ". " << pObj[i]->GetName() << std::endl;
    }

    int item = Menu::SelectItem(nItem);
    std::string objName = pObj[item - 1]->GetName();
    delete pObj[item - 1]; // Освобождаем память
    pObj.erase(pObj.begin() + item - 1);
    std::cout << "Объект " << objName << " удалено." << std::endl;
    std::cin.get();
}
