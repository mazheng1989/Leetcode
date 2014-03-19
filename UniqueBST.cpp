#include "stdafx.h"
class Solution {
public:
    int numTrees(int n) {
        if(n<=1)
			return 1;
		n--;
		int output = 0;
		for(int i=0;i<=n;++i)
		{
			output+=(numTrees(i)*numTrees(n-i));
		}
		return output;
    }
};