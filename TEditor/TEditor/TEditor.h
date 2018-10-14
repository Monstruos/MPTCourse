#pragma once

#include <string>
#include "../../TPNumber/TPNumber/TPNumber.h"

class TEditor
{
public:
	TEditor();
	~TEditor();
	bool isZero();
	std::string changeSign();
	std::string addDigit(unsigned int digit);
	std::string addZero();
	std::string backspace();
	std::string clear();
	void setNumber(std::string & num);
	std::string getNumber() const;
	static const std::string ZERO;
	static const char DIV_SIGN;
private:
	std::string number;
	unsigned int base;
};

