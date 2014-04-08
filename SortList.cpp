#include "stdafx.h"
#include "use_me.h"
// Definition for singly-linked list.
ListNode *mergeLists(ListNode *head1, ListNode *head2)
	{
		ListNode *head = NULL;
		ListNode *tail = NULL;
		while(head1&&head2)
		{
			if(head1->val<=head2->val)
			{
				if(!head)
				{
					head = head1;
					tail = head;
				}
				else
				{
					tail->next = head1;
					tail = head1;
				}
				head1 = head1->next;
			}
			else
			{
				if(!head)
				{
					head = head2;
					tail = head;
				}
				else
				{
					tail->next = head2;
					tail = head2;
				}
				head2 = head2->next;
			}
		}
		if(head1)
				tail->next = head1;
		if(head2)
				tail->next = head2;
		return head;
	}
 ListNode *sortP(ListNode*& head, int nNode)
	{// reference of pointer, because need to change the pointer
		if(nNode==1)
		{
			ListNode *tempNode = head;
			head = head->next;
			tempNode->next = NULL;
			return tempNode;
		}
		ListNode *left = sortP(head, nNode/2);
		ListNode *right = sortP(head, nNode - nNode/2);
		return mergeLists(left,right);
	}
	
    ListNode* Solution::sortList(ListNode *head) {
        if(!head||!head->next)
        return head;
        int nNode = 0;
		ListNode *current = head;
		while(current)
		{
			nNode++;
			current = current->next;
		}
		return sortP(head,nNode);
    }
	
