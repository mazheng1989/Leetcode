#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>
using namespace std;
class Solution {
public:
	string printOutFingureprint(vector<int> &fingureprint)
	{
		string Result;
		std::ostringstream convert;
		for(size_t i=0;i<fingureprint.size();++i)
			convert<<'-'<<fingureprint[i];
		Result = convert.str();
		return Result;
	}
    vector<string> anagrams(vector<string> &strs) {
		unordered_map<string,std::string> countMap;
		unordered_set<std::string> alreadyFound;
		vector<int> fingerprint;
		fingerprint.resize(26);
		vector<std::string> output;
		for(size_t i=0;i<strs.size();++i)
		{
			std::fill_n(fingerprint.begin(),26,0);
			for(size_t j = 0;j<strs[i].length();++j)
				if(strs[i][j]>='a'&&strs[i][j]<='z')
					fingerprint[strs[i][j]-'a']++;
			string fpStr = printOutFingureprint(fingerprint);
			if(countMap.find(fpStr)!=countMap.end())
			{
				output.push_back(strs[i]);
				if(alreadyFound.find(countMap[fpStr])==alreadyFound.end())
				{
					alreadyFound.insert(countMap[fpStr]);
					output.push_back(countMap[fpStr]);
				}
			}
			else
			{
				countMap[fpStr] = strs[i];
			}
		}
		return output;
    }
};