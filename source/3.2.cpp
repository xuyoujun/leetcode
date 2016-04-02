// 3.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>

char * strStr(char * haystack, char * needle);
char * strStr2(const char * haystack, const char * needle);

int main()
{

	char  haystack[] = "Hello youjun strstr";
	char needle[] = "youjun";
	char * ret = (char *)strStr2(haystack, needle);
	printf("%s", ret);
	system("pause");
    return 0;
}

char * strStr(const char * haystack, const char * needle) {
	const char  *p1 ;
	const char  *p2 ;
	const char  *temp;
	for (p1 = haystack ; *p1; p1++) {
		p2 = needle;
		if (*p1 == *p2) {
			temp = p1;
			for (p2 ; *p2 ; p2++){
				if (*temp && *temp == *p2)  temp++;
				else break;
			}
			if (!*p2) return (char *)p1;
		}
	}
	return NULL;
}

char * strStr2(const char * haystack, const char * needle) {
	const char  *p1;
	const char  *p2;
	const char  *p1_advance = haystack;
	if (!needle) return (char *)haystack;

	for (p2 = &needle[1]; *p2; p2++) {
		p1_advance++;
	}

	for (p1 = haystack; *p1_advance; p1_advance++) {
		char *p1_old = (char *)p1;
		p2 = needle;
		while (*p1 && *p2 && *p1 == *p2) {
			p1++;
			p2++;
		}
		if (!*p2) return p1_old;
		p1 = p1_old + 1;
	}
	return NULL;
}