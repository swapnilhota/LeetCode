/*
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        
        if(num1.length()<num2.length())
        {
            return addStrings(num2, num1);
        }
        
        string ans = "";
        
        int i = num1.length()-1;
        int j = num2.length()-1;
        int carry = 0;
        
        while(i>=0 && j>=0)
        {
            int x = (num1[i]-'0') + (num2[j]-'0') + carry;
            carry = x/10;
            x = x%10;
            ans += to_string(x);
            i--;
            j--;
        }
        
        while(i>=0)
        {
            int x = (num1[i]-'0') + carry;
            carry = x/10;
            x = x%10;
            ans += to_string(x);
            i--;
        }
        
        if(carry>0)
        {
            ans += to_string(carry);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};
