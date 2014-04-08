#include "stdafx.h"
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
		if(k==0||!head)
			return head;

		int nNode = 0;
		ListNode *current = head,*prev=NULL, *tail = NULL;
		for(int i=0;i<k;++i)
		{
			prev = current;
			current = current->next;
			if(!current)
			current = head;
		}
		if(current == head)
		return head;
		ListNode *newHead = head, *newTail = NULL;
		while(current)
		{
			prev = current;
			current=current->next;
			newTail = newHead;
			newHead = newHead->next;
		}
		if(newTail)
		newTail->next = NULL;
		
		prev->next = head;
		return newHead;
    }
};