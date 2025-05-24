#include <iostream>
#include "HexString.h"
#include "AString.h"
bool IsHexStrVal(const std::string& _str) {
    for (char c : _str) {
        if (alph.find(c) == std::string::npos) {
            return false;
        }
    }
    return true;
}

