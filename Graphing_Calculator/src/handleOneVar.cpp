#include "../header/handleOneVar.hpp"
#include <iostream>
using std::cout;

string OneVar::enterVariable(string var)
{
	for (int i = 0; i < this->eq.length(); i++)
	{
		if (isalpha(this->eq.at(i)))
		{
			this->eq.replace(i, 1, var);
		}
	}

	return string();
}
