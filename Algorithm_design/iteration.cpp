#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<stack>
#include<map>
#include<algorithm>
#include<vector>
#include <cstdlib> /* 亂數相關函數 */
#include <ctime>   /* 時間相關函數 */

using namespace std;

void print_board(bool board[5][5])
{
	for (int x=0; x<5; ++x)
	{
		for (int y=0; y<5; ++y)
			cout << (board[x][y] ? '@' : ' ');
		cout << '\n';
	}
	cout << '\n';
}

// 八個鄰居中，還活著的細胞數目。
int count_neighbor(int x, int y, bool board[5][5])
{
	static const int dx[8] = {-1,-1,-1,0,0,1,1,1};
	static const int dy[8] = {-1,0,1,-1,1,-1,0,1};

	int n = 0;
	for (int i=0; i<8; ++i)
	{
		int mx = x + dx[i];
		int my = y + dy[i];
		if (mx >= 0 && mx < 5 && my >= 0 && my < 5)
			n += board[mx][my];
	}
	return n;
}

// 判斷細胞死活
void go(int x, int y, bool board[5][5], bool next[5][5])
{
	int n = count_neighbor(x, y, board);
	if (!board[x][y])
		if (n == 3)					// 復活
			next[x][y] = true;
		else						// 仍舊死亡
			next[x][y] = board[x][y];
	else
		if (n == 2 || n == 3)		// 存活
			next[x][y] = true;
		else if (n == 0 || n == 1)	// 死於孤單
			next[x][y] = false;
		else if (n >= 4)			// 死於擁擠
			next[x][y] = false;
}

// 清空細胞
void clear_board(bool board[5][5])
{
	for (int x=0; x<5; ++x)
		for (int y=0; y<5; ++y)
			board[x][y] = false;
}

// 預先設定一些活的細胞
void load_board(bool board[5][5])
{
	board[3][1] = true;
	board[3][2] = true;
	board[3][3] = true;
	board[2][3] = true;
	board[1][2] = true;
}

void cellular_automaton()
{
	bool board[2][5][5] = {};
	clear_board(board[0]);
	load_board(board[0]);
	print_board(board[0]);

	// 遞推四回合
	for (int t=0; t<4; ++t)
	{
		for (int x=0; x<5; ++x)
			for (int y=0; y<5; ++y)
				go(x, y, board[t%2], board[(t+1)%2]);

		print_board(board[(t+1)%2]);
	}
}


int main(){
    cellular_automaton();
    
    
    
    return 0;
}