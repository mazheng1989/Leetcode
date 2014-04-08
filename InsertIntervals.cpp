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
bool comp1(const Interval &a, const Interval &b)
{
	return a.start<b.start;
}
class Solution {
public:
	bool intersect(const Interval &a, const Interval &b)
	{
		if(a.start>b.end||a.end<b.start)
			return false;
		return true;
	}
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		sort(intervals.begin(),intervals.end(),comp1);
		int startI = intervals.size(), endI = -1;
		for(int i = 0;i<intervals.size();++i)
		{
			if(intervals[i].start>newInterval.end)
			{
			    startI = i;
				break;
			}
			if(intervals[i].end<newInterval.start)
				continue;
			startI = i;
			endI = i;
			newInterval.start = (newInterval.start<intervals[i].start)?newInterval.start:intervals[i].start;
			newInterval.end = (newInterval.end>intervals[i].end)?newInterval.end:intervals[i].end;
			while(i<intervals.size()-1&&intersect(intervals[i+1],newInterval))
			{
				i++;
				endI = i;
				newInterval.end = (newInterval.end>intervals[i].end)?newInterval.end:intervals[i].end;
			}
			break;
		}
		if(endI==-1)
		{
			intervals.insert(intervals.begin()+startI,newInterval);
		}
		else
		{
			intervals.erase(intervals.begin()+startI,intervals.begin()+endI+1);
			intervals.insert(intervals.begin()+startI,newInterval);
		}
		return intervals;
	}
};