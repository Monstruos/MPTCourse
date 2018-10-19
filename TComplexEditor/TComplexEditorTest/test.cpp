#include "pch.h"

#include "../TComplexEditor/TComplexEditor.h"

TEST(TComplexEditorTest, ConstructorAndGetters) {
	TComplexEditor test;
	ASSERT_EQ(test.getNumber(), std::to_string(0.0));
}


TEST(TComplexEditorTest, IsZero) {
	TComplexEditor test;
	ASSERT_EQ(test.isZero(), true);
	test.addDigit(5);
	ASSERT_EQ(test.isZero(), false);
}


TEST(TComplexEditorTest, AddSignAndAddDigit) {
	TComplexEditor test;
	test.addDigit(5);
	ASSERT_EQ(test.changeSign(), "-5");
	ASSERT_EQ(test.changeSign(), "5");
}

TEST(TComplexEditorTest, AddZeroAndAddSplit) {
	TComplexEditor test;
	test.addDigit(5);
	test.addZero();
	ASSERT_EQ(test.getNumber(), std::to_string(50.0));
	test.addSplit();
	test.addZero();
	test.addDigit(2);
	ASSERT_EQ(test.getNumber(), std::to_string(50.0) + "+i*" + std::to_string(2.0));
}


TEST(TComplexEditorTest, BackSpace) {
	TComplexEditor test;
	test.addDigit(5);
	test.changeSign();
	ASSERT_EQ(test.backspace(), "0");
}


TEST(TComplexEditorTest, Clear) {
	TComplexEditor test;
	test.addDigit(5);
	test.addDigit(6);
	test.changeSign();
	ASSERT_EQ(test.clear(), "0");
}


TEST(TComplexEditorTest, WriteString) {
	TComplexEditor test;
	std::string number = "3-i*0";
	test.setNumber(number);
	ASSERT_EQ(test.getNumber(), std::to_string(3.0));
}