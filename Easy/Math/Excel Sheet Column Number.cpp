/*
Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.
*/

class Solution {
public:
    int titleToNumber(string s) {
        
        int p = 0;
        int n=s.length();
        int ans=0;
        for(int i=n-1; i>=0; i--)
        {
            int x = s[i]-'A'+1;
            ans += x*(int)pow(26, p);
            p++;
        }
        return ans;
        
    }
};
