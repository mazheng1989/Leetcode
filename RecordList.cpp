#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    void reorderList(ListNode *head) {
        vector<ListNode*> listArray;
		ListNode *tempNode = head;
		while(tempNode)
		{
			listArray.push_back(tempNode);
			tempNode = tempNode->next;
		}
		int nNode = listArray.size();
		for(int i=0;(2*i)<(nNode-2);++i)
		{
			listArray[nNode-i-2]->next = NULL;
			listArray[nNode-i-1]->next = listArray[i+1];
			listArray[i]->next = listArray[nNode-i-1];
		}
    }
};