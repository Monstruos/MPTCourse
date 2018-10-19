#include "pch.h"

#include "../TFracEditor/TFracEditor.h"

TEST(TFracEditorTest, ConstructorAndGetters) {
	TFracEditor test;
	ASSERT_EQ(test.getNumber(), "0/1");
}


TEST(TFracEditorTest, IsZero) {
	TFracEditor test;
	ASSERT_EQ(test.isZero(), true);
	test.addDigit(5);
	ASSERT_EQ(test.isZero(), false);
}


TEST(TFracEditorTest, AddSignAndAddDigit) {
	TFracEditor test;
	test.addDigit(5);
	ASSERT_EQ(test.changeSign(), "-5");
	ASSERT_EQ(test.changeSign(), "5");
}

TEST(TFracEditorTest, AddZeroAndAddSplit) {
	TFracEditor test;
	test.addDigit(5);
	test.addZero();
	ASSERT_EQ(test.getNumber(), "50/1");
	test.addSplit();
	test.addZero();
	test.addDigit(2);
	ASSERT_EQ(test.getNumber(), "25/1");
}


TEST(TFracEditorTest, BackSpace) {
	TFracEditor test;
	test.addDigit(5);
	test.changeSign();
	ASSERT_EQ(test.backspace(), "0");
}


TEST(TFracEditorTest, Clear) {
	TFracEditor test;
	test.addDigit(5);
	test.addDigit(6);
	test.changeSign();
	ASSERT_EQ(test.clear(), "0");
}


TEST(TFracEditorTest, WriteString) {
	TFracEditor test;
	std::string number = "4/2";
	test.setNumber(number);
	ASSERT_EQ(test.getNumber(), "2/1");
}