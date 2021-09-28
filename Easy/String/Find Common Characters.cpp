/*
Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

 

Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of lowercase English letters.
*/

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        map<char, int> mp;
        int n=words.size();
        
        set<char> st;
        for(int i=0; i<n; i++)
        {
            for(auto c: words[i])
            {
                st.insert(c);
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(auto c: st)
            {
                int cnt=0;
                for(auto x: words[i])
                {
                    if(x==c)
                    {
                        cnt++;
                    }
                }
                if(i==0)
                {
                    mp[c]=cnt;
                }
                else
                {
                    mp[c]=min(mp[c], cnt);
                }
            }
        }
        vector<string> ans;
        for(auto i: mp)
        {
            if(i.second>0)
            {
                int t=i.second;
                while(t--)
                {
                    string s="";
                    s += i.first;
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};
