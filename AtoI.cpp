#include "stdafx.h"
#include <vector>
#include <queue>
#include <algorithm>    // std::reverse
#include <deque>
#include <stack>
#include <string>
#include <unordered_map>
#include <climits>
#include "use_me.h"
using namespace std;
    int Solution::atoi(const char *str) {
        //ignore leading whitesapce
		while(*str==' ')
			str++;
		const char *end = str;
		bool isNeg = false;
		if(*end=='+'||*end=='-')
		{
			isNeg = *end=='-';
			end++;
			str++;
		}
		while(*str=='0')
			str++;
		while(*end>='0'&&*end<='9')
			end++;
		// if empty
		if(str==end)
			return 0;
		
		int output = 0;
		int digit = 0;
		while(str!=end)
		{
			digit = *str - '0';
			if(isNeg)
			{
				// negative
				if(INT_MIN/10>output||INT_MIN+digit>output*10)
					return INT_MIN;
				else
				{
					output *= 10;
					output-=digit;
				}
			}
			else
			{
				// positive
				if(INT_MAX/10<output||INT_MAX-digit<output*10)
					return INT_MAX;
				else
				{
					output *= 10;
					output+=digit;
				}
			}
			str++;
		}
		return output;
    }