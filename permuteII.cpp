#include "stdafx.h"
#include <vector>
#include <queue>
#include <algorithm>    // std::reverse
using namespace std;
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
		sort(num.begin(),num.end());
		return permute(num);
    }
	vector<vector<int>> permute(vector<int> &num)
	{
		vector<vector<int>> output,outputTemp;
		if(num.size()==0)
			return output;
		vector<int> temp,inputTemp;
		if(num.size()==1)
		{
			temp.push_back(num[0]);
			output.push_back(temp);
			return output;
		}

		for(int i = 0;i<num.size();++i)
		{
			inputTemp = num;
			inputTemp.erase(inputTemp.begin()+i);
			outputTemp = permuteUnique(inputTemp);
			for(vector<vector<int>>::iterator it = outputTemp.begin();it!=outputTemp.end();++it)
			{
				it->insert(it->begin(),num[i]);
			}
			output.insert(output.end(),outputTemp.begin(),outputTemp.end());
			while((i+1)<num.size()&&num[i+1]==num[i])
				++i;
		}
		return output;
	}
};