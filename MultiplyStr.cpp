#include "stdafx.h"
#include <vector>
#include <queue>
#include <algorithm>    // std::reverse
#include <deque>
#include <stack>
#include <string>
#include "use_me.h"
#include <unordered_map>
using namespace std;
	void multiplyStrSimple(string &num1, char digit)
	{
		int increment = 0, temp=0, num2 = digit-'0';
		for(int i=num1.length()-1;i>=0;--i)
		{
			temp = (num1[i]-'0')*num2+increment;
			increment = temp/10;
			temp = temp%10;
			num1[i] = '0' + temp;
		}
		if(increment>0)
			num1.insert(0,1,increment+'0');
		while(num1.length()>1&&num1[0]=='0')
			num1.erase(0,1);
	}
	void sumStr(string &num1, string &num2)
	{
		int increment = 0, temp=0, n2 = 0;
		for(int i=num1.length()-1;i>=0;--i)
		{
			int index = num1.length()-1-i;
			if(index<=num2.length()-1)
				n2 = num2[num2.length()-1-index]-'0';
			else
				n2 = 0;
			temp = (num1[i]-'0')+n2+increment;
			increment = temp/10;
			temp = temp%10;
			num1[i] = '0' + temp;
		}
		if(num1.length()<num2.length())
			for(int i = num2.length()-num1.length()-1;i>=0;--i)
			{
				temp = num2[i]-'0'+increment;
				increment = temp/10;
				temp = temp%10;
				num1.insert(0,1,temp+'0');
			}
		if(increment>0)
			num1.insert(0,1,increment+'0');
	}
    string Solution::multiply(string num1, string num2) {
        string output="",m1,m2;
		int nChar1 = num1.length(), nChar2 = num2.length();
		if(nChar1==0||nChar2==0)
			return "0";
		if(nChar1<nChar2)
		{
			m1 = num2;
			m2 = num1;
		}
		else
		{
			m1 = num1;
			m2 = num2;
		}
		for(int i = m2.length()-1;i>=0;--i)
		{
			string tempStr = m1;
			multiplyStrSimple(tempStr, m2[i]);
			if(i<m2.length()-1)
			{
				tempStr.append(m2.length()-1-i,'0');
			}
			if(output.length()==0)
				output = tempStr;
			else
				sumStr(output, tempStr);
		}
		return output;
    }