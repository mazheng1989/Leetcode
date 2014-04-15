#include "stdafx.h"
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	bool checkSquare(vector<vector<char> > &board)
	{
		vector<bool> flag;
		flag.resize(9);
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
			{
				std::fill_n(flag.begin(),9,false);
				int startI = i*3, startJ = j*3;
				for(int m = startI; m<startI+3; ++m)
					for(int n = startJ; n<startJ+3; ++n)
					{
						int offset = board[m][n] - '1';
						if(offset>=0&&offset<9)
						{
							if(flag[offset])
								return false;
							else
								flag[offset] = true;
						}
					}
			}
			return true;
	}
	bool checkRow(vector<vector<char> > &board)
	{
		vector<bool> flag;
		flag.resize(9);
		for(int i=0;i<9;++i)
		{
			std::fill_n(flag.begin(),9,false);
			for(int m = 0; m<9; ++m)
			{
				int offset = board[i][m] - '1';
				if(offset>=0&&offset<9)
				{
					if(flag[offset])
						return false;
					else
						flag[offset] = true;
				}
			}
		}
		return true;
	}
	bool checkCol(vector<vector<char> > &board)
	{
		vector<bool> flag;
		flag.resize(9);
		for(int i=0;i<9;++i)
		{
			std::fill_n(flag.begin(),9,false);
			for(int m = 0; m<9; ++m)
			{
				int offset = board[m][i] - '1';
				if(offset>=0&&offset<9)
				{
					if(flag[offset])
						return false;
					else
						flag[offset] = true;
				}
			}
		}
		return true;
	}
	bool isValidSudoku(vector<vector<char> > &board) {
		if(board.size()<9||board[0].size()<9)
			return false;
		bool output;
		output= output&&checkSquare(board);
		if(!output)
			return false;
		output= output&&checkRow(board);
		if(!output)
			return false;
		output= output&&checkCol(board);
		if(!output)
			return false;
		else
			return true;
	}
};