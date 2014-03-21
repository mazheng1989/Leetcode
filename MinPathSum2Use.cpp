#include "stdafx.h"
#include "use_me.h"
#include <vector>
using namespace std;
int Solution::minPathSum(vector<vector<int> > &grid) {
		int m = grid.size();
		if(m<=0)
			return 0;
		int n = grid[0].size();

		int **dynamicArray = 0;

		//memory allocated for elements of rows.

		

		dynamicArray = new int *[m] ;

		//memory allocated for  elements of each column.


		for( int i = 0 ; i < m ; i++ )
		{
			dynamicArray[i] = new int[n];
			for(int j = 0;j<n;j++)
			dynamicArray[i][j] = 0;
		}
		dynamicArray[0][0] = grid[0][0];
		int i=0,j=0;
		for(i = 1;i<m;++i)
			dynamicArray[i][0] = (dynamicArray[i-1][0]+grid[i][0]);
		for(i = 1;i<n;++i)
			dynamicArray[0][i] = (dynamicArray[0][i-1]+grid[0][i]);
		for(i=1;i<m;++i)
			for(j=1;j<n;++j)
			{
				dynamicArray[i][j]+= (dynamicArray[i][j-1]<dynamicArray[i-1][j])?
					(dynamicArray[i][j-1]+grid[i][j]):(dynamicArray[i-1][j]+grid[i][j]);
			}
		//free the allocated memory

		int output = dynamicArray[m-1][n-1];
		for( int i = 0 ; i < m ; i++ )
			delete [] dynamicArray[i] ;
		delete [] dynamicArray ;
		return output;
	}
