#include "stdafx.h"
#include<queue>
using namespace std;
//  Definition for binary tree with next pointer.
  struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };
 
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> q;
		int currentLevelN = 0, nextLevelN = 0;
		q.push(root);
		currentLevelN = 1;
		TreeLinkNode* tempNode;
		while (!q.empty())
		{
			tempNode = q.front();
			q.pop();
			currentLevelN--;
			
			if(tempNode->left!=NULL)
			{
				q.push(tempNode->left);
				nextLevelN++;
			}
			if(tempNode->right!=NULL)
			{
				q.push(tempNode->right);
				nextLevelN++;
			}
			if(currentLevelN>0)
			{
				tempNode->next = q.front();
			}
			else
			{
				tempNode->next = NULL;
				currentLevelN = nextLevelN;
				nextLevelN = 0;
			}
		}
    }
};