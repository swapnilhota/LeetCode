/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int sum=0;
        
        for(auto i: nums)
        {
            sum += i;
        }
        
        int n = nums.size();
        
        return (n*(n+1)/2 - sum);
        
    }
};
