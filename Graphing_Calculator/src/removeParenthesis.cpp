#include "../header/removeParenthesis.hpp"

#include <iostream>
using std::cout;

string removeSpaces(string eq);
string findParenthesis(string eq);
vector<vector<int>> adjustLocation(vector<vector<int>> parenLocations, int change, int i);
string handleParenthesis(string eq, vector<vector<int>> parenLocations);
string distributeNeg(string eq);
string distributeMult(string parenLeft, string parenRight);
string distributePow(string parenLeft, string parenRight);
vector<string> getVals(string eq);


string removeSpaces(string eq)
{
	for (int i = 0; i < eq.size(); i++)
	{
		if (eq[i] == ' ')
			eq.erase(i--, 1);
	}
	return eq;
}

	/*
	Finds the locations of outer parenthesis and passes them to handleParenthesis
	 - If none returns the given string
	*/
string findParenthesis(string eq)
{
	cout << "\n\t\t\t\tTop\t" << eq << "\n";		//<<<<<<<<----------------------------------------------------------
	vector<vector<int>> parenLocations;
	int openParen = 0;		//Used to track how many open parenthesis have been found	|	parenFound(+1 if open, -1 if closed)
	vector<int> paren;			//Tracks location of both parenthesis 0='(' 1=')'
	for (int i = 0; i < eq.size(); i++)
	{
		if (eq[i] == '(')
			if (openParen++ == 0)
				paren.push_back(i);
		if (eq[i] == ')')
			if (--openParen == 0)
			{
				paren.push_back(i);
				parenLocations.push_back(paren);
				cout << "\t\t\t\tMid\t" << eq.substr(paren[0], 1 + paren[1] - paren[0]) << "\n"; //<<<<<<<<----------------------------------------------------------
				paren.clear();
			}
	}
	cout << "\t\t\t\tEnd\t" << eq << "\n\n";		//<<<<<<<<----------------------------------------------------------
	if (parenLocations.empty())
		return eq;
	return handleParenthesis(eq, parenLocations);		//There were parenthesis inside the parenthesis
}

	//adjusts all parenLocations after parenLocations[i][0] by change
vector<vector<int>> adjustLocation(vector<vector<int>> parenLocations, int change, int i)
{
	parenLocations[i][1] += change;
	for (++i; i < parenLocations.size(); i++)
	{
		parenLocations[i][0] += change;
		parenLocations[i][1] += change;
	}
	return parenLocations;
}

string handleParenthesis(string eq, vector<vector<int>> parenLocations)
{
	if (parenLocations.size() > 1)
	{
		int powPos = -1;
		for (int i = 0; i < parenLocations.size() - 1; i++)		//Handle possible paren with exponent------------------DOESN'T WORK WITH ()^-()-----------------
		{
			if (eq[parenLocations[i][1] + 1] == '^')		//a paren is in form ()^x
			{
				string exponent = "";
				int originalSize = parenLocations.size();
				if (parenLocations[i][1] == parenLocations[i + 1][0] - 2)		//eq has paren^paren
					exponent = findParenthesis(eq.substr(parenLocations[i + 1][0] + 1, parenLocations[i + 1][1]));
				else if (parenLocations[i][1] + 2 < eq.size())
					exponent = eq[parenLocations[i][1] + 2];
				string paren1 = eq.substr(parenLocations[i][0] + 1, parenLocations[i][1] - (parenLocations[i][0] + 1));
				paren1 = distributePow(findParenthesis(paren1), exponent);
				eq.replace(parenLocations[i][0], 1 + parenLocations[i + 1][1] - parenLocations[i][0], paren1);
				parenLocations = adjustLocation(parenLocations, eq.size() - originalSize, i);
				parenLocations.erase(parenLocations.begin() + i);
				cout << "handleParenthesis:\t" << eq << "\n\n";	//<<<<<<<<----------------------------------------------------------
			}
		}
	}
	if (parenLocations.size() > 1)		//handle possible paren multiplication
	{
		for (int i = 0; i + 1 < parenLocations.size(); i++)
		{
			if (parenLocations[i][0] - 1 >= 0 && (isdigit(eq[parenLocations[i][0] - 1]) || isalpha(eq[parenLocations[i][0] - 1])))
			{
				int originalSize = eq.size();
				int valStart = parenLocations[i][0] - 1;
				while (eq[valStart] == '.' || eq[valStart] == '*' || eq[valStart] == '-' || isalpha(eq[valStart]) || isdigit(eq[valStart]))		//Get the entire first value
				{
					if (--valStart < 0)
						break;
					if (eq[valStart + 1] == '-' && eq[valStart] != '*')
						break;
				}
				valStart++;
				string val1 = eq.substr(valStart, parenLocations[i][0] - valStart);
				string paren1 = eq.substr(parenLocations[i][0] + 1, parenLocations[i][1] - (parenLocations[i][0] + 1));
				paren1 = findParenthesis(paren1);
				eq.replace(valStart, parenLocations[i][1] - (valStart - 1), distributeMult(val1, paren1));
				parenLocations = adjustLocation(parenLocations, eq.size() - originalSize, i);
				parenLocations.erase(parenLocations.begin() + i--);
				int remainingParens = parenLocations.size();
				if (remainingParens <= i)
					break;
			}
			else
			{
				if (parenLocations[i][1] + 1 < eq.size())
					if (isdigit(eq[parenLocations[i][1] + 1]) || isalpha(eq[parenLocations[i][1] + 1]))
					{
						eq.insert(parenLocations[i][1] + 1, "*");
						adjustLocation(parenLocations, 1, i);
					}
				//there is at least one operation between the parenthesis
				int originalSize = eq.size();
				bool run = false;
				if (parenLocations[i][1] != parenLocations[i + 1][0] - 1 && parenLocations[i][1] >= parenLocations[i + 1][0] - 3)
				{
					if (eq[parenLocations[i][1] + 1] == '*')
					{
						if (eq[parenLocations[i][1] + 2] == '-')
						{
							string paren1 = eq.substr(parenLocations[i + 1][0] + 1, parenLocations[i + 1][1]);
							paren1 = "+" + distributeNeg(findParenthesis(paren1));
							eq.replace(parenLocations[i][1] + 2, 1 + parenLocations[i + 1][1], paren1);
							parenLocations = adjustLocation(parenLocations, eq.size() - originalSize, i);
							originalSize = parenLocations.size();
							cout << "handle-Mult:\t" << eq << "\n";		//<<<<<<<<----------------------------------------------------------
						}
						if (eq[parenLocations[i][1] + 2] == '+')
							run = true;
					}
				}
				else if (parenLocations[i][1] == parenLocations[i + 1][0] - 1)
					run = true;
				if (run)
				{
					string paren1 = eq.substr(parenLocations[i][0] + 1, parenLocations[i][1] - 1 - parenLocations[i][0]);
					paren1 = findParenthesis(paren1);
					string paren2 = eq.substr(parenLocations[i + 1][0] + 1, parenLocations[i + 1][1] - 1 - parenLocations[i + 1][0]);
					paren2 = findParenthesis(paren2);
					eq.replace(parenLocations[i][0], 1 + parenLocations[i + 1][1] - parenLocations[i][0], distributeMult(paren1, paren2));
					parenLocations = adjustLocation(parenLocations, eq.size() - originalSize, i);
					parenLocations.erase(parenLocations.begin());
					parenLocations.erase(parenLocations.begin());
					cout << "handleMult:\t" << eq << "\n";		//<<<<<<<<----------------------------------------------------------
				}
			}
		}
	}
	for (int i = 0; i < parenLocations.size(); i++)		//Handles distributing negatives
	{
		if (parenLocations[i][0] > 0 && eq[parenLocations[i][0] - 1] == '-')
		{
			eq.erase(parenLocations[i][0] - 1, 1);

			//Adjusts for deletion of leading '-'
			parenLocations[i][0]--;
			parenLocations = adjustLocation(parenLocations, -1, i);

			int  originalSize = eq.size();
			string paren1 = eq.substr(1 + parenLocations[i][0], parenLocations[i][1] - (parenLocations[i][0] + 1));
			eq.replace(parenLocations[i][0], 1 + parenLocations[i][1] - parenLocations[i][0], distributeNeg(findParenthesis(paren1)));
			parenLocations = adjustLocation(parenLocations, eq.size() - originalSize, i);
			parenLocations.erase(parenLocations.begin() + i--);
			cout << "handleNeg:\t" << eq << "\n\n";		//<<<<<<<<----------------------------------------------------------
		}
	}
	cout << "finishedParen:\t" << eq << "\n\n";		//<<<<<<<<----------------------------------------------------------
	return eq;
}

string distributeNeg(string eq)
{
	bool firstDigit = true;
	for (int i = 0; i < eq.size(); i++)
	{
		if (isdigit(eq[i]))
		{
			if (i == 0)
			{
				eq.insert(0, 1, '+');	//Second if() assumes a sign is given
				i++;
			}
			if (firstDigit == true)
			{
				firstDigit = false;
				if (eq[i - 1] == '+')	//flips sign to negative
				{
					eq.erase(--i, 1);
					eq.insert(i, 1, '-');
				}
				else if (eq[i - 1] == '-')	//flips sign to positive
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

string distributeMult(string parenLeft, string parenRight)
{
	vector<string> parenValsLeft = getVals(parenLeft), parenValsRight = getVals(parenRight);
	string result = "";
	for (int i = 0; i < parenValsLeft.size(); i++)
	{
		for (int j = 0; j < parenValsRight.size(); j++)
		{
			result += parenValsLeft[i] + "*" + parenValsRight[j] + '+';
			cout << "distributeMult:\t" << result << "\n";		//<<<<<<<<----------------------------------------------------------

		}
	}
	if (result[result.size() - 1] == '+')
		result.pop_back();
	return result;
}

string distributePow(string parenLeft, string parenRight)
{
	return parenLeft + parenRight;		//Placeholder
}

//Used by distributeMult
vector<string> getVals(string eq)
{
	vector<string> parenVals;
	bool digitStarted = false;
	int firstPos = 0;
	for (int i = 0; i < eq.size(); i++)
	{
		char val = eq[i];
		if (isdigit(val) || val == '.' || isalpha(val))
		{
			if (digitStarted == false)
			{
				digitStarted = true;
				firstPos = i;
				if (i != 0 && eq[i - 1] == '-')
					firstPos--;
			}
		}
		if (i != 0)
			if (val == '+' || val == '-')
				if (isdigit(eq[i - 1]) || isalpha(eq[i - 1]) || eq[i - 1] == '(')
				{
					digitStarted = false;
					parenVals.push_back(eq.substr(firstPos, i - firstPos));
					cout << "getVals\tTop:\t" << eq.substr(firstPos, i - firstPos) << "\n";
				}
	}
	parenVals.push_back(eq.substr(firstPos, eq.size() - firstPos));
	cout << "getVals\tEnd:\t" << eq.substr(firstPos, eq.size() - firstPos) << "\n";
	return parenVals;
}

namespace removeParenthesis
{
	string parse(string eq)
	{
		eq = removeSpaces(eq);
		return findParenthesis(eq);
	}
}