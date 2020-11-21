#pragma once
#include <string>
#include <vector>
#include "handleNoVars.hpp"
#include "handleOneVar.hpp"

using std::string;
using std::vector;

class Interpreter
{
protected:
	//data
	string eq;

	//functions
	string removeSpaces(string eq);
	string handleParenthesis(string eq, vector<vector<int>> parenLocations);
	string findParenthesis(string eq);
	string distributeNeg(string eq);
	string distributeMult(string parenLeft, string parenRight);
	vector<string> getVals(string eq);

public:
	//constructors
	Interpreter(string eq) { this->eq = eq; this->getParsedEquation(); };
	Interpreter() : Interpreter("") {};

	//accessors
	HandleVars* getParsedEquation() { return this->getParsedEquation(this->eq); };
	HandleVars* getParsedEquation(string eq);

	//mutators
	void setEquation(string equation) { this->getParsedEquation(equation); };
};