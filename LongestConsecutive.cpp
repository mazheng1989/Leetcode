#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
		unordered_set<int> hashSet;
		for(int i=0;i<num.size();++i)
		{
			if(hashSet.find(num[i])==hashSet.end())
			{
				hashSet.insert(num[i]);
			}
		}
		int count=0,longestCount = 0,tempNum=0;
		int left = 0, right = 0;
		while(!hashSet.empty())
		{
			count = 1;
			tempNum = *(hashSet.begin());
			hashSet.erase(tempNum);
			left = tempNum-1;
			while(hashSet.find(left)!=hashSet.end())
			{
				count++;
				hashSet.erase(left);
				left--;
			}
			right = tempNum+1;
			while(hashSet.find(right)!=hashSet.end())
			{
				count++;
				hashSet.erase(right);
				right++;
			}
			if(count>longestCount)
				longestCount = count;
		}
		return longestCount;
    }
};
