#include "stdafx.h"
#include <vector>
#include <queue>
#include <algorithm>    // std::reverse
#include <deque>
#include <stack>
#include <string>
#include "use_me.h"
#include <unordered_map>
using namespace std;

	void Solution::recoverTree(TreeNode *root) {
		TreeNode *h1=NULL, *h2 = NULL, *temp = NULL;
		TreeNode *parent = NULL, *prev = NULL, *current = root;
		while(current)
		{
			if(!current->left)
			{
				if(prev && prev->val>current->val)
				{
					if(!h1)
						h1 = prev;
					h2 = current;
				}
				prev = current;
				current = current->right;
				continue;
			}
			temp = current->left;
			parent = temp;
			while(temp&&temp->right!=current)
			{
				parent = temp;
				temp = temp->right;
			}
			if(temp)
			{
				if(prev && prev->val>current->val)
				{
					if(!h1)
						h1 = prev;
					h2 = current;
				}
				temp->right = NULL;
				prev = current;
				current = current->right;
			}
			else
			{
				parent->right = current;
				//prev = current;
				current = current->left;
			}
		}
		if(h1&&h2)
		{
			int value = h1->val;
			h1->val = h2->val;
			h2->val = value;
		}
	}