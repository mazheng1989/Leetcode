#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target){
		sort(num.begin(),num.end());
		int i=0,j=0,k=0,closestSum=0,diffSum=0,minDiff,diff=0;
		closestSum = num[0] + num[1] +num[3];
		minDiff = abs(closestSum-target);
		for(i=0;i<num.size()-3;++i)
		{
			diffSum = target - num[i];
			j = i+1;
			k = num.size()-1;
			while(j<k)
			{
				diff = (num[j]+num[k])-diffSum;
				if(abs(diff)<minDiff)
				{
					minDiff = abs(diff);
					closestSum = num[i]+num[j]+num[k];
				}
				if(diff<0)
				{
					// num[j]+num[k] should goes up
					j++;
				}
				if(diff>0)
				{
					// num[j]+num[k] should goes down
					k--;
				}
				if(diff==0)
				{
					return target;
				}
			}
		}
		return closestSum;
    }
};