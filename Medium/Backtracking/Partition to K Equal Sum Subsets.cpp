/*
Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.
*/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> vis(n, false);
        
        int sum = 0;
        for(auto i: nums) sum+=i;
        
        if(sum%k!=0 || k>n) return false;
        if(k==1) return true;
        
        return backtrack(nums, k, sum/k, vis, 0, 0);
    }
    
    bool backtrack(vector<int> &nums, int k, int target, vector<bool> &vis, int sum, int idx)
    {
        if(k==0) return true;
        if(sum==target)
        {
            return backtrack(nums, k-1, target, vis, 0, 0);
        }
        
        for(int i=idx; i<nums.size(); i++)
        {
            if(!vis[i] && target>=sum+nums[i])
            {
                vis[i]=true;
                if(backtrack(nums, k, target, vis, sum+nums[i], i+1)) return true;
                vis[i]=false;
            }
        }
        
        return false;
    }
};
