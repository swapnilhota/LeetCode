/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1];
        memset(dp, -1, sizeof(dp));
        return solve(n, dp);
    }
    
    int solve(int n, int* dp)
    {
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        if(n==1)
        {
            return 1;
        }
        if(n==2)
        {
            return 2;
        }
        dp[n] = solve(n-1, dp) + solve(n-2, dp);
        return dp[n];
    }
};
