#include "stdafx.h"
#include <string>
#include <vector>
#include <queue>
#include "use_me.h"
using namespace std;
	
	int int2pow(int num)
	{
		int output=-1;
		while(num)
		{
			num>>=1;
			output++;
		}
		return output;
	}
	void updateAvailable(vector<vector<char> > &board, vector<vector<short>> &available, int offset, queue<int> &result)
	{
		int n=9;
		int row = offset/n, col = offset%n;
		int num = board[row][col]-'1';
	    short mask = 1;
		mask<<=(num);
		mask = Solution::allAvailable - mask;
		//col
		for(int i=0;i<n;++i)
		{
			if(i==row||(board[i][col]!='.'))
				continue;
			available[i][col]&=(mask);
			if(available[i][col]>0&&(available[i][col]&(available[i][col]-1))==0)
			{
				result.push(i*n+col);
				board[i][col] = '1'+int2pow(available[i][col]);
			}
		}
		//row
		for(int i=0;i<n;++i)
		{
			if(i==col||(board[row][i]!='.'))
				continue;
			available[row][i]&=(mask);
			if(available[row][i]>0&&(available[row][i]&(available[row][i]-1))==0)
			{
				result.push(n*row+i);
				board[row][i] = '1'+int2pow(available[row][i]);
			}
		}
		int startI = row - row%3;
		int startJ = col - col%3;
		// square
		for(int i=startI;i<startI+3;++i)
			for(int j=startJ;j<startJ+3;++j)
			{
				if((i==row&&j==col)||(board[i][j]!='.'))
					continue;
				available[i][j]&=(mask);
				if(available[i][j]>0&&(available[i][j]&(available[i][j]-1))==0)
				{
					result.push(i*n+j);
					board[i][j] = '1'+int2pow(available[i][j]);
				}
			}
	}
	void Solution::solveSudoku(vector<vector<char> > &board) {
		vector<vector<short>> available;
		available.resize(9);
		for(int i=0;i<9;++i)
		{
			available[i].resize(9);
			std::fill_n(available[i].begin(),9,Solution::allAvailable);
		}
		queue<int> result;
		int offset = 0;
		// initialize all entries
		for(int i=0;i<9;++i)
			for(int j = 0;j<9;++j)
			{
				offset = board[i][j]-'1';
				if(offset>=0&&offset<9)
					updateAvailable(board,available,i*9+j,result);
			}
		while(!result.empty())
		{
			int tempI = result.front();
			result.pop();
			updateAvailable(board,available,tempI,result);
		}
	}