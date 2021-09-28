/*
On an 8 x 8 chessboard, there is exactly one white rook 'R' and some number of white bishops 'B', black pawns 'p', and empty squares '.'.

When the rook moves, it chooses one of four cardinal directions (north, east, south, or west), then moves in that direction until it chooses to stop, reaches the edge of the board, captures a black pawn, or is blocked by a white bishop. A rook is considered attacking a pawn if the rook can capture the pawn on the rook's turn. The number of available captures for the white rook is the number of pawns that the rook is attacking.

Return the number of available captures for the white rook.
*/

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ans=0;
        int r, c;
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                if(board[i][j]=='R')
                {
                    r=i;
                    c=j;
                    break;
                }
            }
        }
        
        //up
        int i=r-1;
        int j=c;
        while(i>=0)
        {
            if(board[i][j]=='B')
            {
                break;
            }
            if(board[i][j]=='p')
            {
                ans++;
                break;
            }
            i--;
        }
        
        cout<<ans<<endl;
        
        //left
        i=r;
        j=c-1;
        while(j>=0)
        {
            if(board[i][j]=='B')
            {
                break;
            }
            if(board[i][j]=='p')
            {
                ans++;
                break;
            }
            j--;
        }
        cout<<ans<<endl;
        
        //down
        i=r+1;
        j=c;
        while(i<8)
        {
            if(board[i][j]=='B')
            {
                break;
            }
            if(board[i][j]=='p')
            {
                ans++;
                break;
            }
            i++;
        }
        cout<<ans<<endl;
        
        //right
        i=r;
        j=c+1;
        while(j<8)
        {
            if(board[i][j]=='B')
            {
                break;
            }
            if(board[i][j]=='p')
            {
                ans++;
                break;
            }
            j++;
        }
        cout<<ans<<endl;
        
        return ans;
    }
};
