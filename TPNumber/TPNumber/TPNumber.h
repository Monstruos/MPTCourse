#ifndef MODERNPROGRAMMING_TPNUMBER_H
#define MODERNPROGRAMMING_TPNUMBER_H

#include <string>

class TPNumber {
public:
	explicit TPNumber(double number = 0.0, int base = 10, int precision = 7);

	TPNumber(const std::string &number, const std::string &base = "10", const std::string &precision = "7");

	TPNumber copy();

	TPNumber operator+(const TPNumber& sec);

	TPNumber operator-(const TPNumber& sec);

	TPNumber operator*(const TPNumber& sec);

	TPNumber operator/(const TPNumber& sec);

	TPNumber sqr();

	TPNumber inv();

	double getNumber();

	std::string getNumberAsString();

	std::string getNumberAsStringWithoutZero();

	int getBase();

	std::string getBaseAsString();

	void setBase(int base);

	void setBase(const std::string &base);

	int getPrecision();

	std::string getPrecisionAsString();

	void setPrecision(int precision);

	void setPrecision(const std::string &precision);

private:
	double strtod(const std::string &num);

	double _number;
	int _base;
	int _precision;
};

#endif // MODERNPROGRAMMING_TPNUMBER_H
