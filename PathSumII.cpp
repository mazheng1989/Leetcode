#include "stdafx.h"
#include <vector>
#include <queue>
#include <algorithm>    // std::reverse
#include <deque>
#include <stack>
#include <string>
#include <unordered_map>
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> output;
		if(root==NULL)
			return output;
		if(root->left==NULL&&root->right==NULL)
		{
			if(root->val!=sum)
				return output;
			vector<int> tempV;
			tempV.push_back(root->val);
			output.push_back(tempV);
			return output;
		}
		if(root->left!=NULL)
		{
			vector<vector<int>> outputLeft = pathSum(root->left,sum-root->val);
			for(int i=0;i<outputLeft.size();++i)
			{
				vector<int> tempV = outputLeft[i];
				tempV.insert(tempV.begin(),root->val);
				output.push_back(tempV);
			}
		}
		if(root->right!=NULL)
		{
			vector<vector<int>> outputRight = pathSum(root->right,sum-root->val);
			for(int i=0;i<outputRight.size();++i)
			{
				vector<int> tempV = outputRight[i];
				tempV.insert(tempV.begin(),root->val);
				output.push_back(tempV);
			}
		}
		return output;
    }
};