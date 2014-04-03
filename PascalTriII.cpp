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
    vector<int> getRow(int rowIndex) {
        
		vector<int> output;
		if(rowIndex==0)
		{
			output.push_back(1);
			return output;
		}
		if(rowIndex==1)
		{
			output.push_back(1);
			output.push_back(1);
			return output;
		}
		output.resize(rowIndex+1);
		output[0] = 1;
		int prevNum = 0, tempNum=0;
		for(int i = 1;i<=rowIndex;++i)
		{
			prevNum = 0;
			for(int j=0;j<=i;++j)
			{
				tempNum = output[j];
				output[j] += prevNum;
				prevNum = tempNum;
			}
		}
		return output;
    }
};