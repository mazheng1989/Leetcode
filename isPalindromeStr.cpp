#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> allChar;
		for(int i=0;i<s.length();i++)
		{
			char currentC = s.at(i);
			if((currentC>='a'&&currentC<='z')||(currentC>='0'&&currentC<='9'))
				allChar.push_back(currentC);
			if(currentC>='A'&&currentC<='Z')
				allChar.push_back(currentC-'A'+'a');
		}
		return ispalindromeChars(allChar);
    }
	bool ispalindromeChars(vector<char> &charVector)
	{
		if(charVector.empty())
			return true;
		bool output = true;
		for(int i=0;i<(charVector.size())/2;++i)
		{
			if(charVector[i]!=charVector[charVector.size()-1-i])
			{
				output = false;
				break;
			}
		}
		return output;
	}
};