#include "stdafx.h"
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int i = 0, j = 0, mid = 0;
        if(matrix[0][0]>target)
        return false;
        
        i = 0,j=matrix.size()-1;
        while(i<=j)
        {
            mid = (i+j)/2;
            if(matrix[mid][0]==target)
            return true;
            if(matrix[mid][0]>target)
            {
                j = mid-1;
            }
            if(matrix[mid][0]<target)
            {
                i = mid+1;
            }
        }
        int row = (i<j)?i:j;
        if(row<0)
        return false;
        
        
        i = 0;j = matrix[0].size()-1;
        while(i<=j)
        {
            mid = (i+j)/2;
            if(matrix[row][mid]==target)
            return true;
            if(matrix[row][mid]>target)
            {
                j = mid-1;
            }
            if(matrix[row][mid]<target)
            {
                i = mid+1;
            }
        }
        return false;
    }
};