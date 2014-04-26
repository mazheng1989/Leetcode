class Solution {
public:
	bool isNumber(const char *s) {
		int ePos = -1, pPos = -1, start = 0, start2 = -1, end = 0;
		int index = 0;
		while(s[start]==' ')
			start++;
		if(s[start]=='-'||s[start]=='+')
			start++;
		index = start;
		while(s[index]&&s[index]!=' ')
		{
			if(! ((s[index]>='0'&&s[index]<='9')||s[index]=='e'||s[index]=='.'||s[index]==' '))
				return false;
			if(s[index]=='e')
				if(ePos==-1)
				{
					ePos = index;
					index++;
					if(!s[index])
					{
						start2 = index+1;
						break;
					}
					if(s[index]=='+'||s[index]=='-')
					{
						index++;
					}
					start2 = index;
					continue;
				}
				else
					return false;
			if(s[index] == '.')
				if(pPos==-1)
				{
					pPos = index;
					index++;
					continue;
				}
				else
					return false;
			index++;
		}
		end = index-1;
		if(s[index])
			while(s[index])
			{
				if(s[index]!=' ')
					return false;
				index++;
			}
			if(ePos!=-1&&ePos<pPos)
				return false;
			if(pPos!=-1&&(ePos-start==1||end==start))
				return false;
			if(ePos==start||ePos==end||start>end||start2>end)
				return false;
			return true;
	}
};