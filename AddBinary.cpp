#include "stdafx.h"
#include <vector>
#include <queue>
#include <algorithm>    // std::reverse
#include <deque>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
		string output;
		int maxLength = (a.length()>b.length())?a.length():b.length();
		int increment = 0;
		output = addBinaryBit(a,b,maxLength-1,increment);
		if(increment == 1)
			output.insert(0,"1");
		return output;
    }
	string addBinaryBit(string a, string b, int bitIndex, int &increment)
	{
		// handle the bit of 2^(bitIndex)
		int aBit = 0, bBit = 0;
		if((a.length()-1)>=bitIndex)
		{
			aBit = a.at(a.length()-1-bitIndex)-'0';
		}
		if((b.length()-1)>=bitIndex)
		{
			bBit = b.at(b.length()-1-bitIndex)-'0';
		}
		string output="";
		if(bitIndex==0)
		{
			increment = 0;
		}
		else
		{
			output = addBinaryBit( a, b, bitIndex -1, increment);
		}
		int sum = aBit+bBit+increment;
		
		switch (sum)
		{
		case 0:
			output.insert(0,"0");
			increment = 0;
			break;
		case 1:
			output.insert(0,"1");
			increment = 0;
			break;
		case 2:
			output.insert(0,"0");
			increment = 1;
			break;
		case 3:
			output.insert(0,"1");
			increment = 1;
			break;
		default:
			break;
		}
		return output;
	}
};