/*
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n<=0)
        {
            return false;
        }
        
        int cnt=0;
        
        for(int i=0; i<=31; i++)
        {
            if((n&(1<<i))>0)
            {
                cnt++;
            }
            if(cnt>1)
            {
                return false;
            }
        }
        
        if(cnt>1)
        {
            return false;
        }
        
        return true;
        
    }
};
