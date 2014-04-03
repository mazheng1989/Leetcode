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
    int numDistinct(string S, string T) {
		int sizeS = S.length(), sizeT = T.length();
		if(sizeS<sizeT)
			return 0;
		vector<vector<int>> result;
		result.resize(sizeS);
		for(int i=0;i<sizeS;++i)
			result[i].resize(sizeT);
		for(int i=0;i<sizeS;++i)
			for(int j=0;j<=i&&j<sizeT;++j)
				result[i][j] = -1;
		int sizeDiff = sizeS-sizeT;
		for(int i=0;i<sizeT;++i)
		{
			if((sizeDiff+i+1)<sizeS)
				result[(sizeDiff+i+1)][i] = 0;
		}
        return numDistinctSub(S, 0, T, 0, result);
    }
	int numDistinctSub(string &S, int startS, string &T, int startT, vector<vector<int>> &result)
	{
		if(startT==T.length())
			return 1;
		if(startS==S.length())
			return 0;
		if(result[startS][startT]!=-1)
			return result[startS][startT];
		if(S.at(startS)==T.at(startT))
		{
			result[startS][startT] = (numDistinctSub(S,startS+1,T,startT,result)+
				numDistinctSub(S,startS+1,T,startT+1,result));
			return result[startS][startT];
		}
		else
		{
			result[startS][startT] = numDistinctSub(S,startS+1,T,startT,result);
			return result[startS][startT];
		}
	}
};