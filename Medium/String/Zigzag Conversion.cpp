/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
*/

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> res(numRows+1, "");
        int curr=1;
        int flag=-1;
        int i=0;
        
        if(numRows==1)
        {
            return s;
        }
        
        while(i<s.length())
        {
            res[curr] += s[i];
            i++;
            
            if(flag==-1)
            {
                curr++;
                if(curr>numRows)
                {
                    curr=numRows-1;
                    flag=1;
                }
            }
            else
            {
                curr--;
                if(curr<1)
                {
                    curr=2;
                    flag=-1;
                }
            }
        }
        
        string ans="";
        
        for(int i=1; i<=numRows; i++)
        {
            ans += res[i];
        }
        
        return ans;
    }
};
