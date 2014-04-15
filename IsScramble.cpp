#include "stdafx.h"
#include <string>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	int charC[256];
	bool isScrambleSub(string &s1, string &s2, int start1, int end1, int start2, int end2)
	{
		if(end1-start1!=end2-start2)
			return false;
		if(start1==end1)
			return s1[start1]==s2[start2];
		int lengthStr = end1 - start1 + 1;
		//quick check whether letters are the same
		std::fill_n(charC,256,0);
		for(int i=0;i<256;++i)
			charC[i] = 0;
		for(int i=0;i<lengthStr;++i)
		{
			charC[s1[start1+i]]++;
			charC[s2[start2+i]]--;
		}
		for(int i=0;i<256;++i)
			if(charC[i]!=0)
				return false;
		int length1 = 1,length2 =1;
		for(length1 = 1;length1<lengthStr;length1++)
		{
			length2= lengthStr - length1;
			bool originalOrder = (isScrambleSub(s1,s2,start1,start1+length1-1,start2,start2+length1-1)&&
				isScrambleSub(s1,s2,start1+length1,end1,start2+length1,end2));
			if(originalOrder)
				return true;
			bool swapOrder = (isScrambleSub(s1,s2,start1,start1+length1-1,start2+length2,end2)&&
				isScrambleSub(s1,s2,start1+length1,end1,start2,start2+length2-1));
			if(swapOrder)
				return true;
		}
		return false;
	}
	bool isScramble(string s1, string s2) {
		if(s1.length()!=s2.length())
			return false;
		if(s1.compare(s2)==0)
			return true;
		int lengthStr = s1.length();
		return isScrambleSub(s1,s2,0,lengthStr-1,0,lengthStr-1);
	}
};