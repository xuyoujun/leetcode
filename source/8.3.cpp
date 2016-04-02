// 8.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution {

public:
	vector <vector<int>> Permutations(vector<int> S) {
		vector <vector<int>> result;
		vector <int> path;
		Permutations2(S, path, result);
		return result;
	}
private:
	void Permutations(vector<int> S,vector <int> &path, vector <vector<int>> &result) { //dfs 寻找路径
		if (0 == S.size()) {
			//cout << path[1] << endl;
			result.push_back(path);
			return;
		}
		vector <int> temp = S;
		vector <int> temp2 = S;
		for (int  itor = 0;  itor < S.size(); itor++) {
			path.push_back(S[itor]);
			temp = S;
			temp.erase(temp.begin() + itor);
			Permutations(temp, path, result);
			path.pop_back(); //走到尽头时回溯
		}
	}
	void Permutations2(vector<int> S, vector <int> &path, vector <vector<int>> &result) { //dfs 寻找路径
		if (path.size() == S.size()) {
			//cout << path[1] << endl;
			result.push_back(path);
			return;
		}
		for (auto i :S) {
			cout << "i = " << i<<endl;
			auto pos = find(path.begin(), path.end(),i);
			if (pos == path.end()) {
				path.push_back(i);
				Permutations2(S, path, result);
				path.pop_back(); //走到尽头时回溯
			}
		}
	}

};
int main()
{
	vector <int> S;
	for (int i = 0; i < 4; i++) {
		S.push_back(i + 1);
	}
	vector < vector <int >> result;
	class solution so;
	result = so.Permutations(S);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j];
		cout << endl;
	}
	system("pause");
    return 0;
}

