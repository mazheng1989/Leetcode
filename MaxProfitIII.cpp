#include "stdafx.h"
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<2)
        return 0;
		if(prices.size()==2)
			return prices[1]>prices[0]?prices[1]-prices[0]:0;
        vector<int> profitSale;
		vector<int> profitBuy;
		int nDays = prices.size();
		profitSale.resize(nDays);
		profitBuy.resize(nDays);
		//first round to calculate sale
		profitSale[0] = 0;
		int lowestP = prices[0];
		for(int i=1;i<nDays;i++)
		{
			profitSale[i] = prices[i] - lowestP;
			if(profitSale[i]<profitSale[i-1])
				profitSale[i] = profitSale[i-1];
			if(lowestP>prices[i])
				lowestP = prices[i];
		}
		//first round to calculate buy
		profitBuy[nDays-1] = 0;
		int highestP = prices[nDays-1];
		for(int i=nDays-2;i>=0;i--)
		{
			profitBuy[i] = highestP - prices[i];
			if(profitBuy[i]<profitBuy[i+1])
				profitBuy[i] = profitBuy[i+1];
			if(highestP<prices[i])
				highestP = prices[i];
		}
		int output = 0;
		for(int i=1;i<nDays-1;++i)
		{
			if(output<(profitBuy[i]+profitSale[i]))
				output = profitBuy[i]+profitSale[i];
		}
		return output;
    }
};