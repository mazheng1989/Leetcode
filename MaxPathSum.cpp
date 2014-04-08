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
    int maxPathSum(TreeNode *root) {
        if(root==NULL)
			return 0;
		int maxPathSofar = root->val, deepPath = 0;
		maxPathSumSub(root, deepPath, maxPathSofar);
		return maxPathSofar;
    }
	int maxPathSumSub(TreeNode *root, int &deepPath, int &maxPathSofar)
	{
		int output = root->val;
		if(!root->left&&!root->right)
		{
			deepPath = root->val;
			maxPathSofar = (maxPathSofar<output)?output:maxPathSofar;
			return output;
		}
		int deepPathL = 0;
		int maxPL = 0;
		if(root->left)
		{
			maxPL = maxPathSumSub(root->left,deepPathL, maxPathSofar);
			output = std::max(maxPL,output);
			output = std::max(deepPathL+root->val,output);
		}
		deepPath = std::max(root->val,deepPathL+root->val);
		int deepPathR = 0;
		int maxPR = 0;
		if(root->right)
		{
			maxPR = maxPathSumSub(root->right,deepPathR, maxPathSofar);
			output = std::max(maxPR,output);
			output = std::max(deepPathR+root->val,output);
		}
		deepPath = std::max(deepPath,deepPathR+root->val);
		output = std::max(deepPathR+deepPathL+root->val,output);
		maxPathSofar = (maxPathSofar<output)?output:maxPathSofar;
		return output;
	}
};