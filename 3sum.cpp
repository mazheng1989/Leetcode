#include "stdafx.h"
#include <vector>
#include <algorithm>    // std::sort
using namespace std;
class Solution {
public:

	/**
	* Main function of the algorithm
	* 
	**/
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > *output = new vector<vector<int> >();
		//if less than 3 elements, output empty vector
		if(num.size()<=2)
			return *output;
		// sort the vector
		sort(num.begin(),num.end());
		// two iterators to search from begin and end
		vector<int>::iterator firstIt = num.begin();
		vector<int>::iterator thirdIt = num.end();
		vector<int>::iterator secondIt = firstIt+1;
		
		int sum = 0;
		for (;firstIt<(num.end() - 2);)
		{
			secondIt = firstIt+1;
			thirdIt = num.end()-1;
			while(thirdIt>secondIt) {
				sum = *firstIt+*secondIt+*thirdIt;
				if(sum>0){
					thirdIt--;
				}
				else if(sum<0)
				{
					secondIt++;
				}
				else
				{
					vector<int> *temp = new vector<int>(3);
					(*temp)[0] = *firstIt;
					(*temp)[1] = *secondIt;
					(*temp)[2] = *thirdIt;
					output->push_back(*temp);
					while((secondIt+1)!= num.end()&&*secondIt == *(secondIt+1))
					{
						++secondIt;
					}
					if((secondIt+1)!= num.end())
						++secondIt;
					while((thirdIt-1)!= num.begin()&&*thirdIt == *(thirdIt-1))
					{
						--thirdIt;
					}
					if((thirdIt-1)!= num.begin())
						--thirdIt;
				}
			}
			while((firstIt+1)!=num.end()&&*firstIt == *(firstIt+1))
			{
				++firstIt;
			}
			++firstIt;
		}
		return *output;
	}
};