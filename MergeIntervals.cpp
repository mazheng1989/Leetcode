#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;
// Definition for an interval.
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
 bool comp(const Interval &a, const Interval &b)
	{
		return a.start<b.start;
	}
class Solution {
public:
	
    vector<Interval> merge(vector<Interval> &intervals) {
		sort(intervals.begin(),intervals.end(),comp);
		vector<Interval> output;
		for(int i = 0;i<intervals.size();i++)
		{
			int startI = intervals[i].start, endI = intervals[i].end;
			while(i<intervals.size()-1&&intervals[i+1].start<=endI)
			{
				endI = intervals[++i].end;
			}
			Interval interTemp(startI, endI);
			output.push_back(interTemp);
		}
		return output;
    }
};