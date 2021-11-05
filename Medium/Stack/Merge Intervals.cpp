/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        stack<pair<int, int>> stk;
        sort(intervals.begin(), intervals.end());
        stk.push(make_pair(intervals[0][0], intervals[0][1]));
        for(int i=1; i<intervals.size(); i++)
        {
            int prev_start = stk.top().first;
            int prev_end = stk.top().second;
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];
            
            if(prev_end >= curr_start)
            {
                stk.pop();
                stk.push(make_pair(min(prev_start, curr_start), max(prev_end, curr_end)));
            }
            else
            {
                stk.push(make_pair(curr_start, curr_end));
            }
        }
        
        vector<vector<int>> res;
        while(!stk.empty())
        {
            vector<int> temp = {stk.top().first, stk.top().second};
            stk.pop();
            res.push_back(temp);
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
