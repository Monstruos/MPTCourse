#include "pch.h"

#include "../TPNumberEditor/TPNumberEditor.h"

TEST(TPNumberEditorTest, ConstructorAndGetters) {
	TPNumberEditor test;
	ASSERT_EQ(test.getNumber(), "0");
}


TEST(TPNumberEditorTest, IsZero) {
	TPNumberEditor test;
	ASSERT_EQ(test.isZero(), true);
	test.addDigit(5);
	ASSERT_EQ(test.isZero(), false);
}


TEST(TPNumberEditorTest, AddSignAndAddDigit) {
	TPNumberEditor test;
	test.addDigit(5);
	ASSERT_EQ(test.changeSign(), "-5");
	ASSERT_EQ(test.changeSign(), "5");
}

TEST(TPNumberEditorTest, AddZeroAndAddSplit) {
	TPNumberEditor test;
	test.addDigit(5);
	test.addZero();
	ASSERT_EQ(test.getNumber(), "50");
	test.addSplit();
	test.addZero();
	test.addDigit(1);
	ASSERT_EQ(test.getNumber(), "50.01");
}


TEST(TPNumberEditorTest, BackSpace) {
	TPNumberEditor test;
	test.addDigit(5);
	test.changeSign();
	ASSERT_EQ(test.backspace(), "0");
}


TEST(TPNumberEditorTest, Clear) {
	TPNumberEditor test;
	test.addDigit(5);
	test.addDigit(6);
	test.changeSign();
	ASSERT_EQ(test.clear(), "0");
}


TEST(TPNumberEditorTest, WriteString) {
	TPNumberEditor test;
	std::string number = "42";
	test.setNumber(number);
	ASSERT_EQ(test.getNumber(), number);
}