#pragma once

#include <string>
#include <math.h>

class TMember
{
public:
	TMember();
	TMember(int k, int n);
	int getExp() const;
	int getFactor() const;
	void setExp(int n);
	void setFactor(int k);
	~TMember();
	friend bool operator==(const TMember & fst, const TMember & sec);
	TMember differentiate();
	double calculate(double a);
	std::string toString();

private:
	int fact;
	int exp;
};

