#include "stdafx.h"
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow=head;
		while(fast&&fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if(fast==slow)
				break;
		}
		return (fast&&fast->next);
    }
};