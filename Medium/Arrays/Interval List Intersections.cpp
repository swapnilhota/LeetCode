/*
You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].
*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        sort(begin(firstList), end(firstList));
        sort(begin(secondList), end(secondList));
        vector<vector<int>> res;
        
        int n1 = firstList.size();
        int n2 = secondList.size();
        
        int i=0;
        int j=0;
        
        while(i<n1 && j<n2)
        {
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];
            int start2 = secondList[j][0];
            int end2 = secondList[j][1];
            
            int new_start = max(start1, start2);
            int new_end = min(end1, end2);
            
            if(new_start<=new_end)
            {
                vector<int> temp = {new_start, new_end};
                res.push_back(temp);
            }
            
            if(end2>end1)
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        
        return res;
    }
};
