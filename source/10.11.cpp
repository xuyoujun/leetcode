// 10.11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	bool wordSearch(vector <vector <char>> &board, string &word) {
		bool done = false;
		int curr = 0;
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[i].size(); j++) {
				if (!done && board[i][j] == word[0]) {
					visited = vector<vector <bool>>(board.size(),vector<bool>(board[0].size(),false));
				//	visited[i][j] = true;
					dfs2(i, j, word, curr, done, board);
					//visited[i][j] = false;
				}
			}
		return done;
	}
private:
	void dfs(int i, int j, string & word, int curr, bool & done, vector<vector<char>> &board) {
		if (done) return ;
		else {
			visited[i][j] = true;
			curr++;
			if (curr == word.size()) {
				done = true;
				return;
			}
			int m = board.size();
			int n = board[i].size();
			
			if (0 == i && board[i + 1][j] == word[curr] && !visited[i + 1][j]) { 
			//	visited[i + 1][j] = true;
				dfs(i + 1, j, word, curr, done, board); 
				//visited[i + 1][j] = false;
			}
			if (i == m - 1 && board[i - 1][j] == word[curr] && !visited[i - 1][j]) { 
				//visited[i - 1][j] = true;
				dfs(i - 1, j, word, curr, done, board);
				//visited[i - 1][j] = false;
			}
			if (j == n - 1 && board[i][j - 1] == word[curr] && !visited[i][j - 1]) { 
				//visited[i][j - 1] = true;
				dfs(i, j - 1, word, curr, done, board);
				//visited[i][j - 1] = false;
			}
			if (j == 0 && board[i][j+1] == word[curr] && !visited[i][j+1]) dfs(i, j + 1, word, curr, done, board);

			if (0 < i&& i < m - 1) {
				if(board[i+1][j] == word[curr] && !visited[i + 1][j + 1])dfs(i + 1, j, word, curr, done, board);
				if(board[i -1][j] == word[curr] && !visited[i -1][j + 1])dfs(i - 1, j, word, curr, done, board);
			
			}
			if (0 < j && j < n - 1) {
				if (board[i][j - 1] == word[curr] && !visited[i][j - 1])dfs(i, j - 1, word, curr, done, board);
				if (board[i][j + 1] == word[curr] && !visited[i][j + 1])dfs(i, j + 1, word, curr, done, board);
			}
			//curr--;
			visited[i][j] = false;
		}
		
	}

	void dfs2(int i, int j, string & word, int curr, bool & done, vector<vector<char>> &board) {
		if (done) return;
		else {
			if (curr == word.size()) {
				done = true;
				return;
			}	
			int m = board.size();
			int n = board[0].size();
			
			if (i < 0 || j < 0 || i > m - 1 || j > n - 1)return;
			if (visited[i][j] || word[curr] != board[i][j]) return;
		
			visited[i][j] = true;
			dfs2(i + 1, j, word, curr + 1, done, board);
			dfs2(i - 1, j, word, curr + 1, done, board);
			dfs2(i, j - 1, word, curr + 1, done, board);
			dfs2(i, j + 1, word, curr + 1, done, board);
			visited[i][j] = false;
		}
	}


	vector<vector<bool>> visited;
};

int main()
{
	vector <vector <char>> result(3, vector<char>(4, 0));
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++) {
			cin >> result[i][j];
		}
	Solution S;
	string word = "ABCCED";
	cout<<S.wordSearch(result,word);
	word = "SEE";
    cout << S.wordSearch(result, word);
	word = "ADCB";
	cout << S.wordSearch(result, word);
	//Solution2 S;
	//S.solveSudoku(result);
	
	system("pause");
	return 0;
}

