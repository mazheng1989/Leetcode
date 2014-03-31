#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include <string> // this should be already included in <sstream>
using namespace std;
class Solution {
public:
    double pow(double x, int n) {
        bool negFlag = (n<0);
        if(negFlag)
        n = -n;
        double result = powRecursive(x,n);
        if(negFlag)
        result = 1/result;
        return result;
    }
    double powRecursive(double x, int n)
    {
        if(n==0)
        return 1;
        if(n==1)
        return x;
        int red = n%2;
        int half = n/2;
        double result = pow(x,half);
        result*=result;
        result*=(pow(x,red));
        return result;
    }
};