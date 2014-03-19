#include "stdafx.h"
using namespace std;
class Solution {
public:
    int removeDuplicates(int A[], int n) {
		int shift = 0;
        for(int i=1;i<n;++i)
		{
			if(A[i]==A[i-shift-1])
			{
				shift++;
			}
			else
			{
				if(shift>0)
					A[i-shift] = A[i];
			}
		}
		return n-shift;
    }
};