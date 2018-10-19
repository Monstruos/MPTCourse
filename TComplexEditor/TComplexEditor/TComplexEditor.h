#pragma once
#include <string>

class TComplexEditor {
public:
	TComplexEditor();

	bool isZero();

	std::string changeSign();

	std::string addDigit(unsigned int digit);

	std::string addZero();

	std::string backspace();

	std::string clear();

	std::string addSplit();

	void setNumber(std::string &num);

	std::string getNumber() const;

	static const std::string ZERO;
	static const std::string DIV_SIGN;
private:
	std::string number;
	bool isRealPartEditing;
};
