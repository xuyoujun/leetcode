// 3.9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

bool valid_number(char *);
bool isNumber(const char *s);
bool isNumber2(const char *s);
int main()
{
	int a = isNumber2(" 2.0e1");
	printf("%d\n", a);
	system("pause");
    return 0;
}



bool valid_number(char *str) {
	
	int state = 0; //0： init  ,1:,整数， 2：小数  3指数

	while ((*str == ' ' || '+' == *str || '-' == *str)&& *str != '\0')str++;
	if (*str == '\0')return false;
	while (*str != '\0') {
		if (isdigit(*str)) {
			if(0 == state) state = 1;
		}
		else if (*str == '.') {
			if (2 == state || 3 == state || 0 == state)return false;
			state = 2;
		}
		else if(*str == 'e' || *str == 'E'){
			if (2 == state || 1 == state) state = 3;
			else
				return false;
		}
		else {
			return false;
		}
	
		str++;
	}
	return true;
}

//leetcode provide
bool isNumber(const char *s) {
	enum InputType {
		INVALID, // 0
		SPACE, // 1
		SIGN, // 2   
		DIGIT, // 3
		DOT, // 4
		EXPONENT, // 5
		NUM_INPUTS // 6
	};
	const int transitionTable[][NUM_INPUTS] = {
		-1, 0, 3, 1, 2, -1, // next states for state 0
		-1, 8, -1, 1, 4, 5, // next states for state 1
		-1, -1, -1, 4, -1, -1, // next states for state 2
		-1, -1, -1, 1, 2, -1, // next states for state 3
		-1, 8, -1, 4, -1, 5, // next states for state 4
		-1, -1, 6, 7, -1, -1, // next states for state 5
		-1, -1, -1, 7, -1, -1, // next states for state 6
		-1, 8, -1, 7, -1, -1, // next states for state 7
		-1, 8, -1, -1, -1, -1, // next states for state 8
	};
	int state = 0;
	for (; *s != '\0'; ++s) {
		InputType inputType = INVALID;
		if (isspace(*s))
			inputType = SPACE;
		else if (*s == '+' || *s == '-')
			inputType = SIGN;
		else if (isdigit(*s))
			inputType = DIGIT;
		else if (*s == '.')
			inputType = DOT;
		else if (*s == 'e' || *s == 'E')
			inputType = EXPONENT;
		// Get next state from current state and input symbol
		state = transitionTable[state][inputType];
		// Invalid input
		if (state == -1) return false;
	}
	// If the current state belongs to one of the accepting (final) states,
	// then the number is valid
	return state == 1 || state == 4 || state == 7 || state == 8;
}



//by me
//.9  8e.8  这样的不合法
bool isNumber2(const char *str) {
	enum InputType{
		INVALID,
		SPACE,
		DOT,
		DIGIT,
		SIGN,
		EXPONMENT,
		TYPE_NUM
	};
	InputType inputtype;
	
	int const STATE_CONVERT[][TYPE_NUM]{
		-1,0,-1,1,0,-1,
		-1,-1,2,1,-1,3,
		-1,-1,-1,6,-1,-1
		-1,-1,-1,5,4,-1
		-1,-1,-1,5,-1,-1
		-1,-1,-1,5,-1,-1
	    -1,-1,-1,6,-1,5
	};
	int state = 0;
	while (*str != '\0') {
		inputtype = INVALID;
		if (*str == ' ')inputtype = SPACE;
		else  if(*str == '.')inputtype = DOT;
		else  if (isdigit(*str))inputtype = DIGIT;
		else  if (*str == '-' || *str == '+')inputtype = SPACE;
		else  if (*str == 'e' || *str == 'E')inputtype = EXPONMENT;
		state = STATE_CONVERT[state][inputtype];
		if (state == -1) return false;
		str++;
	}
	return state == 1 || state == 6 || state == 5;
}