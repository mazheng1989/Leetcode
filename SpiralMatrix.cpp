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
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> output;
		int rowNum = matrix.size();
		if(rowNum==0)
			return output;
		int colNum = matrix[0].size();
		int round = 0;
		int row = 0, col = 0;
		while(true)
		{
			//firt row
			row = round;
			if(row>((rowNum-1)/2))
				break;
			for(int i = (0+round);i<=(colNum-1-round);++i)
				output.push_back(matrix[row][i]);
			//last col
			col = colNum-1-round;
			if(col<((colNum)/2))
				break;
			for(int i=(1+round);i<=(rowNum-1-round);++i)
				output.push_back(matrix[i][col]);
			//last row
			row = rowNum - 1 - round;
			if(row<=((rowNum-1)/2))
				break;
			for(int i=(colNum-2-round);i>=(0+round);--i)
				output.push_back(matrix[row][i]);
			//firt col
			col = 0 + round;
			if(col>=((colNum)/2))
				break;
			for(int i = (rowNum-2-round);i>(0+round);--i)
				output.push_back(matrix[i][col]);
			round++;
		}
		return output;
    }
};