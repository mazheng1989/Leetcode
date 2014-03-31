#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>
#include <string> // this should be already included in <sstream>
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
    vector<TreeNode *> generateTrees(int n) {
        return generateTreesRange(1, n);
    }
	vector<TreeNode *> generateTreesRange(int start, int end) {
		vector<TreeNode *> output;
		if(start>end)
		{
			output.push_back(NULL);
			return output;
		}
		if(start == end)
		{
			output.push_back(new TreeNode(start));
			return output;
		}
		for(int i = start;i<=end;i++)
		{
			vector<TreeNode *> rightRoot = generateTreesRange(i+1,end);
			vector<TreeNode *> leftRoot = generateTreesRange(start,i-1);
			for(int j = 0;j<rightRoot.size();++j)
				for(int k = 0;k<leftRoot.size();++k)
				{
					TreeNode *root = new TreeNode(i);
					root->left = leftRoot[k];
					root->right = rightRoot[j];
					output.push_back(root);
				}
		}
		return output;
    }
};