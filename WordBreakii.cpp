#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;
class Solution {
public:
	vector<string> constructResult(string &s,vector<vector<int>> &preI, int endI)
	{
		vector<string> output;
		for(int i=0;i<preI[endI].size();++i)
		{
			if(preI[endI][i]==0)
			{
				string tempStr = s.substr(1,endI);
				output.push_back(tempStr);
			}
			else
			{
				vector<string> tempResult = constructResult(s,preI,preI[endI][i]);
				if(!tempResult.empty())
				{
					string tailStr = " " + s.substr(preI[endI][i]+1,endI-preI[endI][i]);
					for(int j = 0;j<tempResult.size();++j)
					{
						tempResult[j].append(tailStr);
						output.push_back(tempResult[j]);
					}
				}
			}
		}
		return output;
	}
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        s.insert(0,"x");
		int nChar = s.size();
		vector<string> output;
		if(nChar==0||dict.size()==0)
		return output;
		vector<bool> possible(nChar, 0);
		vector<vector<int>> preI;
		preI.resize(nChar);
		vector<int> emptyV;
		for(int i=0;i<nChar;++i)
			preI[i]=emptyV;

		possible[0] = true;
		for(int i =1; i< nChar; ++i)
		{
			for(int k=0; k<i; ++k)
			{
				bool tempR = possible[k] && 
					dict.find(s.substr(k+1, i-k)) != dict.end();
				if(tempR)
				{
				    possible[i] = true;
					preI[i].push_back(k);
				}
			}
		}

		return constructResult(s,preI,nChar-1);
    }
};