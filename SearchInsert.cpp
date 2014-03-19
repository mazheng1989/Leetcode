#include "stdafx.h"
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int left = 0,right = n-1;
        if(left>right)
        return 0;
        int insertP = 0,midP = 0;
        while(left<right)
        {
            midP = (left+right)/2;
            if(A[midP]>target)
            {
                right=midP-1;
            }
            if(A[midP]<target)
            {
                left=midP+1;
            }
            if(A[midP]==target)
            {
                return midP;
            }
        }
        if(A[left]>=target)
        return left;
        if(A[left]<target)
        return left+1;
    }
};