#include "stdafx.h"
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
		vector<vector<int> > output;
		if(numRows==0)
			return output;
		if(numRows==1)
		{
			vector<int> temp;
			temp.push_back(1);
			output.push_back(temp);
			return output;
		}
		output = generate(numRows-1);
		vector<int> preLevel = output[output.size()-1];
		vector<int> currentLevel;
		currentLevel.push_back(1);
		for(int i = 0;i<preLevel.size()-1;++i)
		{
			currentLevel.push_back(preLevel[i]+preLevel[i+1]);
		}
		currentLevel.push_back(1);
		output.push_back(currentLevel);
		return output;
    }
};