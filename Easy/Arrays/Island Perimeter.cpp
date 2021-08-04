/*
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example 1:


Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
Example 2:

Input: grid = [[1]]
Output: 4
Example 3:

Input: grid = [[1,0]]
Output: 4
 

Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] is 0 or 1.
*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int ans=0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    ans += check(grid, i, j);
                }
            }
        }
        
        return ans;
        
    }
    
    int check(vector<vector<int>>& grid, int row, int col)
    {
        int a1 = up(grid, row, col);
        int a2 = left(grid, row, col);
        int a3 = right(grid, row, col);
        int a4 = down(grid, row, col);
        
        return a1+a2+a3+a4;
    }
    
    int up(vector<vector<int>>& grid, int row, int col)
    {
        if(row==0)
        {
            return 1;
        }
        if(grid[row-1][col]==0)
        {
            return 1;
        }
        return 0;
    }
    
    int left(vector<vector<int>>& grid, int row, int col)
    {
        if(col==0 || grid[row][col-1]==0)
        {
            return 1;
        }
        return 0;
    }
    
    int right(vector<vector<int>>& grid, int row, int col)
    {
        if(col==grid[0].size()-1 || grid[row][col+1]==0)
        {
            return 1;
        }
        return 0;
    }
    
    int down(vector<vector<int>>& grid, int row, int col)
    {
        if(row==grid.size()-1 || grid[row+1][col]==0)
        {
            return 1;
        }
        return 0;
    }
};
