#include "stdafx.h"
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
	bool isMatch(const char *s, const char *p)   
    {  
		// idea from :http://blog.csdn.net/kenden23/article/details/17123497
        int sn = strlen(s);  
        int pn = strlen(p);  
        for (int i = 0, c = 0; i < pn; i++)  
        {  
            if (p[i] != '*') c++;  
            if (c > sn) return false;  
        }  
        vector<vector<bool> > tbl(2, vector<bool>(sn+1));  
        tbl[0][0] = true;  
        bool idx = true;  
        bool finished = false;  
        for (int i = 0; i < pn && !finished; i++)  
        {  
            if (p[i] == '*')  
            {  
                while (i < pn && p[i] == '*') i++;  
                i--;  
            }  
            finished = true;  
            if (p[i] == '*')  
            {  
                int j = 0;  
                for (; j < sn && !tbl[!idx][j]; j++) tbl[idx][j] = false;  
                if (j <= sn) finished = false;  
                for (; j <= sn; j++) tbl[idx][j] = true;  
            }  
            else  
            {  
                tbl[idx][0] = false;  
                int j = 0;  
                for ( ; j < sn; j++)  
                {  
                    if (s[j] == p[i] || p[i] == '?')   
                        tbl[idx][j+1] = tbl[!idx][j];  
                    else tbl[idx][j+1] = false;  
                    if (tbl[idx][j+1]) finished = false;  
                }  
            }  
            idx = !idx;  
        }  
        return finished? false : tbl[!idx][sn];  
    }  
};