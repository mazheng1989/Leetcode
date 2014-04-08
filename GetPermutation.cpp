#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int factorial(int n)
	{
		if(n<=1)
			return 1;
		return factorial(n-1)*n;
	}
	void generatePerm(vector<char> &dictionary, string &result, int k)
	{
		int nChar = dictionary.size();
		if(nChar==1)
		{
			result.append(1,dictionary[0]);
			return;
		}
		int permN = factorial(nChar-1);
		int indexC = (k-1)/permN;
		result.append(1,dictionary[indexC]);
		dictionary.erase(dictionary.begin()+indexC,dictionary.begin()+indexC+1);
		generatePerm(dictionary,result,(k-1)%permN+1);
	}
    string getPermutation(int n, int k) {
        vector<char> dictionary;
		for(int i=1;i<=n;++i)
			dictionary.push_back('0'+i);
		string result="";
		generatePerm(dictionary, result, k);
		return result;
    }
};