#include "stdafx.h"
#include <vector>
#include "use_me.h"
using namespace std;
	int largestRectangleArea(vector<int> &height) {
        // this algorithm comes from:
		//http://fisherlei.blogspot.com/2012/12/leetcode-largest-rectangle-in-histogram.html
		int output = 0;
		for(int i=0;i<height.size();++i)
		{
			if(i<height.size()-1&&height[i]<=height[i+1])
				continue;
			int minHeight = height[i];
			for(int j=i;j>=0;--j)
			{
				minHeight = (minHeight<height[j])?minHeight:height[j];
				int tempArea = minHeight*(i-j+1);
				if(tempArea>output)
					output = tempArea;
			}
		}
		return output;
    }
    int Solution::maximalRectangle(vector<vector<char> > &matrix) {
        int nRow = matrix.size();
		if(nRow==0)
			return 0;
		int nCol = matrix[0].size();
		vector<int> countV;
		countV.resize(nCol);
		fill_n(countV.begin(),nCol,0);
		int left = nCol, right = -1, top = nRow, bottom = -1;
		int output = 0, tempArea = 0;
		for(int i = 0;i<nRow;++i)
		{
			for(int j = 0;j<nCol;++j)
			{
				if(matrix[i][j]=='1')
				{
					countV[j]++;
				}
				else
				{
					countV[j] = 0;
				}
			}
			tempArea = largestRectangleArea(countV);
			if(tempArea>output)
				output = tempArea;
		}
		return output;
    }