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
	NoVar(string inputEq) { this->fillOp(inputEq); }

	//Accessors
	virtual vector<double> getPoint();
	virtual vector<double> getPoint(string somePoint) { return this->getPoint(0); }		//Will always be something like the lines x=1 or y=1, so this is fine
};