#pragma once

#include <set>

template<class T>
class TSetComp
{
public:
	TSetComp();
	~TSetComp();
	void clear();
	void insert(T x);
	void erase(T x);
	bool empty();
	bool contains(T x);
	TSetComp<T> concat(TSetComp<T> & x);
	TSetComp<T> substract(TSetComp<T> & x);
	TSetComp<T> intersect(TSetComp<T> & x);
	int size();
	T elemAt(int i);

private:
	std::set<T> set;
};

template<class T>
TSetComp<T>::TSetComp()
{
}

template<class T>
TSetComp<T>::~TSetComp()
{
}

template<class T>
void TSetComp<T>::clear()
{
}

template<class T>
void TSetComp<T>::insert(T x)
{
}

template<class T>
void TSetComp<T>::erase(T x)
{
}

template<class T>
bool TSetComp<T>::empty()
{
	return false;
}

template<class T>
bool TSetComp<T>::contains(T x)
{
	return false;
}

template<class T>
TSetComp<T> TSetComp<T>::concat(TSetComp<T> & x)
{
	return TSetComp();
}

template<class T>
TSetComp<T> TSetComp<T>::substract(TSetComp<T> & x)
{
	return TSetComp();
}

template<class T>
TSetComp<T> TSetComp<T>::intersect(TSetComp<T> & x)
{
	return TSetComp<T>();
}

template<class T>
int TSetComp<T>::size()
{
	return 0;
}

template<class T>
T TSetComp<T>::elemAt(int i)
{
	return T();
}
