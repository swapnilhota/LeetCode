/*
Given a string s, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any order.
*/

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        set<string> res;
        string temp="";
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        helper(s, s.length(), temp, res);
        vector<string> ans;
        for(auto i: res)
        {
            ans.push_back(i);
        }
        return ans;
    }
    
    void helper(string &s, int n, string curr, set<string> &res)
    {
        if(n==0)
        {
            res.insert(curr);
            return;
        }
        
        string a = s[n-1]+curr;
        char c = toupper(s[n-1]);
        string b = c+curr;
        helper(s, n-1, a, res);
        helper(s, n-1, b, res);
    }
};
