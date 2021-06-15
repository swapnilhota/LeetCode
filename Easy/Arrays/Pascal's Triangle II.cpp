/*
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> ans;
        
        for(int i=0; i<=rowIndex; i++)
        {
            ans.push_back(1);
            for(int j=i-1; j>0; j--)
            {
                ans[j]=ans[j]+ans[j-1];
            }
        }
        
        return ans;
        
    }
};