// TProc.cpp : Определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include "TProc.h"



template <class T>
TProc<T>::TProc() : Lop_Res(T()), Rop(T())
{
	Operation = None;
}


template <class T>
TProc<T>::~TProc()
{
}

template<class T>
void TProc<T>::ReSet()
{
	Lop_Res = T();
	Rop = T();
	Operation = None;
}

template<class T>
void TProc<T>::OprtnClear()
{
	Operation = None;
}

template<class T>
void TProc<T>::OprtnRun()
{
	switch (Operation)
	{
	case Add:
		Lop_Res = Lop_Res + Rop;
		break;
	case Sub:
		Lop_Res = Lop_Res - Rop;
		break;
	case Mul:
		Lop_Res = Lop_Res * Rop;
		break;
	case Dvd:
		Lop_Res = Lop_Res / Rop;
		break;
	None:
	default:
		break;
	}
}

template<class T>
void TProc<T>::FuncRun(enum TFunc func)
{
	switch (func) {
	Rev:
		Rop = Rop.reverse();
		break;
	Sqr:
		Rop = Rop.sqr();
		break;
	default:
		break;
	}
}

template<class T>
T TProc<T>::Lop_Res_Get()
{
	return Lop_Res;
}

template<class T>
void TProc<T>::Lop_Res_Set(const T & set)
{
	Lop_Res = set;
}

template<class T>
void TProc<T>::Rop_Set(const T & set)
{
	Rop = set;
}

template<class T>
T TProc<T>::Rop_Get()
{
	return Rop;
}

template<class T>
TOprtn TProc<T>::OprtnGet()
{
	return Operation;
}

template<class T>
void TProc<T>::OprtnSet(enum TOprtn set)
{
	Operation = set;
}
