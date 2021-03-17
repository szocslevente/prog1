#include "std_lib_facilities.h"


class B1 
{
public:

	virtual void vf() { cout << "B1::vf()\n";}
	void f() {cout << "B1::f()\n";}
	//virtual void pvf() = 0;
};

class D1 : public B1
{
public:
	
	void vf() override{ cout << "D1::vf()\n";}	
	void f() { cout << "D1::f()\n";}
	//void pvf() override { cout << "D1::pvf\n";}

};

class D2 : public D1
{
public:

	//void pvf() override { cout << "D2::pvf()\n";} 
};

class B2
{
public:
	virtual void pvf() = 0; 
};

class D21 : public B2
{
public:
	void pvf() override { cout << s <<'\n';}
	string s;
};

class D22 : public B2
{
public:
	void pvf() override { cout << i <<'\n';}
	void f(B2& b2Ref) { b2Ref.pvf();}
	int i;
};

int main()
{
	
	B1 b1;
	b1.vf();
	b1.f();
	cout << endl;
	

	D1 d1;
	d1.vf();
	d1.f();
	cout << endl;

	B1&  b1Ref = d1;
	b1Ref.vf();
	b1Ref.f();
	cout << endl;

	D2 d2;
	d2.vf();
	d2.f();
	//d2.pvf();
	cout << endl;

	D21 d21;
	d21.s = "ez egy string";

	D22 d22;
	d22.i = 10;

	d22.f(d21);
	d22.f(d22);
}