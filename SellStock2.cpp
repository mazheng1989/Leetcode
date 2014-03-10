#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
		for(vector<int>::iterator it=prices.begin();it!=prices.end();++it)
		{
			if((it+1)!=prices.end())
			{
				if(*it<*(it+1))
					profit+=(*(it+1) - *it);
			}
		}
		return profit;
    }
};