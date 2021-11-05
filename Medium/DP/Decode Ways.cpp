/*
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The answer is guaranteed to fit in a 32-bit integer.
*/

class Solution {
public:
    int numDecodings(string s) {
        string nums = s;
        memset(dp, -1, sizeof(dp));
        int ans = solve(nums, nums.length()-1, nums.length()-1);
        return ans;
    }
    
    int dp[102][102];
    
    int solve(string &nums, int start, int end)
    {
        if(start==0)
        {
            string tmp = nums.substr(start, end-start+1);
            int x = stoi(tmp);
            if(x>26 || x<1)
            {
                cout<<x<<endl;
                return 0;
            }
            if(tmp.length() != to_string(x).length())
            {
                cout<<tmp<<endl;
                cout<<x<<endl;
                return 0;
            }
            cout<<tmp<<endl;
            return 1;
        }
        if(dp[start][end]!=-1)
        {
            return dp[start][end];
        }
        
        string tmp = nums.substr(start, end-start+1);
        int x = stoi(tmp);
        if(x==0)
        {
            return dp[start][end] = solve(nums, start-1, end);
        }
        if(x>26 || x<1)
        {
            cout<<x<<endl;
            return dp[start][end] = 0;
        }
        if(tmp.length() != to_string(x).length())
        {
            return dp[start][end] = 0;
        }
        
        int ans = 0;
        
        ans += solve(nums, start-1, start-1);
        ans += solve(nums, start-1, end);
        
        return dp[start][end] = ans;
    }
};
