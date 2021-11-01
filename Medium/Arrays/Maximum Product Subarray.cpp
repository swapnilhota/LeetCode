/*
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

It is guaranteed that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        
        int curr_max=1;
        int curr_min=1;
        
        for(int i=0; i<nums.size(); i++)
        {
            curr_max *= nums[i];
            curr_min *= nums[i];
            
            if(nums[i]<0)
            {
                swap(curr_max, curr_min);
            }
            
            res = max(res, curr_max);
            
            if(curr_max<=0)
            {
                curr_max = 1;
            }
            if(curr_min>1)
            {
                curr_min = 1;
            }
        }
        
        return res;
    }
};
