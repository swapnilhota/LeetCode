/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int c = matrix[0].size();
        for(int i=0; i<n; i++)
        {
            if(matrix[i][c-1]>=target)
            {
                int x = *lower_bound(matrix[i].begin(), matrix[i].end(), target);
                if(x==target)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
