/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int, vector<int>> mp;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]].push_back(i);
        }
        
        vector<int> ans;
        
        for(auto i:nums)
        {
            if(mp[target-i].size()>0)
            {
                if(target-i == i)
                {
                    if(mp[target-i].size()>1)
                    {
                        ans.push_back(mp[target-i][0]);
                        ans.push_back(mp[target-i][1]);
                        return ans;
                    }
                }
                else
                {
                    ans.push_back(mp[i][0]);
                    ans.push_back(mp[target-i][0]);
                    return ans;
                }
            }
        }
        
        return ans;
    }
    
};
