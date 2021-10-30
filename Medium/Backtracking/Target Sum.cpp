/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int cnt=0;
        helper(nums, nums.size(), target, cnt);
        return cnt;
    }
    
    void helper(vector<int> &nums, int n, int target, int &cnt)
    {
        if(target==0 && n==0)
        {
            cnt++;
            return;
        }
        if(n==0)
        {
            return;
        }
        
        helper(nums, n-1, target-nums[n-1], cnt);
        helper(nums, n-1, target+nums[n-1], cnt);
    }
};
