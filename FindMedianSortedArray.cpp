#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if((m+n)%2==1)
			return findKthSortedArray(A,m,B,n,(m+n+1)/2);
		else
			return (findKthSortedArray(A,m,B,n,(m+n)/2)+findKthSortedArray(A,m,B,n,(m+n)/2+1))/2;
    }
	double findKthSortedArray(int A[],int m, int B[], int n, int K)
	{
		if(m==0)
			return (double)B[K-1];
		if(n==0)
			return (double)A[K-1];
		if(K==1)
			return (double)(A[0]>B[0])?B[0]:A[0];
		int medA = A[m/2];
		int medB = B[n/2];
		if(medA>medB)
		{
			if((m/2+1+n/2)>=K)
				return findKthSortedArray(A,m/2,B,n,K);
			else
				return findKthSortedArray(A,m,&B[n/2+1],n-n/2-1,K-n/2-1);
		}
		else
		{
			if((m/2+n/2+1)>=K)
				return findKthSortedArray(A,m,B,n/2,K);
			else
				return findKthSortedArray(&A[m/2+1],m-m/2-1,B,n,K-m/2-1);
		}
	}
};