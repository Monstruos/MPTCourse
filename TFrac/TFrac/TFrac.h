#pragma once

#include <string>

class TFrac
{
public:
	TFrac();
	TFrac(int a, int b);
	TFrac(const std::string &frac);
	~TFrac();

	static TFrac copy(TFrac c);

	TFrac operator-() const;

	TFrac operator+ (const TFrac& sec);
	TFrac operator- (const TFrac& sec);
	TFrac operator* (const TFrac& sec);
	TFrac operator/ (const TFrac& sec);

	TFrac operator+= (const TFrac& sec);
	TFrac operator-= (const TFrac& sec);
	TFrac operator*= (const TFrac& sec);
	TFrac operator/= (const TFrac& sec);

	bool operator== (const TFrac& sec);
	bool operator< (const TFrac& sec);
	bool operator> (const TFrac& sec);
	bool operator!= (const TFrac& sec);

	TFrac sqr();
	TFrac inverse();

	double getNumer();
	double getDenom();
	std::string getStringNumer();
	std::string getStringDenom();
	std::string getStringTFrac();


private:
	int numer;
	int denom;
	int GCD(int a, int b);
	int LCM(int a, int b);
	void toShorten();
	void setSign();
};

