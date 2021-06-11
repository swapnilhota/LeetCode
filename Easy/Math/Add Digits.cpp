/*
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
*/

class Solution {
public:
    int addDigits(int num) {
        
        string s = to_string(num);
        
        if(s.length()==1)
        {
            return num;
        }
        
        int x=0;
        
        for(char c: s)
        {
            x += (c-'0');
        }
        
        return addDigits(x);
        
    }
};
