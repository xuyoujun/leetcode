// 9.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <vector>
using namespace std;


class Solution {

public:
	void surround_Region(vector <vector<char>> &board) {
		if (board.empty())return;  //ÌØÊâÇé¿ö
		int m = board.size();
		int n = board[0].size();
		for (int row = 0; row < m;row ++) {
		
			bfs(row, n - 1,board);
			bfs(row, 0, board);
		}
		for (int col = 0; col < n; col++) {
			bfs(0, col,board);
			bfs(m - 1, col,board);
		}
		for (auto i = 0; i < m; i++)
			for (auto j = 0; j < n; j++) {
				if (board[i][j] == 'o')
					board[i][j] = 'X';
				else if (board[i][j] == '+')
					board[i][j] = 'o';
		}

	
	}
private :
	void bfs(int row, int col, vector <vector <char>> &board) {
		int m = board.size();
		int n = board[0].size();

		typedef pair<int, int> state_t;
		auto state_is_valid = [&]( state_t & s) {
			int x = s.first;
			int y = s.second;
			if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'o')
				return false;
			return true;
		};
		vector <state_t> result;
		auto state_extend = [&](state_t & s) {
			int x = s.first;
			int y = s.second;
			state_t new_state[4] = { {x - 1,y},{x + 1, y},{x, y - 1},{x, y + 1} };
			for (int i = 0; i < 4; i++) {
				if (state_is_valid(new_state[i])) {
					//board[new_state[i].first][new_state[i].second] = '+';
					result.push_back(new_state[i]);
				}
			}
			return result;
		};
		state_t start = { row,col };
		vector <state_t> current;
		if (state_is_valid(start)) {
			board[row][col] = '+';
			current.push_back(start);
		}
		while (!current.empty()) {
			state_t cur;
			cur = current.front();
			current.pop_back();
			for (auto i : state_extend(cur)) {
				board[i.first][i.second] = '+';
				current.push_back(i);
			}
		}
	}

};


int main()
{
	char ch[4][4] = { 
	{'X','X','X' ,'X'},
	{'X','O','O','X'},
	{'X','X','O','X' },
	{'X','O','X','X' }
	};
	vector <vector<char>> board;
	board.push_back({ 'X','X','X' ,'X' });
	board.push_back({ 'X','o','o' ,'X' });
	board.push_back({ 'X','X','o' ,'X' });
	board.push_back({ 'X','o','X' ,'X' });
	Solution S;
	S.surround_Region(board);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
    return 0;
}

