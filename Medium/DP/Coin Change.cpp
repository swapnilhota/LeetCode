/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
Example 4:

Input: coins = [1], amount = 1
Output: 1
Example 5:

Input: coins = [1], amount = 2
Output: 2
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<long>> dp(n+1, vector<long>(amount+1, -1));
        int ans = helper(coins, n, amount, dp);
        if(ans>=INT_MAX)
        {
            return -1;
        }
        return ans;
    }
    
    int helper(vector<int> &coins, int n, int amount, vector<vector<long>> &dp)
    {
        if(n==0)
        {
            if(amount==0)
            {
                return 0;
            }
            
            return INT_MAX;
        }
        if(dp[n][amount]!=-1)
        {
            return dp[n][amount];
        }
        
        if(coins[n-1]<=amount)
        {
            long a1 = 1L + helper(coins, n, amount-coins[n-1], dp);
            long a2 = helper(coins, n-1, amount, dp);
            return dp[n][amount] = min(a1, a2);
        }
        else
        {
            return dp[n][amount] = helper(coins, n-1, amount, dp);
        }
    }
};
