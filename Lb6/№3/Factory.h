#ifndef FACTORY_H
#define FACTORY_H

#include <vector>
#include "AString.h"

class Factory {
    friend class Menu; // Даем доступ классу Menu к закрытым членам Factory
public:
    Factory() {}
    void AddObject();
    void DeleteObject();
private:
    std::vector<AString*> pObj; // Убедитесь, что pObj является вектором указателей на AString
};

#endif // FACTORY_H
