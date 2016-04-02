// 2.1.13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
void Permutation_Sequence(int n, int k);
int main()
{
	Permutation_Sequence(3, 5);
	system("pause");
    return 0;
}

void Permutation_Sequence(int n, int k) 
{
	int nn[10] = {1};
	int cantor[9];
	int x = k - 1;
	int i;
	for (i = 1; i < 10; i++)
		nn[i] = nn[i - 1]*i;
	if (nn[8] < k) printf("error::k is too large!!");
	for (i = 0; i < n; i++) {
		cantor[i] = x / nn[n - i - 1];
		x = x % nn[n - i - 1];
	}
	for (i = 0; i < n; i++) {
		printf("%d  ", cantor[i]);
	}
}

