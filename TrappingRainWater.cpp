#include "stdafx.h"
class Solution {
public:
    int trap(int A[], int n) {
        int *leftMax  = new int[n];
        int output=0, i=0,tempHeight=0,rightMax = A[n-1];
        leftMax[0] = 0;
        for(i=1;i<n;++i)
        {
            if(A[i-1]>leftMax[i-1])
            leftMax[i] = A[i-1];
            else
            leftMax[i] = leftMax[i-1];
        }
        
        for(i=n-2;i>=0;--i)
        {
            if(A[i+1]>rightMax)
            rightMax = A[i+1];
            
            tempHeight = (rightMax>leftMax[i])?leftMax[i]:rightMax;
            output+=(tempHeight>A[i])?(tempHeight-A[i]):0;
        }
        
        delete [] leftMax;
        return output;
    }
};