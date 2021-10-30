/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        set<string> res;
        helper(n, 0, 0, "", res);
        vector<string> ans;
        for(auto s: res)
        {
            ans.push_back(s);
        }
        return ans;
    }
    
    void helper(int n, int left, int right, string curr, set<string> &res)
    {
        if(left==n && right==n)
        {
            res.insert(curr);
        }
        if(left>n || right>n)
        {
            return;
        }
        
        if(left<right)
        {
            return;
        }
        
        string temp = "";
        temp += curr + ')';
        helper(n, left, right+1, temp, res);
        temp = "";
        temp += curr + '(';
        helper(n, left+1, right, temp, res);
        
    }
};
