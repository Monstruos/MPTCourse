#include "pch.h"
#include "../TEditor/TEditor.h"

TEST(TEditorTest, ConstructorAndGetters) {
	TEditor test;
	ASSERT_EQ(test.getNumber(), "0");
}


TEST(TEditorTest, IsZero) {
	TEditor test;
	ASSERT_EQ(test.isZero(), true);
	test.addDigit(5);
	ASSERT_EQ(test.isZero(), false);
}


TEST(TEditorTest, AddSignAndAddDigit) {
	TEditor test;
	test.addDigit(5);
	ASSERT_EQ(test.changeSign(), "-5");
	ASSERT_EQ(test.changeSign(), "5");
}

TEST(TEditorTest, AddZeroAndAddSplit) {
	TEditor test;
	test.addDigit(5);
	test.addZero();
	ASSERT_EQ(test.getNumber(), "50");
	test.addSplit();
	test.addZero();
	test.addDigit(1);
	ASSERT_EQ(test.getNumber(), "50.01");
}


TEST(TEditorTest, BackSpace) {
	TEditor test;
	test.addDigit(5);
	test.changeSign();
	ASSERT_EQ(test.backspace(), "0");
}


TEST(TEditorTest, Clear) {
	TEditor test;
	test.addDigit(5);
	test.addDigit(6);
	test.changeSign();
	ASSERT_EQ(test.clear(), "0");
}


TEST(TEditorTest, WriteString) {
	TEditor test;
	test.setNumber(std::string("42"));
	ASSERT_EQ(test.getNumber(), "42");
}