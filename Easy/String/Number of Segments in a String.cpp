/*
You are given a string s, return the number of segments in the string. 

A segment is defined to be a contiguous sequence of non-space characters.
*/

class Solution {
public:
    int countSegments(string s) {
        int ans = 0;
        string tmp="";
        
        for(auto c: s)
        {
            if(c==' ')
            {
                if(tmp!="")
                {
                    ans++;
                    tmp="";
                }
            }
            else
            {
                tmp += c;
            }
        }
        
        if(tmp!="")
        {
            ans++;
        }
        
        return ans;
    }
};
