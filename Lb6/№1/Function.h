#pragma once
#ifndef  FUNCTION_H
#define FUNCTION_H

#include <string>
class Function
{
protected:
	double x; 
public:
	virtual ~Function() {}
	virtual const std::string& Get_Name() const = 0;
	virtual void Calculate() = 0;
};

#endif // ! FUNCTION_H
