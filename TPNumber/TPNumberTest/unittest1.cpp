#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TPNumber/TPNumber.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TPNumberTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			TPNumber num(123, 4, 3);
			Assert::AreEqual(123.0, num.getNumber());
		}

		TEST_METHOD(ConstructorString)
		{
			TPNumber num("123", "4", "3");
			Assert::AreEqual(27.0, num.getNumber());
		}

		TEST_METHOD(NumberContructor) {
			Assert::AreEqual(TPNumber(123, 4, 3).getNumber(), 123.0);
			Assert::AreEqual(TPNumber(123.5, 4, 3).getNumber(), 123.5);
			Assert::AreNotEqual(TPNumber(123, 4, 3).getNumber(), 27.0);
			Assert::AreNotEqual(TPNumber(123, 1, 3).getNumber(), 123.0);
			Assert::AreNotEqual(TPNumber(123, 17, 3).getNumber(), 123.0);
			Assert::AreNotEqual(TPNumber(123, 4, -1).getNumber(), 123.0);
			Assert::AreEqual(TPNumber(123, 0, -1).getNumber(), 0.0);
		}

		TEST_METHOD(StringContructor) {
			Assert::AreEqual(TPNumber("123", "4", "3").getNumber(), 27.0);
			Assert::AreEqual(TPNumber("123.2", "4", "3").getNumber(), 27.5);
			Assert::AreEqual(TPNumber("123.22", "4", "3").getNumber(), 27.625);
			Assert::AreEqual(TPNumber("1A", "16", "3").getNumber(), 26.0);
			Assert::AreNotEqual(TPNumber("123", "4", "3").getNumber(), 123.0);
			Assert::AreNotEqual(TPNumber("123", "1", "3").getNumber(), 27.0);
			Assert::AreNotEqual(TPNumber("123", "17", "3").getNumber(), 27.0);
			Assert::AreNotEqual(TPNumber("123", "4", "-1").getNumber(), 27.0);
			Assert::AreEqual(TPNumber("123", "sdf", "11").getNumber(), 0.0);
		}

		TEST_METHOD(Copy) {
			Assert::AreEqual(TPNumber(123, 4, 3).getNumber(), TPNumber(123, 4, 3).copy().getNumber());
		}

		TEST_METHOD(Add) {
			Assert::AreEqual(TPNumber(246, 4, 3).getNumber(), (TPNumber(123, 4, 3) + TPNumber(123, 4, 3)).getNumber());
			auto f1 = [this] {
				TPNumber(123, 5, 3) + TPNumber(123, 4, 3);
			};
			Assert::ExpectException<std::invalid_argument>(f1);
			auto f2 = [this] {
				TPNumber(123, 4, 3) + TPNumber(123, 4, 4);
			};
			Assert::ExpectException<std::invalid_argument>(f2);
		}

		TEST_METHOD(Multiply) {
			Assert::AreEqual(TPNumber(4, 4, 3).getNumber(), (TPNumber(2, 4, 3) * TPNumber(2, 4, 3)).getNumber());
			auto f1 = [this] {
				TPNumber(2, 5, 3) * TPNumber(2, 4, 3);
			};
			Assert::ExpectException<std::invalid_argument>(f1);
			auto f2 = [this] {
				TPNumber(2, 4, 3) * TPNumber(2, 4, 4);
			};
			Assert::ExpectException<std::invalid_argument>(f2);
		}

		TEST_METHOD(Substract) {
			Assert::AreEqual(TPNumber(1, 4, 3).getNumber(), (TPNumber(123, 4, 3) - TPNumber(122, 4, 3)).getNumber());
			auto f1 = [this] {
				TPNumber(123, 5, 3) - TPNumber(122, 4, 3);
			};
			Assert::ExpectException<std::invalid_argument>(f1);
			auto f2 = [this] {
				TPNumber(123, 4, 3) - TPNumber(122, 4, 4);
			};
			Assert::ExpectException<std::invalid_argument>(f2);
		}

		TEST_METHOD(Divide) {
			Assert::AreEqual(TPNumber(2, 4, 3).getNumber(), (TPNumber(4, 4, 3) / TPNumber(2, 4, 3)).getNumber());
			auto f1 = [this] {
				TPNumber(4, 5, 3) / TPNumber(2, 4, 3);
			};
			Assert::ExpectException<std::invalid_argument>(f1);
			auto f2 = [this] {
				TPNumber(4, 4, 3) / TPNumber(2, 4, 4);
			};
			Assert::ExpectException<std::invalid_argument>(f2);
		}

		TEST_METHOD(Square) {
			Assert::AreEqual(TPNumber(4, 4, 3).getNumber(), TPNumber(2, 4, 3).sqr().getNumber());
			Assert::AreEqual(TPNumber(0.25, 4, 3).getNumber(), TPNumber(0.5, 4, 3).sqr().getNumber());
		}

		TEST_METHOD(Inversion) {
			Assert::AreEqual(TPNumber(0.5, 4, 3).getNumber(), TPNumber(2, 4, 3).inv().getNumber());
			Assert::AreEqual(TPNumber(2, 4, 3).getNumber(), TPNumber(0.5, 4, 3).inv().getNumber());
			auto f1 = [this] {
				TPNumber(0, 4, 3).inv();
			};
			Assert::ExpectException<std::invalid_argument>(f1);
		}

		TEST_METHOD(Number) {
			Assert::AreEqual(123.0, TPNumber(123, 4, 3).getNumber());
			Assert::AreEqual(123.5, TPNumber(123.5, 4, 3).getNumber());
			Assert::AreEqual(27.0, TPNumber("123", "4", "3").getNumber());
			Assert::AreEqual(27.5, TPNumber("123.2", "4", "3").getNumber());
		}

		TEST_METHOD(NumberString) {
			Assert::AreEqual(0, TPNumber(27, 4, 3).getNumberAsString().compare("123"));
			Assert::AreEqual(0, TPNumber(27.5, 4, 3).getNumberAsString().compare("123.200"));
			Assert::AreEqual(0, TPNumber("123", "4", "3").getNumberAsString().compare("123"));
			Assert::AreEqual(0, TPNumber("123.2", "4", "3").getNumberAsString().compare("123.200"));
			Assert::AreEqual(0, TPNumber("123.2222", "4", "3").getNumberAsString().compare("123.222"));
			Assert::AreEqual(0, TPNumber(0.6875, 16, 1).getNumberAsString().compare("0.B"));
			Assert::AreEqual(0, TPNumber(26.4375, 16, 1).getNumberAsString().compare("1A.7"));
		}

		TEST_METHOD(Base) {
			Assert::AreEqual(4, TPNumber(123, 4, 3).getBase());
			Assert::AreEqual(4, TPNumber("123", "4", "3").getBase());
		}

		TEST_METHOD(BaseString) {
			Assert::AreEqual(0, TPNumber(27, 4, 3).getBaseAsString().compare("4"));
			Assert::AreEqual(0, TPNumber("123", "4", "3").getBaseAsString().compare("4"));
		}

		TEST_METHOD(Precision) {
			Assert::AreEqual(3, TPNumber(123, 4, 3).getPrecision());
			Assert::AreEqual(3, TPNumber("123", "4", "3").getPrecision());
		}

		TEST_METHOD(PrecisionString) {
			Assert::AreEqual(0, TPNumber(27, 4, 3).getPrecisionAsString().compare("3"));
			Assert::AreEqual(0, TPNumber("123", "4", "3").getPrecisionAsString().compare("3"));
		}

		TEST_METHOD(SetBase) {
			TPNumber pnum(123, 4, 3);
			pnum.setBase(5);
			Assert::AreEqual(5, pnum.getBase());
			pnum.setBase(3);
			Assert::AreEqual(3, pnum.getBase());
			auto f1 = [this] {
				TPNumber fnum(546, 7, 2);
				fnum.setBase(1);
			};
			Assert::ExpectException<std::invalid_argument>(f1);
			auto f2 = [this] {
				TPNumber fnum(546, 7, 2);
				fnum.setBase(17);
			};
			Assert::ExpectException<std::invalid_argument>(f2);
		}

		TEST_METHOD(SetBaseString) {
			TPNumber pnum(123, 4, 3);
			pnum.setBase("5");
			Assert::AreEqual(5, pnum.getBase());
			pnum.setBase("3");
			Assert::AreEqual(3, pnum.getBase());
			auto f1 = [this] {
				TPNumber fnum(546, 7, 2);
				fnum.setBase("1");
			};
			Assert::ExpectException<std::invalid_argument>(f1);
			auto f2 = [this] {
				TPNumber fnum(546, 7, 2);
				fnum.setBase("17");
			};
			Assert::ExpectException<std::invalid_argument>(f2);
		}

		TEST_METHOD(SetPrecision) {
			TPNumber pnum(123, 4, 3);
			pnum.setPrecision(4);
			Assert::AreEqual(4, pnum.getPrecision());
			pnum.setPrecision(2);
			Assert::AreEqual(2, pnum.getPrecision());
			auto f1 = [this] {
				TPNumber fnum(546, 7, 2);
				fnum.setPrecision(-1);
			};
			Assert::ExpectException<std::invalid_argument>(f1);
		}

		TEST_METHOD(SetPrecisionString) {
			TPNumber pnum(123, 4, 3);
			pnum.setPrecision("4");
			Assert::AreEqual(4, pnum.getPrecision());
			pnum.setPrecision("2");
			Assert::AreEqual(2, pnum.getPrecision());
			auto f1 = [this] {
				TPNumber fnum(546, 7, 2);
				fnum.setPrecision("-1");
			};
			Assert::ExpectException<std::invalid_argument>(f1);
		}
	};
}