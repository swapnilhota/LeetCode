/*
Give a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

 

Example 1:

Input: s = "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
Example 2:

Input: s = "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
 

Constraints:

1 <= s.length <= 105
s[i] is either '0' or '1'.
*/

class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<string> v;
        string temp = "";
        for(int i=0; i<s.length(); i++)
        {
            if(temp=="")
            {
                temp += s[i];
            }
            else
            {
                if(temp[0]!=s[i])
                {
                    v.push_back(temp);
                    temp = s[i];
                }
                else
                {
                    temp += s[i];
                }
            }
        }
        if(temp!="")
        {
            v.push_back(temp);
        }
        
        int ans=0;
        
        for(int i=1; i<v.size(); i++)
        {
            ans += min(v[i].length(), v[i-1].length());
        }
        
        return ans;
    }
};
