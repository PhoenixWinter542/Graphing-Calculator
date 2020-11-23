#pragma once

#include <iostream>

#include <vector>
#include <string>

using std::vector;
using std::string;

class HandleVars		//Abstract class
{
protected:
	struct Op
	{
		Op(double left, double right, char op) { this->left = left; this->right = right; this->op = op; };
		Op() : Op(0, 0, ' ') {}

		double left, right;
		char op;
	};
	string eq;

	double solveEquation(string eq);

	virtual void fillOp(string inputEq) = 0;
	virtual Op getDouble(string inputEq, int start) = 0;
	HandleVars(string eq) { this->eq = eq; };

public:
	virtual vector<double> getPoint() = 0;
	virtual vector<double> getPoint(string somePoint) = 0;
};