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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		
		int index = 0, startIndex = 0, minSum = 0, sum = 0, n = gas.size();
		for(index = 0; index<n; ++index)
		{
			sum+=(gas[index]-cost[index]);
			if(sum<0)
			{
				minSum+=sum;
				startIndex = index+1;
				sum = 0;
				
			}
		}
		if((minSum+sum)>=0)
			return startIndex;
		else
			return -1;
    }
};