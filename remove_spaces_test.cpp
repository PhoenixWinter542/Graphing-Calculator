#ifndef __INTERPRETER_TEST_HPP__
#define __INTERPRETER_TEST_HPP__

#include "gtest/gtest.h"
#include "interpreter.hpp"
#include "interpreter.cpp"
#include "handleOneVar.cpp"

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
