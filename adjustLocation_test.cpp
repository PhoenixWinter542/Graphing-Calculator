#ifndef __INTERPRETER_TEST_HPP__
#define __INTERPRETER_TEST_HPP__

#include "gtest/gtest.h"
#include "interpreter.hpp"
#include "interpreter.cpp"
#include "handleOneVar.cpp"

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
