// 3.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int add_binary(char * a, char * b, char * result);
int main()
{
	char a[] = "11111100";
	char b[] = "110011";
	char result[20];
	int i;
	int k = add_binary(a, b, result);
	for (i = k - 1; i > -1; i--)
		printf("%d ", result[i]);
	system("pause");
    return 0;
}

int add_binary(char * a, char * b, char * result) 
{
	int len_max = strlen(a);
	int len_min = strlen(b);
	char *ch_max;
	char *ch_min;
	int diff;
	int carry = 0;
	int i,j,k;
	if (len_max > len_min) {
		ch_max = a;
		ch_min = b;
	}
	else {
		ch_max = b;
		ch_min = a;
		diff = len_min;
		len_min = len_max;
		len_max = diff;
	}
	diff = len_max - len_min;
	for (i = len_min - 1, j = len_max - 1,k =0; i > -1; i--,j--,k++) {
		result[k] = (ch_min[i] - '0' + ch_max[j] - '0' + carry) & 0x01;;
		carry = (ch_min[i] - '0' + ch_max[j] - '0' + carry) >> 1;
	}
	for (i = diff - 1; i > -1; i--,k++) {
		result[k] = (ch_max[i] - '0' + carry) & 0x01;
		carry = (ch_max[i] - '0'+ carry) >> 1;
	}
	if (1 == carry) result[k++] = 1;
	return k;

}