/*
Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.

A word is a maximal substring consisting of non-space characters only.
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        vector<string> v;
        string temp = "";
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]==' ')
            {
                if(temp!="")
                {
                    v.push_back(temp);
                }
                temp="";
            }
            else
            {
                temp += s[i];
            }
        }
        
        if(temp!="")
        {
            v.push_back(temp);
        }
        
        if(v.size()==0)
        {
            return 0;
        }
        
        return v[v.size()-1].length();
        
    }
};
