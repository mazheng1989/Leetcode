#include "stdafx.h"
#include <vector>
#include <queue>
#include <algorithm>    // std::reverse
#include <deque>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		ListNode *start = head, *end = head, *tempNode, *prev = NULL;
		if(head==NULL)
			return head;
		ListNode *next = start->next;
		while(start!=NULL&&next!=NULL)
		{
			end = start;
			while((end->next)!=NULL&&start->val == (end->next)->val)
			{
				end = end->next;
			}
			if(start==end)
			{
				prev = start;
				start = prev->next;
				if(start!=NULL)
					next = start->next;
				continue;
			}

			next = end->next;
			if(prev!=NULL)
			{
				prev->next = next;
			}
			else
			{
				head = next;
			}
			start = next;
			if(start!=NULL)
				next = start->next;
		}
		return head;
	}
};