#pragma once

#include <iostream>

#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;

class HandleVars		//Abstract class
{
protected:
	string eq;

	double solveEquation(string eq);

	virtual void fillOp(string inputEq) = 0;
	HandleVars(string eq) { this->eq = eq; };

public:
	virtual double getPoint() = 0;
	virtual double getPoint(string somePoint) = 0;
};
