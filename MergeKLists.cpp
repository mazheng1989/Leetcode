#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 class CompareFoo
{
public:
    // Compare two Foo structs.
    bool operator()(ListNode* a, ListNode* b) const
    {
        return (a->val>b->val);
    }
};
class Solution {
public:
	/*bool compareNodes(ListNode* a, ListNode* b)
	{
		return (a->val>b->val)?true:false;
	}*/
    ListNode *mergeKLists(vector<ListNode *> &lists) {
		vector<ListNode*> mergePool;
		ListNode *output = NULL;
		for(int i = 0;i<lists.size();++i)
		{
			if(!lists[i])
			{
				continue;
			}
			mergePool.push_back(lists[i]);
		}
		std::make_heap(mergePool.begin(),mergePool.end(),CompareFoo());
		ListNode *currentNode=NULL,*preNode=NULL;
		while(!mergePool.empty())
		{
			std::pop_heap(mergePool.begin(),mergePool.end(),CompareFoo());
			currentNode = mergePool.back();
			mergePool.pop_back();
			if(!output)
				output = currentNode;
			if(preNode)
				preNode->next = currentNode;
			preNode = currentNode;

			currentNode = currentNode->next;
			if(currentNode)
			{
				mergePool.push_back(currentNode);
				std::make_heap(mergePool.begin(),mergePool.end(),CompareFoo());
			}
		}
		return output;
    }
};