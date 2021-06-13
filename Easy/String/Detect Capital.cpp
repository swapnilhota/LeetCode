/*
We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int cnt=0;
        
        for(char c:word)
        {
            if(c>='A' && c<='Z')
            {
                cnt++;
            }
        }
        
        if(cnt==0)
        {
            return true;
        }
        if(cnt==word.length())
        {
            return true;
        }
        if(cnt==1)
        {
            if(word[0]>='A' && word[0]<='Z')
            {
                return true;
            }
        }
        
        return false;
    }
};
