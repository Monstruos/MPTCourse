#ifndef MODERNPROGRAMMING_TCOMPLEX_H
#define MODERNPROGRAMMING_TCOMPLEX_H

#include <string>

#define COMPL_PI 3.14159265358979323846 // From math.h

class TComplex {
public:
	explicit TComplex(double real = 0, double image = 0);

	explicit TComplex(const std::string &number);

	TComplex& operator=(const TComplex &sec);

	TComplex operator+(const TComplex &sec);

	TComplex operator-(const TComplex &sec);

	TComplex operator*(const TComplex &sec);

	TComplex operator/(const TComplex &sec);

	TComplex operator-();

	bool operator==(const TComplex &sec);

	bool operator!=(const TComplex &sec);

	TComplex sqr();

	TComplex inverse();

	double module();

	double radAngle();

	double degAngle();

	TComplex pow(int exp);

	TComplex root(int exp, int idx = 0);

	double getRealPart();

	std::string getRealPartAsString();

	double getImaginaryPart();

	std::string getImaginaryPartAsString();

	std::string toString();

private:
	int sign(double x);

	double re;
	double im;
};


#endif //MODERNPROGRAMMING_TCOMPLEX_H