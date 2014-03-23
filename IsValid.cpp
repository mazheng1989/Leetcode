#include "stdafx.h"
#include <vector>
#include <queue>
#include <math.h>
#include <string>
#include <stack>
#include <algorithm>    // std::reverse
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stackChar;
		char tempChar;
		for(int i=0;i<s.length();++i)
		{
			tempChar = s.at(i);
			if(tempChar=='('||tempChar=='['||tempChar=='{')
			{
				stackChar.push(tempChar);
				continue;
			}
			if(stackChar.empty())
				return false;
			switch (tempChar)
			{
			case '}':
				tempChar = stackChar.top();
				stackChar.pop();
				if(tempChar!='{')
					return false;
				break;
			case ']':
				tempChar = stackChar.top();
				stackChar.pop();
				if(tempChar!='[')
					return false;
				break;
			case ')':
				tempChar = stackChar.top();
				stackChar.pop();
				if(tempChar!='(')
					return false;
				break;
			default:
				return false;
				break;
			}
		}
		if(stackChar.empty())
			return true;
		else
			return false;
    }
};