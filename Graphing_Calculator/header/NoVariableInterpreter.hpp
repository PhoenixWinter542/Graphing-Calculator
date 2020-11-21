#pragma once
#include "Interpreter.hpp"
#include <iostream>
class NoVar :  public Interpreter
{
protected:
	virtual void fillOp(string inputEq);
	Op getDouble(string inputEq, int start);

public:
	NoVar() : NoVar("") {}
	NoVar(string inputEq) : Interpreter(inputEq)
	{
		this->fillOp(this->inputEq);
		for (int i = 0; i < this->eq.size(); i++)
		{
			std::cout << this->eq[i].left << this->eq[i].op << this->eq[i].right << "\n";
		}

	};
};