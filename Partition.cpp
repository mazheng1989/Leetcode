#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include <string> // this should be already included in <sstream>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
		ListNode *left = head, *right=head, *currentTail=NULL, *tempNode=head;
		ListNode *prev = NULL;
		if(head==NULL)
			return NULL;
		tempNode = head->next;
		while(tempNode!=NULL)
		{
			tempNode = tempNode->next;
			right = right->next;
		}
		currentTail = right;
		tempNode = head;
		prev = NULL;
		if(left == right)
			return left;
		while(tempNode!=right)
		{
			if(tempNode->val>=x)
			{
				if(prev!=NULL)
				{
					prev->next = tempNode->next;
				}
				else
				{
					left = tempNode->next;
				}
				currentTail->next = tempNode;
				currentTail = tempNode;
				tempNode = tempNode->next;
				currentTail->next = NULL;
				continue;
			}
			prev = tempNode;
			tempNode = tempNode->next;
		}
		tempNode = right;
		if(currentTail!=tempNode)
		{
			if(tempNode->val>=x)
			{
				if(prev!=NULL)
				{
					prev->next = tempNode->next;
				}
				else
				{
					left = tempNode->next;
				}
				currentTail->next = tempNode;
				currentTail = tempNode;
				tempNode = tempNode->next;
				currentTail->next = NULL;
			}
		}
		return left;
    }
};