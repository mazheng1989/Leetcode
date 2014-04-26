#include "stdafx.h"
#include <vector>
#include <queue>
#include <algorithm>    // std::reverse
#include <deque>
#include <stack>
#include <string>
#include <unordered_map>
#include "use_me.h"
using namespace std;
bool valid(string &s, int start, int end)
	{
		if(end-start<0||end-start>2||start<0||end>=s.length()||(s[start]=='0'&&end-start>0))
			return false;
		int num = 0;
		for(int i=start;i<=end;++i)
		{
			num*=10;
			num+=(s[i]-'0');
		}
		if(num>=0&&num<=255)
			return true;
		else
			return false;
	}
	vector<vector<int>> dividIP(string &s, int start, int nSeg)
	{
		vector<vector<int>> output;
		if((nSeg)*3<s.length()-start||(nSeg)>s.length()-start)
			return output;
		if(nSeg==1)
		{
		    if(valid(s,start,s.length()-1))
		    {
			vector<int> tempV;
			tempV.push_back(s.length()-1);
			output.push_back(tempV);
		    }
			return output;
		}
		for(int i=0;i<3;++i)
		{
			if(valid(s,start,start+i))
			{
				vector<vector<int>> outputTemp = dividIP(s,start+i+1,nSeg-1);
				if(!outputTemp.empty())
					for(int j=0;j<outputTemp.size();++j)
					{
						outputTemp[j].push_back(start+i);
						output.push_back(outputTemp[j]);
					}
			}
		}
		return output;
	}
    vector<string> Solution::restoreIpAddresses(string s) {
		vector<string> output;
        if(s.length()<4||s.length()>12)
			return output;
		vector<vector<int>> outputI = dividIP(s,0,4);
		for(int i=0;i<outputI.size();++i)
		{
			string str = s;
			for(int j = outputI[i].size()-1;j>0;--j)
			{
				int pos = outputI[i][j]+(3-j)+1;
				str.insert(pos,1,'.');
			}
			output.push_back(str);
		}
		return output;
    }