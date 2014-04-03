#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		
        ListNode *h1 = l1, *h2 = l2;
		int increment = 0, v1, v2, tempI;
		if(!l1&&!l2)
			return NULL;
		ListNode *prev=NULL, *output = NULL;
		while(h1||h2)
		{
			if(h1)
			{
				v1 = h1->val;
				h1 = h1->next;
			}
			else
				v1 = 0;
			if(h2)
			{
				v2 = h2->val;
				h2 = h2->next;
			}
			else
				v2 = 0;
			tempI = v1+v2+increment;
			if(tempI>9)
			{
				increment = 1;
				tempI -=10;
			}
			else
				increment = 0;
			ListNode *tempNode = new ListNode(tempI);
			if(prev)
			{
				prev->next = tempNode;
				prev = tempNode;
			}
			else
			{
				output = tempNode;
				prev = tempNode;
			}
		}
		if(increment==1)
		{
			ListNode *tempNode = new ListNode(1);
			if(prev)
			{
				prev->next = tempNode;
				prev = tempNode;
			}
			else
			{
				output = tempNode;
				prev = tempNode;
			}
		}
		return output;
    }
};