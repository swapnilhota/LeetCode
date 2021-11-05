/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(1, 1, m, n);
        return ans;
    }
    int dp[102][102];
    int solve(int i, int j, int m, int n)
    {
        if(i==m && j==n)
        {
            return 1;
        }
        if(i>m || j>n)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int ans = 0;
        
        ans += solve(i+1, j, m, n);
        ans += solve(i, j+1, m, n);
        
        return dp[i][j] = ans;
    }
};
