#include "stdafx.h"
#include <vector>
#include <queue>
#include <algorithm>    // std::reverse
#include <deque>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
	int jump(int A[], int n) {
		if(n<=1)
			return 0;
		int stepN = 1;
		int maxReach = A[0];
		int maxReachNew = 0;
		int startI = 1;
		while(maxReach<(n-1))
		{
			maxReachNew = -1;
			for(;startI<=maxReach;startI++)
			{
				if(maxReachNew<(A[startI]+startI))
					maxReachNew = (A[startI]+startI);
				if(maxReachNew>=(n-1))
					return ++stepN;
			}
			startI = maxReach+1;
			if(maxReach>=maxReachNew)
				return -1;
			stepN++;
			maxReach = maxReachNew;
		}
		return stepN;
	}
};