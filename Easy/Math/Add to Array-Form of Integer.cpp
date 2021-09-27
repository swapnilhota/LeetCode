/*
The array-form of an integer num is an array representing its digits in left to right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

 

Example 1:

Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: num = [2,7,4], k = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
Example 3:

Input: num = [2,1,5], k = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
Example 4:

Input: num = [9,9,9,9,9,9,9,9,9,9], k = 1
Output: [1,0,0,0,0,0,0,0,0,0,0]
Explanation: 9999999999 + 1 = 10000000000
 

Constraints:

1 <= num.length <= 104
0 <= num[i] <= 9
num does not contain any leading zeros except for the zero itself.
1 <= k <= 104
*/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        string s = to_string(k);
        vector<int> b;
        for(auto c: s)
        {
            b.push_back(c-'0');
        }
        if(num.size()>b.size())
        {
            return helper(num, b);
        }
        return helper(b, num);
    }
    vector<int> helper(vector<int> &a, vector<int> &b)
    {
        int i=a.size()-1;
        int j=b.size()-1;
        int carry=0;
        while(i>=0 && j>=0)
        {
            int x = a[i]+b[j]+carry;
            carry = x/10;
            a[i] = x%10;
            i--;
            j--;
        }
        while(i>=0)
        {
            int x = a[i]+carry;
            carry = x/10;
            a[i] = x%10;
            i--;
        }
        if(carry>0)
        {
            reverse(a.begin(), a.end());
            a.push_back(carry);
            reverse(a.begin(), a.end());
        }
        return a;
    }
};
