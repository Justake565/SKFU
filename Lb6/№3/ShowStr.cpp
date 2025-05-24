#include <iostream>
#include "ShowStr.h"

void ShowStr::Operate(AString* pObj) {
    std::cout << pObj->GetName() << ": " << pObj->GetVal() << std::endl;
    std::cin.get();
}
