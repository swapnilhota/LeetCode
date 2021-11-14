/*
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.
*/

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = helper(nums, k) - helper(nums, k-1);
        return ans;
    }
    
    int helper(vector<int> &nums, int k)
    {
        map<int, int> mp;
        int i=0;
        int j=0;
        int n=nums.size();
        int ans=0;
        while(j<n)
        {
            mp[nums[j]]++;
            if(mp.size()>k)
            {
                while(mp.size()>k)
                {
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0)
                    {
                        mp.erase(mp.find(nums[i]));
                    }
                    i++;
                }
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }
};
