#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>
#include <string> // this should be already included in <sstream>
using namespace std;
class Solution {
public:
    int removeDuplicates(int A[], int n) {
		unordered_map<int,int> countMap;
		int ArrayLength = n, tempI=0;
		for(int i=0;i<ArrayLength;++i)
		{
			if(countMap.find(A[i])==countMap.end())
			{
				countMap[A[i]] = 1;
			}
			else if(countMap[A[i]]==1)
			{
				countMap[A[i]]=2;
			}
			else
			{
				tempI = A[i];
				for(int j=i;j<ArrayLength-1;++j)
				A[j] = A[j+1];
				A[ArrayLength-1] = tempI;
				ArrayLength--;
				i--;
			}
		}
		return ArrayLength;
    }
};