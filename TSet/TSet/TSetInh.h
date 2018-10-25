#pragma once

#include <set>

template <class T>
class TSetInh : public std::set<T>
{
public:
	TSetInh();
	~TSetInh();
	void clear();
	void insert(T x);
	void erase(T x);
	bool empty();
	bool contains(T x);
	TSetInh<T> concat(TSetInh<T> & x);
	TSetInh<T> substract(TSetInh<T> & x);
	TSetInh<T> intersect(TSetInh<T> & x);
	int size();
	T elemAt(int i);
};

template<class T>
inline TSetInh<T>::TSetInh()
{
}

template<class T>
inline TSetInh<T>::~TSetInh()
{
}

template<class T>
inline void TSetInh<T>::clear()
{
}

template<class T>
inline void TSetInh<T>::insert(T x)
{
}

template<class T>
inline void TSetInh<T>::erase(T x)
{
}

template<class T>
inline bool TSetInh<T>::empty()
{
	return false;
}

template<class T>
inline bool TSetInh<T>::contains(T x)
{
	return false;
}

template<class T>
inline TSetInh<T> TSetInh<T>::concat(TSetInh<T>& x)
{
	return TSetInh<T>();
}

template<class T>
inline TSetInh<T> TSetInh<T>::substract(TSetInh<T>& x)
{
	return TSetInh<T>();
}

template<class T>
inline TSetInh<T> TSetInh<T>::intersect(TSetInh<T>& x)
{
	return TSetInh<T>();
}

template<class T>
inline int TSetInh<T>::size()
{
	return 0;
}

template<class T>
inline T TSetInh<T>::elemAt(int i)
{
	return T();
}
