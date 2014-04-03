#include "stdafx.h"
#include <vector>
#include <queue>
#include <algorithm>    // std::reverse
#include <deque>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> matrix;
		if(n==0)
			return matrix;
		matrix.resize(n);
		for(int i=0;i<n;++i)
			matrix[i].resize(n);
		if(n==1)
		{
			matrix[0][0] = 1;
			return matrix;
		}
		int rowNum = n;		
		int colNum = n;
		int round = 0;
		int row = 0, col = 0;
		int index = 1;
		while(true)
		{
			//firt row
			row = round;
			if(row>((rowNum-1)/2))
				break;
			for(int i = (0+round);i<=(colNum-1-round);++i)
				matrix[row][i] = (index++);
			//last col
			col = colNum-1-round;
			if(col<((colNum)/2))
				break;
			for(int i=(1+round);i<=(rowNum-1-round);++i)
				matrix[i][col] = (index++);
			//last row
			row = rowNum - 1 - round;
			if(row<=((rowNum-1)/2))
				break;
			for(int i=(colNum-2-round);i>=(0+round);--i)
				matrix[row][i] = (index++);
			//firt col
			col = 0 + round;
			if(col>=((colNum)/2))
				break;
			for(int i = (rowNum-2-round);i>(0+round);--i)
				matrix[i][col] = (index++);
			round++;
		}
		return matrix;
    }
};