// 11.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
double  pow(int x, int n) {
	bool flag = true;
	if (n < 0) {
		flag = false;
		n = -1 * n;
	}
	int ret = 1;
	while (0 != n) {
		if (1 == (n & 1)) {
			ret *= x;
		}
		x = x *x;
		n >>= 1;
	}
	if(flag)
		return ret;
	return (double)1 / (double)ret;
}


/*int pow(int x, int n) {
	if (0 == n)return 1;
		
	else {
		int v = pow(x, n / 2);
		cout << v << endl;
		if (0 == (n & 0x01)) return v*v;
		else return x*v*v;
	}
}*/
int main()
{
	cout << pow(2, -10);
	system("pause");
    return 0;
}

