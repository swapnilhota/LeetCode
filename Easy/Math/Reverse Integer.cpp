/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
*/

class Solution {
public:
    int reverse(int x) {
        
        string s = to_string(x);
        std::reverse(s.begin(), s.end());
        
        if(x<0)
        {
            try
            {
                return (-1)*stoi(s);
            }
            catch(...)
            {
                return 0;
            }
        }
        else
        {
            try
            {
                return stoi(s);
            }
            catch(...)
            {
                return 0;
            }
        }
        
    }
};
