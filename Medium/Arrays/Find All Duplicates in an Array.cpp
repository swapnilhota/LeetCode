/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i=0;
        while(i<nums.size())
        {
            if(nums[i]!=i+1)
            {
                if(nums[nums[i]-1]==nums[i])
                {
                    i++;
                }
                else
                {
                    swap(nums[i], nums[nums[i]-1]);
                }
            }
            else
            {
                i++;
            }
        }
        
        int j=0;
        
        i=0;
        
        while(i<nums.size())
        {
            if(i+1!=nums[i])
            {
                nums[j]=nums[i];
                j++;
            }
            i++;
        }
        
        nums.erase(nums.begin()+j, nums.end());
        
        return nums;
    }
};
