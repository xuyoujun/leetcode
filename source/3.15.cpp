// 3.15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include<stdio.h>
//#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
unsigned int Last_word_length(char *);
unsigned int Last_word_length2(const char *str);
int main()
{
	char *str = "dasel a;oerje ;aoueiraiw  aierui eiuri";
	int len = Last_word_length2(str);
	printf("%d\n", len);
	system("pause");
    return 0;
}

//比较精妙的写法
unsigned int Last_word_length(char *str) {
	unsigned int len = 0;
	while (*str) {
		if (*str++ != ' ') {
			len++;
		}
		else if(*str != ' ' && *str){  //执行到这时，*str的前一个是空格
			len = 0;
		}
	}
	return len;
}
unsigned int Last_word_length2(const char *str) {
	const string c_str(str);
	auto first = find_if(c_str.rbegin(), c_str.rend(), ::isalpha);
	auto last = find_if_not(first, c_str.rend(), ::isalpha);
	return distance(first, last);
}









