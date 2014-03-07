#include "stdafx.h"
class Solution {
public:
    int singleNumber(int A[], int n) {
        int output = 0;
		for (int i = 0;i<n;++i)
			output = output^A[i];
		return output;
    }
};