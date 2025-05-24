#ifndef SHOWBIN_H
#define SHOWBIN_H

#include "Action.h"

class ShowBin : public Action {
public:
    ShowBin() : name("Показать двоичное значение") {}
    void Operate(AString* pObj) override;
    const std::string& GetName() const override { return name; }

private:
    std::string GetBinary(AString* pObj) const;
    std::string name; // обозначение операции
};

#endif // SHOWBIN_H
