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
    bool hasPathSum(TreeNode *root, int sum) {
        if(root==NULL)
        return false;
        if(root->left==NULL&&root->right==NULL&&sum==root->val)
        return true;
        if(root->left==NULL&&root->right==NULL&&sum!=root->val)
        return false;
        
        sum-=root->val;
        bool output = false;
        if(root->left!=NULL)
        output = output||hasPathSum(root->left,sum);
        if(root->right!=NULL)
        output = output||hasPathSum(root->right,sum);
        
        return output;
    }
};