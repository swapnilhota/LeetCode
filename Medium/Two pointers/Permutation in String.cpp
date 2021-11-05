/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length() < s1.length())
        {
            return false;
        }
        if(s2==s1)
        {
            return true;
        }
        if(s1.length()==s2.length())
        {
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            if(s1==s2)
            {
                return true;
            }
            return false;
        }
        
        set<char> st;
        map<char, int> req;
        for(auto c: s1)
        {
            req[c]++;
            st.insert(c);
        }
        int letters = st.size();
        st.clear();
        int i=0;
        int j=0;
        
        map<char, int> cnt;
        
        for(; j<s1.length(); j++)
        {
            cnt[s2[j]]++;
            st.insert(s2[j]);
        }
        
        if(letters==st.size() && check(s1, req, cnt))
        {
            return true;
        }
        
        while(j<s2.length())
        {
            cnt[s2[i]]--;
            if(cnt[s2[i]]==0)
            {
                st.erase(st.find(s2[i]));
            }
            cnt[s2[j]]++;
            st.insert(s2[j]);
            if(letters==st.size() && check(s1, req, cnt))
            {
                return true;
            }
            j++;
            i++;
        }
        
        return false;
        
    }
    
    bool check(string &s, map<char, int> &req, map<char, int> &cnt)
    {
        for(auto c: s)
        {
            if(req[c]!=cnt[c])
            {
                return false;
            }
        }
        return true;
    }
};
