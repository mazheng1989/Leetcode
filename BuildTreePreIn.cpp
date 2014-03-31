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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		TreeNode *root = NULL;
		if(inorder.size()==0||inorder.size()!=preorder.size())
			return root;
		return (buildTreeIterator(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1));
    }
	TreeNode* buildTreeIterator(vector<int> &inorder, int sI, int eI, vector<int> &preorder, int sP, int eP)
	{
		if(sI>eI)
			return NULL;
		if(sI==eI)
			return (new TreeNode(inorder[sI]));
		int rootV = preorder[sP];
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
		 int sIL = sI, eIL = rootI-1,sPL = sP+1, ePL = sP+(rootI-sI);
		 TreeNode *left = buildTreeIterator(inorder,sIL,eIL,preorder,sPL,ePL);
		 int sIR = rootI+1, eIR = eI,sPR = sP+(rootI-sI+1), ePR = eP;
		 TreeNode *right = buildTreeIterator(inorder,sIR,eIR,preorder,sPR,ePR);
		 root->left = left;
		 root->right = right;
		 return root;
	}
};