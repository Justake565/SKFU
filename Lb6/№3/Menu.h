#ifndef MENU_H
#define MENU_H

#include <vector>
#include "AString.h"
#include "Action.h"
#include "Factory.h"

typedef enum { AddObj, DelObj, WorkWithObj, Exit } JobMode;

class Menu {
public:
    Menu(std::vector<Action*> _pAct) : pAct(_pAct) {}
    JobMode SelectJob() const;
    AString* SelectObject(const Factory& fctry) const;
    Action* SelectAction(const AString* pObj) const;
    static int SelectItem(int nItem);

private:
    std::vector<Action*> pAct;
};

#endif // MENU_H
