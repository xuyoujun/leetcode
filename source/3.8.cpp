// 3.8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>
int LongestCommonPrefix(char ** metrix,int row,int colunm);
int LongestCommonPrefix2(char ** metrix, int row, int colunm);
int main()
{
	char *str[5] = { "dddddgtg","ddddss","ddddddswe","ddderrrt","dddewrwe" };
	printf("%d\n",LongestCommonPrefix2(str,5,9));
	system("pause");
    return 0;
}


int LongestCommonPrefix(char ** metrix,int row,int column) {
	int i;
	int j;
	int count = 0;
	for (i = 0; i < column; i++) {
		for (j = 1; j < row; j++) {
			if (metrix[j][i] != metrix[0][i]) return i;
		}
	}
	return i;
}

int LongestCommonPrefix2(char ** metrix, int row, int column) {
	int i;
	int j;
	int most_R = INT_MAX;
	int count = 0;
	for (i = 1; i < row; i++) {
		for (j = 0; j < column; j++) {
			if (metrix[i][j] != metrix[0][j]) break;
			count++;
		}
		most_R = most_R > count ? count : most_R;
		count = 0;
	}
	return most_R;
}