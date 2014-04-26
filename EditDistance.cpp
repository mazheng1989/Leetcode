#include "stdafx.h"
#include <vector>
#include <queue>
#include <algorithm>    // std::reverse
#include <deque>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
		int nChar1 = word1.length(), nChar2 = word2.length();
		if(!nChar1)
			return nChar2;
		if(!nChar2)
			return nChar1;
		int **result = new int*[nChar1+1];
		for(int i=0;i<=nChar1;++i)
			result[i] = new int[nChar2+1];
		for(int i=0;i<=nChar1;++i)
			result[i][0] = i;
		for(int i=0;i<=nChar2;++i)
			result[0][i] = i;
		for(int i=1;i<=nChar1;++i)
			for(int j=1;j<=nChar2;++j)
			{
				if(word1[i-1]==word2[j-1])
				{
					result[i][j] = result[i-1][j-1];
				}
				else
				{
					int temp = result[i-1][j-1];
					temp = result[i-1][j]<temp?result[i-1][j]:temp;
					temp = result[i][j-1]<temp?result[i][j-1]:temp;
					result[i][j] = temp+1;
				}
			}
		return result[nChar1][nChar2];
    }
};