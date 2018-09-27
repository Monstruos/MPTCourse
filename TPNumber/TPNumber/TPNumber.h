#ifndef MODERNPROGRAMMING_TPNUMBER_H
#define MODERNPROGRAMMING_TPNUMBER_H

#include <string>

class TPNumber {
public:
	explicit TPNumber(double number, int base = 10, int precision = 7);

	TPNumber(const std::string &number, const std::string &base, const std::string &precision);

	TPNumber copy();

	TPNumber operator+(const TPNumber& sec);

	TPNumber operator-(const TPNumber& sec);

	TPNumber operator*(const TPNumber& sec);

	TPNumber operator/(const TPNumber& sec);

	TPNumber sqr();

	TPNumber inv();

	double getNumber();

	std::string getNumberAsString();

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
