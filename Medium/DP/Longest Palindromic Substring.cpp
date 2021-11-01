/*
Given a string s, return the longest palindromic substring in s.
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                if(i==j)
                {
                    dp[i][j]=true;
                }
                if(j==i+1 && s[i]==s[j])
                {
                    dp[i][j]=true;
                }
            }
        }
        
        int ans=0;
        string res="";
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i+1; j<n; j++)
            {
                if(dp[i][j]) continue;
                dp[i][j] = dp[i+1][j-1] && s[i]==s[j];
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                if(dp[i][j])
                {
                    if(j-i >= ans)
                    {
                        ans = j-i;
                        res = s.substr(i, j-i+1);
                    }
                }
            }
        }
        
        return res;
    }
};
