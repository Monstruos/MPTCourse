#include "stdafx.h"
#include "TPoly.h"
#include <list>

typedef std::list<TMember>::iterator ltmi;


TPoly::TPoly()
{
	polynom.push_front(TMember(0, 0));
}

TPoly::TPoly(int k, int n)
{
	polynom.push_front(TMember(k, n));
}

TPoly::~TPoly()
{
}

int TPoly::getExp()
{
	return polynom.begin()->getExp();
}

int TPoly::getFactor(int exp)
{
	for (ltmi i = this->polynom.begin(); i != polynom.end(); i++)
	{
		int bufExp = i->getExp();
		if (bufExp == exp)
		{
			return i->getFactor();
		}
	}
	return 0;
}

void TPoly::clear()
{
	polynom.clear();
	polynom.push_back(TMember(0, 0));
}

TPoly & operator+(TPoly & fst, TMember & elem)
{
	TPoly res = fst;
	/*for (ltmi i = res.polynom.begin(); i != res.polynom.end(); i++)
	{
		int bufExp = i->getExp();
		if (bufExp == elem.getExp())
		{
			//i->setFactor(i->getFactor() + elem.getFactor());
			//res.removeDead();
			return res;
		}
		else
		{
			if (elem.getExp() > bufExp)
			{
				TMember buf = elem;
				//res.polynom.insert(i, buf);
				return res;
			}
		}
	}*/
	return res;
}

TPoly & operator+(TPoly & fst, TPoly & sec)
{
	TPoly res;
	for (ltmi i = sec.polynom.begin(); i != sec.polynom.end(); i++)
	{
		res = fst + *i;
	}
	return res;
}

TPoly & operator-(TPoly & fst, TMember & elem)
{
	TMember buf(-(elem.getFactor()), elem.getExp());
	return fst + buf;
}

TPoly & operator-(TPoly & fst, TPoly & sec)
{
	TPoly res;
	for (ltmi i = sec.polynom.begin(); i != sec.polynom.end(); i++)
	{
		TMember buf(-(i->getFactor()), i->getExp());
		res = fst + buf;
	}
	return res;
}

TPoly & operator*(TPoly & fst, TMember & elem)
{
	TPoly res;
	for (ltmi i = fst.polynom.begin(); i != fst.polynom.end(); i++)
	{
		TMember buf(i->getFactor() * elem.getFactor(),
			i->getExp() + elem.getExp());
		res = res + buf;
	}
	return res;
}

TPoly & operator*(TPoly & fst, TPoly & sec)
{
	TPoly res;
	for (ltmi i = sec.polynom.begin(); i != sec.polynom.end(); i++)
	{
		res = res + (fst * (*i));
	}
	return res;
}

TPoly & operator-(TPoly & fst)
{
	TMember a(-1, 0);
	TPoly res = fst * a;
	return res;
}

bool operator==(TPoly & fst, TPoly & sec)
{
	for (ltmi i = fst.polynom.begin(); i != fst.polynom.end(); i++)
	{
		for (ltmi j = sec.polynom.begin(); j != sec.polynom.end(); j++)
		{
			if (*i == *j)
			{
				// Still think that it's evil;
				goto next;
			}
		}
		return false;
	next:;
	}
	return true;
}

TPoly TPoly::differentiate()
{
	TPoly res;
	for (ltmi i = polynom.begin(); i != polynom.end(); i++)
	{
		TMember diff = i->differentiate();
		if (!(diff == TMember(0, 0)))
		{
			res = res + diff;
		}
	}
	return res;
}

double TPoly::calculate(double a)
{
	double res = 0.0;
	for (ltmi i = polynom.begin(); i != polynom.end(); i++)
	{
		res += i->calculate(a);
	}
	return res;
}

TMember & TPoly::elemAt(int i)
{
	for (ltmi it = polynom.begin(); it != polynom.end(); it++)
	{
		if (it->getExp() == i)
		{
			return *it;
		}
	}
	TMember res(0, i);
	return res;
}

void TPoly::removeDead()
{
	ltmi prev;
	ltmi i = polynom.begin();
	prev = i;
	for (i++; i != polynom.end(); i++)
	{
		if (i->getFactor() == 0)
		{
			polynom.remove(*i);
			i = prev;
		}
		prev = i;
	}
}
