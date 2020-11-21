#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

class Interpreter
{
protected:
	struct Op
	{
		Op(double left, double right, char op) { this->left = left; this->right = right; this->op = op; };
		Op() : Op(0, 0, ' ') {}

		double left, right;
		char op;
	};
	//data
	string inputEq;
	vector<Op> eq;

	//functions
	void simplify();
	void simplify(string inputEq);
	string removeSpaces(string inputEq);
	string handleParenthesis(string inputEq);
	string distributeNeg(string inputEq);
	string distributeMult(string parenLeft, string parenRight);
	vector<string> getVals(string inputEq);
	virtual void fillOp(string inputEq) {};	//was Pure virtual, wouldn't compile
	virtual Op getDouble(string inputEq, int start) { return Op(); };		//if possible, make pure virtual

public:
	//constructors
	Interpreter(string inputEq);
	Interpreter() : Interpreter("") {};

	//accessors
	virtual vector<double> getOtherVariables() { vector<double> empty; return empty; }		//pure virtual again
	string testing()
	{
		return this->inputEq;
	}
};