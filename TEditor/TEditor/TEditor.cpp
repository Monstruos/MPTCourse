#include "stdafx.h"
#include "TEditor.h"

const std::string TEditor::ZERO = "0";
const char TEditor::DIV_SIGN = '.';

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
		if(number != TEditor::ZERO)
			number = "-" + number;
	}
	return number;
}


std::string TEditor::addDigit(unsigned int digit)
{
	if (digit < base)
	{
		if (number == TEditor::ZERO)
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
	if (number == "-" || number == "")
	{
		number = TEditor::ZERO;
	}
	return number;
}


std::string TEditor::clear()
{
	number = TEditor::ZERO;
	return number;
}

std::string TEditor::addSplit()
{
	if (number.find(DIV_SIGN) == std::string::npos)
	{
		number = number + DIV_SIGN;
	}
	return number;
}


void TEditor::setNumber(std::string & num)
{
	number = TPNumber(num, std::to_string(base)).getNumberAsString();
}


std::string TEditor::getNumber() const
{
	return TPNumber(number, std::to_string(base)).getNumberAsString();
}

