#include "stdafx.h"
#include "../../TComplex/TComplex/TComplex.h"
#include "TComplexEditor.h"

const std::string TComplexEditor::ZERO = "0+i*0";
const std::string TComplexEditor::DIV_SIGN = "+i*";

TComplexEditor::TComplexEditor() : number("0"), isRealPartEditing(true) {
}


bool TComplexEditor::isZero() {
	return TComplex(number).toString() == TComplex(0).toString();
}


std::string TComplexEditor::changeSign() {
	if (isRealPartEditing) {
		if (number[0] == '-') {
			number.erase(number.begin());
		}
		else {
			if (number[0] != '0') {
				number = "-" + number;
			}
		}
	}
	else {
		auto pos = number.find("i*");
		number[pos - 1] = (number[pos - 1] == '-') ? '+' : '-';
	}
	return number;
}


std::string TComplexEditor::addDigit(unsigned int digit) {
	auto pos = isRealPartEditing ? 0 : number.find('*') + 1;
	if (number[pos] == '0') {
		number.pop_back();
	}
	number += (char)('0' + digit);
	return number;
}


std::string TComplexEditor::addZero() {
	return addDigit(0);
}


std::string TComplexEditor::backspace() {
	number.pop_back();
	if (isRealPartEditing) {
		if (number == "-" || number.empty()) {
			number = "0";
		}
	}
	else {
		if (number.find('*')) {
			number.erase(number.end() - 2, number.end());
			isRealPartEditing = true;
		}
	}
	return number;
}


std::string TComplexEditor::clear() {
	number = "0";
	isRealPartEditing = true;
	return number;
}

std::string TComplexEditor::addSplit() {
	if (number.find(DIV_SIGN) == std::string::npos) {
		number = number + DIV_SIGN;
		isRealPartEditing = false;
	}
	return number;
}


void TComplexEditor::setNumber(std::string &num) {
	number = TComplex(num).toString();
}


std::string TComplexEditor::getNumber() const {
	return TComplex(number).toString();
}