#include <iostream>
#include "Action.h"
#include "HexString.h"

long Action::GetDecimal(AString* pObj) const {
    if (dynamic_cast<HexString*>(pObj)) {
        long dest;
        std::string source = pObj->GetVal();
        sscanf_s(source.c_str(), "%lx", &dest); // Используйте sscanf_s
        return dest;
    }
    else {
        std::cout << "Действие не поддерживается." << std::endl;
        return -1;
    }
}
