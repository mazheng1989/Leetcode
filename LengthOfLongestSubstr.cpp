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
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> alreadyApp;
		int output = 0,longest = 0;
		for(size_t i = 0;i<s.length();++i)
		{
			if(alreadyApp.find(s.at(i))==alreadyApp.end())
			{
				++output;
				if(output>longest)
					longest = output;
				//std::pair<char,int> tempPair(s.at(i),i);
				//alreadyApp.insert(tempPair);
				
			}
			else
			{
				if(i-alreadyApp[s.at(i)]<=output)
				{
					output = (i-alreadyApp[s.at(i)]);
				}
				else
				{
					output++;
					if(output>longest)
						longest = output;
				}
			}
			alreadyApp[s.at(i)] = i;
		}
		output = longest;
		return output;
    }
};