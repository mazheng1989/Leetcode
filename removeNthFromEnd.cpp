#include "stdafx.h"
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *ahead = head, *behind = head,*preNode = NULL;
        for(int i=0;i<n;++i)
        {
            ahead = ahead->next;
        }
        while(ahead!=NULL)
        {
            preNode = behind;
            ahead = ahead->next;
            behind = behind->next;
        }
        if(preNode!=NULL)
        {
            preNode->next = behind->next;
        }
        else
        {
            head = head->next;
        }
        return head;
    }
};