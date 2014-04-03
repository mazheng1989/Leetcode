#include "stdafx.h"

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *prev = NULL, *current = head, *start = head, *end = head, *next = NULL;
		ListNode *prevTemp = NULL, *nextTemp = NULL;
		while(current!=NULL)
		{
			start = current;
			end = start;
			for(int i = 1;i<k;++i)
			{
				end = end->next;
				if(end==NULL)
				{
					break;
				}
			}
			if(end==NULL)
				break;
			next = end->next;
			
			if(start!=end)
			{
				prevTemp = start; nextTemp = prevTemp->next;
				while(prevTemp!=end)
				{
					ListNode *tempNode = nextTemp->next;
					nextTemp->next = prevTemp;
					prevTemp = nextTemp;
					nextTemp = tempNode;
				}
				if(prev==NULL)
					head = end;
				else
					prev->next = end;
				start->next = next;
				prev = start;
			}
			current = next;
			
		}
		return head;
    }
};