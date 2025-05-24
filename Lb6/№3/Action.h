#ifndef ACTION_H
#define ACTION_H

#include "AString.h"

class Action {
public:
    virtual ~Action() {}
    virtual void Operate(AString* pObj) = 0;
    virtual const std::string& GetName() const = 0;

protected:
    long GetDecimal(AString* pObj) const;
};

#endif // ACTION_H

