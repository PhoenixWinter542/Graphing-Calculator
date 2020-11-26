#include "../header/handleNoVars.hpp"
#include <iostream>
using std::cout;

//Only gets digits, no signs are taken		----------------BROKEN------------------
NoVar::Op NoVar::getDouble(string inputEq, int start)		//Might be the only function that needs to be virtual?
{
	bool leftDone = false, rightDone = false;
	Op result;
	result.op = inputEq.at(start);
	for (int i = 0; i < inputEq.size(); i++)		//Will go out of bounds if not checked
	{
		if (!leftDone)
		{
			if (start - i >= 0)
			{
				if (!isdigit(inputEq.at(start - i)))		//Likely cause of any issues with double operators eg.(*-), (--), or(+-)
				{
					leftDone = true;
					result.left = stod(inputEq.substr(1 + start - i, i - 1));
				}
			}
			else
			{
				leftDone = true;
				result.left = stod(inputEq.substr(0, start));
			}
		}
		if (!rightDone)
		{
			if (start + 1 < inputEq.size())
			{
				if (!isdigit(inputEq.at(start + 1)))
				{
					rightDone = true;
					result.right = stod(inputEq.substr(start + 1, i - 1));
				}
			}
			else
			{
				rightDone = true;
				result.right = stod(inputEq.substr(start + 1, i - 1));
			}
		}

		if (leftDone && rightDone)
		{
			cout << result.left << "\t" << result.op << "\t" << result.right << "\n";
			return result;
		}
	}
}

double NoVar::getPoint()
{
	return this->solveEquation(this->eq);		//<<<<<<<<<<<<<<<<<<<<--------------------------------------Allows for early testing of other systems, unhelpfull otherwise
}


void NoVar::fillOp(string inputEq)
{
	vector<int> add, sub, mult, div, pow, paren;
	for (int i = 0; i < inputEq.size(); i++)		//Gets the amount of each equation type
	{
		switch (inputEq.at(i))
		{
		case '+':
			add.push_back(i);
			break;
		case '-':
			sub.push_back(i);
			break;
		case '*':
			mult.push_back(i);
			break;
		case '/':
			div.push_back(i);
			break;
		case '^':
			pow.push_back(i);
			break;
		}
	}
	int runtime = add.size() + sub.size() + mult.size() + div.size() + pow.size() + paren.size();		//This might need to change if parenthesis are handled differently
	int startLocation = 0;
	vector<int> searchOp;
	if (runtime > 0)		//for loop runs when runtime == 0 otherwise
	{
		for (int i = 0; i < runtime; i++)
		{
			if (!pow.empty())
			{
				searchOp = pow;
			}
			else if (!mult.empty())		//Mult before division in an attempt to reduce decimals
			{
				searchOp = mult;
			}
			else if (!div.empty())
			{
				searchOp = div;
			}
			else if (!sub.empty())
			{
				searchOp = sub;
			}
			else if (!add.empty())
			{
				searchOp = add;
			}
			searchOp.erase(searchOp.begin());
		}
	}
}