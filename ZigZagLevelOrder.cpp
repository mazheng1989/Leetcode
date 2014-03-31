#include "stdafx.h"
#include <vector>
#include <queue>
#include <algorithm>    // std::reverse
#include <deque>
#include <stack>
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> output;
		if(root==NULL)
			return output;
		queue<TreeNode*> currentLevel;
		stack<TreeNode*> nextLevel;
		TreeNode *tempNode;
		currentLevel.push(root);
		vector<int> tempVector;
		tempVector.push_back(root->val);
		output.push_back(tempVector);
		bool left2right = true;
		while(!currentLevel.empty())
		{
			tempNode = currentLevel.front();
			currentLevel.pop();
			if(left2right)
			{
				if(tempNode->left!=NULL)
					nextLevel.push(tempNode->left);
				if(tempNode->right!=NULL)
					nextLevel.push(tempNode->right);
			}
			else
			{
				if(tempNode->right!=NULL)
					nextLevel.push(tempNode->right);
				if(tempNode->left!=NULL)
					nextLevel.push(tempNode->left);
			}

			if(currentLevel.empty()&&!nextLevel.empty())
			{
				vector<int> tempVector;
				left2right = !left2right;
				while(!nextLevel.empty())
				{
					currentLevel.push(nextLevel.top());
					tempVector.push_back(nextLevel.top()->val);
					nextLevel.pop();
				}
				output.push_back(tempVector);
			}
		}
		return output;
    }
};