#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include "use_me.h"
using namespace std;
	
	void regionGrow(vector<vector<char>> &board, int row, int col)
	{
		int nRow = board.size();
		int nCol = board[0].size();
		queue<int> seeds;
		seeds.push(row*nCol+col);
		board[row][col] = Solution::symble;
		while(!seeds.empty())
		{
			int oneD = seeds.front();
			seeds.pop();
			row = oneD/nCol;
			col = oneD%nCol;
			int i=0,j=0;
			i=-1;j=0;
			if((row+i)>=0&&(row+i)<nRow&&(col+j)>=0&&(col+j)<nCol&&board[row+i][col+j]=='O')
			{
				board[row+i][col+j] = Solution::symble;
				seeds.push((row+i)*nCol+(col+j));
			}
			i=1;j=0;
			if((row+i)>=0&&(row+i)<nRow&&(col+j)>=0&&(col+j)<nCol&&board[row+i][col+j]=='O')
			{
				board[row+i][col+j] = Solution::symble;
				seeds.push((row+i)*nCol+(col+j));
			}
			i=0;j=-1;
			if((row+i)>=0&&(row+i)<nRow&&(col+j)>=0&&(col+j)<nCol&&board[row+i][col+j]=='O')
			{
				board[row+i][col+j] = Solution::symble;
				seeds.push((row+i)*nCol+(col+j));
			}
			i=0;j=1;
			if((row+i)>=0&&(row+i)<nRow&&(col+j)>=0&&(col+j)<nCol&&board[row+i][col+j]=='O')
			{
				board[row+i][col+j] = Solution::symble;
				seeds.push((row+i)*nCol+(col+j));
			}
		}
	}
	void reassign(vector<vector<char>> &board, int nRow, int nCol)
	{
		for(int i = 0;i<nRow; ++i)
			for(int j = 0;j<nCol;++j)
			{
				if(board[i][j]=='X')
					continue;
				if(board[i][j]=='O')
				{
					board[i][j] = 'X';
					continue;
				}
				if(board[i][j] == Solution::symble)
					board[i][j] = 'O';
			}
	}
	void Solution::solve(vector<vector<char>> &board) {
		int nRow = board.size();
		if(nRow<1)
			return;
		int nCol = board[0].size();

		for(int i=0;i<nCol;++i)
			if(board[0][i]=='O')
				regionGrow(board,0,i);
		for(int i = 0;i<nCol;++i)
			if(board[nRow-1][i]=='O')
				regionGrow(board,nRow-1,i);
		for(int i=0;i<nRow;++i)
			if(board[i][0]=='O')
				regionGrow(board,i,0);
		for(int i = 0;i<nRow;++i)
			if(board[i][nCol-1]=='O')
				regionGrow(board,i,nCol-1);
		reassign(board, nRow, nCol);
	}