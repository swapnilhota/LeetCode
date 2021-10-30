/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        set<vector<int>> res;
        vector<int> tmp;
        int n = arr.size();
        helper(arr, n, 0, target, tmp, res);
        vector<vector<int>> ans;
        for(auto i: res)
        {
            ans.push_back(i);
        }
        return ans;
    }
    
    void helper(vector<int> &arr, int n, int idx, int target, vector<int> &tmp, set<vector<int>> &res)
    {
        if(target==0)
        {
            sort(tmp.begin(), tmp.end());
            res.insert(tmp);
            return;
        }
        else if(idx<n)
        {
            for(int i=idx; i<n; i++)
            {
                if((i==idx || arr[i]!=arr[i-1]) && arr[i]<=target)
                {
                    tmp.push_back(arr[i]);
                    helper(arr, n, i+1, target-arr[i], tmp, res);
                    tmp.pop_back();
                }
            }
        }
    }
};
