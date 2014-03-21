#include "stdafx.h"
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
		int temp = 0;
		int boundaryI =0,boundaryJ = 0; 
		if(n%2==0)
		{
		    boundaryI = (n-1)/2;
		    boundaryJ = (n-1)/2;
		}
		else
		{
		    boundaryI = (n-1)/2;
		    boundaryJ = (n-1)/2-1;
		}
		for(int i= 0;i<=boundaryI;++i)
			for(int j = 0;j<=boundaryJ;++j)
			{
				temp = matrix[i][j];
				matrix[i][j] = matrix[n-1-j][i];
				matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
				matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
				matrix[j][n-1-i] = temp;
			}
    }
};