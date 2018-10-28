#include "stdafx.h"
#include <cmath>
#include "TPoly.h"


TPoly::TPoly(int k, int n){
	polynom.emplace_back(k, n);
}

int TPoly::getExp()
{
	return polynom.begin()->getExp();
}

int TPoly::getFactor(int exp)
{
	for (auto mem : polynom)
	{
		if (mem.getExp() == exp)
		{
			return mem.getFactor();
		}
	}
	return 0;
}

void TPoly::clear()
{
	polynom.clear();
	polynom.emplace_back(0, 0);
}

TPoly TPoly::operator+(const TMember &elem)
{
	TPoly res = *this;

	res.polynom.remove(TMember(0, 0));

	for (auto it = res.polynom.begin(); it != res.polynom.end(); ++it)
	{
		int memExp = it->getExp();
		int elemExp = elem.getExp();
		if (memExp == elemExp)
		{
			int buf = it->getFactor() + elem.getFactor();
			if (buf != 0)
			{
				it->setFactor(buf);
			}
			else
			{
				res.polynom.remove(*it);
			}
			if (res.polynom.empty())
			{
				res.polynom.emplace_back(0, 0);
			}
			return res;
		}
		else
		{
			if (elemExp > memExp)
			{
				TMember buf = elem;
				res.polynom.insert(it, buf);
				return res;
			}
		}
	}

	res.polynom.push_back(elem);

	return res;
}

TPoly TPoly::operator+(const TPoly &sec)
{
	TPoly res = *this;
	auto itFst = res.polynom.begin();
	auto itSnd = sec.polynom.begin();
	for (; itFst != res.polynom.end(); ++itFst)
	{
		// insert all elems from snd list that should place before (fst->exp)
		while (itSnd->getExp() > itFst->getExp() && itSnd != sec.polynom.end())
		{
			res.polynom.insert(itFst, *itSnd);
			++itSnd;
		}
		if (itSnd->getExp() == itFst->getExp())
		{
			int buf = itFst->getFactor() + itSnd->getFactor();
			if (buf != 0)
			{
				itFst->setFactor(buf);
			}
			else
			{
				res.polynom.remove(*itFst);
			}
			++itSnd;
		}
	}
	// if fst list is ended, but second still have mononoms.
	// for example:
	// fst: x^4 + x^3
	// snd: x^2 + x^1
	if (itSnd != sec.polynom.end())
	{
		res.polynom.insert(itFst, itSnd, sec.polynom.end());
	}
	if (res.polynom.empty())
	{
		polynom.emplace_back(0, 0);
	}
	return res;
}

TPoly TPoly::operator-(const TMember &elem)
{
	return *this + TMember(-elem.getFactor(), elem.getExp());
}

TPoly TPoly::operator-(const TPoly &sec)
{
	TPoly res = *this;

	for (auto mem : sec.polynom)
	{
		res = res - mem;
	}

	return res;
}

TPoly TPoly::operator*(const TMember &elem)
{
	TPoly res;

	for (auto mem : polynom)
	{
		res = res + TMember(mem.getFactor() * elem.getFactor(), mem.getExp() + elem.getExp());
	}

	return res;
}

TPoly TPoly::operator*(const TPoly &sec)
{
	TPoly res;

	for (auto mem : polynom)
	{
		for (auto secMem : sec.polynom)
		{
			res = res + TMember(mem.getFactor() * secMem.getFactor(), mem.getExp() + secMem.getExp());
		}
	}

	return res;
}

TPoly TPoly::operator-()
{
	TPoly zero(0, 0);
	return zero - *this;
}

bool TPoly::operator==(const TPoly &sec)
{
	auto size = polynom.size();
	if (size != sec.polynom.size())
	{
		return false;
	}

	auto secMem = sec.polynom.begin();
	for (auto mem : polynom)
	{
		if (!(mem == *secMem))
		{
			return false;
		}
	}

	return true;
}

TPoly TPoly::differentiate()
{
	TPoly res;

	for (auto mem : polynom)
	{
		if (mem.getExp())
		{
			res = res + mem.differentiate();
		}
	}

	return res;
}

double TPoly::calculate(double a)
{
	double res = 0.0;

	for (auto i : polynom)
	{
		res += i.calculate(a);
	}

	return res;
}

TPoly::TMember &TPoly::elemAt(int idx)
{
	auto mem = polynom.begin();
	for (int i = 0; i < idx; ++i)
	{
		mem++;
	}
	return *mem;
}

TPoly::TMember::TMember(int k, int n) : fact(k), exp(n)
{

}

int TPoly::TMember::getExp() const
{
	return exp;
}

int TPoly::TMember::getFactor() const
{
	return fact;
}

void TPoly::TMember::setExp(int n)
{
	exp = n;
}

void TPoly::TMember::setFactor(int k)
{
	fact = k;
}

bool TPoly::TMember::operator==(const TMember &sec)
{
	return fact == sec.fact && exp == sec.exp;
}

TPoly::TMember TPoly::TMember::differentiate()
{
	return TMember(fact * exp, exp - 1);
}

double TPoly::TMember::calculate(double a)
{
	return pow(a, exp) * fact;
}

std::string TPoly::TMember::toString()
{
	return std::to_string(fact) + "*x^" + std::to_string(exp);
}
