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
