#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;
class Solution {
public:
	bool wordBreak(string s, unordered_set<std::string> &dict) {
		s.insert(0,"x");
		int nChar = s.size();
		vector<bool> possible(nChar, 0);

		possible[0] = true;
		for(int i =1; i< nChar; ++i)
		{
			for(int k=0; k<i; ++k)
			{
				possible[i] = possible[k] && 
					dict.find(s.substr(k+1, i-k)) != dict.end();
				if(possible[i]) break;
			}
		}

		return possible[nChar-1];
	}
};