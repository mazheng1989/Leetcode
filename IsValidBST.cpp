#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>
#include <string> // this should be already included in <sstream>
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
    bool isValidBST(TreeNode *root) {
        int minV=0, maxV=0;
		if(root==NULL)
			return true;
		return isValidBSTRange(root, minV, maxV);
    }
	bool isValidBSTRange(TreeNode *root, int &minV, int &maxV)
	{
		bool output = true;
		int leftMin = root->val, rightMin = root->val, leftMax = root->val, rightMax = root->val;
		if(root->left==NULL)
		{
			minV = root->val;
		}
		else
		{
			output = output&&isValidBSTRange(root->left,leftMin,leftMax);
			output = output&&(leftMax<root->val);
				minV = leftMin;
		}
		if(root->right==NULL)
		{
			maxV = root->val;
		}
		else
		{
			output = output&&isValidBSTRange(root->right,rightMin,rightMax);
			output = output&&(rightMin>root->val);
				maxV = rightMax;
		}
		return output;
	}
};