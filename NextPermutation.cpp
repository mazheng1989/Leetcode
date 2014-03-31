#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include <string> // this should be already included in <sstream>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int> &num) {
		if(num.size()<=1)
			return;
        int tempI = 0;
		bool found = false;
		vector<int> rightMax;
		rightMax.reserve(num.size());
		rightMax[num.size()-1] = -1;
		for(int i=num.size()-2;i>=0;i--)
		{
			rightMax[i] = (rightMax[i+1]<num[i+1])?num[i+1]:rightMax[i+1];
		}
		int leftIndex = 0;
		for(int i=num.size()-2;i>=0;i--)
		{
			if(num[i]<rightMax[i])
			{
				leftIndex = i;
				found = true;
				break;
			}
		}
		if(!found)
		{
			reverse(num.begin(),num.end());
		}
		else
		{
			vector<int>::iterator it = num.begin()+leftIndex+1;
			vector<int>::iterator minMaxIt;
			
			tempI = num[leftIndex];
			int minMax = rightMax[leftIndex];
			while(it!=num.end())
			{
				if(*it>tempI&&*it<=minMax)
				{
					minMax = *it;
					minMaxIt = it;
				}
				it++;
			}
			num[leftIndex] = *minMaxIt;
			*minMaxIt = tempI;
			sort(num.begin()+leftIndex+1,num.end());
		}
    }
};