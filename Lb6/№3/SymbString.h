#ifndef SYMBSTRING_H
#define SYMBSTRING_H

#include <string>
#include "AString.h"

class SymbString : public AString {
public:
    SymbString(std::string _name) : name(_name) {}
    SymbString(std::string _name, std::string _val) : name(_name), val(_val) {}

    const std::string& GetName() const override { return name; }
    const std::string& GetVal() const override { return val; }
    int GetSize() const override { return val.size(); }

private:
    std::string name;
    std::string val;
};

#endif // SYMBSTRING_H
