#include "pch.h"
#include "../TPoly/TPoly.h"
TEST(TMemberTest, ConstructorAndGetters)
{
	TPoly::TMember test;
	TPoly::TMember test2(2, 1);
	EXPECT_EQ(test.getFactor(), 0);
	EXPECT_EQ(test.getExp(), 0);
	EXPECT_EQ(test2.getFactor(), 2);
	EXPECT_EQ(test2.getExp(), 1);
}

TEST(TMemberTest, Setters)
{
	TPoly::TMember test;
	test.setFactor(2);
	test.setExp(3);
	EXPECT_EQ(test.getFactor(), 2);
	EXPECT_EQ(test.getExp(), 3);
}

TEST(TMemberTest, Equal)
{
	TPoly::TMember test(2, 3);
	TPoly::TMember test2(2, 3);
	TPoly::TMember test3(3, 4);
	EXPECT_TRUE(test == test2);
	EXPECT_FALSE(test == test3);
}

TEST(TMemberTest, Differentiate)
{
	TPoly::TMember test(3, 2);
	TPoly::TMember res(6, 1);
	EXPECT_TRUE(test.differentiate() == res);
}

TEST(TMemberTest, Calculate)
{
	TPoly::TMember test(4, 3);
	EXPECT_TRUE(test.calculate(-2) == -32);
}

TEST(TMemberTest, String)
{
	TPoly::TMember test(4, 3);
	EXPECT_EQ(test.toString(), "4*x^3");
}

TEST(TPolyTest, ConstructorAndGetters)
{
	TPoly test(4, 3);
	TPoly test2;
	EXPECT_TRUE(test.elemAt(0) == TPoly::TMember(4, 3));
	EXPECT_EQ(test2.getExp(), 0);
	EXPECT_EQ(test2.getFactor(0), 0);
}

TEST(TPolyTest, Clear)
{
	TPoly test(4, 3);
	test.clear();
	EXPECT_EQ(test.getExp(), 0);
	EXPECT_EQ(test.getFactor(0), 0);
}

TEST(TPolyTest, Plus)
{
	TPoly test(4, 3);
	TPoly test2 = test + TPoly::TMember(2, 4);
	EXPECT_EQ(test2.getExp(), 4);
	EXPECT_EQ(test2.getFactor(4), 2);
	EXPECT_EQ(test2.getFactor(3), 4);
	EXPECT_EQ(test2.calculate(2), 64);
	TPoly test3 = test + test;
	EXPECT_EQ(test3.getExp(), 3);
	EXPECT_EQ(test3.getFactor(3), 8);
}

TEST(TPolyTest, Minus)
{
	TPoly test(4, 3);

	TPoly test2 = test - TPoly::TMember(2, 4);
	EXPECT_EQ(test2.getExp(), 4);
	EXPECT_EQ(test2.getFactor(4), -2);
	EXPECT_EQ(test2.getFactor(3), 4);
	EXPECT_EQ(test2.calculate(2), 0);

	TPoly test3 = test2 - TPoly::TMember(2, 4);
	TPoly test4 = test - test;
	TPoly test5 = test - TPoly::TMember(4, 3);
	EXPECT_EQ(test3.getExp(), 4);
	EXPECT_EQ(test3.getFactor(4), -4);
	EXPECT_EQ(test3.getFactor(3), 4);
	EXPECT_EQ(test3.calculate(2), -32);
	EXPECT_EQ(test4.getExp(), 0);
	EXPECT_EQ(test4.getFactor(0), 0);
	EXPECT_EQ(test5.getExp(), 0);
	EXPECT_EQ(test5.getFactor(0), 0);
}

TEST(TPolyTest, Multiplicate)
{
	TPoly test = TPoly(2, 2) + TPoly::TMember(3, 1); // 2x^2 + 3x
	TPoly test2 = TPoly(3, 2) + TPoly::TMember(2, 1); // 3x^2 + 2x
	TPoly test3 = test * test2; // 6x^4 + 13x^3 + 6x^2

	EXPECT_EQ(test3.getFactor(4), 6);
	EXPECT_EQ(test3.getFactor(3), 13);
	EXPECT_EQ(test3.getFactor(2), 6);
	EXPECT_EQ(test3.getFactor(1), 0);
	EXPECT_EQ(test3.getFactor(0), 0);
}

TEST(TPolyTest, Equal)
{
	TPoly test(2, 2);
	TPoly test2(3, 2);
	TPoly test3(3, 2);
	EXPECT_FALSE(test == test2);
	EXPECT_FALSE(test == test3);
	EXPECT_FALSE(test == test2 + test3);
	EXPECT_TRUE(test2 == test3);
	EXPECT_TRUE(test3 == test3);
}

TEST(TPolyTest, Differentiate)
{
	TPoly test = (TPoly(2, 2) + TPoly::TMember(3, 4)).differentiate();
	EXPECT_EQ(test.getFactor(0), 0);
	EXPECT_EQ(test.getFactor(1), 4);
	EXPECT_EQ(test.getFactor(2), 0);
	EXPECT_EQ(test.getFactor(3), 12);
	EXPECT_EQ(test.getFactor(4), 0);
}

TEST(TPolyTest, Calculate)
{
	TPoly test = TPoly(2, 1) + TPoly::TMember(1, 2);
	EXPECT_EQ(test.calculate(3), 15);
}