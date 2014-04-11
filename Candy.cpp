#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    int candy(vector<int> &ratings) {
		if(ratings.size()==0)
			return 0;
		int nCur = 1, output = 1, minV = 1;
		vector<int> tempV(ratings.size(),1);
		for(int i =1;i<ratings.size();++i)
		{
			if(ratings[i]>ratings[i-1])
			{
				nCur++;
			}
			else
			{
				nCur = 1;
			}
			tempV[i] = nCur;
		}
		for(int i = ratings.size()-2;i>=0;--i)
		{
			if(ratings[i]>ratings[i+1])
			{
				nCur = std::max(++nCur,tempV[i]);
			}
			else
			{
				nCur = std::max(1,tempV[i]);
			}
			tempV[i] = nCur;
		}
		output = 0;
		for(int i =0;i<tempV.size();++i)
			output+=tempV[i];
		return output;
    }
};