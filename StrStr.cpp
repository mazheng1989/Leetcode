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
    char *strStr(char *haystack, char *needle) {
        char *h1 = haystack, *h2 = needle;
		if(!*h2)
			return h1;
		char *scan1 = h1, *scan2 = h2;
		int nH=0, nN=0;
		while(*scan1)
		{
			scan1++;
			nH++;
		}
		while(*scan2)
		{
			scan2++;
			nN++;
		}
		int threshold = nH-nN;
		h1 = haystack;h2 = needle;
		while(threshold>=0)
		{
			scan1 = h1;
			scan2 = h2;
			while(*scan1&&*scan2&&*scan1==*scan2)
			{
				scan1++;
				scan2++;
			}
			if(!*scan2)
				return h1;
			h1++;
			threshold--;
		}
		return NULL;
    }
};