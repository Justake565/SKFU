#include <iostream>
#include "ShowBin.h"
#include "ShowDec.h"

void ShowBin::Operate(AString* pObj) {
    std::cout << pObj->GetName() << ": ";
    std::cout << GetBinary(pObj) << std::endl;
    std::cin.get();
}

std::string ShowBin::GetBinary(AString* pObj) const {
    int nBinDigit = 4 * pObj->GetSize();
    std::string binStr(nBinDigit, '0');
    long decVal = GetDecimal(pObj);
    if (decVal == -1)
        return "";

    for (int k = 0; k < nBinDigit; ++k) {
        binStr[k] = (decVal & (1 << (nBinDigit - 1 - k))) ? '1' : '0';
    }
    return binStr;
}

