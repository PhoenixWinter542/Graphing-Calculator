#include "../header/Interpreter.hpp"
//for testing only
#include <iostream>
using std::cout;

void Interpreter::simplify()
{
	this->simplify(this->inputEq);
}

void Interpreter::simplify(string inputEq)
{
	inputEq = "(x+31*5)(3/5+1-72)";
	cout << inputEq << "\n\n";
	inputEq = this->distributeMult("x+31*5", "3/5+1-72");

	//inputEq = this->removeSpaces(inputEq);
	//inputEq = this->handleParenthesis(inputEq);


	cout << "\n " << inputEq << "\n";
}

string Interpreter::removeSpaces(string inputEq)
{
	for (int i = 0; i < inputEq.size(); i++)
	{
		if (inputEq.at(i) == ' ')
			inputEq.erase(i--, 1);
	}
	return inputEq;
}

string Interpreter::handleParenthesis(string inputEq)	//Doesn't handle distributive property
{
	int openParen = 0;		//Used to track how many open parenthesis have been found	|	parenFound(+1 if open, -1 if closed)
	int parenStart;			//Tracks location of initial openParen
	for (int i = 0; i < inputEq.size(); i++)
	{
		if (inputEq.at(i) == '(')
			if (openParen++ == 0)
				parenStart = i;
		if (inputEq.at(i) == ')')
			if (--openParen == 0)
			{
				string temp = this->handleParenthesis(inputEq.substr(parenStart + 1, i - 1 - parenStart));	//temp = simplified inner paren
				if (parenStart != 0)
					switch (inputEq.at(parenStart - 1))
					{
					case '+':
						//Does anything even need to happen here?
						break;
					case '-':
						inputEq.erase(parenStart - 1, 1);
						i--; parenStart--;	//Adjusts for deletion of leading '-'
						temp = this->distributeNeg(temp);
						break;
					case '*':	//Same as ), will drop down into the ) case
					case ')':

						break;
					case '/':

						break;
					case '^':

						break;
					}
				if (parenStart != 0)
					if (parenStart != 0 && inputEq.at(parenStart - 1) == '+' && inputEq.at(parenStart + 1) == '-')
						inputEq.erase(parenStart - 1, 1);
				inputEq.replace(parenStart, 1 + i - parenStart, temp);	//replaces old paren with new simplified version	|	removes outer parenthesis
				i = i - 2;
			}
	}
	cout << " " << inputEq << "\n";
	return inputEq;
}

vector<string> Interpreter::getVals(string inputEq)
{
	vector<string> parenVals;
	bool digitStarted = false;
	int firstPos = 0;
	for (int i = 0; i < inputEq.size(); i++)
	{
		char val = inputEq.at(i);
		if (isdigit(val) || val == '.' || isalpha(val))
		{
			if (digitStarted == false)
			{
				digitStarted = true;
				firstPos = i;
				if (i != 0 && inputEq.at(i - 1) == '-')
					firstPos--;
			}
		}
		if (i != 0 && val == '+' || val == '-')
		{
			digitStarted = false;
			parenVals.push_back(inputEq.substr(firstPos, i - firstPos));
			cout << inputEq.substr(firstPos, i - firstPos) << "\n";
		}
	}
	parenVals.push_back(inputEq.substr(firstPos, inputEq.size() - firstPos));
	cout << inputEq.substr(firstPos, inputEq.size() - firstPos) << "\n";
	return parenVals;
}

string Interpreter::distributeMult(string parenLeft, string parenRight)
{
	vector<string> parenValsLeft = this->getVals(parenLeft), parenValsRight = this->getVals(parenRight);
	string result = "";
	for (int i = 0; i < parenValsLeft.size(); i++)
	{
		for (int j = 0; j < parenValsRight.size(); j++)
		{
			result += parenValsLeft[i] + "*" + parenValsRight[j] + "+";
		}
	}
	result.pop_back();
	return result;
}

string Interpreter::distributeNeg(string inputEq)
{
	bool firstDigit = true;
	for (int i = 0; i < inputEq.size(); i++)
	{
		if (isdigit(inputEq.at(i)))
		{
			if (i == 0)
			{
				inputEq.insert(0, 1, '+');	//Second if() assumes a sign is given
				i++;
			}
			if (firstDigit == true)
			{
				firstDigit = false;
				if (inputEq.at(i - 1) == '+')	//flips sign to negative
				{
					inputEq.erase(--i, 1);
					inputEq.insert(i, 1, '-');
				}
				else if (inputEq.at(i - 1) == '-')	//flips sign to positive
				{
					inputEq.erase(--i, 1);
					inputEq.insert(i, 1, '+');
				}
			}
		}
		else
			firstDigit = true;
	}
	return inputEq;
}

Interpreter::Interpreter(string inputEq)
{
	this->inputEq = inputEq;
	this->simplify();
}
