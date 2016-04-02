// 11.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int sqrt(int x) {
	int lower = 1;
	int upper = x / 2;
	int mid;// = lower + (upper - lower) / 2;
	int mid_last;
	if (x < 2) return x;
	while (lower <= upper) {
		mid = lower + (upper - lower) / 2;
		if (x / mid > mid) {
			lower = mid + 1;
			mid_last = mid;    //目的是使 x>= 返回值的平方
		}
		else if(x / mid < mid){
			upper = mid - 1;
		}
		else return mid;
	}
	return mid_last;
	
}


int main()
{
	cout << sqrt(98);
	system("pause");
    return 0;
}

