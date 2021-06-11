/*
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
*/

class Solution {
public:
    string convertToTitle(int n) {
        
        string ans="";
        
        while(n)
        {
            int rem = n%26;
            if(rem==0)
            {
                ans += "Z";
                n--;
            }
            else
            {
                ans += (char)('A'+rem-1);
            }
            n=n/26;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};
