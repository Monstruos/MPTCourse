#include "stdafx.h"
#include "TMember.h"


TMember::TMember() : fact(0), exp(0)
{

}

TMember::TMember(int k = 0, int n = 0) : fact(k), exp(n)
{

}

int TMember::getExp() const
{
	return exp;
}

int TMember::getFactor() const
{
	return fact;
}

void TMember::setExp(int n)
{
	exp = n;
}

void TMember::setFactor(int k)
{
	fact = k;
}

TMember::~TMember()
{
}

bool operator==(const TMember & fst, const TMember & sec)
{
	return fst.fact == sec.fact && fst.exp == sec.exp;
}

TMember TMember::differentiate()
{
	TMember res(fact * exp, exp - 1);
	return res;
}

double TMember::calculate(double a)
{
	return pow(a, exp) * fact;
}

std::string TMember::toString()
{
	return std::to_string(fact) + "*x^" + std::to_string(exp);
}
