#include "stdafx.h"
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int length = 0,lastLength = 0;
        while(*s!='\0')
        {
            if(*s==' ')
            {
                if(length>0)
                lastLength = length;
                length=0;
            }
            else
            length++;
            s++;
        }
        if(length>0)
        lastLength = length;
        return lastLength;
    }
};