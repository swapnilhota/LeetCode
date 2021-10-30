/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> res;
        int n = nums.size();
        vector<int> tmp;
        helper(nums, n, tmp, res);
        vector<vector<int>> ans;
        for(auto v: res)
        {
            ans.push_back(v);
        }
        return ans;
    }
    
    void helper(vector<int> &nums, int n, vector<int> curr, set<vector<int>> &res)
    {
        if(n==0)
        {
            res.insert(curr);
            return;
        }
        
        helper(nums, n-1, curr, res);
        curr.push_back(nums[n-1]);
        helper(nums, n-1, curr, res);
    }
};
