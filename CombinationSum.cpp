#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include <string> // this should be already included in <sstream>
using namespace std;
class Solution{
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
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
				tempResult = generateComb(candidates,target-candidates[i],i);
				for (int j = 0; j < tempResult.size(); j++)
				{
					vector<int> tempV = tempResult[j];
					tempV.push_back(candidates[i]);
					output.push_back(tempV);
				}
			}
		}
		return output;
	}
}; 