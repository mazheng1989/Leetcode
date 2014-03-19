#include "stdafx.h"
class Solution {
public:
   void merge(int A[], int m, int B[], int n) {
        int index1 = m-1,index2=n-1,bufferN = 0;
		int firstLarger=m-1,firstSmaller = m-1;
		for(index1 = m-1,index2=n-1;index2>=0;--index2)
		{
			while(index1>=0&&A[index1]>B[index2])
			{
				index1--;
			}
			firstSmaller = index1;
			for(int i =firstLarger;i>= firstSmaller+1;--i)
			{
				A[i+index2+1] = A[i];
			}
			A[index1+1+index2] = B[index2];
			firstLarger = firstSmaller;
		}
    }
};