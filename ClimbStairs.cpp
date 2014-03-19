#include "stdafx.h"
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)
        return n;
        int prev = 1,current = 2;
        for(int i =3;i<=n;++i)
        {
            current = prev + current;
            prev = current - prev;
        }
        return current;
    }
};