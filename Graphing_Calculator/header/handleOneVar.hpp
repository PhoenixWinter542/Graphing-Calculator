#pragma once
#include "handleVars.hpp"
#include <iostream>
class OneVar : public HandleVars
{
protected:
	virtual void fillOp(string inputEq);

public:
	//Constructors
	OneVar() : OneVar("") {}
	OneVar(string inputEq) : HandleVars(inputEq) {}

	//Accessors
	virtual double getPoint(string somePoint) { this->fillOp(somePoint); }
};