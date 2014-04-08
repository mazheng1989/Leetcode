#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> output;
		if(num.size()<=3)
			return output;
		sort(num.begin(),num.end());
		int firstI = 0;
		for(firstI = 0;firstI<=num.size()-4;firstI++)
		{
			vector<vector<int>> threeResult = threeSum(num,target-num[firstI],firstI+1);
			for(int i = 0;i<threeResult.size();++i)
			{
				vector<int> tempV = threeResult[i];
				tempV.insert(tempV.begin(),num[firstI]);
				output.push_back(tempV);
			}
			while(firstI<num.size()-1&&num[firstI]==num[firstI+1])
				firstI++;
		}
		return output;
    }
	vector<vector<int>> threeSum(vector<int> &num, int target, int startI)
	{
		vector<vector<int>> output;
		if(num.size()-startI<3)
			return output;
		int firstI = 0;
		for(firstI = startI;firstI<=num.size()-3;++firstI)
		{
			vector<vector<int>> threeResult = twoSum(num,target-num[firstI],firstI+1);
			for(int i = 0;i<threeResult.size();++i)
			{
				vector<int> tempV = threeResult[i];
				tempV.insert(tempV.begin(),num[firstI]);
				output.push_back(tempV);
			}
			while(firstI<num.size()-1&&num[firstI]==num[firstI+1])
				firstI++;
		}
		return output;
	}
	vector<vector<int>> twoSum(vector<int> &num, int target, int startI)
	{
		vector<vector<int>> output;
		if(num.size()-startI<2)
			return output;
		int i = startI, j=num.size()-1;
		while(i<j)
		{
			if(num[i]+num[j]>target)
			{
				j--;
				continue;
			}
			if(num[i]+num[j]<target)
			{
				i++;
				continue;
			}
			vector<int> tempV;
			tempV.push_back(num[i]);
			tempV.push_back(num[j]);
			output.push_back(tempV);
			while(i<num.size()-1&&num[i]==num[i+1])
				i++;
			i++;
			while(j>startI&&num[j]==num[j-1])
				j--;
			j--;
		}
		return output;
	}
};