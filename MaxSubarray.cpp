#include "stdafx.h"
class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n<=0)
        return 0;
        int currentSum = 0, maxSum = A[0]-1;
        int startIndex=0,endIndex=0;
        for (int i=0;i<n;++i)
        {
            if(currentSum<0)
            {
                startIndex = i;
                currentSum = 0;
            }
            currentSum+=A[i];
            if(currentSum>maxSum)
            {
                maxSum = currentSum;
                endIndex = i;
            }
            
        }
        return maxSum;
    }
};