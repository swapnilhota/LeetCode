/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i: nums) {
            sum+=i;
        }
        
        if(sum%2!=0) {
            return false;
        }
        
        bool dp[sum/2+1][nums.size()+1];
        for(int i=0; i<sum/2+1; i++)
        {
            for(int j=0; j<nums.size()+1; j++)
            {
                if(j==0)
                {
                    if(i==0)
                    {
                        dp[i][j]=true;
                    }
                    else
                    {
                        dp[i][j]=false;
                    }
                }
            }
        }
        
        for(int j=0; j<nums.size()+1; j++)
        {
            dp[0][j]=true;
        }
        
        for(int i=1; i<=sum/2; i++)
        {
            for(int j=1; j<=nums.size(); j++)
            {
                if(nums[j-1]<=i)
                {
                    dp[i][j] = dp[i-nums[j-1]][j-1] || dp[i][j-1];
                }
                else
                {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        
        return dp[sum/2][nums.size()];
    }
};
