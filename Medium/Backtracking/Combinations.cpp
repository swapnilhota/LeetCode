/*
Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

You may return the answer in any order.
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        helper(1, n, k, tmp, res);
        return res;
    }
    
    void helper(int curr, int n, int k, vector<int> &tmp, vector<vector<int>> &res)
    {
        if(k==0)
        {
            res.push_back(tmp);
            return;
        }
        
        if(curr>n)
        {
            return;
        }
        
        helper(curr+1, n, k, tmp, res);
        tmp.push_back(curr);
        helper(curr+1, n, k-1, tmp, res);
        tmp.pop_back();
    }
};
