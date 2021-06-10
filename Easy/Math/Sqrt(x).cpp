/*
Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.
*/

class Solution {
public:
    int mySqrt(int x) {
        
        long long n = (long long)x;
        long long ans = 1LL;
        
        while(ans*ans<n)
        {
            ans++;
        }
        
        if(ans*ans > n)
        {
            return ans-1;
        }
        
        return ans;
        
    }
};
