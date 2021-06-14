/*
Given an integer numRows, return the first numRows of Pascal's triangle.
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> output;
        
        if(numRows==0)
        {
            return output;
        }
        
        if(numRows==1)
        {
            vector<int> temp;
            temp.push_back(1);
            output.push_back(temp);
            return output;
        }
        if(numRows==2)
        {
            vector<int> temp;
            temp.push_back(1);
            output.push_back(temp);
            temp.push_back(1);
            output.push_back(temp);
            return output;
        }
        
        vector<int> temp;
        temp.push_back(1);
        output.push_back(temp);
        temp.push_back(1);
        output.push_back(temp);
        
        for(int i=2; i<numRows; i++)
        {
            vector<int> temp;
            temp.push_back(1);
            for(int j=i-1; j>0; j--)
            {
                temp.push_back(output[i-1][j]+output[i-1][j-1]);
            }
            temp.push_back(1);
            output.push_back(temp);
        }
        
        return output;
        
        
        
    }
};
