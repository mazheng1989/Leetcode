#include "stdafx.h"
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>    // std::reverse
#include "use_me.h"
#include <unordered_map>

using namespace std;


vector<vector<string>> travel2Start(vector<vector<int>> &prevIndex, vector<string> &allWords, int currentIndex,int startIndex){
	vector<vector<string>> temp;
	vector<vector<string>> output;
	vector<int> prevIndexT = prevIndex[currentIndex];
	string currentString = allWords[currentIndex];
	if(currentIndex == startIndex)
	{
		vector<string> tempStringV;
		tempStringV.push_back(currentString);
		output.push_back(tempStringV);
		return output;
	}
	for (int i=0;i<prevIndexT.size();++i)
	{
		int tempIndex = prevIndexT[i];
		temp = travel2Start(prevIndex, allWords, tempIndex,startIndex);
		output.insert(output.end(),temp.begin(),temp.end());		
	}
	for (int j = 0;j<output.size();++j)
	{
		output[j].push_back(currentString);
	}
	return output;
}

vector<vector<string>> Solution::findLadders(string start, string end, unordered_set<string> &dict) {
	vector<vector<string>> output;

	int size = dict.size();
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
	int i = 0,j = 0;
	vector<vector<int>> prevIndex;
	prevIndex.resize(allWords.size());

	int leftIndex = 0, rightIndex = 0, firstInsert = 0;
	bool reachEnd = false;
	vector<int> endPrev;
	vector<string>::iterator wordIter;
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
				prevIndex[*iter].push_back(currentIndex);
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
	int tempCount = -1;

	output = travel2Start(prevIndex, allWords, endIndex,startIndex);
	return output;
}