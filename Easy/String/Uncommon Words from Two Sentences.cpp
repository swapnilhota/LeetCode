/*
A sentence is a string of single-space separated words where each word consists only of lowercase letters.

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.

 

Example 1:

Input: s1 = "this apple is sweet", s2 = "this apple is sour"
Output: ["sweet","sour"]
Example 2:

Input: s1 = "apple apple", s2 = "banana"
Output: ["banana"]
 

Constraints:

1 <= s1.length, s2.length <= 200
s1 and s2 consist of lowercase English letters and spaces.
s1 and s2 do not have leading or trailing spaces.
All the words in s1 and s2 are separated by a single space.
*/

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> w1;
        vector<string> w2;
        
        string tmp="";
        for(auto c: s1)
        {
            if(c==' ')
            {
                if(tmp!="")
                {
                    w1.push_back(tmp);
                    tmp="";
                }
            }
            else
            {
                tmp+=c;
            }
        }
        if(tmp!="")
        {
            w1.push_back(tmp);
        }
        
        tmp="";
        for(auto c: s2)
        {
            if(c==' ')
            {
                if(tmp!="")
                {
                    w2.push_back(tmp);
                    tmp="";
                }
            }
            else
            {
                tmp+=c;
            }
        }
        if(tmp!="")
        {
            w2.push_back(tmp);
        }
        
        map<string, int> m1;
        map<string, int> m2;
        
        for(auto w: w1)
        {
            m1[w]++;
        }
        for(auto w: w2)
        {
            m2[w]++;
        }
        
        vector<string> res;
        
        for(auto i: m1)
        {
            if(m2[i.first]==0 && i.second==1)
            {
                res.push_back(i.first);
            }
        }
        
        for(auto i: m2)
        {
            if(m1[i.first]==0 && i.second==1)
            {
                res.push_back(i.first);
            }
        }
        
        return res;
    }
};
