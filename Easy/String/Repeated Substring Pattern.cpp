/*
Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        for(int i=2; i<=s.length(); i++)
        {
            if(s.length()%i!=0)
            {
                continue;
            }
            int subLen = s.length()/i;
            string tmp = s.substr(0, subLen);
            int flag=0;
            for(int j=subLen; j<s.length(); j += subLen)
            {
                if(s.substr(j, subLen)!=tmp)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                return true;
            }
        }
        
        return false;
    }
};
