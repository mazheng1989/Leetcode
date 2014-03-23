#include "stdafx.h"
#include "use_me.h"

using namespace std;
bool Solution::canJump(int A[], int n) {
        int maxReach = A[0];
		for(int i=1;i<=maxReach&&maxReach<(n-1);++i)
		{
			if((A[i]+i)>maxReach)
				maxReach = (A[i]+i);
		}
		return maxReach>=(n-1);
    }
    
