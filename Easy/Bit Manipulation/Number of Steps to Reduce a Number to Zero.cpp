/*
Given an integer num, return the number of steps to reduce it to zero.

In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.
*/

class Solution {
public:
    int numberOfSteps(int num) {
        int cnt=0;
        while(num!=0)
        {
            while(num%2==0)
            {
                num /= 2;
                cnt++;
            }
            num--;
            cnt++;
        }
        return cnt;        
    }
};
