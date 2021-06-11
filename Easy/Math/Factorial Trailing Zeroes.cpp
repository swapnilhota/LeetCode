/*
Given an integer n, return the number of trailing zeroes in n!
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int div=5;
        int ans = 0;
        while(div<=n)
        {
            ans += n/div;
            div *= 5;
        }
        return ans;
    }
};
