#include "stdafx.h"
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>    // std::reverse
#include <list>
#include <iostream>
#include <map>
#include <unordered_map>;

using namespace std;
class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		int size = dict.size(), i=0;
		vector<string> allWords;
		unordered_map<string,int> ids;
		vector<vector<int> > adj;
		unordered_set<string>::iterator dictIter;
		dict.insert(start);
		dict.insert(end);
		for(dictIter = dict.begin();dictIter!=dict.end();++dictIter)
		{
			ids[*dictIter] = allWords.size();
			allWords.push_back(*dictIter);
		}

		adj.clear();
		adj.resize(allWords.size());
		for(int i = 0; i < allWords.size(); i++){
			string w = allWords[i];
			for(int j = 0; j < allWords[i].size(); j++){
				for(char c = 'a'; c <= 'z'; c++)
					if(c != allWords[i][j]){
						w[j] = c;
						if(ids.count(w)){
							adj[i].push_back(ids[w]);
						}
						w[j] = allWords[i][j];
					}
			}
		}

		vector<int> currentLevel;

		vector<int> newLevel;
		int endIndex = ids[end];
		int startIndex = ids[start];
		currentLevel.push_back(startIndex);
		unordered_set<int> reached;
		reached.insert(startIndex);
		int currentIndex;
		int levelCount = 0;
		while(!currentLevel.empty()){
			levelCount++;
			if(reached.find(endIndex)!=reached.end())
			{
				break;
			}
			for(i=0;i<currentLevel.size();++i)
			{
				currentIndex = currentLevel[i];
				for(vector<int>::iterator iter = adj[currentIndex].begin();
					iter != adj[currentIndex].end();++iter)
				{
					if(reached.find(*iter)!=reached.end())
					{
						continue;
					}
					if(find(newLevel.begin(), newLevel.end(), *iter)==newLevel.end())
						newLevel.push_back(*iter);
				}
			}
			currentLevel.clear();
			for(i=0;i<newLevel.size();++i)
			{
				currentLevel.push_back(newLevel[i]);
				reached.insert(newLevel[i]);
			}
			newLevel.clear();
		}
		if(reached.find(endIndex)==reached.end())
		{
		    return 0;
		}
		return levelCount;
	}
};