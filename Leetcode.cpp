// Leetcode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <unordered_set>
#include <string>
#include "use_me.h"
#include "use_solution.h"
#include <iostream>
using namespace std;

void testWordLader2()
{
	std::string tmp[] = {"a","b","c"};
	unordered_set<string> dict(tmp, tmp + sizeof(tmp) / sizeof(tmp[0]));
	//dict.insert("a");
	//dict.insert("b");
	//dict.insert("c");
	
	string start = "a",end = "c";
	Solution1 solution1;
	Solution solution;
	for (unordered_set<string>::iterator it = dict.begin();it!=dict.end();++it)
		cout<<*it<<","<<endl;
	char ch;
	cin.get(ch);
	vector<vector<string>> output = solution1.findLadders(start,end,dict);
	for (vector<vector<string>>::iterator itr = output.begin();itr!=output.end();++itr)
	{
		cout<<"[ ";
		for(vector<string>::iterator iter = (*itr).begin();iter!=(*itr).end();++iter)
		{
			cout<<*iter<<",";
		}
		cout<<" ]"<<endl;
	}
	cin.get(ch);
	output = solution.findLadders(start,end,dict);
	for (vector<vector<string>>::iterator itr = output.begin();itr!=output.end();++itr)
	{
		cout<<"[ ";
		for(vector<string>::iterator iter = (*itr).begin();iter!=(*itr).end();++iter)
		{
			cout<<*iter<<",";
		}
		cout<<" ]"<<endl;
	}
	cin.get(ch);
}
int _tmain(int argc, _TCHAR* argv[])
{
	testWordLader2();
	char ch;
	cin.get(ch);
	return 0;
}

