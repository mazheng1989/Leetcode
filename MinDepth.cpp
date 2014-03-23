#include "stdafx.h"
#include <vector>
#include <queue>
#include <math.h>
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
    int minDepth(TreeNode *root) {
        if(root==NULL)
			return 0;
		queue<TreeNode*> currentLevel, nextLevel,tempLevel;
		TreeNode *tempNode;
		currentLevel.push(root);
		int depth = 1;
		while(!currentLevel.empty())
		{
			tempNode = currentLevel.front();
			currentLevel.pop();
			if(tempNode->left==NULL&&tempNode->right==NULL)
				return depth;
			if(tempNode->left!=NULL)
				nextLevel.push(tempNode->left);
			if(tempNode->right!=NULL)
				nextLevel.push(tempNode->right);
			if(currentLevel.empty())
			{
				tempLevel = currentLevel;
				currentLevel = nextLevel;
				nextLevel = tempLevel;
				depth++;
			}
		}
    }
};