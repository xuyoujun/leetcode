// recoverfile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream in;
	in.open("txt.txt", ios::in);
	string str;
	while (( in >> str)) {
		//FILE *fptemp;
		//char temp;
		//fopen_s(&fptemp, str, "r");
		//fscanf_s(fptemp, "%c", &temp);
		//if(temp == '/')
		//cout << str << '\n';
		ifstream intemp;
		string temp, temp1;
		intemp.open(str.c_str(), ios::in);
		intemp >> temp;
		intemp >> temp1;
	//	cout << temp;
		string echo = "rename ";
		string vv = "  ";
		if ("//" == temp) {
			cout << temp1 << '\n';
			cout << str << '\n';
			string h = echo + str + vv + temp1;
			cout << h << '\n';
			//system(h.c_str());
		}
		str.clear();
		//printf("%s\n", str);
		//fclose(fptemp);
	}



	//fclose(fp);
	system("pause");
    return 0;
}

