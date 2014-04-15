#include "stdafx.h"
#include <string>
using namespace std;
class Solution {
public:
	void appendDigit(string &result, int num)
	{
		switch(num)
		{
		case 1:
			result.append("I");
			break;
		case 4:
			result.append("IV");
			break;
		case 5:
			result.append("V");
			break;
		case 9:
			result.append("IX");
			break;
		case 10:
			result.append("X");
			break;
		case 40:
			result.append("XL");
			break;
		case 50:
			result.append("L");
			break;
		case 90:
			result.append("XC");
			break;
		case 100:
			result.append("C");
			break;
		case 400:
			result.append("CD");
			break;
		case 500:
			result.append("D");
			break;
		case 900:
			result.append("CM");
			break;
		case 1000:
			result.append("M");
			break;
		default:
			break;
		}
	}
    string intToRoman(int num) {
		int dict[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
		string output = "";
		int index = 0;
		while(num>0&&index<13)
		{
			if(num>=dict[index])
			{
				appendDigit(output,dict[index]);
				num-=dict[index];
			}
			else
			{
				index++;
			}
		}
		return output;
    }
};