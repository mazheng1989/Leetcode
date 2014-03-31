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
bool isPalindrome(string &s,unordered_map<std::string,bool> &palindromes){            
		if(palindromes.find(s)!=palindromes.end())
			return (palindromes.at(s));
		int m=0;int n=s.length()-1;
		while(m<n){
			if(s.at(m++)!=s.at(n--)){
				std::pair<std::string,bool> tempPair(s,false);
				palindromes.insert(tempPair);
				return false;
			}
		}
		std::pair<std::string,bool> tempPair(s,true);
		palindromes.insert(tempPair);
		return true;
	}
vector<vector<string>> partitionSub(string &s, unordered_map<std::string,bool> &palindromes, unordered_map<std::string,vector<vector<std::string>>> &dict){
		if(dict.find(s)!=dict.end())
			return dict.at(s);

		vector<vector<string>> res;
		if(s.length()==0)
			return res; 
		else
		{
			for(int i=1;i<=(s.length()-1);i++){
				string start = s.substr(0,i);
				if(isPalindrome(start,palindromes)){
				    string tailStr = s.substr(i,s.length()-i);
					vector<vector<string>> restPart = partitionSub(tailStr,palindromes,dict);
					for(vector<string> onePart : restPart){
						onePart.insert(onePart.begin(),start);
						res.push_back(onePart);
					}
				}
			}
			if(isPalindrome(s,palindromes))
			{
				vector<string> tempV;
				tempV.push_back(s);
				res.push_back(tempV);
			}
		}
		std::pair<string,vector<vector<string>>> tempPair(s,res);
		dict.insert(tempPair);
		return res;
	}
	
	vector<vector<string>> Solution::partition(string s) {
		vector<vector<string>> output;
		if(s.length()==0)
		{
			vector<string> tempV;
			tempV.push_back("");
			output.push_back(tempV);
			return output;
		}
	    unordered_map<std::string,bool> palindromes;
        unordered_map<std::string,vector<vector<std::string>>> dict;
		return partitionSub(s,palindromes,dict);
	}
	