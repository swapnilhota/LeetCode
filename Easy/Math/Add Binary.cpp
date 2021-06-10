/*
Given two binary strings a and b, return their sum as a binary string
*/

class Solution {
public:
    string addBinary(string a, string b) {
        
        string ans="";
        
        int lenA = a.length();
        int lenB = b.length();
        
        if(lenA<lenB)
        {
            return addBinary(b, a);
        }
        
        int i=lenA-1;
        int j=lenB-1;
        
        int carry=0;
        
        while(i>=0 && j>=0)
        {
            int x = (a[i]-'0')+(b[j]-'0')+carry;
            carry = x/2;
            x = x%2;
            
            ans += to_string(x);
            i--;
            j--;
        }
        
        while(i>=0)
        {
            int x = (a[i]-'0')+carry;
            carry = x/2;
            x=x%2;
            
            ans += to_string(x);
            i--;
        }
        
        while(carry>0)
        {
            int x = carry;
            carry = x/2;
            x = x%2;
            
            ans += to_string(x);
        }
        
        std::reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};
