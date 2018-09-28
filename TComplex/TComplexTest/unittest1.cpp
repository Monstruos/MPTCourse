#include "stdafx.h"
#include "CppUnitTest.h"

#include "../TComplex/TComplex.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TComplexTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TComplexSuiteNumberContructor) {
			TComplex first(6, 3);
			TComplex second(3, 0);
			TComplex third(3);
			TComplex fourth(0, 0);
			TComplex fifth;

			Assert::AreEqual(first.getRealPart(), 6.0);
			Assert::AreEqual(first.getImaginaryPart(), 3.0);

			Assert::AreEqual(second.getRealPart(), 3.0);
			Assert::AreEqual(second.getImaginaryPart(), 0.0);

			Assert::IsTrue(third == second);

			Assert::AreEqual(fourth.getRealPart(), 0.0);
			Assert::AreEqual(fourth.getImaginaryPart(), 0.0);

			Assert::IsTrue(fifth == fourth);
			Assert::IsFalse(TComplex(1, 2) == TComplex(2, 1));
		}

		TEST_METHOD(TComplexSuiteStringContructor) {
			Assert::IsTrue(TComplex("1+i*2") == TComplex(1, 2));
			Assert::IsTrue(TComplex("1-i*2") == TComplex(1, -2));
			Assert::IsTrue(TComplex("1+i*-2") == TComplex(1, -2));
			Assert::IsTrue(TComplex("Incorrect") == TComplex(0, 0));
		}

		TEST_METHOD(TComplexSuiteCopy) {
			TComplex first(1, 2);
			TComplex second = first;
			Assert::IsTrue((second = first) == first);
		}

		TEST_METHOD(TComplexSuiteAdd) {
			Assert::IsTrue(TComplex(3, 4) == TComplex(1, 2) + TComplex(2, 2));
			Assert::IsTrue(TComplex(2, 0) + TComplex(0, 2) == TComplex(1, 1) + TComplex(1, 1));
			Assert::IsTrue(TComplex(1, 2) + TComplex(-3, 4) == TComplex(-2, 6));
		}

		TEST_METHOD(TComplexSuiteMultiply) {
			Assert::IsTrue(TComplex(-5, -1) == TComplex(2, 3) * TComplex(-1, 1));
			Assert::IsTrue(TComplex(2, 4) == TComplex(1, 2) * TComplex(2));
		}

		TEST_METHOD(TComplexSuiteSquare) {
			Assert::IsTrue(TComplex(-5, 12) == TComplex(2, 3).sqr());
			Assert::IsTrue(TComplex(3, 2) * TComplex(3, 2) == TComplex(3, 2).sqr());
		}

		TEST_METHOD(TComplexSuiteInversion) {
			Assert::IsTrue(TComplex(4.0 / 17, -1.0 / 17) == TComplex(4, 1).inverse());
			Assert::IsTrue(TComplex(1) / TComplex(4, 1) == TComplex(4, 1).inverse());
			auto f = [this] {
				TComplex(0, 0).inverse();
			};
			Assert::ExpectException<std::invalid_argument>(f);
		}

		TEST_METHOD(TComplexSuiteSubstract) {
			Assert::IsTrue(TComplex(0, 0) == TComplex(2, 1) - TComplex(2, 1));
		}

		TEST_METHOD(TComplexSuiteDivide) {
			Assert::IsTrue(TComplex(-1.5, -0.5) == TComplex(-2, 1) / TComplex(1, -1));
			auto f = [this] {
				TComplex(1, 2) / TComplex(0, 0);
			};
			Assert::ExpectException<std::invalid_argument>(f);
		}

		TEST_METHOD(TComplexSuiteNegate) {
			Assert::IsTrue(TComplex(-1, -2) == -TComplex(1, 2));
			Assert::IsTrue(TComplex(0) - TComplex(1, 2) == -TComplex(1, 2));
		}

		TEST_METHOD(TComplexSuiteModule) {
			Assert::AreEqual(TComplex(2, 1).module(), sqrt(5));
			Assert::AreEqual(TComplex(0, 17).module(), 17.0);
		}

		TEST_METHOD(TComplexSuiteRadians) {
			Assert::AreEqual(TComplex(0, -1).radAngle(), -COMPL_PI / 2);
			Assert::AreEqual(TComplex(1, -1).radAngle(), -COMPL_PI / 4);
			Assert::AreEqual(TComplex(1, 0).radAngle(), 0.0);
			Assert::AreEqual(TComplex(1, 1).radAngle(), COMPL_PI / 4);
			Assert::AreEqual(TComplex(0, 1).radAngle(), COMPL_PI / 2);
			Assert::AreEqual(TComplex(-1, 1).radAngle(), 3 * COMPL_PI / 4);
			Assert::AreEqual(TComplex(-1, 0).radAngle(), COMPL_PI);
			Assert::AreEqual(TComplex(-1, -1).radAngle(), 5 * COMPL_PI / 4);
			auto f = [this] {
				TComplex(0, 0).radAngle();
			};
			Assert::ExpectException<std::invalid_argument>(f);
		}

		TEST_METHOD(TComplexSuiteDegrees) {
			Assert::AreEqual(TComplex(0, -1).degAngle(), -90.0);
			Assert::AreEqual(TComplex(1, -1).degAngle(), -45.0);
			Assert::AreEqual(TComplex(1, 0).degAngle(), 0.0);
			Assert::AreEqual(TComplex(1, 1).degAngle(), 45.0);
			Assert::AreEqual(TComplex(0, 1).degAngle(), 90.0);
			Assert::AreEqual(TComplex(-1, 1).degAngle(), 135.0);
			Assert::AreEqual(TComplex(-1, 0).degAngle(), 180.0);
			Assert::AreEqual(TComplex(-1, -1).degAngle(), 225.0);
			auto f = [this] {
				TComplex(0, 0).degAngle();
			};
			Assert::ExpectException<std::invalid_argument>(f);
		}

		TEST_METHOD(TComplexSuitePower) {
			Assert::IsTrue(TComplex(2, 3).pow(2) == TComplex(-5, 12));
			Assert::IsTrue(TComplex(2, 3).pow(2) == TComplex(2, 3).sqr());
			Assert::IsTrue(TComplex(3, 2) * TComplex(3, 2) * TComplex(3, 2) == TComplex(3, 2).pow(3));
		}

		TEST_METHOD(TComplexSuiteRoot) {
			double value = sqrt(2) / 2;

			Assert::IsTrue(TComplex(-1).root(4, 0) == TComplex(value, value));
			Assert::IsTrue(TComplex(-1).root(4, 1) == TComplex(-value, value));
			Assert::IsTrue(TComplex(-1).root(4, 2) == TComplex(-value, -value));
			Assert::IsTrue(TComplex(-1).root(4, 3) == TComplex(value, -value));
			auto f1 = [this] {
				TComplex(-1).root(4, 4);
			};
			Assert::ExpectException<std::invalid_argument>(f1);
			auto f2 = [this] {
				TComplex(-1).root(0);
			};
			Assert::ExpectException<std::invalid_argument>(f2);
		}

		TEST_METHOD(TComplexSuiteEqual) {
			Assert::IsTrue(TComplex(1, 2) == TComplex(1, 2));
			Assert::IsFalse(TComplex(1, 2) == TComplex(1, 3));
		}

		TEST_METHOD(TComplexSuiteNotEqual) {
			Assert::IsTrue(TComplex(1, 2) != TComplex(1, 3));
			Assert::IsFalse(TComplex(1, 2) != TComplex(1, 2));
		}

		TEST_METHOD(TComplexSuiteReal) {
			Assert::AreEqual(2.0, TComplex(2, 3).getRealPart());
		}

		TEST_METHOD(TComplexSuiteImaginary) {
			Assert::AreEqual(3.0, TComplex(2, 3).getImaginaryPart());
		}

		TEST_METHOD(TComplexSuiteRealString) {
			Assert::AreEqual(std::to_string(2.0), TComplex(2, 3).getRealPartAsString());
		}

		TEST_METHOD(TComplexSuiteImaginaryString) {
			Assert::AreEqual(std::to_string(3.0), TComplex(2, 3).getImaginaryPartAsString());
		}

		TEST_METHOD(TComplexSuiteString) {
			std::string re = std::to_string(2.0);
			std::string im = std::to_string(3.0);

			Assert::AreEqual(re + "+i*" + im, TComplex(2, 3).toString());
			Assert::AreEqual(re + "-i*" + im, TComplex(2, -3).toString());
			Assert::AreEqual(re + "-i*" + im, TComplex("2+i*-3").toString());
			Assert::AreEqual(re, TComplex("2+i*0").toString());
		}

	};
}