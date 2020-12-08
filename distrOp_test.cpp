#ifndef __DISTROP_TEST_CPP__
#define __DISTROP_TEST_CPP__

#include "gtest/gtest.h"
#include "../Graphing_Calculator/header/Interpreter.hpp"
#include "../Graphing_Calculator/header/handleNoVars.hpp"
#include "../Graphing_Calculator/src/removeParenthesis.cpp"

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

#endif /*_DISTROP_TEST_CPP__*/
