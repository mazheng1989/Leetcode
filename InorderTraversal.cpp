#include "stdafx.h"
#include <vector>
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
    	vector<int> inorderTraversal(TreeNode *root) {
		stack<TreeNode*> stackOfNode;
		vector<int> output;
		TreeNode *tempNode = root;

		while(tempNode!=NULL)
		{
			stackOfNode.push(tempNode);
			tempNode = tempNode->left;
		}
		while (!stackOfNode.empty())
		{
			tempNode = stackOfNode.top();
			stackOfNode.pop();
			output.push_back(tempNode->val);
			if(tempNode->right!=NULL)
			{
				tempNode=tempNode->right;
				while (tempNode!=NULL)
				{
				    stackOfNode.push(tempNode);
				    tempNode = tempNode->left;
				}
			}
		}
		return output;
	}
};