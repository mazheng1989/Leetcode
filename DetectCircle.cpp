#include "stdafx.h"
//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
		if (head==NULL)
		{
			return head;
		}
     int circleLength = 0;
	 ListNode *slowP=head, *fastP=head->next;
	 while (fastP!=NULL&&slowP!=NULL)
	 {
		 if(fastP==slowP)
			 break;
		 
		 slowP = slowP->next;
		 fastP = fastP->next;
		 if(fastP!=NULL)
			 fastP = fastP->next;
	 }
	 if(fastP==NULL)
		 return fastP;
	 slowP = slowP->next;
     circleLength = 1;
	 while(fastP!=slowP)
	 {
		 circleLength++;
		 slowP = slowP->next;
	 }
	 slowP = head;
	 fastP = head;
	 for(int i = 0;i<circleLength;++i)
	 {
		 fastP = fastP->next;
	 }
	 while (slowP!=fastP)
	 {
		 fastP = fastP->next;
		 slowP = slowP->next;
	 }
	 return fastP;
    }
};