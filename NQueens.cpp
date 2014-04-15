#include "stdafx.h"
#include <string>
#include <vector>
#include "use_me.h"
using namespace std;

vector<vector<string>> generateSol(vector<int> &colIndex, vector<bool> &colFlag, int indexRow, vector<string> &dict)
{
	vector<vector<string>> output;
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
					vector<string> tempV;
					tempV.push_back(dict[i]);
					output.push_back(tempV);
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
					vector<vector<string>> outputT = generateSol(colIndex,colFlag,indexRow+1,dict);
					for(int k=0;k<outputT.size();++k)
					{
						vector<string> tempV = outputT[k];
						tempV.insert(tempV.begin(),dict[i]);
						output.push_back(tempV);
					}
					colFlag[i]=false;
				}
			}
	}
	return output;
}
vector<vector<string> > Solution::solveNQueens(int n) {
	vector<int> colIndex;
	vector<bool> colFlag;
	vector<string> dict;
	dict.resize(n);
	colFlag.resize(n);
	colIndex.resize(n);
	std::fill_n(colFlag.begin(),n,false);
	vector<vector<string>> output;
	if(n==0)
		return output;
	for(int i=0;i<n;++i)
	{
		string tempStr(n,'.');
		tempStr[i] = 'Q';
		dict[i]=tempStr;
	}
	output = generateSol(colIndex, colFlag, 0, dict);
	return output;
}