/*
Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        
        string temp = "";
        
        for(int i=0; i<s.length(); i++)
        {
            if('0'<=s[i] && s[i]<='9' || 'A'<=s[i] && s[i]<='Z' || 'a'<=s[i] && s[i]<='z')
            {
                temp += s[i];
            }
        }
        
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        
        string rev = temp;
        
        reverse(rev.begin(), rev.end());
        
        if(rev==temp)
        {
            return true;
        }
        
        return false;
        
    }
};
