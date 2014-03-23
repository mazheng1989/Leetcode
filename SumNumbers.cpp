#include "stdafx.h"
// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if(root==NULL)
        return 0;
        return sumNumbersTree(root,0);
    }
    int sumNumbersTree(TreeNode *root,int sumSofar){
        if(root->left==NULL&&root->right==NULL)
        {
            return (sumSofar*10)+root->val;
        }
        int output = 0;
        if(root->left!=NULL)
        {
            output+=(sumNumbersTree(root->left,(sumSofar*10)+root->val));
        }
        if(root->right!=NULL)
        {
            output+=(sumNumbersTree(root->right,(sumSofar*10)+root->val));
        }
        return output;
    }
};