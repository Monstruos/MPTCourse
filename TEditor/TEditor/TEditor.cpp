#include "stdafx.h"
#include "TEditor.h"

const std::string ZERO = "0";
const char DIV_SIGN = '.';

TEditor::TEditor() : number("0"), base(10)
{
}


TEditor::~TEditor()
{
}

bool TEditor::isZero()
{
	return TPNumber(number, std::to_string(base)).getNumber() == 0.0;
}

std::string TEditor::changeSign()
{
	if (number[0] == '-')
	{
		number.erase(number.begin());
	}
	else
	{
		number = "-" + number;
	}
	return number;
}

std::string TEditor::addDigit(unsigned int digit)
{
	if (digit < base)
	{
		if (isZero())
		{
			number = "";
		}
		number += digit < 10 ? digit + '0' : digit - 10 + 'A';
	}
	return number;
}

std::string TEditor::addZero()
{
	return addDigit(0);
}

std::string TEditor::backspace()
{
	number.pop_back();
	return number;
}

std::string TEditor::clear()
{
	number = TEditor::ZERO;
	return number;
}

void TEditor::setNumber(std::string & num)
{
	number = num;
}

std::string TEditor::getNumber() const
{
	return number;
}

