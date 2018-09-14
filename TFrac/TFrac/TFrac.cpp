// TFrac.cpp : Определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include "TFrac.h"




TFrac::TFrac() : numer(0), denom(1)
{
}

TFrac::TFrac(int a, int b)
{
	if (b) {
		numer = a;
		denom = b;
		toShorten();
		setSign();
	}
	else {
		numer = 0;
		denom = 1;
	}
}

TFrac::TFrac(std::string frac)
{
	size_t slashIdx = frac.rfind('/');
	int a = std::stoi(frac.substr(0, slashIdx));
	int b = std::stoi(frac.substr(slashIdx + 1));
	if (b) {
		numer = a;
		denom = b;
		toShorten();
		setSign();
	}
	else {
		numer = 0;
		denom = 1;
	}
}


TFrac::~TFrac()
{
}

TFrac TFrac::copy(TFrac c)
{
	return TFrac((int)c.getNumer(), (int)c.getDenom());
}

TFrac TFrac::operator-() const
{
	TFrac res = TFrac(0, 1) - *this;
	return res;
}

TFrac TFrac::operator+(const TFrac & sec)
{
	int resDenom = LCM(this->denom, sec.denom);
	int resNumer = this->numer * (resDenom / this->denom) + sec.numer * (resDenom / sec.denom);
	TFrac res(resNumer, resDenom);
	return res;
}

TFrac TFrac::operator-(const TFrac & sec)
{
	int resDenom = LCM(this->denom, sec.denom);
	int resNumer = this->numer * (resDenom / this->denom) - sec.numer * (resDenom / sec.denom);
	TFrac res(resNumer, resDenom);
	return res;
}

TFrac TFrac::operator*(const TFrac & sec)
{
	int resDenom = this->denom * sec.denom;
	int resNumer = this->numer * sec.numer;
	TFrac res(resNumer, resDenom);
	return res;
}

TFrac TFrac::operator/(const TFrac & sec)
{
	int resDenom = this->denom * sec.numer;
	int resNumer = this->numer * sec.denom;
	TFrac res(resNumer, resDenom);
	return res;
}

TFrac TFrac::operator+=(const TFrac & sec)
{
	*this = *this + sec;
	return *this;
}

TFrac TFrac::operator-=(const TFrac & sec)
{
	*this = *this - sec;
	return *this;
}

TFrac TFrac::operator*=(const TFrac & sec)
{
	*this = *this * sec;
	return *this;
}

TFrac TFrac::operator/=(const TFrac & sec)
{
	*this = *this / sec;
	return *this;
}

bool TFrac::operator==(const TFrac & sec)
{
	TFrac resNumer = *this - sec;
	return resNumer.numer == 0;
}

bool TFrac::operator<(const TFrac & sec)
{
	TFrac resNumer = *this - sec;
	return resNumer.numer < 0;
}

bool TFrac::operator>(const TFrac & sec)
{
	TFrac resNumer = *this - sec;
	return resNumer.numer > 0;
}

bool TFrac::operator!=(const TFrac & sec)
{
	TFrac resNumer = *this - sec;
	return resNumer.numer != 0;
}

TFrac TFrac::sqr()
{
	return TFrac(this->numer * this->numer, this->denom * this->denom);
}

TFrac TFrac::inverse()
{
	return TFrac(this->denom, this->numer);
}

double TFrac::getNumer()
{
	return (double) this->numer;
}

double TFrac::getDenom()
{
	return this->denom;
}

std::string TFrac::getStringNumer()
{
	return std::to_string(this->numer);
}

std::string TFrac::getStringDenom()
{
	return std::to_string(this->denom);
}

std::string TFrac::getStringTFrac()
{
	return getStringNumer() + "/" + getStringDenom();
}

int TFrac::GCD(int a, int b)
{
	return b ? GCD(b, a%b) : a;
}

int TFrac::LCM(int a, int b)
{
	return a * b / GCD(a, b);
}

void TFrac::toShorten()
{
	int k = GCD(numer, denom);
	numer /= k;
	denom /= k;
}

void TFrac::setSign()
{
	if (denom < 0) {
		numer *= -1;
		denom *= -1;
	}
}
