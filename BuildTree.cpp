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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		TreeNode *root = NULL;
		if(inorder.size()==0||inorder.size()!=postorder.size())
			return root;
		return (buildTreeIterator(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1));
    }
	TreeNode* buildTreeIterator(vector<int> &inorder, int sI, int eI, vector<int> &postorder, int sP, int eP)
	{
		if(sI>eI)
			return NULL;
		if(sI==eI)
			return (new TreeNode(inorder[sI]));
		int rootV = postorder[eP];
		int rootI = -1;
		for(int i=eI;i>=sI;i--)
			if(inorder[i]==rootV)
			{
				rootI = i;
				break;
			}
         if(rootI==-1)
			 return NULL;
		 TreeNode *root = new TreeNode(rootV);
		 int sIL = sI, eIL = rootI-1,sPL = sP, ePL = sP+(rootI-1-sI);
		 TreeNode *left = buildTreeIterator(inorder,sIL,eIL,postorder,sPL,ePL);
		 int sIR = rootI+1, eIR = eI,sPR = sP+(rootI-sI), ePR = eP-1;
		 TreeNode *right = buildTreeIterator(inorder,sIR,eIR,postorder,sPR,ePR);
		 root->left = left;
		 root->right = right;
		 return root;
	}
};