// TMemory.cpp : Определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include "TMemory.h"



template <class T>
TMemory<T>::TMemory() : fNumber(T()), fState(false)
{

}

template <class T>
TMemory<T>::~TMemory()
{

}

template<class T>
void TMemory<T>::write(const T & e)
{
	fNumber = e;
	fState = true;
}

template<class T>
T TMemory<T>::get()
{
	fState = true;
	return fNumber;
}

template<class T>
void TMemory<T>::add(const T & e)
{
	fNumber = fNumber + e;
	fState = true;
}

template<class T>
void TMemory<T>::clear()
{
	fNumber = T();
	fState = false;
}
