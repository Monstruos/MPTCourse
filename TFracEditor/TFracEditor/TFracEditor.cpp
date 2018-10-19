#include "stdafx.h"
#include "../../TFrac/TFrac/TFrac.h"
#include "TFracEditor.h"

const std::string TFracEditor::ZERO = "0/1";
const char TFracEditor::DIV_SIGN = '/';

TFracEditor::TFracEditor() : number("0") {
}


bool TFracEditor::isZero() {
	return TFrac(number).getStringTFrac() == TFracEditor::ZERO;
}


std::string TFracEditor::changeSign() {
	if (number[0] == '-') {
		number.erase(number.begin());
	}
	else {
		if (!isZero()) {
			number = "-" + number;
		}
	}
	return number;
}


std::string TFracEditor::addDigit(unsigned int digit) {
	if (number == "0") {
		number = "";
	}
	number += (char)('0' + digit);
	return number;
}


std::string TFracEditor::addZero() {
	return number.back() != DIV_SIGN ? addDigit(0) : number;
}


std::string TFracEditor::backspace() {
	number.pop_back();
	if (number == "-" || number.empty()) {
		number = "0";
	}
	return number;
}


std::string TFracEditor::clear() {
	number = "0";
	return number;
}

std::string TFracEditor::addSplit() {
	if (number.find(DIV_SIGN) == std::string::npos) {
		number = number + DIV_SIGN;
	}
	return number;
}


void TFracEditor::setNumber(std::string &num) {
	number = TFrac(num).getStringTFrac();
}


std::string TFracEditor::getNumber() const {
	return TFrac(number).getStringTFrac();
}