#include "stdafx.h"
#include <vector>
using namespace std;
class Solution {
public:
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
};