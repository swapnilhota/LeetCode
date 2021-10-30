/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>> res;
        vector<int> temp;
        helper(n, k, 1, temp, res);
        vector<vector<int>> ans;
        for(auto i: res)
        {
            ans.push_back(i);
        }
        return ans;
    }
    
    void helper(int target, int k, int curr, vector<int> &temp, set<vector<int>> &res)
    {
        if(target==0 && k==0)
        {
            res.insert(temp);
            return;
        }
        if(k==0 || curr>target || curr>9)
        {
            return;
        }
        
        temp.push_back(curr);
        helper(target-curr, k-1, curr+1, temp, res);
        temp.pop_back();
        helper(target, k, curr+1, temp, res);
    }
};
