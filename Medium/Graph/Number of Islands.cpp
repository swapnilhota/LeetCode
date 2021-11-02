/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        int ans=0;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    ans++;
                    dfs(grid, m, n, i, j, vis);
                }
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<char>> &grid, int m, int n, int r, int c, vector<vector<int>> &vis)
    {
        vis[r][c] = 1;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, -1, 0, 1};
        
        for(int k=0; k<4; k++)
        {
            int i = r+dr[k];
            int j = c+dc[k];
            
            if(i>=0 && j>=0 && i<m && j<n)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    dfs(grid, m, n, i, j, vis);
                }
            }
        }
    }
};
