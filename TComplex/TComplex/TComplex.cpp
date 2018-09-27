// TComplex.cpp : Определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include "TComplex.h"
#include <cmath>



int TComplex::sign(double x)
{
	if (x > 0)
	{
		return 1;
	}
	else
	{
		return x == 0 ? 0 : -1;
	}
}

TComplex::TComplex() : re(0), im(0)
{
}


TComplex::~TComplex()
{
}

TComplex::TComplex(double real, double image) : re(real), im(image)
{
}

TComplex::TComplex(std::string & number)
{
	try
	{
		size_t slashIdx = number.find("+i*");
		int k = 1;
		if (slashIdx == std::string::npos)
		{
			slashIdx = number.find("-i*");
			k = -1;
		}
		re = std::stod(number.substr(0, slashIdx));
		im = std::stod(number.substr(slashIdx + 3)) * k;
	}
	catch (...)
	{
		re = 0;
		im = 0;
	}
}

TComplex TComplex::operator=(const TComplex & sec)
{
	re = sec.re;
	im = sec.im;
	return *this;
}

TComplex TComplex::operator+(const TComplex & sec)
{
	TComplex tmp(re + sec.re, im + sec.im);
	return tmp;
}

TComplex TComplex::operator-(const TComplex & sec)
{
	TComplex tmp(re - sec.re, im - sec.im);
	return tmp;
}

TComplex TComplex::operator*(const TComplex & sec)
{
	TComplex tmp(re*sec.re - im * sec.im, re*sec.im + im * sec.re);
	return tmp;
}

TComplex TComplex::operator/(const TComplex & sec)
{
	TComplex tmp((re*sec.re + im * sec.im) / (im*im + sec.im*sec.im),
		(im*sec.re - re * sec.im) / (im*im + sec.im*sec.im));
	return tmp;
}

TComplex TComplex::operator-()
{
	return TComplex(-re, im);
}

TComplex TComplex::sqr()
{
	return *this * *this;
}

TComplex TComplex::inverse()
{
	return TComplex(1, 0) / *this;
}

double TComplex::module()
{
	return sqrt(re * re + im * im);
}

double TComplex::radDegree()
{
	switch (sign(re))
	{
	case 1:
		return atan(im / re);
	case 0:
		switch (sign(im))
		{
		case 1:
			return COMPL_PI / 2;
		case 0:
			throw std::invalid_argument("Number is zero!");
		case -1:
			return -COMPL_PI / 2;
		}
	case -1:
		return atan(im / re) + COMPL_PI;
	}
}

double TComplex::gradDegree()
{
	return radDegree() * 180 / COMPL_PI;
}

bool TComplex::operator==(const TComplex & sec)
{
	return (re == sec.re && im == sec.im);
}

bool TComplex::operator!=(const TComplex & sec)
{
	return re != sec.re || im != sec.im;
}
