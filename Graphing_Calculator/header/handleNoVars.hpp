#pragma once
#include "handleVars.hpp"
#include <iostream>
class NoVar :  public HandleVars
{
protected:
	virtual void fillOp(string inputEq);
	Op getDouble(string inputEq, int start);

public:
	//Constructors
	NoVar() : NoVar("") {}
	NoVar(string inputEq) : HandleVars(inputEq) {}

	//Accessors
	virtual double getPoint();
	virtual double getPoint(string somePoint) { this->fillOp(somePoint);  return this->getPoint(); }		//Will always be something like the lines x=1 or y=1, so this is fine
};