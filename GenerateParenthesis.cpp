#include "stdafx.h"
#include <vector>
using namespace std;
class Solution {
public:
	void generate(vector<string> &result, string temp, int leftN, int rightN, int n)
	{
	    string tempStr = temp;
		if(leftN==n)
		{
			for(int i=rightN+1;i<=n;++i)
				temp.append(")");
			result.push_back(temp);
			return;
		}
		generate(result,temp.append("("),leftN+1,rightN,n);
		if(leftN>rightN)
		{
			generate(result,tempStr.append(")"),leftN,rightN+1,n);
		}
	}
	vector<string> generateParenthesis(int n) {
		vector<string> output;
		if(n<=1)
		{
			output.push_back("()");
			return output;
		}
		string tempStr="";
		generate(output, tempStr, 0, 0,n);
		return output;
	}
};