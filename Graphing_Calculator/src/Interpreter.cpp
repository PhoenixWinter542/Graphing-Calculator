#include "../header/Interpreter.hpp"

HandleVars* Interpreter::getParsedEquation(string eq)
{
	eq = removeParenthesis::parse(eq);
	NoVar* test = new NoVar(eq);		//<<<<-------------------------Needs Changed-------------------------------------
	return test;
}