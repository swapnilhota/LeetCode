/*
Given a string s, return the first non-repeating character in it and return its index. If it does not exist, return -1.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        
        int ans = -1;
        
        map<char, int> m;
        
        for(auto i: s)
        {
            m[i]++;
        }
        
        for(int i=0; i<s.length(); i++)
        {
            if(m[s[i]]==1)
            {
                return i;
            }
        }
        
        return ans;
        
    }
};
