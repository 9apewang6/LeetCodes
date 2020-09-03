
#include<stdio.h>
#include"stdlib.h"
#include<iostream>
#include<ctype.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<vector<char> > >sum;
bool check(vector<vector<char> > &board, int k)
{
	int x = k / 9;
	int y = k % 9;
	for (int i = 0; i < 9; i++)
	{
		if (i != x&&board[x][y] == board[i][y])
			return false;
	}
	for (int j = 0; j < 9; j++)
	{
		if (j != y&&board[x][y] == board[x][j])
			return false;
	}
	for (int i = 3 * (x / 3); i < 3 * (x / 3 + 1); i++)
		for (int j = 3 * (y / 3); j < 3 * (y / 3 + 1); j++)
			if (i != x&&j != y&&board[i][j] == board[x][y])
				return false;
	return true;
}
void dfs(int num, vector<vector<char> >& board)
{
	if (num == 81)
	{
		sum.push_back(board);
		return;
	}
	else {
		int x = num / 9;
		int y = num % 9;
		if (board[x][y] == '.')
		{
			for (int i = 1; i < 10; i++)
			{
				board[x][y] = i + '0';
				if (check(board, num))
				{
					dfs(num + 1, board);
				}

			}
			board[x][y] = '.';//如果没有满足条件的数值，则恢复原来点值，向上回溯，改变父节点的值，重新往下计算，直到根节点第一个位置的值遍历到9为止。
		}
		else
		{
			dfs(num + 1, board);
		}
	}
}
void solveSudoku(vector<vector<char> >& board)
{
	dfs(0, board);
}
int main()
{
	vector<string> myboard({ "...748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.." });
	vector<char> temp(9, '.');
	vector<vector<char> > board(9, temp);
	for (int i = 0; i < myboard.size(); i++) {
		for (int j = 0; j < myboard[i].length(); j++) {
			board[i][j] = myboard[i][j];
		}
	}
	solveSudoku(board);
	for (int k = 0; k < sum.size(); k++) {
		for (int i = 0; i < sum[k].size(); i++) {
			for (int j = 0; j < sum[k][i].size(); j++) {
				cout << sum[k][i][j] << " ";
			}
			cout << endl;
		}
		cout << "######" << endl;
	}
	cout << "sum is " << sum.size() << endl;
	cout << "Hello world!" << endl;
	system("pause");
	return 0;
}