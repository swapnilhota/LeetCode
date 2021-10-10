/*
You are given four integers row, cols, rCenter, and cCenter. There is a rows x cols matrix and you are on the cell with the coordinates (rCenter, cCenter).

Return the coordinates of all cells in the matrix, sorted by their distance from (rCenter, cCenter) from the smallest distance to the largest distance. You may return the answer in any order that satisfies this condition.

The distance between two cells (r1, c1) and (r2, c2) is |r1 - r2| + |c1 - c2|.
*/

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        set<pair<int, vector<int>>> st;
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                int dist = abs(rCenter-i)+abs(cCenter-j);
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                st.insert(make_pair(dist, tmp));
            }
        }
        
        vector<vector<int>> res;
        for(auto i: st)
        {
            res.push_back(i.second);
        }
        
        return res;
    }
};
