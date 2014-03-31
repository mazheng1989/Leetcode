#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include <string> // this should be already included in <sstream>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
		int minTotal = 0;
		if(n==0)
			return 0;
		vector<int> buffer;
		buffer.reserve(n);
		buffer[0] = triangle[0][0];
		minTotal = buffer[0];
		int prevNum = 0,tempNum = 0;
		for(int i=1;i<n;++i)
		{
			prevNum = buffer[0];
			minTotal = buffer[0]+triangle[i][0];
			for(int j=0;j<=i;++j)
			{
				if(j==0)
				{
				    tempNum = buffer[0];
					buffer[j] = buffer[0]+triangle[i][j];
					prevNum = tempNum;
					if(minTotal>buffer[0])
						minTotal = buffer[1];
					continue;
				}
				if(j==i)
				{
				    tempNum = buffer[j];
					buffer[j] = prevNum+triangle[i][j];
					prevNum = tempNum;
					if(minTotal>buffer[j])
						minTotal = buffer[j];
					continue;
				}
				tempNum = buffer[j];
				buffer[j] = ( (prevNum>buffer[j])?buffer[j]:prevNum )+triangle[i][j];
				prevNum = tempNum;
				if(minTotal>buffer[j])
				minTotal = buffer[j];
			}
			
		}
		return minTotal;
    }
};