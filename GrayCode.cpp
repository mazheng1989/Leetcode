#include "stdafx.h"
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>    // std::reverse
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> output,outputTemp;
        if(n<=0)
        {
            output.push_back(0);
            return output;
        }
        if(n==1)
        {
            output.push_back(0);
            output.push_back(1);
            return output;
        }
        output = grayCode(n-1);
		int range = (int)pow(2.0f,(float)(n-1));
        for(int i=0;i<range;++i)
		{
			output.push_back(range+output[range-1-i]);
		}
		return output;
    }
};