// 6.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
void merge(int A[], int m, int B[], int n);
void merge2(int A[], int m, int B[], int n);
int main()
{
	int A[12] = { 4,5,6,19,20,25 };
	int B[] = { 10,11,12,13,14,15 };
	merge2(A, 6, B, 6);
	for (int i = 0; i < 12; i++) {
		printf("%d ", A[i]);
	}
	system("pause");
    return 0;
}

void merge(int A[], int m, int B[], int n) {
	int acurr = m + n - 1;
	int a = m - 1;
	int b = n - 1;
	while (a >= 0 && b >= 0) {
		A[acurr--] = A[a] > B[b] ? A[a--] : B[b--];
	}
	while (b >= 0)A[acurr--] = B[b--];

}
// 插入排序
void merge2(int A[], int m, int B[], int n) {
	int i;
	int j;
	int x;
	for (i = 0; i < n; i++) {
		x = B[i]; //
		j = m + i - 1; //j+ 1处是个空位，待数据插入
		while (A[j] > x && j >= 0) A[j + 1] = A[j], j--;
		A[j + 1] = x; //j + 1处是个空位，把x 插入
	}

}