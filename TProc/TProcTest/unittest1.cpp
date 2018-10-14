#include "stdafx.h"
#include "CppUnitTest.h"

#include "../TProc/TProc.h"
#include "../../TFrac/TFrac/TFrac.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TProcTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(ConstructorAndGetters)
		{
			TProc<TFrac> test = TProc<TFrac>();
			TFrac lrget = test.Lop_Res_Get();
			TFrac rget = test.Rop_Get();
			TOprtn operation = test.OprtnGet();
			Assert::IsTrue(lrget == TFrac());
			Assert::IsTrue(rget == TFrac());
			Assert::IsTrue(operation == None);
		}

		
		TEST_METHOD(Setters)
		{
			TProc<TFrac> test = TProc<TFrac>();
			TFrac test1(2, 1), test2(3, 4);
			test.Lop_Res_Set(test1);
			test.Rop_Set(test2);
			test.OprtnSet(Add);
			Assert::IsTrue(test.Lop_Res_Get() == test1);
			Assert::IsTrue(test.Rop_Get() == test2);
			Assert::IsTrue(test.OprtnGet() == Add);
		}


		TEST_METHOD(Reset)
		{
			TProc<TFrac> test = TProc<TFrac>();
			test.Lop_Res_Set(TFrac(2, 1));
			test.Rop_Set(TFrac(3, 4));
			test.OprtnSet(Add);
			test.ReSet();
			Assert::IsTrue(test.Lop_Res_Get() == TFrac());
			Assert::IsTrue(test.Rop_Get() == TFrac());
			Assert::IsTrue(test.OprtnGet() == None);
		}


		TEST_METHOD(OprtnClear)
		{
			TProc<TFrac> test = TProc<TFrac>();
			test.OprtnSet(Sub);
			test.OprtnClear();
			Assert::IsTrue(test.OprtnGet() == None);
		}


		TEST_METHOD(OprtnRun)
		{
			TProc<TFrac> test = TProc<TFrac>();
			test.Lop_Res_Set(TFrac(1, 2));
			test.Rop_Set(TFrac(1, 3));
			test.OprtnSet(Mul);
			test.OprtnRun();
			Assert::IsTrue(test.Lop_Res_Get() == TFrac(1, 6));
			Assert::IsTrue(test.Rop_Get() == TFrac(1, 3));
			Assert::IsTrue(test.OprtnGet() == Mul);
		}


		TEST_METHOD(TestFuncRun) {
			TProc<TFrac> test;
			TFrac rop(3, 4);
			test.Rop_Set(rop);
			test.FuncRun(Rev);
			Assert::IsTrue(test.Rop_Get() == rop.inverse());
		}

		TEST_METHOD(TestRun)
		{
			TProc<TFrac> test = TProc<TFrac>();
			Assert::IsTrue(test.Lop_Res_Get() == TFrac());
			Assert::IsTrue(test.Rop_Get() == TFrac());
			Assert::IsTrue(test.OprtnGet() == None);

			test.Lop_Res_Set(TFrac(2, 1));
			test.OprtnSet(Add);
			Assert::IsTrue(test.Lop_Res_Get() == TFrac(2, 1));
			Assert::IsTrue(test.Rop_Get() == TFrac());
			Assert::IsTrue(test.OprtnGet() == Add);

			test.Rop_Set(TFrac(3, 1));
			test.OprtnRun();
			test.OprtnSet(Mul);
			Assert::IsTrue(test.Lop_Res_Get() == (TFrac(2, 1) + TFrac(3, 1)));
			Assert::IsTrue(test.Rop_Get() == TFrac(3, 1));
			Assert::IsTrue(test.OprtnGet() == Mul);

			test.Rop_Set(TFrac(4, 1));
			test.FuncRun(Sqr);
			Assert::IsTrue(test.Lop_Res_Get() == (TFrac(2, 1) + TFrac(3, 1)));
			Assert::IsTrue(test.Rop_Get() == TFrac(4, 1).sqr());
			Assert::IsTrue(test.OprtnGet() == Mul);

			test.OprtnRun();
			Assert::IsTrue(test.Lop_Res_Get() == (TFrac(2, 1) + TFrac(3, 1)) * TFrac(4, 1).sqr());
			Assert::IsTrue(test.Rop_Get() == TFrac(4, 1).sqr());
			Assert::IsTrue(test.OprtnGet() == Mul);

			test.ReSet();
			Assert::IsTrue(test.Lop_Res_Get() == TFrac());
			Assert::IsTrue(test.Rop_Get() == TFrac());
			Assert::IsTrue(test.OprtnGet() == None);
		}
	};
}