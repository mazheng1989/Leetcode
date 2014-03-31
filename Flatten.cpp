#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 class Solution {
public:
    void flatten(TreeNode *root) {
        
    }
	TreeNode *flattenTree(TreeNode *root)
	{
		if(root==NULL)
			return NULL;
		if(root->left==NULL&&root->right==NULL)
			return root;
		TreeNode *leftSub = root->left;
		TreeNode *rightSub = root->right;
		TreeNode *leftLast = flattenTree(leftSub);
		TreeNode *rightLast = flattenTree(rightSub);

		if(leftSub!=NULL)
		{
			root->left = NULL;
			root->right = leftSub;
			leftLast->right=rightSub;
		}
		if(rightLast!=NULL)
			return rightLast;
		else
			return leftLast;
	}
};