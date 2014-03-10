#include "stdafx.h"
class Solution {
public:
    int reverse(int x) {
        int output = 0;
		bool isNeg = false;
		if(x<0){
			x = -x;
			isNeg = true;
		}
		while(x>0) {
			output *=10;
			output +=(x%10);
			x/=10;
		}
		if(isNeg)
			output = -output;
		return output;
    }
};