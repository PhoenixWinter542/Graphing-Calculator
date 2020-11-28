#pragma once
#include "handleVars.hpp"
#include <iostream>
class OneVar : public HandleVars
{
public:
	//Constructors
	OneVar() : OneVar("") {}
	OneVar(string inputEq) : HandleVars(inputEq) {}

	//Accessors
	//virtual double getPoint(string somePoint) { somePoint; }
};