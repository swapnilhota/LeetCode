/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        if(m==1 && n==1)
        {
            if(board[0][0]==word[0] && word.length()==1)
            {
                return true;
            }
        }
        
        vector<vector<bool>> vis(m+1, vector<bool>(n+1, false));
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j]==word[0])
                {
                    if(check(board, i, j, word, 0, vis))
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};
    
    bool check(vector<vector<char>> &board, int row, int col, string &word, int idx, vector<vector<bool>> &vis)
    {
        if(idx==word.length()-1 && board[row][col]==word[idx])
        {
            return true;
        }
        if(row >= board.size() || col >= board[0].size() || row<0 || col<0)
        {
            return false;
        }
        
        if(board[row][col]!=word[idx])
        {
            return false;
        }
        
        vis[row][col] = true;
        
        for(int k=0; k<4; k++)
        {
            int i = row+dr[k];
            int j = col+dc[k];
            
            if(i>=0 && j>=0 && i<board.size() && j<board[0].size())
            {
                if(!vis[i][j] && check(board, i, j, word, idx+1, vis))
                {
                    return true;
                }
            }
        }
        
        vis[row][col] = false;
        
        return false;
    }
};
