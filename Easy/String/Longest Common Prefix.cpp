/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans="";
        
        for(int i=1; i<=strs[0].length(); i++)
        {
            string pref = strs[0].substr(0, i);
            for(int j=1; j<strs.size(); j++)
            {
                if(strs[j].substr(0, i)!=pref)
                {
                    return ans;
                }
            }
            ans = pref;
        }
        
        return ans;
    }
};
