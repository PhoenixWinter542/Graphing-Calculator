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

	HandleVars(string eq) { this->eq = eq; };

public:
	virtual double getPoint(string somePoint) = 0;
};
