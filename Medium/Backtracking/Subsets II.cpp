/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
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
            if(curr.size()>1) sort(curr.begin(), curr.end());
            res.insert(curr);
            return;
        }
        
        helper(nums, n-1, curr, res);
        curr.push_back(nums[n-1]);
        helper(nums, n-1, curr, res);
    }
};
