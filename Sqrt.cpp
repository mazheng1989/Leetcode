#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    int sqrt(int x) {
		if(!x)
			return 0;
        double prevsolution = 0, solution = (double)x/2;
		double epsilon = 0.000001;
		while(std::abs(prevsolution-solution)>epsilon)
		{
			prevsolution = solution;
			solution -= ((solution*solution-x)/(2*solution));
		}
		return (int)(solution);
    }
};