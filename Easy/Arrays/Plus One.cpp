/*
Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();
        int x = digits[n-1]+1;
        int carry = x/10;
        x = x%10;
        digits[n-1] = x;
        if(carry==0)
        {
            return digits;
        }
        for(int i=n-2; i>=0; i--)
        {
            int tmp = digits[i]+carry;
            carry = tmp/10;
            tmp = tmp%10;
            digits[i] = tmp;
            if(carry==0)
            {
                break;
            }
        }
        
        vector<int> ans;
        if(carry>0)
        {
            ans.push_back(1);
        }
        for(auto i:digits)
        {
            ans.push_back(i);
        }
        
        return ans;
    }
};
