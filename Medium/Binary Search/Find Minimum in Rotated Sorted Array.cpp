/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int ans = solve(nums, left, right);
        return ans;
    }
    
    int solve(vector<int> &nums, int left, int right)
    {
        if(left>right)
        {
            return INT_MAX;
        }
        if(left==right)
        {
            return nums[left];
        }
        
        int mid = (right-left)/2+left;
        
        if(mid<nums.size()-1 && nums[mid+1]<nums[mid])
        {
            return nums[mid+1];
        }
        if(mid-1>=0 && nums[mid-1]>nums[mid])
        {
            return nums[mid];
        }
        
        return min(solve(nums, left, mid), solve(nums, mid+1, right));
    }
};
