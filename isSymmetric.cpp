#include "stdafx.h"
#include <queue>
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
    bool isSymmetric(TreeNode *root) {
        if(root==NULL||(root->left==NULL&&root->right==NULL))
        return true;
        if((root->left==NULL&&root->right!=NULL)||(root->right==NULL&&root->left!=NULL))
        return false;
		queue<TreeNode*> q;
		queue<TreeNode*> tempLevel;
		q.push(root);
		bool output = true;
		while(!q.empty())
		{
			TreeNode *tempNode = q.front();
			q.pop();

			if(tempNode!=NULL)
			{
				tempLevel.push(tempNode->left);
				tempLevel.push(tempNode->right);
			}
			if(q.empty())
			{
				q = tempLevel;
				if(!checkLevel(tempLevel))
					output = false;
			}
		}
		return output;
    }
	bool checkLevel(queue<TreeNode*> &q)
	{
		if(q.size()<=1)
			return true;
		vector<TreeNode*> tempVector;
		while(!q.empty())
		{
			TreeNode *tempNode = q.front();
			tempVector.push_back(tempNode);
			q.pop();
		}
		if(tempVector.size()%2!=0)
			return false;
		bool output = true;
		for(int i=0;i<tempVector.size()/2;++i)
		{
			if(tempVector[i]==NULL&&tempVector[tempVector.size()-1-i]==NULL)
				continue;
			if((tempVector[i]==NULL&&tempVector[tempVector.size()-1-i]!=NULL)||
				(tempVector[i]!=NULL&&tempVector[tempVector.size()-1-i]==NULL))
			{
				output = false;
				break;
			}
			if(tempVector[i]->val!=tempVector[tempVector.size()-1-i]->val)
			{
				output = false;
				break;
			}
		}
		return output;
	}
};