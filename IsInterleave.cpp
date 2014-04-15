#include "stdafx.h"
#include <string>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	int charC[256];
	bool preCheck(string &s1, string &s2, string &s3)
	{
		int length1=s1.length(), length2 = s2.length(), length3 = s3.length();
		for(int i=0;i<256;++i)
			charC[i] = 0;
		for(int i=0;i<length1;++i)
			charC[s1[i]]++;
		for(int i=0;i<length2;++i)
			charC[s2[i]]++;
		for(int i=0;i<length3;++i)
			charC[s3[i]]--;
		for(int i=0;i<256;++i)
			if(charC[i]!=0)
				return false;
		return true;
	}
	bool isInterleaveSub(string &s1, string &s2, string &s3, int index1, int index2, int index3, vector<vector<char>> &result)
	{
		int length1=s1.length(), length2 = s2.length(), length3 = s3.length();
		bool output = false;
		if(index1 == length1)
		{
			output = true;
			while(index2!=length2)
			{
				if(s2[index2]!=s3[index3])
					return false;
				index2++;
				index3++;
			}
			return output;
		}
		if(index2 == length2)
		{
			output = true;
			while(index1!=length1)
			{
				if(s1[index1]!=s3[index3])
					return false;
				index1++;
				index3++;
			}
			return output;
		}
		if(result[index1][index2]!=0)
			return (result[index1][index2]==1);
		if(s1[index1]==s3[index3])
		{
			output = isInterleaveSub(s1, s2, s3, index1+1, index2, index3+1, result);
			if(index1+1<length1)
				result[index1+1][index2] = (output)?1:2;
		}
		if(output)
			return true;
		if(s2[index2]==s3[index3])
		{
			output = isInterleaveSub(s1, s2, s3, index1, index2+1, index3+1, result);
			if(index2+1<length2)
				result[index1][index2+1] = (output)?1:2;
		}
		if(output)
			return true;
		result[index1][index2] = 2;
		return false;
	}
    bool isInterleave(string s1, string s2, string s3) {
		if(s1.length()+s2.length()!=s3.length())
			return false;
		if(!preCheck(s1,s2,s3))
			return false;
		int length1=s1.length(), length2 = s2.length(), length3 = s3.length();
		vector<vector<char>> result; //0:tbd, 1:yes, 2:no
		result.resize(length1);
		for(int i=0;i<length1;i++)
		{
			result[i].resize(length2);
			std::fill_n(result[i].begin(),length2,0);
		}
		return isInterleaveSub(s1, s2, s3, 0, 0, 0, result);
    }
};