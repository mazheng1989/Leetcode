#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
		if(tokens.size()==0)
			return 0;
		if(tokens.size()==1)
			return std::stoi(tokens[0]);
        stack<int> immediateResult;
		int index = 0;
		int lhs = 0, rhs = 0;
		while(index<tokens.size())
		{
			string tempStr = tokens[index];
			if(!tempStr.compare("+"))
			{
				rhs = immediateResult.top();
				immediateResult.pop();
				lhs = immediateResult.top();
				immediateResult.pop();
				immediateResult.push(lhs+rhs);
				index++;
				continue;
			}
			if(!tempStr.compare("-"))
			{
				rhs = immediateResult.top();
				immediateResult.pop();
				lhs = immediateResult.top();
				immediateResult.pop();
				immediateResult.push(lhs-rhs);
				index++;
				continue;
			}
			if(!tempStr.compare("*"))
			{
				rhs = immediateResult.top();
				immediateResult.pop();
				lhs = immediateResult.top();
				immediateResult.pop();
				immediateResult.push(lhs*rhs);
				index++;
				continue;
			}
			if(!tempStr.compare("/"))
			{
				rhs = immediateResult.top();
				immediateResult.pop();
				lhs = immediateResult.top();
				immediateResult.pop();
				immediateResult.push(lhs/rhs);
				index++;
				continue;
			}
			immediateResult.push(stoi(tempStr));
		}
		if(immediateResult.size())
			return immediateResult.top();
		else
			return 0;
    }
};