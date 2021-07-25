/*
You are given a string num, which represents a large integer. You are also given a 0-indexed integer array change of length 10 that maps each digit 0-9 to another digit. More formally, digit d maps to digit change[d].

You may choose to mutate any substring of num. To mutate a substring, replace each digit num[i] with the digit it maps to in change (i.e. replace num[i] with change[num[i]]).

Return a string representing the largest possible integer after mutating (or choosing not to) any substring of num.

A substring is a contiguous sequence of characters within the string.
*/

class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        
        int i=0;
        int flag=0;
        
        while(i<num.length())
        {
            int digit = num[i]-'0';
            if(change[digit]<digit)
            {
                if(flag==1)
                {
                    break;
                }
            }
            else if(change[digit]>digit)
            {
                num[i] = (char)('0'+change[digit]);
                flag=1;
            }
            
            i++;
        }
        
        return num;
        
    }
};
