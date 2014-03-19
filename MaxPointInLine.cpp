#include "stdafx.h"
#include <vector>
#include <unordered_map>
using namespace std;

//  Definition for a point.
  struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
 };
 
class Solution {
public:
    int maxPoints(vector<Point> &points) {     
		unordered_map<float,int> slop;
		vector<Point>::iterator it1,it2;
		int output=0;
		float slopT = 0.0;
		int slopInf = 0;
		int maxPoints=0;
		int samePoint =1;
		for(it1=points.begin();it1!=points.end();++it1)
		{
			slopInf = 1;
			slop.clear();
			maxPoints = 1;
			samePoint =0;
			for(it2 = (it1+1);it2!=points.end();++it2)
			{
			    if(it1->x==it2->x&&it1->y==it2->y)
				{
					samePoint++;
					continue;
				}
				if(it1->x==it2->x)
				{
					slopInf++;
					continue;
				}
				slopT = ((float)(it1->y-it2->y))/((float)(it1->x-it2->x));
				if(slop.find(slopT)==slop.end())
				{
					slop[slopT] = 2;
					if(slop[slopT]>maxPoints)
						maxPoints = slop[slopT];
				}
				else
				{
					slop[slopT]++;
					if(slop[slopT]>maxPoints)
						maxPoints = slop[slopT];
				}
			}
			maxPoints+=samePoint;
		    slopInf+=samePoint;
			if(maxPoints>output)
				output = maxPoints;
			if(slopInf>output)
				output = slopInf;
		}
		return output;
    }
};