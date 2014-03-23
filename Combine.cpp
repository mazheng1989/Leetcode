#include "stdafx.h"
#include <vector>
using namespace std;
class Solution {
public:
       vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > output;
        if(k<=0||n<=0)
        return output;
        vector<int> tempV;
        if(k==1)
        {
			for(int i = 1;i<=n;i++)
			{
			tempV.clear();
			tempV.push_back(i);
			output.push_back(tempV);
			}
			return output;

        }
		output = combine(n,k-1);
		int originalSize = output.size();
		for(int i=1;i<=n;++i)
		{
			for(int j =0;j<originalSize;++j)
			{
			    if(output[j][k-2]<i)
			    {
				tempV = output[j];
				tempV.push_back(i);
				output.push_back(tempV);
			    }
			}
		}
		output.erase(output.begin(),output.begin()+originalSize);
		return output;
    }
};