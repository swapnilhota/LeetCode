/*
Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.

The words in paragraph are case-insensitive and the answer should be returned in lowercase.

 

Example 1:

Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
Output: "ball"
Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.
Example 2:

Input: paragraph = "a.", banned = []
Output: "a"
 

Constraints:

1 <= paragraph.length <= 1000
paragraph consists of English letters, space ' ', or one of the symbols: "!?',;.".
0 <= banned.length <= 100
1 <= banned[i].length <= 10
banned[i] consists of only lowercase English letters.
*/

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        vector<string> words;
        string temp="";
        for(auto c: paragraph)
        {
            if(c>='a' && c<='z' || c>='A' && c<='Z')
            {
                temp+=c;                
            }
            else
            {
                if(temp!="")
                {
                    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
                    words.push_back(temp);
                    temp="";
                }
            }
        }
        
        if(temp!="")
        {
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            words.push_back(temp);
            temp="";
        }
        
        set<string> st;
        for(auto s: banned)
        {
            st.insert(s);
        }
        
        map<string, int> mp;
        for(auto s: words)
        {
            if(st.find(s)!=st.end())
            {
                continue;
            }
            mp[s]++;
            //cout<<s<<endl;
        }
        
        int freq=0;
        string res;
        
        for(auto i: mp)
        {
            if(i.second>freq)
            {
                freq=i.second;
                res=i.first;
            }
        }
        
        return res;
    }
};
