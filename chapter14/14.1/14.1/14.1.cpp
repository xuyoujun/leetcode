// 14.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

class solution {
public:
	int reverse(int x) {
		int r = 0;
		while(x != 0){
			r = r * 10 + x % 10;
			x /= 10;
		};
		return r;
	}

};

int main()
{
	solution S;
	cout << S.reverse(123);
	system("pause");
    return 0;
}