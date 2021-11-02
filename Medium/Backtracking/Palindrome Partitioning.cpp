/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        vector<vector<string>> res;
        helper(s, 0, 0, s.length(), tmp, res);
        return res;
    }
    
    bool check(string &s, int i, int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    void helper(string &s, int prev, int curr, int n, vector<string> tmp, vector<vector<string>> &res)
    {
        if(curr==n-1)
        {
            if(check(s, prev, curr))
            {
                tmp.push_back(s.substr(prev, curr-prev+1));
                res.push_back(tmp);
            }
            return;
        }
        if(curr>=n)
        {
            return;
        }
        
        if(check(s, prev, curr))
        {
            helper(s, prev, curr+1, n, tmp, res);
            string t = s.substr(prev, curr-prev+1);
            tmp.push_back(t);
            helper(s, curr+1, curr+1, n, tmp, res);
            tmp.pop_back();            
        }
        else
        {
            helper(s, prev, curr+1, n, tmp, res);
        }
    }
};
