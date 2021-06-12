/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
*/

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> stk;
        
        if(s.length()%2!=0)
        {
            return false;
        }
        
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                stk.push(s[i]);
            }
            else
            {
                if(stk.empty())
                {
                    return false;
                }
                if(s[i]==')')
                {
                    if(stk.top()!='(')
                    {
                        return false;
                    }
                }
                if(s[i]=='}')
                {
                    if(stk.top()!='{')
                    {
                        return false;
                    }
                }
                if(s[i]==']')
                {
                    if(stk.top()!='[')
                    {
                        return false;
                    }
                }
                
                stk.pop();
                
            }
        }
        
        if(stk.empty())
        {
            return true;
        }
        return false;
        
    }
};
