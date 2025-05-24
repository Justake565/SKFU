#include <iostream>
#include "Menu.h"

JobMode Menu::SelectJob() const {
    std::cout << "===========\n";
    std::cout << "Выберите один из следующих режимов работы:\n";
    std::cout << "1. Добавить объект" << std::endl;
    std::cout << "2. Удалить объект" << std::endl;
    std::cout << "3. Работать с объектом" << std::endl;
    std::cout << "4. Выход" << std::endl;

    int item = SelectItem(4);
    return (JobMode)(item - 1);
}

AString* Menu::SelectObject(const Factory& fctry) const {
    int nItem = fctry.pObj.size();
    if (nItem == 0) {
        std::cout << "Нет объектов." << std::endl;
        std::cin.get();
        return nullptr;
    }

    std::cout << "Выберите один из следующих объектов:\n";
    for (int i = 0; i < nItem; ++i) {
        std::cout << i + 1 << ". " << fctry.pObj[i]->GetName() << std::endl;
    }

    int item = SelectItem(nItem);
    return fctry.pObj[item - 1];
}

Action* Menu::SelectAction(const AString* pObj) const {
    if (!pObj) return nullptr;

    int nItem = pAct.size();
    std::cout << "Выберите одно из следующих действий:\n";
    for (int i = 0; i < nItem; ++i) {
        std::cout << i + 1 << ". " << pAct[i]->GetName() << std::endl;
    }

    int item = SelectItem(nItem);
    return pAct[item - 1];
}

int Menu::SelectItem(int nItem) {
    int item;
    std::cin >> item;
    while (item < 1 || item > nItem) {
        std::cout << "Недопустимый выбор, попробуйте снова: ";
        std::cin >> item;
    }
    return item;
}

