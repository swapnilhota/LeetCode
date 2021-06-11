/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if(num==0)
        {
            return true;
        }
        if(num<0)
        {
            return false;
        }
        
        long long i=1LL;
        
        while(i*i < (long long)num)
        {
            i++;
        }
        
        if(i*i==(long long)num)
        {
            return true;
        }
        
        return false;
        
    }
};
