#include "stdafx.h"
#include <vector>
#include <algorithm>    // std::max
using namespace std;
class Solution {
public:
    int maxArea(vector<int> &height) {
        int high = height.size()-1,low=0;
        int maxArea = 0;
        while(high>low)
        {
            maxArea = max(maxArea, min(height[low],height[high])*(high-low));
            if(height[low]<height[high])
            {
                low++;
            }
            else
            {
                high--;
            }
        }
        return maxArea;
    }
};