#include "pch.h"
#include "../TPoly/TMember.h"
#include "../TPoly/TPoly.h"

TEST(TMemberTest, ConstructorAndGetters) {
	TMember test;
	TMember test2(2, 1);
	EXPECT_EQ(test.getFactor(), 0);
	EXPECT_EQ(test.getExp(), 0);
	EXPECT_EQ(test2.getFactor(), 2);
	EXPECT_EQ(test2.getExp(), 1);
}

TEST(TMemberTest, Setters) {
	TMember test;
	test.setFactor(2);
	test.setExp(3);
	EXPECT_EQ(test.getFactor(), 2);
	EXPECT_EQ(test.getExp(), 3);
}

TEST(TMemberTest, Equal) {
	TMember test(2, 3);
	TMember test2(2, 3);
	TMember test3(3, 4);
	EXPECT_TRUE(test == test2);
	EXPECT_FALSE(test == test3);
}

TEST(TMemberTest, Differentiate) {
	TMember test(3, 2);
	TMember res(6, 1);
	EXPECT_EQ(test.differentiate(), res);
}

TEST(TMemberTest, Calculate) {
	TMember test(4, 3);
	EXPECT_EQ(test.calculate(-2), -32);
}

TEST(TPolyTest, ConstructorAndGetters) {
	TPoly test(4, 3);
	TPoly test2;
	EXPECT_EQ(test.elemAt(3), TMember(4, 3));
	EXPECT_EQ(test2.getExp(), 0);
	EXPECT_EQ(test2.getFactor(0), 0);
}
/*
TEST(TPolyTest, Clear) {
	TPoly test(4, 3);
	test = test + TMember(2, 4);
	//test.clear();
	//EXPECT_EQ(test.getExp(), 0);
	//EXPECT_EQ(test.getFactor(0), 0);
}*/

TEST(TPolyTest, Plus) {
	TPoly test(4, 3);
	//TPoly test2(-2, 4);
	TPoly test2 = test + TMember(2, 4);
	EXPECT_EQ(test.getExp(), 4);
	EXPECT_EQ(test.getFactor(4), 2);
	EXPECT_EQ(test.getFactor(3), 4);
	EXPECT_EQ(test.calculate(2), 64);
	test = test + TMember(2, 3);
	/*test = test + test2;
	EXPECT_EQ(test.getFactor(3), 6);
	EXPECT_EQ(test.getFactor(4), 0);
	EXPECT_EQ(test.getExp(), 3);*/
}
/*
TEST(TPolyTest, Minus) {
	TPoly test(4, 3);
	test = test - TMember(2, 4);
	EXPECT_EQ(test.getExp(), 4);
	EXPECT_EQ(test.getFactor(4), -2);
	EXPECT_EQ(test.getFactor(3), 4);
	EXPECT_EQ(test.calculate(2), 64);
	test = test - TMember(2, 4);
	EXPECT_EQ(test.getFactor(4), -4);
	EXPECT_EQ(test.getFactor(3), 4);
}

TEST(TPolyTest, Multiplicate) {
	TPoly test(2, 2);
	TPoly test2(3, 2);
	test = test + TMember(3, 1);
	test2 = test2 + TMember(2, 1);
	EXPECT_EQ(test.getFactor(4), 6);
	EXPECT_EQ(test.getFactor(3), 4 + 9);
	EXPECT_EQ(test.getFactor(2), 6);
	EXPECT_EQ(test.getFactor(1), 0);
	EXPECT_EQ(test.getFactor(0), 0);
}

TEST(TPolyTest, Equal) {
	TPoly test(2, 2);
	TPoly test2(3, 2);
	TPoly test3(3, 2);
	EXPECT_TRUE(test3 == test3);
	EXPECT_FALSE(test == test2);
}

TEST(TPolyTest, Differentiate) {
	TPoly test(2, 2);
	test = test + TMember(3, 4);
	EXPECT_EQ(test.getFactor(0), 0);
	EXPECT_EQ(test.getFactor(1), 4);
	EXPECT_EQ(test.getFactor(2), 0);
	EXPECT_EQ(test.getFactor(3), 12);
	EXPECT_EQ(test.getFactor(4), 0);
}

TEST(TPolyTest, Calculate) {
	TPoly test(2, 1);
	test = test + TMember(1, 2);
	EXPECT_EQ(test.calculate(3), 15);
}*/