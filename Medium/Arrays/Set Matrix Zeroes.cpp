/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

You must do it in place.
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int a=1;
        int b=1;
        
        for(int i=0; i<m; i++)
        {
            if(matrix[i][0]==0) a=0;
        }
        for(int i=0; i<n; i++)
        {
            if(matrix[0][i]==0) b=0;
        }
        
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        
        for(int i=0; i<m; i++)
        {
            if(a==0)
            {
                matrix[i][0]=0;
            }
        }
        
        for(int i=0; i<n; i++)
        {
            if(b==0)
            {
                matrix[0][i]=0;
            }
        }
    }
};
