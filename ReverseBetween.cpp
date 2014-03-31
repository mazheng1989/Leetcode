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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
		if(head==NULL)
			return head;
        ListNode *prev = NULL, *start = head, *end = head, *next = NULL;
		ListNode *currentNode = NULL, *tempNode = NULL;
		for(int i=1;i<m;++i)
		{
			prev = start;
			start = start->next;
		}
		for(int i=1;i<n;++i)
		{
			end = end->next;
		}
		currentNode = start;
		    next = start->next;
		    while(currentNode!=end)
		    {
		        tempNode = next->next;
		        next->next = currentNode;
		        currentNode = next;
		        next = tempNode;
		    }
		if(prev!=NULL)
		{
			prev->next = end;
		}
		else
		{
			head = end;
		}
		start->next = next;
		return head;
    }
};