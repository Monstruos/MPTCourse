#pragma once

#define COMPL_PI 3.14159265358979323846
#include <string>
class TComplex
{
private:
	double re;
	double im;
	int sign(double x);
public:
	TComplex();
	~TComplex();
	TComplex(double real, double image);
	TComplex(std::string &number);
	TComplex operator=(const TComplex& sec);
	TComplex operator+(const TComplex& sec);
	TComplex operator-(const TComplex& sec);
	TComplex operator*(const TComplex& sec);
	TComplex operator/(const TComplex& sec);
	TComplex operator-();
	TComplex sqr();
	TComplex inverse();
	double module();
	double radDegree();
	double gradDegree();

	bool operator==(const TComplex& sec);
	bool operator!=(const TComplex& sec);

};

