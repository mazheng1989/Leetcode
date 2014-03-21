#include "stdafx.h"
#include <vector>
using namespace std;
class Solution {
public:
	bool isSymmetric(string str){
		if((int)str.length()<3)
			return true;
		for(int i=0;i<(int)str.length()/2;++i)
		{
			if(str.at(i)!=str.at((int)str.length()-1-i))
				return false;
		}
		return true;
	}
	vector<string> generateParenthesis(int n) {
		vector<string> output;
		if(n<=1)
		{
			output.push_back("()");
			return output;
		}
		output = generateParenthesis(n-1);
		int originalSize = output.size();
		string tempStr1, tempStr2;
		string left = "(",right = ")";
		for(int i = 0;i<originalSize;++i)
		{
			tempStr1 = output[i];
			tempStr1.insert(0,left);
			tempStr1.push_back(')');
			output.push_back(tempStr1);
			tempStr1 = output[i];
			tempStr1.push_back('(');
			tempStr1.push_back(')');
			output.push_back(tempStr1);
			tempStr2 = output[i];
			tempStr2.insert(0,"()");
			if(tempStr1.compare(tempStr2)!=0)
				output.push_back(tempStr2);
		}
		output.erase(output.begin(),output.begin()+originalSize);
		return output;
	}

};