#include "stdafx.h"
#include <unordered_set>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
		if(n==0)
			return 1;
        int *count  = new int[n];
		for(int i = 0;i<n;i++)
			count[i] = 0;
		for(int i=0;i<n;i++)
		{
			if(A[i]>0&&A[i]<=n)
				count[A[i]-1]++;
		}
		int output = n+1;
		for(int i = 0;i<n;i++)
		{
			if(count[i]==0&&(i+1)<output)
				output = i+1;
		}
		delete[] count;
		count = NULL;
		return output;
    }
};