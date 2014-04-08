#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution {
public:
	vector<int> num2Index(vector<int> &numbers,vector<int> &target)
	{
		vector<int> output;
		output.resize(target.size());
		for(int index = 0;index<target.size();++index)
			output[index] = -1;
		for(int index = 0;index<numbers.size();++index)
		{
			bool complete = true;
			for(int i=0;i<target.size();i++)
			{
				if(output[i]!=-1)
				{
					continue;
				}
				complete = false;
				if(target[i]==numbers[index])
				{
					output[i] = index+1;
					break;
				}
			}
			if(complete)
				break;
		}
		sort(output.begin(),output.end());
		return output;
	}
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> numbersBackup = numbers;
		sort(numbers.begin(),numbers.end());
		int left = 0, right = numbers.size()-1;
		vector<int> output;
		while(left<right)
		{
			int sum = numbers[left]+numbers[right];
			if(sum==target)
			{
				vector<int> num;
				num.push_back(numbers[left]);
				num.push_back(numbers[right]);
				output = num2Index(numbersBackup,num);
				return output;
			}
			if(sum<target)
			{
				left++;
			}
			else
				right--;
		}
		vector<int> num;
		num.push_back(numbers[left]);
		num.push_back(numbers[right]);
		output = num2Index(numbersBackup,num);
		return output;
	}
};