#include <iostream>
#include "ShowDec.h"
#include "HexString.h"

void ShowDec::Operate(AString* pObj) {
    std::cout << pObj->GetName() << ": ";
    long decVal = GetDecimal(pObj);
    if (decVal != -1)
        std::cout << decVal;
    std::cout << std::endl;
    std::cin.get();
}
