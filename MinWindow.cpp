#include "stdafx.h"
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
	string minWindow(string S, string T) {
		int i=0,j=0,minI=0,minL=S.length()+1,startI=0;
		int nS = S.length(),nT = T.length();
		unordered_map<char, int> counterT;
		for(j=0;j<nT;++j)
			if(counterT.find(T[j])==counterT.end())
				counterT[T[j]] = 1;
			else
				counterT[T[j]]++;
		unordered_map<char, queue<int>> lastI;
		bool foundAll = false;
		char frontC;
		for(i = 0;i<nS;++i)
		{
			if(counterT.find(S[i])==counterT.end())
				continue;
			if(lastI.find(S[i])==lastI.end())
			{
				queue<int> q;
				q.push(i);
				lastI[S[i]] = q;
				counterT[S[i]]--;
			}
			else
			{
				if(counterT[S[i]]==0)
				{
					lastI[S[i]].pop();
				}
				else
				    counterT[S[i]]--;
				lastI[S[i]].push(i);
			}
			minI = S.length();
			if(!foundAll)
			{
				frontC = S[i];
				unordered_map<char, int>::iterator it = counterT.begin();
				for(;it!=counterT.end();++it)
				{
					if(it->second>0)
						break;
				}
				if(it==counterT.end())
					foundAll = true;
			}
			if(!foundAll||S[i]!=frontC)
				continue;
			for(unordered_map<char, int>::iterator it = counterT.begin();it!=counterT.end();++it)
				if(minI>lastI[it->first].front())
				{
					minI = lastI[it->first].front();
					frontC = S[minI];
				}
			if((i-minI+1)<minL)
			{
				startI = minI;
				minL = (i-minI+1);
			}
		}
		if(!foundAll)
			return "";
		else
			return S.substr(startI,minL);
	}
};