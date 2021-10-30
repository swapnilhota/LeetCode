/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> res;
        int n = candidates.size();
        vector<int> tmp;
        solve(candidates, n, target, tmp, res);
        vector<vector<int>> ans;
        for(auto i: res)
        {
            ans.push_back(i);
        }
        return ans;
    }
    
    void solve(vector<int> &candidates, int n, int target, vector<int> &tmp, set<vector<int>> &res)
    {
        if(target==0)
        {
            res.insert(tmp);
            return;
        }
        if(n==0)
        {
            return;
        }
        
        if(candidates[n-1]<=target)
        {
            solve(candidates, n-1, target, tmp, res);
            tmp.push_back(candidates[n-1]);
            solve(candidates, n, target-candidates[n-1], tmp, res);
            tmp.pop_back();
        }
        else
        {
            solve(candidates, n-1, target, tmp, res);
        }
    }
};
