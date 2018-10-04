#pragma once
template <class T>
class TMemory
{
private:
	T fNumber;
	bool fState;
public:
	TMemory();
	~TMemory();

	void write(const T& e);
	T get();
	void add(const T & e);
	void clear();
};

