#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TFrac/TFrac.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TFracTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(IntABConstructorTest03)
		{
			TFrac test1(0, 3);
			Assert::AreEqual(0.0, test1.getNumer());
			Assert::AreEqual(1.0, test1.getDenom());
		}


		TEST_METHOD(IntABConstructorTest63)
		{
			TFrac test2(6, 3);
			Assert::AreEqual(2.0, test2.getNumer());
			Assert::AreEqual(1.0, test2.getDenom());
		}

		TEST_METHOD(StringConstructorTest03)
		{
			TFrac test1("0/3");
			Assert::AreEqual(0.0, test1.getNumer());
			Assert::AreEqual(1.0, test1.getDenom());
		}


		TEST_METHOD(StringConstructorTest63)
		{
			TFrac test2("6/3");
			Assert::AreEqual(2.0, test2.getNumer());
			Assert::AreEqual(1.0, test2.getDenom());
		}

		TEST_METHOD(CopyTest)
		{
			TFrac testOrig(2, 1);
			TFrac testCopy = TFrac::copy(testOrig);
			Assert::AreEqual(2.0, testCopy.getNumer());
			Assert::AreEqual(1.0, testCopy.getDenom());
		}

		TEST_METHOD(AddTest)
		{
			TFrac testFst(1, 2);
			TFrac testSnd(-3, 4);
			TFrac ResAdd = testFst + testSnd;
			Assert::AreEqual(-1.0, ResAdd.getNumer());
			Assert::AreEqual(4.0, ResAdd.getDenom());
		}


		TEST_METHOD(SubTest)
		{
			TFrac testFst(1, 2);
			TFrac ResAdd = testFst - testFst;
			Assert::AreEqual(0.0, ResAdd.getNumer());
			Assert::AreEqual(1.0, ResAdd.getDenom());
		}


		TEST_METHOD(MulTest)
		{
			TFrac testFst(2, 3);
			TFrac testSnd(3, 4);
			TFrac ResAdd = testFst * testSnd;
			Assert::AreEqual(1.0, ResAdd.getNumer());
			Assert::AreEqual(2.0, ResAdd.getDenom());
		}


		TEST_METHOD(DivTest)
		{
			TFrac testFst(2, 3);
			TFrac testSnd(3, 4);
			TFrac ResAdd = testFst / testSnd;
			Assert::AreEqual(8.0, ResAdd.getNumer());
			Assert::AreEqual(9.0, ResAdd.getDenom());
		}


		TEST_METHOD(SqrTest)
		{
			TFrac testFst(2, 3);
			TFrac ResAdd = testFst.sqr();
			Assert::AreEqual(4.0, ResAdd.getNumer());
			Assert::AreEqual(9.0, ResAdd.getDenom());
		}


		TEST_METHOD(InverseTest)
		{
			TFrac testFst(2, 3);
			TFrac ResAdd = testFst.inverse();
			Assert::AreEqual(3.0, ResAdd.getNumer());
			Assert::AreEqual(2.0, ResAdd.getDenom());
		}


		TEST_METHOD(UnaryMinusTest)
		{
			TFrac testFst(2, 3);
			TFrac ResAdd = -testFst;
			Assert::AreEqual(-2.0, ResAdd.getNumer());
			Assert::AreEqual(3.0, ResAdd.getDenom());
		}


		TEST_METHOD(EqualTestTrue)
		{
			TFrac testFst(2, 3);
			Assert::IsTrue(testFst == testFst);
		}


		TEST_METHOD(EqualTestFalse)
		{
			TFrac testFst(2, 3);
			TFrac testSnd(3, 3);
			Assert::IsFalse(testFst == testSnd);
		}


		TEST_METHOD(SmTestTrue)
		{
			TFrac testFst(2, 3);
			TFrac testSnd(3, 2);
			Assert::IsTrue(testFst < testSnd);
		}


		TEST_METHOD(SmTestFalse)
		{
			TFrac testFst(2, 3);
			TFrac testSnd(1, 5);
			Assert::IsFalse(testFst < testSnd);
		}


		TEST_METHOD(BgTestTrue)
		{
			TFrac testFst(3, 4);
			TFrac testSnd(2, 3);
			Assert::IsTrue(testFst > testSnd);
		}


		TEST_METHOD(BgTestFalse)
		{
			TFrac testFst(2, 7);
			TFrac testSnd(3, 4);
			Assert::IsFalse(testFst > testSnd);
		}


		TEST_METHOD(GetNumerTest)
		{
			TFrac testFst(2, -7);
			Assert::AreEqual(-2.0, testFst.getNumer());
		}


		TEST_METHOD(GetDenomTest)
		{
			TFrac testFst(2, -7);
			Assert::AreEqual(7.0, testFst.getDenom());
		}


		TEST_METHOD(GetNumerStringTest)
		{
			TFrac testFst(2, -7);
			Assert::AreEqual(std::string("-2"), testFst.getStringNumer());
		}


		TEST_METHOD(GetDenomStringTest)
		{
			TFrac testFst(2, -7);
			Assert::AreEqual(std::string("7"), testFst.getStringDenom());
		}


		TEST_METHOD(GetFracStringTest)
		{
			TFrac testFst(2, -7);
			Assert::AreEqual(std::string("-2/7"), testFst.getStringTFrac());
		}
	};
}