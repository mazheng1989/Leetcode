#include "stdafx.h"
#include <string>
#include <vector>
using namespace std;

class Solution {
public:

	int generateSol(vector<int> &colIndex, vector<bool> &colFlag, int indexRow)
	{
		int output = 0;
		int n = colIndex.size();
		if(indexRow==n-1)
		{
			for(int i=0;i<n;++i)
				if(!colFlag[i])
				{
					int j=0;
					for(;j<indexRow;++j)
						if(abs(colIndex[j]-i)==abs(j-indexRow))
							break;
					if(j==indexRow)
					{
						colFlag[i] = true;
						colIndex[indexRow] = i;
						output++;
						colFlag[i]=false;
					}

				}
		}
		else
		{
			for(int i=0;i<n;++i)
				if(!colFlag[i])
				{
					int j=0;
					for(;j<indexRow;++j)
						if(abs(colIndex[j]-i)==abs(j-indexRow))
							break;
					if(j==indexRow)
					{
						colFlag[i] = true;
						colIndex[indexRow] = i;
						output+= generateSol(colIndex,colFlag,indexRow+1);
						colFlag[i]=false;
					}
				}
		}
		return output;
	}
	int totalNQueens(int n) {
		vector<int> colIndex;
		vector<bool> colFlag;
		vector<string> dict;
		dict.resize(n);
		colFlag.resize(n);
		colIndex.resize(n);
		std::fill_n(colFlag.begin(),n,false);
		int output = 0;
		if(n==0)
			return output;
		output = generateSol(colIndex, colFlag, 0);
		return output;
	}
};