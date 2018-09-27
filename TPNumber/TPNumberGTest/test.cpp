#include "pch.h"

#include "../TPNumber/TPNumber.h"

TEST(TPNumberSuite, NumberContructor) {
	ASSERT_TRUE(TPNumber(123, 4, 3).getNumber() == 123);
	ASSERT_TRUE(TPNumber(123.5, 4, 3).getNumber() == 123.5);
	ASSERT_FALSE(TPNumber(123, 4, 3).getNumber() == 27);
	ASSERT_FALSE(TPNumber(123, 1, 3).getNumber() == 123);
	ASSERT_FALSE(TPNumber(123, 17, 3).getNumber() == 123);
	ASSERT_FALSE(TPNumber(123, 4, -1).getNumber() == 123);
}

TEST(TPNumberSuite, StringContructor) {
	ASSERT_TRUE(TPNumber("123", "4", "3").getNumber() == 27);
	ASSERT_TRUE(TPNumber("123.2", "4", "3").getNumber() == 27.5);
	ASSERT_TRUE(TPNumber("123.22", "4", "3").getNumber() == 27.625);
	ASSERT_FALSE(TPNumber("123", "4", "3").getNumber() == 123);
	ASSERT_FALSE(TPNumber("123", "1", "3").getNumber() == 27);
	ASSERT_FALSE(TPNumber("123", "17", "3").getNumber() == 27);
	ASSERT_FALSE(TPNumber("123", "4", "-1").getNumber() == 27);
}

TEST(TPNumberSuite, Copy) {
	ASSERT_TRUE(TPNumber(123, 4, 3).getNumber() == TPNumber(123, 4, 3).copy().getNumber());
}

TEST(TPNumberSuite, Add) {
	ASSERT_TRUE(TPNumber(246, 4, 3).getNumber() == (TPNumber(123, 4, 3) + TPNumber(123, 4, 3)).getNumber());
	ASSERT_THROW(TPNumber(123, 5, 3) + TPNumber(123, 4, 3), std::invalid_argument);
	ASSERT_THROW(TPNumber(123, 4, 3) + TPNumber(123, 4, 4), std::invalid_argument);
}

TEST(TPNumberSuite, Multiply) {
	ASSERT_TRUE(TPNumber(4, 4, 3).getNumber() == (TPNumber(2, 4, 3) * TPNumber(2, 4, 3)).getNumber());
	ASSERT_THROW(TPNumber(2, 5, 3) * TPNumber(2, 4, 3), std::invalid_argument);
	ASSERT_THROW(TPNumber(2, 4, 3) * TPNumber(2, 4, 4), std::invalid_argument);
}

TEST(TPNumberSuite, Substract) {
	ASSERT_TRUE(TPNumber(1, 4, 3).getNumber() == (TPNumber(123, 4, 3) - TPNumber(122, 4, 3)).getNumber());
	ASSERT_THROW(TPNumber(123, 5, 3) - TPNumber(122, 4, 3), std::invalid_argument);
	ASSERT_THROW(TPNumber(123, 4, 3) - TPNumber(122, 4, 4), std::invalid_argument);
}

TEST(TPNumberSuite, Divide) {
	ASSERT_TRUE(TPNumber(2, 4, 3).getNumber() == (TPNumber(4, 4, 3) / TPNumber(2, 4, 3)).getNumber());
	ASSERT_THROW(TPNumber(4, 5, 3) / TPNumber(2, 4, 3), std::invalid_argument);
	ASSERT_THROW(TPNumber(4, 4, 3) / TPNumber(2, 4, 4), std::invalid_argument);
}

TEST(TPNumberSuite, Square) {
	ASSERT_TRUE(TPNumber(4, 4, 3).getNumber() == TPNumber(2, 4, 3).sqr().getNumber());
	ASSERT_TRUE(TPNumber(0.25, 4, 3).getNumber() == TPNumber(0.5, 4, 3).sqr().getNumber());
}

TEST(TPNumberSuite, Inversion) {
	ASSERT_TRUE(TPNumber(0.5, 4, 3).getNumber() == TPNumber(2, 4, 3).inv().getNumber());
	ASSERT_TRUE(TPNumber(2, 4, 3).getNumber() == TPNumber(0.5, 4, 3).inv().getNumber());
	ASSERT_THROW(TPNumber(0, 4, 3).inv(), std::invalid_argument);
}

TEST(TPNumberSuite, Number) {
	ASSERT_EQ(123, TPNumber(123, 4, 3).getNumber());
	ASSERT_EQ(123.5, TPNumber(123.5, 4, 3).getNumber());
	ASSERT_EQ(27, TPNumber("123", "4", "3").getNumber());
	ASSERT_EQ(27.5, TPNumber("123.2", "4", "3").getNumber());
}

TEST(TPNumberSuite, NumberString) {
	ASSERT_EQ("123", TPNumber(27, 4, 3).getNumberAsString());
	ASSERT_EQ("123.200", TPNumber(27.5, 4, 3).getNumberAsString());
	ASSERT_EQ("123", TPNumber("123", "4", "3").getNumberAsString());
	ASSERT_EQ("123.200", TPNumber("123.2", "4", "3").getNumberAsString());
	ASSERT_EQ("123.222", TPNumber("123.2222", "4", "3").getNumberAsString());
}

TEST(TPNumberSuite, Base) {
	ASSERT_EQ(4, TPNumber(123, 4, 3).getBase());
	ASSERT_EQ(4, TPNumber("123", "4", "3").getBase());
}

TEST(TPNumberSuite, BaseString) {
	ASSERT_EQ("4", TPNumber(27, 4, 3).getBaseAsString());
	ASSERT_EQ("4", TPNumber("123", "4", "3").getBaseAsString());
}

TEST(TPNumberSuite, Precision) {
	ASSERT_EQ(3, TPNumber(123, 4, 3).getPrecision());
	ASSERT_EQ(3, TPNumber("123", "4", "3").getPrecision());
}

TEST(TPNumberSuite, PrecisionString) {
	ASSERT_EQ("3", TPNumber(27, 4, 3).getPrecisionAsString());
	ASSERT_EQ("3", TPNumber("123", "4", "3").getPrecisionAsString());
}

TEST(TPNumberSuite, SetBase) {
	TPNumber pnum(123, 4, 3);
	pnum.setBase(5);
	ASSERT_EQ(5, pnum.getBase());
	pnum.setBase(3);
	ASSERT_EQ(3, pnum.getBase());
	ASSERT_THROW(pnum.setBase(1), std::invalid_argument);
	ASSERT_THROW(pnum.setBase(17), std::invalid_argument);
}

TEST(TPNumberSuite, SetBaseString) {
	TPNumber pnum(123, 4, 3);
	pnum.setBase("5");
	ASSERT_EQ(5, pnum.getBase());
	pnum.setBase("3");
	ASSERT_EQ(3, pnum.getBase());
	ASSERT_THROW(pnum.setBase("1"), std::invalid_argument);
	ASSERT_THROW(pnum.setBase("17"), std::invalid_argument);
}

TEST(TPNumberSuite, SetPrecision) {
	TPNumber pnum(123, 4, 3);
	pnum.setPrecision(4);
	ASSERT_EQ(4, pnum.getPrecision());
	pnum.setPrecision(2);
	ASSERT_EQ(2, pnum.getPrecision());
	ASSERT_THROW(pnum.setPrecision(-1), std::invalid_argument);
}

TEST(TPNumberSuite, SetPrecisionString) {
	TPNumber pnum(123, 4, 3);
	pnum.setPrecision("4");
	ASSERT_EQ(4, pnum.getPrecision());
	pnum.setPrecision("2");
	ASSERT_EQ(2, pnum.getPrecision());
	ASSERT_THROW(pnum.setPrecision("-1"), std::invalid_argument);
}