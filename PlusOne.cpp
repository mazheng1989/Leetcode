#include "stdafx.h"
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if(digits.size()==0)
        digits.push_back(1);
        
        int plus = 1;
        for(int i=digits.size()-1;i>=0;i--)
        {
            if(digits[i]==9&&plus ==1)
            {
                digits[i] = 0;
                continue;
            }
            if(plus==1)
            {
                digits[i]++;
                plus = 0;
            }
        }
        if(plus==1)
        {
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};