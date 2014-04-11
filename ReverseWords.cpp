#include "stdafx.h"
#include<string>
#include "use_me.h"
using namespace std;

	void reversPartStr(string &s, int startI, int endI)
	{
		if(endI<=startI)
			return;
		int len = endI-startI+1;
		for(int i = 0;i<=(len-1)/2;++i)
		{
			char tempC = s[i+startI];
			s[i+startI] = s[endI-i];
			s[endI-i] = tempC;
		}
	}
    void Solution::reverseWords(string &s) {
		reversPartStr(s,0,s.length()-1);
		int startI = 0, endI = 0;
		while(s[startI]==' ')
			startI++;
		if(startI>0)
			s.erase(0,startI);
		startI = 0;
		while(startI<s.length())
		{
			endI=startI;
			while(endI<s.length()&&s[endI]!=' ')
				endI++;
			endI--;
			reversPartStr(s,startI,endI);
			startI=endI+1;
			endI = startI;
			while(endI<s.length()&&s[endI]==' ')
				endI++;
			if(endI<s.length())
			{
			    if(endI-startI>1)
			    s.erase(startI,endI-startI-1); //leave one space between words.
			}
			else
			{
			    if(startI<s.length())
			    s.erase(startI,endI-startI);
			}
			startI = startI+1;
		}
    }