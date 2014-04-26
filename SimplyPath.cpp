#include "stdafx.h"
#include <vector>
#include <queue>
#include <algorithm>    // std::reverse
#include <deque>
#include <stack>
#include <string>
#include "use_me.h"
#include <unordered_map>
using namespace std;
string Solution::simplifyPath(string path) {
	stack<int> result;
	int index=0, nChar = path.length();
	if(nChar==0)
		return path;
	int start = 0, end = 0;
	string output="";
	while(index<nChar)
	{
		while(index<nChar&&path[index]=='/')
			index++;
		if(index>=nChar)
			break;

		start = index, end = index;
		while(end<nChar&&path[end]!='/')
			end++;
		end--;
		string str = path.substr(start,end-start+1);
		if(!str.compare("."))
		{
			index = end+1;
			continue;
		}
		if(!str.compare(".."))
		{
			if(!result.empty())
			{
				result.pop();
				result.pop();
			}
			index = end+1;
			continue;
		}
		result.push(start);
		result.push(end);
		index=end+1;
	}
	while(!result.empty())
	{
		end = result.top(); result.pop();
		start = result.top(); result.pop();
		output = "/"+path.substr(start,end-start+1)+output;
	}
	if(output.length()==0)
		output = "/";
	return output;
}