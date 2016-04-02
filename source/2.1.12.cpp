// 2.1.12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
//#include<algorithm.h>

void Next_Permutation(int A[], int len);
int main()
{
	int i;
	int A[3] = {1,1,7 };
	Next_Permutation(A, 3);
	for (i = 0; i < 3; i++) {
		printf("%d ", A[i]);
	}
	system("pause");
    return 0;
}

int cmp(void const *a, void const *b) 
{
	return *(int *)a - *(int *)b;
}

void swap(int *a, int *b) {
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

void Next_Permutation(int A[], int len) 
{
	int pivot  = 0;
	int rfirst = len - 1;
	int rlast  = rfirst;
	int brlast;
	while (rlast >= 1 && A[rlast] <= A[rlast - 1]) rlast--;  //寻找一个递增数列
	if (rlast == 0) {
		qsort(A, len, sizeof(int), cmp);
		return ;
	}
	brlast = rlast - 1;
	for (pivot = rfirst; pivot >= rlast; pivot--) {      //
		if (A[brlast] < A[pivot]) break;
	}
	swap(&A[pivot], &A[brlast]);
	qsort(A + rlast, rfirst - rlast + 1, sizeof(int), cmp); //把递增数列降序排列
}

