// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//class base{
//	public:
//		static unsigned int get_count(){
//			return _object_count;
//		}	
//	private:
//		static int _object_count; 
//			
//};
//int base::_object_count = 0; 
//
//class A : public base{
//	public: 
//	static unsigned int get_count(){
//		return 1;
//	}
//};
class base {
public:
	base(int x) {
		a = x;
	}
	void get() {
		cout << a;

	}
private:
	int a;

};
class A :public base {
public:
	A(int x) :base(x + 1) {
		b = x;
	}
	void get() {
		cout << b;

	}
private:
	int b;

};
int main(int argc, char** argv) {
	base a(14);
	base *pa = &a;
	//	a.a = 0;
	void (base::*pmf)() = &base::get;
	*pmf();
	//cout << &a.get;
	cout << sizeof(A);
	//	base ba(2);
	//	base * pba = &a;
	// 	a.get();
	// 	pba->get();
	system("pause");
	return 0;
}

