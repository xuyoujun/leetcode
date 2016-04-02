// 3.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
int my_atoi(const char *str);
int main()
{
	char str1[] = "78hh";
	char str2[] = "7d8h";
	char str3[] = "-78d";
	char str4[] = "d78";
	char str5[] = "78000099999999999999999";
	printf("%d\n", my_atoi(str1));
	printf("%d\n", my_atoi(str2));
	printf("%d\n", my_atoi(str3));
	printf("%d\n", my_atoi(str4));
	printf("%d\n", my_atoi(str5));
	system("pause");
    return 0;
}


int my_atoi(const char *str) 
{
	int sign = 1;
	int num = 0;
	int i = 0;
	while (str[i] == ' ')i++;
	if (str[i] == '-') {
		sign = -1;
		i++;
	}else if (str[i] == '+') {
		sign = 1;
		i++;
	}
	printf("%d  \n", sign);
	for (; str[i]; i++) {
		if ( isdigit(str[i]) ) {
			if (num > INT_MAX / 10 || num == INT_MAX / 10 && (str[i] - '0' > INT_MAX % 10))
				return sign == - 1 ? INT_MIN : INT_MAX;
			num = num * 10 + (str[i] - '0');
		}
		else break;
	}
	return sign * num;
}