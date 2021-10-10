/*
Given an array points where points[i] = [xi, yi] represents a point on the X-Y plane, return true if these points are a boomerang.

A boomerang is a set of three points that are all distinct and not in a straight line.

 

Example 1:

Input: points = [[1,1],[2,3],[3,2]]
Output: true
Example 2:

Input: points = [[1,1],[2,2],[3,3]]
Output: false
 

Constraints:

points.length == 3
points[i].length == 2
0 <= xi, yi <= 100
*/

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        
        int a = (points[1][1]-points[0][1])*(points[2][0]-points[1][0]);
        int b = (points[2][1]-points[1][1])*(points[1][0]-points[0][0]);
        
        set<vector<int>> st;
        st.insert(points[0]);
        st.insert(points[1]);
        st.insert(points[2]);
        
        if(a!=b && st.size()==3)
        {
            return true;
        }
        
        return false;
    }
};
