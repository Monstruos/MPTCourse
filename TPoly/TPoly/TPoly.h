#pragma once

#include <list>
#include "TMember.h"

class TPoly
{
public:
	TPoly();
	TPoly(int k, int n);
	~TPoly();
	int getExp();
	int getFactor(int exp);
	void clear();
	friend TPoly & operator+(TPoly & fst, TMember & elem);
	friend TPoly & operator+(TPoly & fst, TPoly & sec);
	friend TPoly & operator-(TPoly & fst, TMember & elem);
	friend TPoly & operator-(TPoly & fst, TPoly & sec);
	friend TPoly & operator*(TPoly & fst, TMember & elem);
	friend TPoly & operator*(TPoly & fst, TPoly & sec);
	friend TPoly & operator-(TPoly & fst);
	friend bool operator==(TPoly & fst, TPoly & sec);
	TPoly differentiate();
	double calculate(double a);
	TMember & elemAt(int i);
private:
	std::list<TMember> polynom;
	void removeDead();
};

