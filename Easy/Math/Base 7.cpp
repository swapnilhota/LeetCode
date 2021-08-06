/*
Given an integer num, return a string of its base 7 representation.

 

Example 1:

Input: num = 100
Output: "202"
Example 2:

Input: num = -7
Output: "-10"
 

Constraints:

-107 <= num <= 107
*/

class Solution {
public:
    string convertToBase7(int num) {
        string ans = "";
        int tmp = num;
        
        if(num==0)
        {
            return "0";
        }
        
        while(num)
        {
            ans += to_string(abs(num%7));
            num = num/7;
        }
        
        reverse(ans.begin(), ans.end());
        
        if(tmp<0)
        {
            ans = '-'+ans;
        }
        
        return ans;
    }
};
