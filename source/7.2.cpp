// 7.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Solution {
public:
	int search_Insert_Position(int A[], int n ,int target) {
		int lower = 0;
		int upper = n;
		int mid;
		while (lower < upper) {
			mid = lower + (upper - lower) / 2;
			if (A[mid] < target)lower = mid + 1;
			else upper = mid;
		}
		return lower;
	}

};
int main()
{
	class Solution S;
	int A[] = { 1,3,5,6 };
	cout << S.search_Insert_Position(A, 4, 5);
	system("pause");
    return 0;
}

