/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int x=0; x<n/2; x++)
        {
            int top = x;
            int left = x;
            int right = n-x-1;
            int bottom = n-x-1;
            
            int temp;
            for(int j=left; j<right; j++)
            {
                temp = matrix[top][j];
                
                swap(matrix[top+j-left][right], temp);
                
                swap(matrix[bottom][right-(j-left)], temp);
                
                swap(matrix[bottom-(j-left)][left], temp);
                
                swap(matrix[top][j], temp);
            }
        }
    }
};
