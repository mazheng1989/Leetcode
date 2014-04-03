#include "stdafx.h"
class Solution {
public:
    int search(int A[], int n, int target) {
        if(n<=0)
        return -1;
        int i=0,j=n-1,mid;
        while(i<=j)
        {
            mid = (i+j)/2;
            if(A[mid]==target)
				return mid;
            if(A[i]<=A[mid]&&A[mid]<=A[j])
            {
                //on the same side of pivot
                if(A[mid]<target)
                {
                    i = mid+1;
                }
                else
                {
                    j = mid-1;
                }
            }
            else //on diff sides of pivot
            {
                if(A[mid]>=A[i]||A[j]<=A[mid])
                {
                    //left of pivot
                    if(A[mid]>target)
                    {
                        if(A[i]>target)
                        {
                            i = mid+1;
                        }
                        else
                        {
                            j = mid-1;
                        }
                    }
                    else
                    {
                        i = mid+1;
                    }
                }
                else
                {
                    //right of pivot
                    if(A[mid]<target)
                    {
                        if(A[j]>=target)
                        {
                            i = mid+1;
                        }
                        else
                        {
                            j = mid-1;
                        }
                    }
                    else
                    {
                        j = mid-1;
                    }
                }
            }
        }
        return -1;
    }
};