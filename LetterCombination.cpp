#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>
#include "use_me.h"
#include <string> // this should be already included in <sstream>
using namespace std;
vector<vector<string>> constructDict()
	{
		vector<vector<string>> dictionary;
		dictionary.resize(10);
		for(int i=0;i<15;i++)
		{
			char c = 'a'+i;
			string s;
			s.push_back(c);
			int tempI = (i/3)+2;
			dictionary[(i/3)+2].push_back(s);
		}
		for(int i=15;i<19;i++)
		{
			char c = 'a'+i;
			string s;
			s.push_back(c);
			dictionary[7].push_back(s);
		}
		for(int i=19;i<22;i++)
		{
			char c = 'a'+i;
			string s;
			s.push_back(c);
			dictionary[8].push_back(s);
		}
		for(int i=22;i<26;i++)
		{
			char c = 'a'+i;
			string s;
			s.push_back(c);
			dictionary[9].push_back(s);
		}
		return dictionary;
	}
	vector<string> Solution::letterCombinations(string digits) {
		vector<string> output;
		if(digits.size()==0)
	    {
	        output.push_back("");
	    return output;
	    }
		vector<vector<string>> dictionary = constructDict();
		
		int tempInt = 0;
		for(int i=0;i<digits.length();++i)
		{
			tempInt = digits.at(i) - '0';
			if(tempInt<0||tempInt>9)
			{
				return output;
			}
			int originalSize = output.size();
			if(originalSize==0)
			{
				output.insert(output.begin(),dictionary[tempInt].begin(),dictionary[tempInt].end());
				continue;
			}
			for(int j = 0;j<originalSize;++j)
			{
				for(int k=0;k<dictionary[tempInt].size();++k)
				{
					string tempStr = output[j];
					tempStr.append(dictionary[tempInt][k]);
					output.push_back(tempStr);
				}
			}
			output.erase(output.begin(),output.begin()+originalSize);
		}
		return output;
	}
	