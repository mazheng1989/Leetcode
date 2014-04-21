#include "stdafx.h"
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.length();
		if(n<=1)
			return s;
		vector<int> result;
		result.resize(n);
		std::fill_n(result.begin(),n,0);
		result[0] = 1;
		int maxL = 1, maxStart = 0;
		for(int i=1;i<n;++i)
		{
			for(int j=0;j<i-1;++j)
			{
				if(s[i]==s[j])
				{
					result[j] = result[j+1];
					if(result[j]&&i-j+1>maxL)
					{
						maxL = i-j+1;
						maxStart = j;
					}
				}
				else
				{
					result[j] = 0;
				}
			}
			if(s[i]==s[i-1])
			{
				result[i-1] = 1;
				if(2>maxL)
				{
					maxL = 2;
					maxStart = i-1;
				}
			}
			else
				result[i-1] = 0;
			result[i] = 1;
		}
		string subStr = s.substr(maxStart,maxL);
		return subStr;
	}
};