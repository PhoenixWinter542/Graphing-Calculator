#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

struct op
{
	string a, b, op;
};

class Interpreter
{
protected:
	//data
	string inputEq;
	vector<op> eq;

	//functions
	void simplify();
	void simplify(string inputEq);
	string removeSpaces(string inputEq);
	string handleParenthesis(string inputEq);
	string distributeNeg(string inputEq);
	string distributeMult(string parenLeft, string parenRight);
	vector<string> getVals(string inputEq);

public:
	//constructors
	Interpreter(string inputEq);
	Interpreter() : Interpreter("") {};

	//accessors
	string testing()
	{
		return this->inputEq;
	}
};