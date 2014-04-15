#include "stdafx.h"
#include <string>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	void longestEndAtI(string &s, int endI, vector<int> &result)
	{
		if(endI==0||s[endI]=='(')
		{
			result[endI] = 0;
			return;
		}
		int index = endI-1; //s[endI] = ')'
		int lengthP = 1;
		bool valid = false;
		while(index>=0)
		{
			if(result[index]>0)
			{
				lengthP+=result[index];
				index-=result[index];
				continue;
			}
			if(s[index]=='('&&!valid)
			{
				lengthP+=1;
				valid = true;
				--index;
				continue;
			}
			if((s[index]=='('&&valid)||s[index]==')')
				break;
		}
		if(!valid)
		    result[endI] = 0;
		else
		    result[endI] = lengthP;
	}
    int longestValidParentheses(string s) {
		int lengthStr = s.length();
		if(lengthStr<=1)
			return 0;
		vector<int> result;
		result.resize(lengthStr);
		int maxL = 0;
		for(int i=0;i<lengthStr;++i)
		{
			longestEndAtI(s, i, result);
			if(result[i]>maxL)
				maxL = result[i];
		}
		return maxL;
    }
};