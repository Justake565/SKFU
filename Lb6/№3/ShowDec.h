#ifndef SHOWDEC_H
#define SHOWDEC_H

#include "Action.h"

class ShowDec : public Action {
public:
    ShowDec() : name("Показать десятичное значение") {}
    void Operate(AString* pObj) override;
    const std::string& GetName() const override { return name; }

private:
    std::string name; // обозначение операции
};

#endif // SHOWDEC_H
