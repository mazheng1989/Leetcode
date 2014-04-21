#include "stdafx.h"
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include "use_me.h"
using namespace std;
	int divideSub(long long &dividend, long long divisor)
	{
		if(dividend<divisor)
			return 0;
		long long output = 1;
		while(dividend>=divisor)
		{
			divisor<<=1;
			output<<=1;
		}
		output>>=1;
		divisor>>=1;
		dividend-=divisor;
		return output;
	}
    int Solution::divide(int dividend, int divisor) {
		if(!dividend||!divisor)
			return 0;
		bool negative = false;
		long long dividendL=dividend,divisorL = divisor;
		if(dividend<0)
		{
			negative=!negative;
			dividendL = -dividendL;
		}
        if(divisor<0)
		{
			negative=!negative;
			divisorL = -divisorL;
		}
		int output = 0;
		while(dividendL>=divisorL)
		{
			output+=divideSub(dividendL,divisorL);
		}
		if(!negative)
			return output;
		else
			return -output;
    }