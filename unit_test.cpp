#ifndef __INTERPRETER_TEST_HPP__
#define __INTERPRETER_TEST_HPP__

#include "gtest/gtest.h"
#include "interpreter.hpp"
#include "interpreter.cpp"
#include "handleOneVar.cpp"

TEST(failingCases, PowVarBase){
	string eq = "x^x";
	EXPECT_EQ("x^x",getParsedEquation(eq));
}

TEST(removeSpaces, BasicEQ) {
	string eq = "y = 2x"
	EXPECT_EQ("y=2x",removeSpaces(eq));

}

TEST(removeSpaces, BasicEQ2) {
	string eq = "y = 3x + 8";
	EXPECT_EQ("y=3x+8", removeSpaces(eq));
}

TEST(removeSpaces, ExpEQ) {
	string eq = "y = 3x^2 + 7";
	EXPECT_EQ("y=3x^2+8", removeSpaces(eq));
}

TEST(removeSpaces, ParaEQ) {
	string eq = "y = 3(x + 6)";
	EXPECT_EQ("y=3(x+6)",removeSpaces(eq));
}

//handlePara 
TEST(handlePara, Basic) {
	string eq = "(x)";
	vector<int> inner;
	inner.push_back(0);
	inner.push_back(2);
	vector<vector<int>> location;
	location.push_back(inner);
	EXPECT_EQ("x",handleParanthesis(eq,location)); 
	
}

TEST(handlePara, Basic2) {
	string eq = "(x)(x)";
	vector<int> inner;
	vector<vector<int>> location;
	inner.push_back(0);
	inner.push_back(3);
	location.push_back(inner);
	inner.pop(); inner.pop();
	inner.push_back(4);
	inner.push_back(6);
	location.push_back(inner);
	EXPECT_EQ("x*x", handleParanthesis(eq,location));
}

TEST(handlePara, Complex) {
	string eq = "(x+2)(x-2)";
	vector<int> inner;
	vector<vector<int>> location;
	inner.push_back(0);
	inner.push_back(4);
	location.push_back(inner);
	inner.pop();
	inner.pop();
	inner.push_back(5);
	inner.push_back(9);
	location.push_back(inner);
	EXPECT_EQ("x*x+x*-2+2*x+2*-2", handleParanthesis(eq,location));

}

TEST(handlePara, Complex2) {
	string eq = "(x+4)(x+7)(x)";
	vector<int> inner;
	vector<vector<int>> location;
	inner.push_back(0);
	inner.push_back(4);
	location.push_back(inner);
	inner.pop();
	inner.pop();
	inner.push_back(5);
	inner.push_back(9);
	inner.pop();
	inner.pop();
	inner.push_back(10);
	inner.push_back(12);
	location.push_back(inner);
	EXPECT_EQ("x*x*x+x*x*4+7*x*x+4*7*x", handleParanthesis(eq,location));
}

TEST(adjustLocation, Complex2) {
	vector<int> inner;
	vector<vector<int>> location;
	inner.push_back(0);
	inner.push_back(3);
	location.push_back(inner);
	inner.pop(); inner.pop();
	inner.push_back(4);
	inner.push_back(6);
	inner.pop(); inner.pop();
	inner.push_back(7);
	inner.push_back(10);
	location = adjustLocation(location,-1,0);
	EXPECT_EQ(0,location.at[0][0]);
	EXPECT_EQ(2,location.at[0][1]);
	EXPECT_EQ(3,location.at[1][0]);
	EXPECT_EQ(5,location.at[1][1]);
	EXPECT_EQ(6,location.at[2][0]);
	EXPECT_EQ(9,location.at[2][1]);
}

TEST(adjustLocation, Basic) {
	vector<int> inner;
	vector<vector<int>> location;
	inner.push_back(0);
	inner.push_back(3);
	location.push_back(inner);
	inner.pop(); inner.pop();
	inner.push_back(4);
	inner.push_back(6);
	location = adjustLocation(location,-1,0);
	EXPECT_EQ(0,location.at[0][0]);
	EXPECT_EQ(2,location.at[0][1]);
	EXPECT_EQ(3,location.at[1][1]);
	EXPECT_EQ(5,location.at[1][2]);
}


TEST(distrNeg,OneNeg) {
	string eq = "-(2+3)";
	EXPECT_EQ("-2-3", distributeNeg(eq));
}

TEST(distrNeg,NegPos) {
	string eq = "-(2-3)";
	EXPECT_EQ("-2+3", distributeNeg(eq));
}

TEST(distrNeg,DubNeg) {
	string eq = "-(-2-3)";
	EXPECT_EQ("-2+3", distributeNeg(eq));
}

TEST(distrNeg,DubParaDubNeg) {
	string eq = "-(-(2+3))";
	EXPECT_EQ("2+3", distributeNeg(findParanthesis(eq)));
}

TEST(distrNeg,TripNegTripPara) {
	string eq = "-(-2+(-3+4))";
	EXPECT_EQ("2+3-4",distributeNeg(findParanthesis(eq)));
}

TEST(distrNeg,DubEqDubNeg) {
	string eq = "-(-4+7) - (-(3+7))";
	EXPECT_EQ("4-7+3+7",distributeNeg(findParanthesis(eq)));

TEST(distrMult,OneVar) {
	EXPECT_EQ("2x+6", distributeMult("2","x+3"));
}

TEST(distrMult,OneVar) {
	EXPECT_EQ("2x", distributeMult("2","x"));
}

TEST(distrMult,OneVarComplex) {
	EXPECT_EQ("4x+18", distributeMult("2","2x+9"));
}

TEST(distrMult,TwoVarComplex) {
	EXPECT_EQ("x*x+x*3", distributeMult("x","x+3"));
}

TEST(distrMult,TripVarComplex) {
	string eq = distributeMult("x","x+3");
	string eq2 = distributeMult(eq,"x");
	EXPECT_EQ("x*x+x*3", eq);
	EXPECT_EQ("x*x*x + x*3*x", eq2;);
}

TEST(distrPow, OneVar) {
	EXPECT_EQ("x^5", distributePow("x","5"));
}

TEST(distrPow, OneVar) {
	EXPECT_EQ("x^5*x^1",distributePow("x","5+1"));
}

TEST(distrPow, DubVar) {
	string eq = distributePow("x","5+1");
	EXPECT_EQ("x^5*x^1",eq);
	EXPECT_EQ("x^x^5*x^x^1".distributePow("x",eq);
}

TEST(distrPow, DubVar) {
	EXPECT_EQ("x^2+2*x+1","(x+1)^2");
}

TEST(getVal, SingleVar) {
	EXPECT_EQ("x",getVals("x"));
}

TEST(getVal, Add) {
	EXPECT_EQ("x+5",getVals("x+5"));
}

TEST(getVal, ComplexAdd) {
	EXPECT_EQ("x+x+x+5+7+9",getVals("x+x+x+5+7+9"));
}

TEST(getVal,Sub) {
	EXPECT_EQ("x-5",getVals("x-5"));
}

TEST(getVal,ComplexSub) {
	EXPECT_EQ("x-5-x-x-6"; getVals("x-5-x-x-6"));
}

TEST(getVal,Pow) {
	EXPECT_EQ("x^5", getVals("x^5"));
}

TEST(getVal,ComplexPow) {
	EXPECT_EQ("x^5^7^8", getVals("x^5^7^8"));
}

TEST(getVal, Div) {
	EXPECT_EQ("x/2", getVals("x/2"));
}

TEST(getVal, ComplexDiv) {
	EXPECT_EQ("x/3/x",getVals("x/3/x"));
}

TEST(getVal, Mult) {
	EXPECT_EQ("x*5", getVals("x*5));
}

TEST(getVal,ComplexMult) {
	EXPECT_EQ("x*5*x*7*9" getVals("x*5*x*7*9");
}

TEST(getVal,ComplexAddMultPowSub) {
	EXPECT_EQ("x^2+2*x+1-x", getVals("x^2+3*x+1-5-x));
}

TEST(getVal, Decimals) {
	EXPECT_EQ(".2*x", getVals(".2 * x"));
}

TEST(getVal, Decimals2) {
	EXPECT_EQ("x*.2", getVals("x*.2"));
}

TEST(simplify, Basic) {
	EXPECT_EQ("x", simplify("x"));
}

TEST(simplify, Add) {
	EXPECT_EQ("x+5+7",simplify("x+12"));
}

TEST(simplify, Sub) {
	EXPECT_EQ("x-6-9",simplify("x-15"));
}

TEST(simplify, Div) {
	EXPECT_EQ("x/12", simplify("x/6/2"));
}

TEST(simplify, Mult) {
	EXPECT_EQ("x*15", simplify(x*5*3*1"));
}

TEST(simplify,Pow) {
	EXPECT_EQ("x^45", simplify("x^9^5"));
}

TEST(simplify, AddSub) {
	string eq = "x-6+2-5"
	EXPECT_EQ("x-9", simplify(eq));
}

TEST(simplify,AddSubMult) {
	string eq = "x*(5-9+4)";
	EXPECT_EQ("x*0", simplify(eq));
}

TEST(simplify,AddSubMultDiv) {
	string eq = "x*(9/3-9+6)";
	EXPECT_EQ("x*0,eq);
}

//Failing Tests

TEST(edgeCases, BaseVar) { 
    Interpreter* test = new Interpreter();
    HandleVars* result = test->getParsedEquation("x^x");
    EXPECT_EQ(4,result->getPoint("2"));

}

TEST(edgeCases, ConstantBase) {
    Interpreter* test = new Interpreter();
    HandleVars* result = test->getParsedEquation("(2*x)^2");
    EXPECT_EQ(16,result->getPoint("2"));
}

TEST(edgeCases, ParaVar) { 
    Interpreter* test = new Interpreter();
    HandleVars* result = test->getParsedEquation("(x+3)");
    EXPECT_EQ(16,result->getPoint("5"));
}

TEST(edgeCases, ParaVar) {
    Interpreter* test = new Interpreter();
    HandleVars* result = test->getParsedEquation("(x)");
    EXPECT_EQ(2,result->getPoint("2"));
}

TEST(edgeCases, Decimal) {
    Interpreter* test = new Interpreter();
    HandleVars* result = test->getParsedEquation(".2");
    EXPECT_EQ(.2,result);

}

TEST(edgeCases, EmptyString) {
    Interpreter* test = new Interpreter();
    HandleVars* result = test->getParsedEquation("");
    EXPECT_EQ(0,result->getPoint("5"));
}

TEST(edgeCases, DollarSign) {
    Interpreter* test = new Interpreter();
    HandleVars* result = test->getParsedEquation("$");
    EXPECT_EQ(0,result->getPoint("5"));
}

TEST(edgeCases, EqualSign) {
    Interpreter* test = new Interpreter();
    HandleVars* result = test->getParsedEquation("=");
    EXPECT_EQ(0,result->getPoint("5"));
}

TEST(edgeCases, RidiculousAddSub) {
    Interpreter* test = new Interpreter();
    HandleVars* result = test->getParsedEquation("4-+-+-++-+--+++--+-+-+-+-+-+--4");
    EXPECT_EQ(0,result->getPoint("0"));
}

TEST(edgeCases, DigitRandomAlpha) {
    Interpreter* test = new Interpreter();
    HandleVars* result = test->getParsedEquation("4asdads$");
    EXPECT_EQ(0,result->getPoint("5"));
}

