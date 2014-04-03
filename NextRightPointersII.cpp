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
		int currentLevelN = 0, nextLevelN = 0;
		if(root==NULL)
			return;
		TreeLinkNode *nextLevel = root, *currentNode = NULL, *prev = NULL;
		while (nextLevel!=NULL)
		{
			currentNode = nextLevel;
			nextLevel = nextLevel->left;
			prev = NULL;
			while(currentNode!=NULL)
			{
				if(currentNode->left!=NULL)
				{
					if(nextLevel==NULL)
						nextLevel = currentNode->left;
					if(prev!=NULL)
						prev->next = currentNode->left;
					prev = currentNode->left;
				}
				if(currentNode->right!=NULL)
				{
					if(nextLevel==NULL)
						nextLevel = currentNode->right;
					if(prev!=NULL)
						prev->next = currentNode->right;
					prev = currentNode->right;
				}
				currentNode = currentNode->next;
			}
		}
    }
};