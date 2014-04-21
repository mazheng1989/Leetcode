#include "stdafx.h"
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include "use_me.h"
using namespace std;
	bool preCheck(string &s)
	{
		for(int i=0;i<s.length();++i)
			if(!(s[i]-'0'>=0&&s[i]-'0'<=9))
				return false;
		return true;
	}
	int numDecSub(string &s, int start, vector<int> &result)
	{
		int n = s.length();
		if(start>=n)
			return 1;
		if(result[start]!=-1)
			return result[start];
		if(start==n-1)
		{
			if(s[start]-'0'>0)
			{
				result[n-1] = 1;
				return 1;
			}
			else
			{
				result[n-1] = 0;
				return 0;
			}
		}
		int cur = s[start]-'0', next = s[start+1]-'0';
		int output = 0;
		if(cur>0)
		{
			output+=numDecSub(s,start+1,result);
		}
		if((cur==2&&next<=6)||(cur==1))
		{
			output+=numDecSub(s,start+2,result);
		}
		result[start] = output;
		return output;

	}
	int Solution::numDecodings(string s) {
		int n = s.length();
		if(n==0)
			return 0;
		if(!preCheck(s))
			return 0;
		vector<int> result;
		result.resize(n);
		for(int i=0;i<n;++i)
			result[i]=-1;
		return numDecSub(s,0,result);
	}