#include "stdafx.h"
#include<string>
using namespace std;
class Solution {
public:
	int digit2Num(char c)
	{
		switch(c)
		{
		case 'M':
			return 1000;
		case 'D':
			return 500;
		case 'C':
			return 100;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'V':
			return 5;
		case 'I':
			return 1;
		default:
			return 0;
		}
	}
    int romanToInt(string s) {
		int output = 0;
		for(int i=0;i<s.length();++i)
		{
			if(i>0&&digit2Num(s[i])>digit2Num(s[i-1]))
			{
				output+=(digit2Num(s[i])-2*digit2Num(s[i-1]));
			}
			else
				output+=digit2Num(s[i]);
		}
		return output;
    }

};