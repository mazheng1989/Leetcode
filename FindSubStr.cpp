#include "stdafx.h"
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include "use_me.h"
using namespace std;
	void initialCounter(unordered_map<std::string,int> &counter,vector<string> &L)
	{
		for(string str:L)
			counter[str] = 0;
		for(string str:L)
			counter[str]++;
	}
    vector<int> Solution::findSubstring(string S, vector<string> &L) {
		int nL = L.size(), nC = L[0].length(), nS = S.length();
		vector<int> output;
		unordered_map<std::string,int> counter;
		unordered_map<std::string,int> counterT;
		if(nL*nC>nS)
			return output;
		initialCounter(counterT,L);
		initialCounter(counter,L);
		for(int i=0;i<=nS-(nL*nC);++i)
		{
			counter.clear();
			int j=i;
			for(;j<i+(nL*nC);j+=nC)
			{
				string str = S.substr(j,nC);
				if(counterT.find(str)==counter.end()||counter[str]>=counterT[str])
					break;
				counter[str]++;
			}
			if(j==i+(nL*nC))
				output.push_back(i);
		}
		return output;
    }
