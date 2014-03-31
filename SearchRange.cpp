#include "stdafx.h"
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int startI = -1, endI = -1;
		for(int i=0;i<n;++i)
		{
			if(A[i]==target)
			{
				if(startI<0)
					startI = i;
				if(endI<i)
					endI = i;
			}
		}
		vector<int> output;
		output.push_back(startI);
		output.push_back(endI);
		return output;
    }
};