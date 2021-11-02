/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return helper(nums, 0);
    }
    static const int N = 1e4+2;
    int dp[N];
    bool helper(vector<int> &nums, int idx)
    {
        if(idx==nums.size()-1)
        {
            return true;
        }
        if(idx>=nums.size())
        {
            return false;
        }
        if(dp[idx]!=-1)
        {
            return dp[idx];
        }
        
        for(int i=1; i<=nums[idx]; i++)
        {
            if(helper(nums, idx+i))
            {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
};
