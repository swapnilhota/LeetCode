/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=0;
        int sum=0;
        
        int ans = INT_MAX;
        
        while(j<n)
        {
            sum += nums[j];
            if(sum >= target)
            {
                ans = min(ans, j-i+1);
                
                while(i<j)
                {
                    sum -= nums[i];
                    i++;
                    if(sum>=target)
                    {
                        ans = min(ans, j-i+1);
                    }
                    else
                    {
                        break;
                    }
                }
            }
            j++;
        }
        while(i<n)
        {
            sum -= nums[i];
            i++;
            if(sum>=target)
            {
                ans = min(ans, j-i+1);
            }
            else
            {
                break;
            }
        }
        
        if(ans==INT_MAX)
        {
            ans = 0;
        }
        
        return ans;
    }
};
