#include "stdafx.h"
class Solution {
public:
    bool isPalindrome(int x) {
        if(x==0)
        return true;
        int y = 0,temp = x;
        while(temp>0)
        {
            y*=10;
            y+=(temp%10);
            temp/=10;
        }
        return (x==y);
        
    }
};