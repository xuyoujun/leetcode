// 6.6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//寻找排好后，第一个不是该在位置上的数   例如 第一个数应该为 i+1；
class solution {
public:
	int first_Missing_Positive(int A[], int n) {
		sort_swap(A, n);
		for (int i = 0; i < n; i++) {
			if (A[i] != i + 1)return i + 1;
		}
		return n + 1;
	}
	void sort_swap(int A[], int n) {
		for (int i = 0; i < n; i++) {
			while (A[i] != i + 1) {
				if (A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1])break;
				swap(A[i], A[A[i] - 1]);
			}
		}
	}
		
};
int main()
{
	class solution S;
	int A[] = {3,4,-1,1};
	int pos = S.first_Missing_Positive(A, 4);
	printf("%d  ", pos);
	system("pause");
    return 0;
}

