#include "stdafx.h"
class Solution {
public:
    void sortColors(int A[], int n) {
        int firstOne = n, lastTwo =n-1;
        while(A[lastTwo]==2)
        lastTwo--;
        for(int i=0;i<=lastTwo;)
        {
            if(A[i]==0)
            {
                if(i>firstOne)
                {
                    A[firstOne]=0;
                    A[i] = 1;
                    firstOne++;
                }
                i++;
                continue;
            }
            if(A[i]==1)
            {
                if(firstOne>i)
                firstOne=i;
                i++;
                continue;
            }
            if(A[i]==2)
            {
                A[i] = A[lastTwo];
                A[lastTwo] = 2;
                lastTwo--;
                continue;
            }
        }
    }
};