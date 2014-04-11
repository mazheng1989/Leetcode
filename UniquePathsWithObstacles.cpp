#include "stdafx.h"
#include <unordered_set>
#include <string>
#include "use_solution.h"
#include <iostream>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        vector<vector<int>> result;
		int nRow = obstacleGrid.size();
		result.resize(nRow);
		if(nRow==0||obstacleGrid[0][0]==1)
			return 0;
		int nCol = obstacleGrid[0].size();
		result[0].resize(nCol);
		result[0][0] = 1;
		for(int i=1;i<nRow;++i)
		{
			result[i].resize(nCol);
			if(!obstacleGrid[i][0]&&result[i-1][0])
				result[i][0] = 1;
			else
				result[i][0] = 0;
		}
		for(int i=1;i<nCol;++i)
		{
			if(!obstacleGrid[0][i]&&result[0][i-1])
				result[0][i] = 1;
			else
				result[0][i] = 0;
		}
		for(int i=1;i<nRow;++i)
			for(int j=1;j<nCol;++j)
			{
			    if(obstacleGrid[i][j])
			    result[i][j] = 0;
			    else
			    result[i][j] = result[i-1][j]+result[i][j-1];
			}
		return result[nRow-1][nCol-1];
    }
};