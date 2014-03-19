#include "stdafx.h"
#include <unordered_map>
using namespace std;
class Solution {
public:
    int singleNumber(int A[], int n) {
		unordered_map<int,int> map;
		int output = 0;
		for(int i = 0;i<n;++i)
		{
			if(map.find(A[i])==map.end())
			{
				map[A[i]] = 1;
			}
			else
			{
				++map[A[i]];
			}
		}
		for(unordered_map<int,int>::iterator it=map.begin();
			it!=map.end();++it)
		{
			if(it->second!=3)
			{
				output = it->first;
				break;
			}
		}
		return output;
    }
};