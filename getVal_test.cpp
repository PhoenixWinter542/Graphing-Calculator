#ifndef __GETVAL_TEST_HPP__
#define __GETVAL_TEST_HPP__

#include "gtest/gtest.h"
#include "interpreter.hpp"
#include "interpreter.cpp"
#include "handleOneVar.cpp"

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

#endif
