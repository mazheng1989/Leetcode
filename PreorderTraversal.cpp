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
	vector<int> preorderTraversal(TreeNode *root) {
		stack<TreeNode*> stackOfNode;
		vector<int> output;
		TreeNode *tempNode;
		stackOfNode.push(root);
		while (!stackOfNode.empty())
		{
			tempNode = stackOfNode.top();
			stackOfNode.pop();
			if(tempNode!=NULL)
			{				
				output.push_back(tempNode->val);
				stackOfNode.push(tempNode->right);
				stackOfNode.push(tempNode->left);
			}
		}
		return output;
	}
};