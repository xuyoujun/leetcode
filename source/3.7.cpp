// 3.7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

bool isMatch(char *, char *);
bool isMatch2(char *, char *);
int main()
{
	printf("%d\n", isMatch2("aa", ".*"));
	system("pause");
	return 0;
}
//c* ��ʾ��0������c 
//�ݹ�
bool isMatch(char *s, char *p)
{
	if (*p == '\0') return *s == '\0';
	if (*(p + 1) != '*') { //p����һ������*
		if (*s == *p || (*p == '.' && *s != '\0')) {
			return isMatch(s + 1, p + 1);
		}
		else {
			return false;
		}
	} //p����һ����*
	else {
		//if (*s == '\0') return true;
		if (*s == *p || *p == '.' && *s != '\0') {
			return isMatch(s + 1, p);
		}
		else {
			return isMatch(s, p + 2);
		}
	}
	/*
	else {
	while( *s == *p || *s != '\0'&& *p == '.'){
	if(isMatch(s, p + 2)) return ture;
	s ++;
	}
	return isMatch(s, p + 2);
	}

	*/
}

//�ǵݹ�

bool isMatch2(char *s, char *p) {
	while (*p != '\0') {
		if (*(p + 1) != '*') {//p����һ������*
			if (*s == *p || *p == '.'&& *s != '\0') {
				s++;
				p++;
			}
			else {
				return false;
			}
		}
		else { //p����һ����*
			if (*s == *p || *p == '.' && *s != '\0') { //s �� p����
				s++;
			}
			else {  //s �� p������
				p += 2;
			}
		}
	}
	return *s == '\0';
}