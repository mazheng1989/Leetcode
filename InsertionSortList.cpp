#include "stdafx.h"
#include <vector>
#include <queue>
#include <algorithm>    // std::reverse
#include <deque>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {        
		ListNode *prev=NULL, *current = head;
		if(head==NULL||head->next==NULL)
			return head;
		ListNode *next = head->next;
		ListNode *prevInsert = NULL;
		while(current!=NULL)
		{
			ListNode *tempNode = head;
			prevInsert = NULL;
			while(tempNode!=current)
			{
				if(tempNode->val<current->val)
				{
					prevInsert = tempNode;
					tempNode = tempNode->next;
				}
				else
				{
					break;
				}
			}
			if(tempNode!=current)
			{
				if(prev!=NULL)
					prev->next = current->next;
				if(prevInsert!=NULL)
					prevInsert->next = current;
				else
					head = current;
				current->next = tempNode;
				
			}
			else
			{
				prev = current;
			}
			current = next;
			if(current!=NULL)
				next = current->next;
		}
		return head;
    }
};