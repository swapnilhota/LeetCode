/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, vector<char>> mp;
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};
        
        vector<string> res;
        
        if(digits=="")
        {
            return res;
        }
        
        
        string temp="";
        solve(digits, 0, temp, res, mp);
        return res;
    }
    
    void solve(string &digits, int idx, string temp, vector<string> &res, map<char, vector<char>> &mp)
    {
        if(idx==digits.length())
        {
            res.push_back(temp);
            return;
        }
        
        for(auto c: mp[digits[idx]])
        {
            string next="";
            next += temp+c;
            solve(digits, idx+1, next, res, mp);
        }
    }
};
