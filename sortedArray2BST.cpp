#include "stdafx.h"
#include<vector>
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
		if(num.size()==0)
			return NULL;
		return constructTree(num,0,num.size()-1);
    }
	TreeNode* constructTree(vector<int> &num,int startIndex,int endIndex){
		if((endIndex-startIndex)<0)
			return NULL;
		if((endIndex-startIndex)==0)
		{
			TreeNode *tempNode = new TreeNode(num[startIndex]);
			return tempNode;
		}
		int midIndex = (startIndex + endIndex)/2;
		TreeNode *tempNode = new TreeNode(num[midIndex]);
		tempNode->left = constructTree(num,startIndex,midIndex-1);
		tempNode->right = constructTree(num,midIndex+1,endIndex);
		return tempNode;
	}
};