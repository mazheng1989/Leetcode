#include "stdafx.h"
#include <vector>
#include <queue>
#include <algorithm>    // std::reverse
#include <deque>
#include <stack>
#include <string>
#include "use_me.h";
#include <unordered_map>
using namespace std;
	 bool existSub(vector<vector<char>> &board, vector<vector<bool>> &flag, int row, int col, string &word, int index)
	{
		int nRow = flag.size(), nCol = flag[0].size();
		//out of boundary
		if(row<0||row>=nRow||col<0||col>=nCol||flag[row][col])
			return false;
		//basic case
		if(index>=word.length())
			return true;
		if(index==word.length()-1)
			return word[index]==board[row][col];
		//not reach the end of word
		if(word[index]!=board[row][col])
			return false;
		flag[row][col] = true;
		int newR = row+1, newC = col;
		bool resultT = false;
		if(newR>=0&&newR<nRow&&newC>=0&&newC<nCol&&!flag[newR][newC]&&word[index+1]==board[newR][newC])
			resultT = existSub(board, flag, newR, newC, word, index+1);
		if(resultT)
			return true;
		newR = row-1;newC = col;
		if(newR>=0&&newR<nRow&&newC>=0&&newC<nCol&&!flag[newR][newC]&&word[index+1]==board[newR][newC])
			resultT = existSub(board, flag, newR, newC, word, index+1);
		if(resultT)
			return true;
		newR = row;newC = col+1;
		if(newR>=0&&newR<nRow&&newC>=0&&newC<nCol&&!flag[newR][newC]&&word[index+1]==board[newR][newC])
			resultT = existSub(board, flag, newR, newC, word, index+1);
		if(resultT)
			return true;
		newR = row;newC = col-1;
		if(newR>=0&&newR<nRow&&newC>=0&&newC<nCol&&!flag[newR][newC]&&word[index+1]==board[newR][newC])
			resultT = existSub(board, flag, newR, newC, word, index+1);
		if(resultT)
			return true;
		flag[row][col] = false;
		return false;
	}
	bool Solution::exist(vector<vector<char> > &board, string word) {
		int nW = word.length();
		if(!nW)
			return true;
		int nRow = board.size();
		if(!nRow)
			return false;
		int nCol = board[0].size();
		if(!nCol)
			return false;
		vector<vector<bool>> flag;
		flag.resize(nRow);
		for(int i=0;i<nRow;++i)
		{
			flag[i].resize(nCol);
			std::fill_n(flag[i].begin(),nCol,false);
		}
		for(int i=0;i<nRow;++i)
			for(int j=0;j<nCol;++j)
			{
				if(word[0]==board[i][j]&&existSub(board, flag, i, j, word, 0))
					return true;
			}
		return false;
	}