// 3.14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
void simply_path(char *path, int,char *s_path,int*);
int main()
{
	char path[] = { "/a/./b/../../c/" };
	char s_path[10];
	int n;
	int i;
	simply_path(path, strlen(path), s_path, &n);
	for (i = 0; i < n;i++)
	printf("%c", s_path[i]);
	system("pause");
    return 0;
}
void simply_path(char *path, int len, char *s_path, int *n) {

	int i;
	int j;
	int top = -1;
	for (i = 0; i < len; i++) {
		if (path[i] == '.') {              //.*
			if (path[i + 1] == '.') {      //..
				i += 2;
				while (path[i] == '/')i++;
				i = i - 1;
				top--;
				while (s_path[top] != '/')top--;
			}
			else {                             //.
				i++;
				while (path[i] == '/')i++;
				i = i - 1;
				//s_path[++top] = '/';
			}
		}
		else if (path[i] == '/') {              //  /
			s_path[++top] = '/';
			i++;
			while (path[i] == '/')i++;
			i--;
		}
		else {                                //else
			s_path[++top] = path[i];
		}
	}
	*n = top + 1;
}


