/*
A fancy string is a string where no three consecutive characters are equal.

Given a string s, delete the minimum possible number of characters from s to make it fancy.

Return the final string after the deletion. It can be shown that the answer will always be unique.

 

Example 1:

Input: s = "leeetcode"
Output: "leetcode"
Explanation:
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".
Example 2:

Input: s = "aaabaaaa"
Output: "aabaa"
Explanation:
Remove an 'a' from the first group of 'a's to create "aabaaaa".
Remove two 'a's from the second group of 'a's to create "aabaa".
No three consecutive characters are equal, so return "aabaa".
Example 3:

Input: s = "aab"
Output: "aab"
Explanation: No three consecutive characters are equal, so return "aab".
 

Constraints:

1 <= s.length <= 105
s consists only of lowercase English letters.
*/

class Solution {
public:
    string makeFancyString(string s) {
        
        string ans="";
        
        if(s.length()<=2)
        {
            return s;
        }
        
        char curr = s[0];
        int tmp = 1;
        
        vector<bool> valid(s.length(), true);
        
        for(int i=1; i<s.length(); i++)
        {
            if(s[i]==curr)
            {
                tmp++;
                if(tmp>=3)
                {
                    valid[i]=false;
                }
            }
            else
            {
                tmp=1;
                curr=s[i];
            }
        }
        
        for(int i=0; i<s.length(); i++)
        {
            if(valid[i])
            {
                ans += s[i];
            }
        }
        
        return ans;
        
    }
};
