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
	vector<string> fullJustify(vector<string> &words, int L) {
		//http://fisherlei.blogspot.com/2013/01/leetcode-text-justification.html
		vector<string> result;   
		if(0 == words.size()) return result;     
		int i =0;   
		while(i< words.size())   
		{   
			int start = i;   
			int sum = 0;   
			while(i<words.size() && sum + words[i].size()<=L)   
			{   
				sum+=words[i].size() +1;   
				i++;   
			}   
			int end = i-1;    
			int intervalCount = end - start;   
			int avgSp = 0, leftSp = 0;   
			if(intervalCount >0)   
			{   
				avgSp = (L-sum + intervalCount+1)/intervalCount;   
				leftSp = (L-sum + intervalCount+1)%intervalCount;   
			}      
			string line;      
			for(int j = start; j<end; j++)   
			{   
				line+=words[j];   
				if(i == words.size()) // the last line  
					line.append(1, ' ');   
				else   
				{   
					line.append(avgSp, ' '); //average space  
					if(leftSp>0) // the extra space  
					{   
						line.append(1, ' ');   
						leftSp--;   
					}   
				}   
			}   
			line+=words[end];   
			if(line.size()<L)   
				line.append(L-line.size(), ' ');   
			result.push_back(line);      
		}   
		return result;   
	}
};