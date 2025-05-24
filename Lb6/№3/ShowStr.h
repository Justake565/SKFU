#ifndef SHOWSTR_H
#define SHOWSTR_H

#include "Action.h"

class ShowStr : public Action {
public:
    ShowStr() : name("Показать строковое значение") {}
    void Operate(AString* pObj) override;
    const std::string& GetName() const override { return name; }

private:
    std::string name; // обозначение операции
};

#endif // SHOWSTR_H
