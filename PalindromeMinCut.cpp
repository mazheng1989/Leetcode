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
	int minCut(string s) {
		if(s.length()==0)
			return 0;
		int nS = s.length();
		int output =nS-1;
		vector<int> minCut(nS+1,0);
		for(int i=0;i<nS;i++)
			minCut[i] = nS-i-1;
		vector<vector<bool>> palindrome;
		palindrome.resize(nS);
		for(int i=0;i<nS;i++)
		{
			palindrome[i].resize(nS);
			std::fill_n(palindrome[i].begin(),nS,false);
		}
		int cutPre = 0;
		for(int i=nS-1;i>=0;--i)
		{
			for(int j=i;j<nS;j++)
			{
			    cutPre = j==nS-1?0:1;
				if(s[i]==s[j]&&(j-i<=2||palindrome[i+1][j-1]))
				{
					palindrome[i][j] = true;
					if(cutPre+minCut[j+1]<minCut[i])
						minCut[i] = cutPre+minCut[j+1];
				}
				else
					palindrome[i][j] = false;
			}
		}
		return minCut[0];
	}
};