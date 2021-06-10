/*
Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        
       if(x<0)
       {
           return false;
       }
        
        string s = to_string(x);
        int i=0;
        int j=s.length()-1;
        
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        
        return true;        
        
    }
};
