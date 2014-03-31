#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 //Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
		int lengthList = 0;
		ListNode *tempNode = head;
		while(tempNode!=NULL)
		{
			lengthList++;
			tempNode = tempNode->next;
		}
		TreeNode* root = generateBST(head, lengthList);
    }
	TreeNode *generateBST(ListNode *head, int lengthList)
	{
		TreeNode *root;
		if(lengthList==0)
		{
			return NULL;
		}
		if(lengthList==1)
		{
			root = new TreeNode(head->val);
			return root;
		}
		if(lengthList==2)
		{
			root = new TreeNode(head->val);
			root->right = new TreeNode(head->next->val);
			return root;
		}

		int midIndex = lengthList/2;
		
		int lengthLeft = midIndex;
		int lengthRight = lengthList - lengthLeft - 1;
		ListNode *midNode = head;
		for(int i=1;i<=midIndex;++i)
			midNode = midNode->next;
		root = new TreeNode(midNode->val);
		root->left = generateBST(head,lengthLeft);
		root->right = generateBST(midNode->next,lengthRight);
		return root;
	}
};