// 3.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int Palindrome(char *str, int len);
int Palindrome2(char *str, int len);
int main()
{

	char  str[] ="A man, a plan, a canal : Panama";
	int ret = Palindrome2(str, strlen(str));
	if (ret == 1) printf("huiwen");
	else  printf(" no huiwen");
	system("pause");
    return 0;
}


int Palindrome(char *str, int len)
{
	int low  = 0;
	int high = len - 1;
	while (low < high){
		while (low <= high && !isalpha(str[low])) low++;
		while (low <= high && !isalpha(str[high])) high--;
		if ( tolower(str[low]) != tolower(str[high]) ) break;
		else {
			low++;
			high--;
		}
	}
	if (low < high  ) return -1;
	else 
		return 1;
}

int Palindrome2(char *str, int len)
{
	int low = 0;
	int high = len - 1;
	while (low <= high) {
		if (!isalpha(str[low])) low++;
		else if (!isalpha(str[high])) high--;
		else if (tolower(str[low]) != tolower(str[high])) return -1;
		else {
			low++;
			high--;
		}
	}
	return 1;
}