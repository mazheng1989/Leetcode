#include "stdafx.h"
#include<string>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
		size_t thousand_pos = s.find_first_of("M");
		size_t fiveHundrid_pos = s.find_first_of("D");
		size_t hundrid_pos = s.find_first_of("C");
		size_t fifty_pos = s.find_first_of("L");
		size_t ten_pos = s.find_first_of("X");
		size_t I_pos = s.find_first_of("I");
		size_t V_pos = s.find_first_of("V");
		return 0;
    }
};