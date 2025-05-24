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
	virtual void Set_Coeff() = 0;
	void Set_Arg(double arg) { x = arg; }
	virtual double Get_Val() const = 0;
	virtual const std::string& Get_Name() const = 0;
};

#endif // ! FUNCTION_H
