/*
You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.


Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile
*/

class Solution {
public:
    int numTilings(int n) {
        
        if(n<3)
        {
            return n;
        }
        
        long mod = 1e9+7;
        vector<long> d(n+1, 0), t(n+1, 0);
        
        d[0]=0; d[1]=1; d[2]=2;
        t[0]=0; t[1]=1; t[2]=2;
        
        for(long i=3L; i<=n; i++)
        {
            d[i] = (d[i-1]+d[i-2]+2*t[i-2])%mod;
            t[i] = (t[i-1]+d[i-1])%mod;
        }
        
        return d[n];
    }
};
