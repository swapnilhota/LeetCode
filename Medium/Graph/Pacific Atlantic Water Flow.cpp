/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.
*/

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        int vis_pac[m][n];
        memset(vis_pac, 0, sizeof(vis_pac));
        
        int vis_at[m][n];
        memset(vis_at, 0, sizeof(vis_at));
        
        vector<vector<int>> res;
        
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, -1, 0, 1};
        
        queue<pair<int, int>> q;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 || j==0)
                {
                    q.push(make_pair(i, j));
                }
            }
        }
        
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            int h = heights[r][c];

            vis_pac[r][c]=1;

            for(int k=0; k<4; k++)
            {
                int x = r+dr[k];
                int y = c+dc[k];

                if(x>=0 && y>=0 && x<m && y<n)
                {
                    if(!vis_pac[x][y] && heights[x][y]>=h)
                    {
                        q.push(make_pair(x, y));
                    }
                }
            }
        }
        
        while(!q.empty()) q.pop();
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==m-1 || j==n-1)
                {
                    q.push(make_pair(i, j));
                }
            }
        }
        
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            int h = heights[r][c];

            vis_at[r][c]=1;

            for(int k=0; k<4; k++)
            {
                int x = r+dr[k];
                int y = c+dc[k];

                if(x>=0 && y>=0 && x<m && y<n)
                {
                    if(!vis_at[x][y] && heights[x][y]>=h)
                    {
                        q.push(make_pair(x, y));
                    }
                }
            }
        }
        
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(vis_pac[i][j] && vis_at[i][j])
                {
                    vector<int> tmp = {i, j};
                    res.push_back(tmp);
                }
            }
        }
        
        return res;
    }
};
