/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> pref(n);
        vector<int> suff(n);
        if(n==1)
        {
            return nums;
        }
        
        pref[0] = nums[0];
        
        for(int i=1; i<n; i++)
        {
            pref[i] = nums[i]*pref[i-1];
        }
        
        suff[n-1] = nums[n-1];
        
        for(int i=n-2; i>=0; i--)
        {
            suff[i] = nums[i]*suff[i+1];
        }
        
        vector<int> ans;
        
        for(int i=0; i<n; i++)
        {
            if(i==0)
            {
                ans.push_back(suff[i+1]);
            }
            else if(i==n-1)
            {
                ans.push_back(pref[i-1]);
            }
            else
            {
                ans.push_back(pref[i-1]*suff[i+1]);
            }
        }
        
        return ans;
    }
};
