/*
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
*/

class Solution {
public:
    bool validPalindrome(string s) {
        int flag=0;
        int i=0;
        int j=s.length()-1;
        bool ans = true;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else if(!flag)
            {
                i++;
                flag=1;
            }
            else
            {
                ans=false;
                break;
            }
        }
        
        if(ans)
        {
            return ans;
        }
        
        i=0;
        j=s.length()-1;
        flag=0;
        
        ans=true;
        
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else if(!flag)
            {
                j--;
                flag=1;
            }
            else
            {
                ans=false;
                break;
            }
        }
        
        return ans;
    }
};
