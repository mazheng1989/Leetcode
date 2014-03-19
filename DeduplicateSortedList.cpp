#include "stdafx.h"
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *temp = head;
        while(temp!=NULL)
        {
            while(temp->next!=NULL&&temp->next->val==temp->val)
            {
                temp->next = temp->next->next;
            }
            temp = temp->next;
        }
        return head;
    }
};