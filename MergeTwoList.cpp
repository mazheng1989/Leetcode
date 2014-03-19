#include "stdafx.h"
using namespace std;
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *preNode = NULL, *currentNode = l1, *l2Pre = NULL,*l2Node = l2;
        ListNode *output = l1;
        if(l2==NULL)
        return l1;
        if(l1==NULL)
        return l2;
        while(l2Node!=NULL&&l2Node->val<=currentNode->val)
        {
            l2Pre = l2Node;
            l2Node = l2Node->next;
        }
        if(l2Pre!=NULL)
        {
            output = l2;
            l2Pre->next = currentNode;
        }
        //preNode = currentNode;
        //currentNode = currentNode->next;
        while(l2Node!=NULL&&currentNode!=NULL)
        {
            while(currentNode!=NULL&&currentNode->val<l2Node->val)
            {
                preNode = currentNode;
                currentNode = currentNode->next;
            }
            preNode->next = l2Node;
            preNode = l2Node;
            l2Node = l2Node->next;
            preNode->next = currentNode;
        }
        if(l2Node!=NULL)
        preNode->next=l2Node;
        return output;
    }
};