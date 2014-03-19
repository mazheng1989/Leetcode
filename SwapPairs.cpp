#include "stdafx.h"
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
		ListNode *prevNode,*currentNode,*outputNode,*tempNode;
		if(head==NULL||head->next==NULL)
			return head;
		prevNode = head;
		currentNode = head->next;
		outputNode = currentNode;
		tempNode = NULL;
		while (currentNode!=NULL&&prevNode!=NULL)
		{
			prevNode->next = currentNode->next;
			currentNode->next = prevNode;
			if(tempNode!=NULL)
				tempNode->next = currentNode;
			tempNode = prevNode;
			prevNode = prevNode->next;
			if(prevNode!=NULL)
				currentNode = prevNode->next; 
		}
		return outputNode;
    }
};