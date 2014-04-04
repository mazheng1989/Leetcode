#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>
using namespace std;
class Solution {
public:
    string convert(string s, int nRows) {
        int period = 0;
		if(nRows==1)
			period=1;
		else
			period = nRows+nRows-2;
		string output;
		for(int i=0;i<s.length();i+=period)
			output+=(s.at(i));
		for(int i=1;i<nRows-1;++i)
		{
			for(int j=i;j<s.length();j+=period)
			{
				output+=(s.at(j));
				if((j+period-(i*2))<s.length())
					output+=(s.at(j+period-(i*2)));
			}
		}
		if(nRows>1)
		for(int i=nRows-1;i<s.length();i+=period)
			output+=(s.at(i));
		return output;
    }
};