#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TMemory/TMemory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TMemoryTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TMemoryAndGetters)
		{
			TMemory<int> test = TMemory<int>();
			int res = test.getFNumber();
			bool state = test.getState();
			Assert::IsFalse(state);
			Assert::IsTrue(res == int());
			int nonConst = test.get();
			state = test.getState();
			Assert::IsTrue(nonConst == int());
			Assert::IsTrue(state);
		}
		
		TEST_METHOD(Write)
		{
			TMemory<int> test = TMemory<int>();
			int fracTest = 12;
			test.write(fracTest);
			Assert::IsTrue(test.getState());
			Assert::IsTrue(test.get() == fracTest);
		}

		TEST_METHOD(Add)
		{
			TMemory<int> test = TMemory<int>();
			int fracTest = 12;
			test.write(fracTest);
			test.add(fracTest);
			Assert::IsTrue(test.getState());
			Assert::AreEqual(test.get(), 24);
		}

		TEST_METHOD(ReadMemoryState)
		{
			TMemory<int> test = TMemory<int>();
			Assert::IsTrue(std::string("_Off") == test.readMemoryState());
			test.write(3);
			Assert::IsTrue(std::string("_On") == test.readMemoryState());
		}

		TEST_METHOD(Clear)
		{
			TMemory<int> test = TMemory<int>();
			test.write(3);
			Assert::IsTrue(test.getState());
			test.clear();
			Assert::IsFalse(test.getState());
			Assert::AreEqual(test.get(), int());
		}
	};
}