#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int indexChar = 0;
		string output = "";
		if(strs.size()==0)
			return output;
		int minSize = strs[0].size();
		int longestNum = 0;
		for(int i=0;i<strs.size();++i)
		{
			if(strs[i].size()<minSize)
				minSize = strs[i].size();
		}
		char tempChar=0;
		bool notSame = false;
		for(int i=0;i<minSize;++i)
		{
			tempChar = strs[0].at(i);
			for (int j = 0; j < strs.size(); j++)
			{
				if(tempChar!=strs[j].at(i))
				{
					notSame = true;
					break;
				}
			}
			if(notSame)
			{
			    longestNum = i;
			    break;
			}
			else
			{
			    longestNum = i+1;
			}
		}
		if(longestNum>0)
		{
			output = strs[0].substr(0,longestNum);
		}
		return output;
    }
};