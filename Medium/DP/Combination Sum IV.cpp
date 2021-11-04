/*
Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The answer is guaranteed to fit in a 32-bit integer.
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> dp(target+1, -1);
        int ans = solve(nums, nums.size(), target, dp);
        return ans;
    }
    
    int solve(vector<int> &nums, int n, int target, vector<int> &dp)
    {
        if(target==0)
        {
            return 1;
        }
        if(dp[target]!=-1)
        {
            return dp[target];
        }
        int ans=0;
        for(int i=0; i<n; i++)
        {
            if(target>=nums[i])
            {
                ans += solve(nums, n, target-nums[i], dp);
            }
        }
        return dp[target] = ans;
    }
};
