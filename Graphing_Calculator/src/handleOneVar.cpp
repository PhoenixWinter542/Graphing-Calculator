#include "../header/handleOneVar.hpp"
#include <iostream>
using std::cout;


void OneVar::fillOp(string inputEq)
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
	int runtime = add.size() + sub.size() + mult.size() + div.size() + pow.size();
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