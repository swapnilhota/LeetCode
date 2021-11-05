/*
A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

You must write an algorithm that runs in O(log n) time.
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ans = solve(nums, 0, nums.size()-1);
        return ans;
    }
    int solve(vector<int> &nums, int left, int right)
    {
        if(left>right)
        {
            return -1;
        }
        
        int mid = (right-left)/2+left;
        
        int l = INT_MIN;
        if(mid-1 >=0 ) l = nums[mid-1];
        int r = INT_MIN;
        if(mid+1 < nums.size()) r=nums[mid+1];
        
        if(nums[mid]>=l && nums[mid]>=r)
        {
            return mid;
        }
        
        return max(solve(nums, left, mid-1), solve(nums, mid+1, right));
    }
};
