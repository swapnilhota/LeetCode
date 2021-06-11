/*
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.
*/

class Solution {
public:
    bool isHappy(int n) {
        map<int, int> mp;
        while(n!=1)
        {
            mp[n]++;
            string s = to_string(n);
            int tmp=0;
            for(char c: s)
            {
                tmp += (c-'0')*(c-'0');
            }
            n = tmp;
            if(mp[n]!=0)
            {
                return false;
            }
        }
        return true;
    }
};
