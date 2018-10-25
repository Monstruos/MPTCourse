#include "pch.h"
#include "../TSet/TSetComp.h"
#include "../TSet/TSetInh.h"
#include "test.h"

TEST(TSetCompose, MainBundle) {
	TSetComp<int> test;
	EXPECT_TRUE(test.size() == 0);
	EXPECT_TRUE(test.empty());

	test.insert(3);
	EXPECT_TRUE(test.elemAt(0) == 3);
	test.insert(5);
	test.insert(3);
	test.insert(2);
	EXPECT_TRUE(test.elemAt(0) == 3);
	EXPECT_TRUE(test.elemAt(1) == 5);
	EXPECT_TRUE(test.elemAt(2) == 2);

	test.erase(5);
	EXPECT_TRUE(test.elemAt(0) == 3);
	EXPECT_TRUE(test.elemAt(1) == 2);
	EXPECT_TRUE(test.size() == 2);
	EXPECT_FALSE(test.empty());

	EXPECT_ANY_THROW(test.elemAt(2));
}

TEST(TSetCompose, Concat) {
	TSetComp<int> test;
	test.insert(2);
	test.insert(6);
	test.insert(-1);

	TSetComp<int> test2;
	test2.insert(5);
	test2.insert(2);
	test2.insert(-4);

	TSetComp<int> test3 = test.concat(test2);
	EXPECT_TRUE(test3.size() == 5);
	EXPECT_TRUE(test3.elemAt(0) == 2);
	EXPECT_TRUE(test3.elemAt(1) == 6);
	EXPECT_TRUE(test3.elemAt(2) == -1);
	EXPECT_TRUE(test3.elemAt(3) == 5);
	EXPECT_TRUE(test3.elemAt(4) == -4);
}

TEST(TSetCompose, Clear) {
	TSetComp<int> test;
	test.insert(2);
	test.insert(6);
	test.insert(-1);
	test.clear();
	EXPECT_TRUE(test.size() == 0);
	EXPECT_TRUE(test.empty());
}

TEST(TSetCompose, Contains) {
	TSetComp<int> test;
	EXPECT_FALSE(test.contains(2));
	test.insert(2);
	EXPECT_TRUE(test.contains(2));
}

TEST(TSetCompose, Substract) {
	TSetComp<int> test;
	test.insert(2);
	test.insert(6);
	test.insert(-1);

	TSetComp<int> test2;
	test2.insert(5);
	test2.insert(2);
	test2.insert(-4);

	TSetComp<int> test3 = test.substract(test2);
	EXPECT_TRUE(test3.size() == 2);
	EXPECT_TRUE(test3.elemAt(0) == 6);
	EXPECT_TRUE(test3.elemAt(1) == -1);
}

TEST(TSetCompose, Intersect) {
	TSetComp<int> test;
	test.insert(2);
	test.insert(6);
	test.insert(-1);
	test.insert(3);

	TSetComp<int> test2;
	test2.insert(3);
	test2.insert(5);
	test2.insert(2);
	test2.insert(-4);

	TSetComp<int> test3 = test.intersect(test2);

	EXPECT_TRUE(test3.size() == 2);
	EXPECT_TRUE(test3.elemAt(0) == 2);
	EXPECT_TRUE(test3.elemAt(1) == 3);
}



TEST(TSetInherit, MainBundle) {
	TSetInh<int> test;
	EXPECT_TRUE(test.size() == 0);
	EXPECT_TRUE(test.empty());

	test.insert(3);
	EXPECT_TRUE(test.contains(3));

	test.insert(5);
	test.insert(2);
	EXPECT_TRUE(test.contains(2));

	test.erase(5);
	EXPECT_TRUE(test.contains(3));
	EXPECT_TRUE(test.contains(2));
	EXPECT_TRUE(test.size() == 2);
	EXPECT_FALSE(test.empty());

	//EXPECT_FALSE(test.contains(5));
}

TEST(TSetInherit, Concat) {
	TSetInh<int> test;
	test.insert(2);
	test.insert(6);
	test.insert(-1);

	TSetInh<int> test2;
	test2.insert(5);
	test2.insert(2);
	test2.insert(-4);

	TSetInh<int> test3 = test.concat(test2);
	EXPECT_TRUE(test3.size() == 5);
	EXPECT_TRUE(test3.contains(2));
	EXPECT_TRUE(test3.contains(6));
	EXPECT_TRUE(test3.contains(-1));
	EXPECT_TRUE(test3.contains(5));
	EXPECT_TRUE(test3.contains(-4));
}

TEST(TSetInherit, Clear) {
	TSetInh<int> test;
	test.insert(2);
	test.insert(6);
	test.insert(-1);
	test.clear();
	EXPECT_TRUE(test.size() == 0);
	EXPECT_TRUE(test.empty());
}

TEST(TSetInherit, Contains) {
	TSetInh<int> test;
	EXPECT_FALSE(test.contains(2));
	test.insert(2);
	EXPECT_TRUE(test.contains(2));
}

TEST(TSetInherit, Substract) {
	TSetInh<int> test;
	test.insert(2);
	test.insert(6);
	test.insert(-1);

	TSetInh<int> test2;
	test2.insert(5);
	test2.insert(2);
	test2.insert(-4);

	TSetInh<int> test3 = test.substract(test2);
	EXPECT_TRUE(test3.size() == 2);
	EXPECT_TRUE(test3.contains(0));
	EXPECT_TRUE(test3.contains(1));
}

TEST(TSetInherit, Intersect) {
	TSetInh<int> test;
	test.insert(2);
	test.insert(6);
	test.insert(-1);
	test.insert(3);

	TSetInh<int> test2;
	test2.insert(3);
	test2.insert(5);
	test2.insert(2);
	test2.insert(-4);

	TSetInh<int> test3 = test.intersect(test2);

	EXPECT_TRUE(test3.size() == 2);
	EXPECT_TRUE(test3.contains(2));
	EXPECT_TRUE(test3.contains(3));
}