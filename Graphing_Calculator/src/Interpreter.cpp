#include "../header/Interpreter.hpp"
//for testing only
#include <iostream>
using std::cout;

HandleVars* Interpreter::getParsedEquation(string eq)
{
	eq = this->removeSpaces(eq);
	eq = this->findParenthesis(eq);
	return new NoVar();		//-------------------------Needs Changed-------------------------------------
}

string Interpreter::removeSpaces(string eq)
{
	for (int i = 0; i < eq.size(); i++)
	{
		if (eq.at(i) == ' ')
			eq.erase(i--, 1);
	}
	return eq;
}

string Interpreter::findParenthesis(string eq)
{
	vector<vector<int>> parenLocations;
	int openParen = 0;		//Used to track how many open parenthesis have been found	|	parenFound(+1 if open, -1 if closed)
	vector<int> paren;			//Tracks location of both parenthesis 0='(' 1=')'
	for (int i = 0; i < eq.size(); i++)
	{
		if (eq.at(i) == '(')
			if (openParen++ == 0)
				paren.push_back(i);
		if (eq.at(i) == ')')
			if (--openParen == 0)
			{
				paren.push_back(i);
				parenLocations.push_back(paren);
			}
	}
	return handleParenthesis(eq, parenLocations);
}

string Interpreter::handleParenthesis(string eq, vector<vector<int>> parenLocations)
{
	int openParen = 0;		//Used to track how many open parenthesis have been found	|	parenFound(+1 if open, -1 if closed)
	int parenStart = 0;		//Tracks location of initial openParen
	for (int i = 0; i < eq.size(); i++)
	{
		if (eq.at(i) == '(')
			if (openParen++ == 0)
				parenStart = i;
		if (eq.at(i) == ')')
			if (--openParen == 0)
			{
				string temp = this->findParenthesis(eq.substr(parenStart + 1, i - 1 - parenStart));	//temp = simplified inner paren
				if (parenStart != 0)		//Handle special cases in here
					switch (eq.at(parenStart - 1))
					{
					case '+':
						//Does anything even need to happen here?
						break;
					case '-':
						eq.erase(parenStart - 1, 1);
						i--; parenStart--;	//Adjusts for deletion of leading '-'
						temp = this->distributeNeg(temp);
						break;
					case '*':	//Not needed?
						break;
					case ')':
						if (i + 1 < eq.size())		//Guard against out of bounds
							if (eq.at(i + 1) != '(' || i + 2 < eq.size() && eq.at(i + 1) == '*' && eq.at(i + 2) == '(')	//if its paren times paren ()*() or ()()
								;
						break;
					case '/':

						break;
					case '^':

						break;
					}
				if (parenStart != 0)
					if (parenStart != 0 && eq.at(parenStart - 1) == '+' && eq.at(parenStart + 1) == '-')
						eq.erase(parenStart - 1, 1);
				eq.replace(parenStart, 1 + i - parenStart, temp);	//replaces old paren with new simplified version	|	removes outer parenthesis
				i = i - 2;
			}
	}
	cout << " " << eq << "\n";
	return eq;
}


//-------------------Here Lies Possibly Unnessesary Functions-------------------



string Interpreter::distributeNeg(string eq)
{
	bool firstDigit = true;
	for (int i = 0; i < eq.size(); i++)
	{
		if (isdigit(eq.at(i)))
		{
			if (i == 0)
			{
				eq.insert(0, 1, '+');	//Second if() assumes a sign is given
				i++;
			}
			if (firstDigit == true)
			{
				firstDigit = false;
				if (eq.at(i - 1) == '+')	//flips sign to negative
				{
					eq.erase(--i, 1);
					eq.insert(i, 1, '-');
				}
				else if (eq.at(i - 1) == '-')	//flips sign to positive
				{
					eq.erase(--i, 1);
					eq.insert(i, 1, '+');
				}
			}
		}
		else
			firstDigit = true;
	}
	return eq;
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

vector<string> Interpreter::getVals(string eq)
{
	vector<string> parenVals;
	bool digitStarted = false;
	int firstPos = 0;
	for (int i = 0; i < eq.size(); i++)
	{
		char val = eq.at(i);
		if (isdigit(val) || val == '.' || isalpha(val))
		{
			if (digitStarted == false)
			{
				digitStarted = true;
				firstPos = i;
				if (i != 0 && eq.at(i - 1) == '-')
					firstPos--;
			}
		}
		if (i != 0 && val == '+' || val == '-')
		{
			digitStarted = false;
			parenVals.push_back(eq.substr(firstPos, i - firstPos));
			cout << eq.substr(firstPos, i - firstPos) << "\n";
		}
	}
	parenVals.push_back(eq.substr(firstPos, eq.size() - firstPos));
	cout << eq.substr(firstPos, eq.size() - firstPos) << "\n";
	return parenVals;
}