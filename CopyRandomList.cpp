#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
// Definition for singly-linked list with a random pointer.
 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        vector<RandomListNode*> sourceList, targetList;
		unordered_map<RandomListNode*, int> sourceMap;
		unordered_map<int, RandomListNode*> targetMap;
		RandomListNode *currentNode = head, *targetHead=NULL, *prev = NULL;
		int index = 0;
		while(currentNode)
		{
			RandomListNode *tempNode = new RandomListNode(currentNode->label);
			if(prev)
			{
				prev->next = tempNode;
				prev = tempNode;
			}
			else
			{
				targetHead = tempNode;
				prev = tempNode;
			}
			sourceList.push_back(currentNode);
			targetList.push_back(tempNode);
			std::pair<RandomListNode*,int> tempPair(currentNode,index);
			sourceMap.insert(tempPair);
			std::pair<int,RandomListNode*> tempPairTarget(index,tempNode);
			targetMap.insert(tempPairTarget);
			currentNode = currentNode->next;
			index++;
		}
		for(int i=0;i<sourceList.size();++i)
		{
			if(!sourceList[i]->random)
				continue;
			int randomIndex = sourceMap.at(sourceList[i]->random);
			targetList[i]->random = targetMap.at(randomIndex);
		}
		return targetHead;
    }
};