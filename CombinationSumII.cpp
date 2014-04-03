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
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
		vector<vector<int> > output = generateComb(candidates,target,candidates.size()-1);
		return output;
    }
	vector<vector<int>> generateComb(vector<int> &candidates, int target, int startI)
	{
		vector<vector<int> > output,tempResult;
		int left=0,right=0,sum=0,mid=0;
		if(target<candidates[0])
			return output;
		for(int i = startI;i>=0;--i)
		{
			if(target<candidates[i])
				continue;
			if(target==candidates[i])
			{
				vector<int> tempV;
				tempV.push_back(candidates[i]);
				output.push_back(tempV);
			}
			if(target>candidates[i])
			{
				tempResult = generateComb(candidates,target-candidates[i],i-1);
				for (int j = 0; j < tempResult.size(); j++)
				{
					vector<int> tempV = tempResult[j];
					tempV.push_back(candidates[i]);
					output.push_back(tempV);
				}
			}
			while(i>0&&candidates[i-1]==candidates[i])
				i--;
		}
		return output;
	}
};