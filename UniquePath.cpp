#include "stdafx.h"
class Solution {
public:
    int uniquePaths(int m, int n) {
        long small=0, large = 0;
        small = (m>n)?(n-1):(m-1);
        large = (m>n)?(m-1):(n-1);
        large +=small;
		double output = 1.0;
        for(int i =1;i<=small;++i)
        {
			output*=(large-i+1);
			output/=i;
        }
        int outputInt  = (int)(output+0.5);
		return outputInt;
    }
};