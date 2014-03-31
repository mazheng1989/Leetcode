#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(),S.end());
        vector<vector<int>> output = generateSubsets(S,0);
		return output;
    }
	vector<vector<int>> generateSubsets(vector<int> &S,int startIndex)
	{
		vector<vector<int>> output;
		if(startIndex==(S.size()-1))
		{
			vector<int> tempV;
			output.push_back(tempV);
			tempV.push_back(S[startIndex]);
			output.push_back(tempV);
			return output;
		}
		output = generateSubsets(S,startIndex+1);
		int originalSize = output.size();
		for(int i=0;i<originalSize;++i)
		{
			vector<int> tempV = output[i];
			tempV.insert(tempV.begin(),S[startIndex]);
			output.push_back(tempV);
		}
		return output;
	}
};