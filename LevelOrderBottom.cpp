#include "stdafx.h"
#include <vector>
#include <queue>
#include <algorithm>    // std::reverse
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > output;
		if(root==NULL)
		return output;
		queue<TreeNode*> currentLevel,nextLevel;
		TreeNode *tempNode;
		currentLevel.push(root);
		vector<int> tempLevel;
		while (!currentLevel.empty())
		{
			tempNode = currentLevel.front();
			currentLevel.pop();
			tempLevel.push_back(tempNode->val);
			if(tempNode->left!=NULL)
				nextLevel.push(tempNode->left);
			if(tempNode->right!=NULL)
				nextLevel.push(tempNode->right);
			if(currentLevel.empty())
			{
				currentLevel = nextLevel;
				output.push_back(tempLevel);
				tempLevel.clear();
				while (!nextLevel.empty())
				{
					nextLevel.pop();
				}
			}
		}
		reverse(output.begin(),output.end()); 
		return output;
    }
};