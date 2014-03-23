#include "stdafx.h"
#include <vector>
#include <queue>
#include <stack>
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
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> output;
		if(root==NULL)
			return output;
		stack<TreeNode*> nodeStack;
		stack<int> tagStack;
		TreeNode *tempNode = root, *prevNode = root;
		while(tempNode!=NULL)
		{
			nodeStack.push(tempNode);
			tagStack.push(2);
			tempNode = tempNode->left;
		}
		int tempTag = 0;
		while (!nodeStack.empty())
		{
			tempNode = nodeStack.top();
			tempTag = tagStack.top();
			nodeStack.pop();
			tagStack.pop();
			tempTag--;
			if(tempTag==1)
			{
				if(tempNode->right==NULL)
				{
					output.push_back(tempNode->val);
				}
				else
				{
					nodeStack.push(tempNode);
					tagStack.push(tempTag);
					tempNode = tempNode->right;
					while(tempNode!=NULL)
					{
						nodeStack.push(tempNode);
						tagStack.push(2);
						tempNode = tempNode->left;
					}
				}
			}
			if(tempTag==0)
			{
				output.push_back(tempNode->val);
			}

		}
		return output;
	}
};