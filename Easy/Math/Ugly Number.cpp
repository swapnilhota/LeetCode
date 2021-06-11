/*
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return true if n is an ugly number.
*/

class Solution {
public:
    bool isUgly(int num) {
        
        if(num<1)
        {
            return false;
        }
        
        vector<int> primes = {2, 3, 5};
        int i=0;
        while(num && i<3)
        {
            if(num%primes[i]!=0)
            {
                i++;
            }
            else
            {
                num = num/primes[i];
            }
        }
        
        if(num>1)
        {
            return false;
        }
        
        return true;
        
    }
};
