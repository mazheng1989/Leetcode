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
    bool isBalanced(TreeNode *root) {
        if(root==NULL)
        return true;
        bool output = true;
        int leftDepth = calculateDepth(root->left,output);
        int rightDepth = calculateDepth(root->right,output);
        int diff = leftDepth>rightDepth?(leftDepth-rightDepth):(rightDepth-leftDepth);
        if(diff>1)
        output = false;
        return output;
    }
    int calculateDepth(TreeNode *node,bool &balanced)
    {
        if(node==NULL)
        {
            return 0;
        }
        int leftDepth = calculateDepth(node->left,balanced);
        int rightDepth = calculateDepth(node->right,balanced);
        int output = leftDepth>rightDepth?leftDepth:rightDepth;
        output++;
        int diff = leftDepth>rightDepth?(leftDepth-rightDepth):(rightDepth-leftDepth);
        if(diff>1)
        balanced = false;
        return output;
    }
};