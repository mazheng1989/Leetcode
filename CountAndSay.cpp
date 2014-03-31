#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include "use_me.h"
#include <string> // this should be already included in <sstream>
using namespace std;

string num2Sring(int num)
{
	string Result;          // string which will contain the result

	ostringstream convert;   // stream used for the conversion

	convert << num;      // insert the textual representation of 'Number' in the characters in the stream

	Result = convert.str(); // set 'Result' to the contents of the stream
	return Result;
}
string char2String(char c)
{
	string Result;          // string which will contain the result

	ostringstream convert;   // stream used for the conversion

	convert << c;      // insert the textual representation of 'Number' in the characters in the stream

	Result = convert.str(); // set 'Result' to the contents of the stream
	return Result;
}
string sayNum(string num)
{
	int count = 1;
	char tempNum, prevNum=num[0];
	string output = "";//char2String(prevNum);
	for(int i=1;i<num.length();++i)
	{
		if(prevNum==num[i])
		{
			count++;
		}
		else
		{
			
			output.append(num2Sring(count));
			output.append(char2String(prevNum));
			count = 1;
			prevNum = num[i];
		}
	}
	output.append(num2Sring(count));
	output.append(char2String(prevNum));
	return output;
}

string countNum(int num)
{
	if(num==1)
		return "1";
	return sayNum(countNum(num-1));
}


string Solution::countAndSay(int n) {
	return countNum(n);
}
