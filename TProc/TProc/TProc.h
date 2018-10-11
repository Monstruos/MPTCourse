#pragma once
template <class T>
class TProc
{
public:
	TProc();
	~TProc();
	void ReSet();
	void OprtnClear();
	void OprtnRun();
	void FuncRun(enum TFunc func);
	T Lop_Res_Get();
	void Lop_Res_Set(const T & set);
	void Rop_Set(const T & set);
	T Rop_Get();
	enum TOprtn OprtnGet();
	void OprtnSet(enum TOprtn set);

private:
	T Lop_Res;
	T Rop;
	enum TOprtn Operation;
};

enum TOprtn {
	None,
	Add,
	Sub,
	Mul,
	Dvd
};

enum TFunc {
	Rev,
	Sqr
};

