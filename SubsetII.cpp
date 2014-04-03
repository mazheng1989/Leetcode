#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(),S.end());
		int increment = 0;
        vector<vector<int>> output = generateSubsets(S,0,increment);
		return output;
    }
	vector<vector<int>> generateSubsets(vector<int> &S,int startIndex, int &increment)
	{
		vector<vector<int>> output;
		if(startIndex==(S.size()-1))
		{
			vector<int> tempV;
			output.push_back(tempV);
			tempV.push_back(S[startIndex]);
			output.push_back(tempV);
			increment = 1;
			return output;
		}
		output = generateSubsets(S,startIndex+1,increment);
		int originalSize = output.size();
		int available = originalSize;
		if(S[startIndex]==S[startIndex+1])
			available = increment;
		for(int i=originalSize-available;i<originalSize;++i)
		{
			vector<int> tempV = output[i];
			tempV.insert(tempV.begin(),S[startIndex]);
			output.push_back(tempV);
		}
		increment = available;
		return output;
	}
};