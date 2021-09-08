/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.
*/

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.length();
        int n=str2.length();
        int dp[m+1][n+1];
        for(int i=0; i<=m; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                }
            }
        }
        
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        string lcs="";
        
        int i=m, j=n;
        
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                lcs += str1[i-1];
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    i--;
                }
                else
                {
                    j--;
                }
            }
        }
        
        reverse(lcs.begin(), lcs.end());
        
        vector<string> v1;
        vector<string> v2;
        
        int idx=0;
        string t="";
        for(int i=0; i<str1.length(); i++)
        {
            if(str1[i]==lcs[idx] && idx<lcs.size())
            {
                v1.push_back(t);
                t="";
                idx++;
            }
            else
            {
                t += str1[i];
            }
        }
        v1.push_back(t);
        
        t="";
        idx=0;
        
        for(int i=0; i<str2.length(); i++)
        {
            if(str2[i]==lcs[idx] && idx<lcs.size())
            {
                v2.push_back(t);
                t="";
                idx++;
            }
            else
            {
                t += str2[i];
            }
        }
        v2.push_back(t);
        
        idx=0;
        
        string res="";
        
        for(int i=0; i<v1.size(); i++)
        {
            res += v1[i];
            res += v2[i];
            if(idx<lcs.size())
            {
                res += lcs[idx];
                idx++;
            }            
        }
        
        return res;
    }
};
