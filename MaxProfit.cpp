#include "stdafx.h"
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
		if(prices.size()==0)
			return profit;
		int minSofar = prices[0];
		for(vector<int>::iterator it = prices.begin();it!=prices.end();++it)
		{
			if((*it-minSofar)>profit)
				profit = (*it-minSofar);
			if(minSofar>*it)
				minSofar = *it;
		}
		return profit;
    }
};